/////////////////////////////////////////////////////////////////////////////
//                         Single Threaded Networking
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////


#include "ChatWindow.h"

#include <cassert>

const int STATS_WINDOW_HEIGHT = 20;
const int STATS_WINDOW_WIDTH = 20;

ChatWindow::ChatWindow(std::function<void(std::string)> onTextEntry,
                       int updateDelay)
  : onTextEntry{onTextEntry} {
  initscr();
  noecho();
  start_color();
  halfdelay(updateDelay);

  getmaxyx(stdscr, parentY, parentX);
  createALL();              //create all the windows view,desc,view,entry
  scrollok(view, TRUE);

  entrySub = derwin(entry, entrySize - 1, parentX, 1, 0);

  entryField = new_field(entrySize - 1, parentX, 0, 0, 0, 0);
  assert(entryField && "Error creating entry field.");
  set_field_buffer(entryField, 0, "");
  set_field_opts(entryField, O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

  fields[0] = entryField;
  entryForm = new_form(fields);
  assert(entryForm && "Error creating entry form.");
  set_form_win(entryForm, entry);
  set_form_sub(entryForm, entrySub);
  post_form(entryForm);

  refresh();
  wrefresh(entry);
}


ChatWindow::~ChatWindow() {
  unpost_form(entryForm);
  free_form(entryForm);
  free_field(entryField);
  delwin(entry);
  delwin(view);
  delwin(desc);
  delwin(Stats);
  delwin(Chatbox);
  endwin();
}


void
ChatWindow::update() {
  resizeOnShapeChange();
  processInput(getch());
  wrefresh(desc);
  wrefresh(view);
  wrefresh(Stats);
  wrefresh(entry);
  wrefresh(Chatbox);

}
void ChatWindow::setWindowColor(WINDOW *win, int color) {
  if (color==1)
    wbkgd(win, COLOR_PAIR(1));
  else if (color==2)
    wbkgd(win, COLOR_PAIR(2));
  else if (color==3)
    wbkgd(win, COLOR_PAIR(3));

  wrefresh(win);
}


void
ChatWindow::createALL() {
  /*define color pairs*/
  init_pair(1,COLOR_BLUE,COLOR_BLACK);
  init_pair(2,COLOR_WHITE,COLOR_BLACK);
  init_pair(3,COLOR_RED,COLOR_BLACK);

  view = newwin(parentY - (entrySize + STATS_WINDOW_HEIGHT), parentX - 40, STATS_WINDOW_HEIGHT , 0);
  setWindowColor(view,1);
  /*Create player's stat window*/
  Stats = newwin(STATS_WINDOW_HEIGHT, STATS_WINDOW_HEIGHT, 0, parentX - STATS_WINDOW_WIDTH);

  //playerStats->displayStatsTest();

  /*CREATE description window*/
  desc = newwin(STATS_WINDOW_HEIGHT, parentX - STATS_WINDOW_WIDTH,0,0);
  setWindowColor(desc,3);
  DUMMYADD();

  /* CREATE the new chatbox window*/

  Chatbox = newwin(parentY - (entrySize + STATS_WINDOW_HEIGHT),40,STATS_WINDOW_HEIGHT,parentX - 40);
  setWindowColor(Chatbox,3);

  entry = newwin(entrySize, parentX, parentY - entrySize, 0);
  wborder(entry, ' ', ' ', '-', ' ', '+', '+', ' ', ' ');
  wborder(Stats, '*', '*', '*', '*', '*', '*', '*', '*');
  wborder(desc, '*', ' ', '*', '*', '*', '*', '*', '*');
  wborder(Chatbox,'*','*',' ','*','*','*', '*', '*');


}

void ChatWindow::DUMMYADD(){
  mvwaddstr(desc,1, 1," This is the description window");
  mvwaddstr(desc,2, 2," This will contain info from the server");
  mvwaddstr(desc,3, 3," This will change depending on the update");

  mvwaddstr(Stats,1,2,"Player: TEST \n");
  mvwaddstr(Stats,2,2,"Level: Noob \n");
  mvwaddstr(Stats,3,2,"Aera: TEST \n");
  mvwaddstr(Stats,4,2,"Health : 25 \n");
  mvwaddstr(Stats,5,2,"Mana: 10 \n");

}

void
ChatWindow::displayText(const std::string& text) {
  int currentY;
  int currentX;
  getyx(view, currentY, currentX);
  currentX = 0;
  mvwaddstr(view, currentY, currentX + 1, text.c_str());

}


void
ChatWindow::resizeOnShapeChange() {
  int newX, newY;
  getmaxyx(stdscr, newY, newX);

  if (newY != parentY || newX != parentX) {
    parentX = newX;
    parentY = newY;

    resizeHelper(view, parentY - (entrySize + STATS_WINDOW_HEIGHT), parentX - 40, STATS_WINDOW_HEIGHT, 0);
    resizeHelper(entry, entrySize, parentX, parentY- entrySize,0);
    resizeHelper(desc, STATS_WINDOW_HEIGHT, parentX - STATS_WINDOW_WIDTH, 0,0);
    resizeHelper(Chatbox,parentY - (entrySize + STATS_WINDOW_HEIGHT),40,STATS_WINDOW_HEIGHT,parentX - 40);
    resizeHelper(Stats,STATS_WINDOW_HEIGHT, STATS_WINDOW_HEIGHT, 0, parentX - STATS_WINDOW_WIDTH);

    wclear(stdscr);

    wborder(entry, ' ', ' ', '-', ' ', '+', '+', ' ', ' ');
    wborder(desc, '*', ' ', '*', '*', '*', '*', '*', '*');
    wborder(Chatbox,'*','*',' ','*','*','*', '*', '*');
    wborder(Stats, '*', '*', '*', '*', '*', '*', '*', '*');
  }
}

void
ChatWindow::resizeHelper(WINDOW *win, int win_heigth, int win_width, int win_y, int win_x) {
  wresize(win, win_heigth , win_width);
  mvwin(win, win_y, win_x);
}

void
ChatWindow::processInput(int key) {
  switch(key) {
    case KEY_ENTER:
    case '\n':
      // Requesting validation synchs the seen field & the buffer.
      form_driver(entryForm, REQ_VALIDATION);
      onTextEntry(getFieldString());
      move(1, 1);
      set_field_buffer(entryField, 0, "");
      refresh();
      pos_form_cursor(entryForm);
      break;
    case KEY_BACKSPACE:
    case 127:
      form_driver(entryForm, REQ_DEL_PREV);
      break;
    case KEY_DC:
      form_driver(entryForm, REQ_DEL_CHAR);
      break;
    case ERR:
      // swallow
      break;
    default:
      form_driver(entryForm, key);
      break;
  }
}


size_t
ChatWindow::getFieldSize() const {
  size_t x, y;
  getyx(entrySub, y, x);
  return y * parentX + x;
}


std::string
ChatWindow::getFieldString() const {
  return std::string{field_buffer(entryField, 0), getFieldSize()};
}
