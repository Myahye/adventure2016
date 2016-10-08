#include <iostream>
#include <fstream>

#include <string>
using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::ios;
//ifstream is for input- used to read file
//ofstream is output - used to create or write to file
//getline gets anything till delimiter or \n is found
/*-----------------
Returns true: 
	-if User/Password combo contained in file
Returns false:
	-if User/Password combo not in file
------------------*/
bool
CheckForUserandPass(string userAndPass){
	ifstream myfile;
	myfile.open ("Signon.txt");
	bool ret = false;
	string users;

	if(!myfile.is_open()){
		//file not opened - probably can get rid of since opening it within func
		return ret;
	}
	while(getline(myfile, users) && ret == false){
		if(users.compare(userAndPass) == 0){
		  ret = true;
		}
	}
	myfile.close();
	return ret;
}

bool
CheckforUser(string username){
	ifstream myfile;
	string users;
	bool ret = false;
	
	myfile.open ("Signon.txt");

	if(!myfile.is_open()){
		//file not opened - probably can get rid of since opening it within func
		return ret;
	}

	while(getline(myfile, users, ' ') && ret == false){ //getline till " ", ie get username/password individually 
		if(users.compare(username) == 0){
		  ret = true;
		}
	}
	myfile.close();
	return ret;
}
/*-----------------
Returns true: 
	-User has been successfully added to file
Returns false:
	-Username has already been taken
------------------*/
//Also add in check for valid username/password
bool
AddUser(string username, string password){
	ofstream myfile;
	string users;
	bool checkUsername;
	myfile.open ("Signon.txt", ios::app);//ios::app means we will append to this file
	bool ret = false;
	if(!myfile.is_open()){
		//file not opened - probably can get rid of since opening it within func
		return ret;
	}
	//checking if username in file
	checkUsername = CheckforUser(username);
	//only write if ret is true, ie if userName not taken
	if(!checkUsername){
		myfile << username << " " << password << "\n";
		ret = true; 
	}
	myfile.close();
	return ret;
}

int main(){
	//setting up sign on/ sign off
	string val, user, pass, CurrentUserName,CurrentPassword;
	bool flag = true;
	bool checkUser;
	//could probably use fstream for both reading and writing?
	cout << "Log in/ Sign up ( type y for Log in and n for Sign up ): \n";
	cin >> val;
	while(flag){
		
		if(val == "y"){
			//they want to log in -- must read from file
			cout << "Log In:\n";
			cout << "\tEnter username:\n";
			cin >> CurrentUserName;
			cout << "\tEnter password:\n";
			cin >> CurrentPassword;

			string userPass = CurrentUserName + " " + CurrentPassword;

			 //check if file has been opened; check if an error occurred if(myfile.is_open() == true?)
			if(CheckForUserandPass(userPass)){		  //ios::in means file opened for reading
				cout << "Login successful! Proceed..\n";
				flag = false;
			}else{
				cout << "Error: Incorrect username or Password\n";
				cout << "Would you like to log in or create an account? Type y/n:\n";
				cin >> val;
				//call signon function again
			} 
		}
		else if(val == "n"){
			//they want to sign up -- must write to file
			cout << "Create a new account:\n";
			cout << "\tEnter username:\n";
			cin >> user;
			cout << "\tEnter password:\n";
			cin >> pass;

			checkUser = AddUser(user,pass); 
			if(!checkUser){
				cout << "Error: Username has already been taken!\n";
			}
			else{
				flag = false;
			}
		}
		else{
			cout << "Wrong input!";
			cout << "Log in/ Sign up ( type y for Log in and n for Sign up ): \n";
			cin >> val;
		}
	}
	cout << "line 63\n";
}