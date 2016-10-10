/////////////////////////////////////////////////////////////////////////////
//                         Single Threaded Networking
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////


#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <functional>

#include <form.h>
#include <ncurses.h>


class ChatWindow {
public:
  explicit ChatWindow(std::function<void(std::string)> onTextEntry)
    : ChatWindow{onTextEntry, 1}
      { }

  ChatWindow(std::function<void(std::string)> onTextEntry, int updateDelay);

  ~ChatWindow();

  ChatWindow(const ChatWindow& cw)      = delete;
  ChatWindow& operator=(ChatWindow& cw) = delete;

  void update();

  void displayText(const std::string& text);

private:
  void resizeOnShapeChange();

  void processInput(int key);

  void createALL();

  void DUMMYADD();

  void resizeHelper(WINDOW *win, int win_heigth, int win_width, int win_y, int win_x);

  void setWindowColor(WINDOW *win, int color);

  size_t getFieldSize() const;

  std::string getFieldString() const;

  std::function<void(std::string)> onTextEntry;

  int parentX   = 0;
  int parentY   = 0;
  int entrySize = 3;

  WINDOW *view     = nullptr;
  WINDOW *entry    = nullptr;
  WINDOW *entrySub = nullptr;
  WINDOW *Stats    = nullptr;
  WINDOW *desc     = nullptr;
  WINDOW *Chatbox  = nullptr;

  FIELD *fields[2]  = { nullptr, nullptr };
  FIELD *entryField = nullptr;

  FORM *entryForm = nullptr;
};


#endif
