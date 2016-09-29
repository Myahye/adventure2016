#include <iostream>
#include <fstream>
#include <string>

#include "yaml-cpp/yaml.h"

using namespace std;

string commandInput;

void mainMenuList(Player &player){
	cout << "=============================" << endl;
	cout << "========= Main Menu =========" << endl;
	cout << "=============================" << endl;
	cout << "0. Type command" << endl;
	cout << "1. List commands" << endl;
	cout << "2. Player Information" << endl;
	cout << "3. Move" << endl;
	cout << "4. Inventory" << endl;
	cout << "5. End Game" << endl << endl;

	cin >> commandInput;
	switch (commandInput){
		case "0":
			//inputCommand();
			break;
		case "1":
			//listCommands();
			break;
		case "2":
			//player.showInfo();
			break;
		case "3":
			//move();
			break;
		case "4":
			//player.showInventory();
			break;
		case "5":
			//endGame();
			break;
		default:
			cout << "Invalid input!!" << endl << endl;
	}
}

void insideRoomMenuList(Player &player){
	cout << "=============================" << endl;
	cout << "========= Room Menu =========" << endl;
	cout << "=============================" << endl;
	cout << "0. Type command" << endl;
	cout << "1. List commands" << endl;
	cout << "2. Player Information" << endl;
	cout << "3. List doors in the room" << endl;
	cout << "4. List players in the room" << endl;
	cout << "5. List objects in the room" << endl;
	cout << "6. Open a door" << endl;
	cout << "7. Fight a player" << endl;
	cout << "8. Pick up an object" << endl;
	cout << "9. End Game" << endl << endl;

	cin >> commandInput;
	switch (commandInput){
		case "0":
			//inputCommand();
			break;
		case "1":
			//listCommands();
			break;
		case "2":
			//player.showInfo();
			break;
		case "3":
			//listDoors(player.getLocation());
			break;
		case "4":
			//listPlayers(player.getLocation());
			break;
		case "5":
			//listObjects(player.getLocation());
			break;
		case "6":
			string doorDirection;
			cout << "Enter the direction of the door : ";
			cin >> doorDirection;
			//player.openDoor(doorDirection);
			break;
		case "7":
			int opponentID;
			cout << "Enter opponent's ID: ";
			cin >> opponentID;
			//player.fightPlayer(opponentID);
			break;
		case "8":
			string objName;
			cout << "Enter object name: ";
			cin >> objName;
			//player.pickUpObject(objName);
			break;
		case "9":
			//endGame();
			break;
		default:
			cout << "Invalid input!!" << endl << endl;
	}
}


int main()
{
	Player player(); //*****fill the bracket
	while (true){
		size_t pos;
		string location = player.getLocation();
		pos = location.find("room");
		if (pos != string::npos) // if the location name includes the word "room"
			insideRoomMenuList();
		else //if the player is not in a room, then he should face the main menu
			mainMenuList();
	}
}
