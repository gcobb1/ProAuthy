#ifndef Wt_Environment_H
#define Wt_Environment_H

/*****
Author: Gavin Cobb
Date: March 2020

The purpose of this file is to the hold the class member declarations for the Login Application that determine theeligibility of a sign in or register by connecting to the backend 
*****/

#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WLineEdit.h>
#include <Wt/WBreak.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WString.h>
#include <Wt/WTemplate.h>
#include <map>
#include "Login.h"

class User;

class loginApplication : public Wt::WApplication {
public:
	
	loginApplication(const Wt::WEnvironment& env);
	void UserInputterMap();	
	int CheckRegisterMap(std::string RegName, std::string RegPass);
	bool CheckLoginMap(std::string RegName, std::string RegPass);


protected:
	bool successFlag = false;
	std::string Rsuccess = "You Have Successfully Registered For An Account: ";
	std::string Lsuccess = "You Have Successfully Logged In To Your Account: ";
	std::string PFail = "This Password Is Unavailable, Please Try Again";
	std::string UFail = "This Username Is Unavailable, Please Try Again";
	std::string LFail = "Login Information Is Incorrect, Please Try Again";
	std::string loggedText;
	std::string success = "";
	Wt::WLineEdit *nameEdit;
	Wt::WLineEdit *passEdit;
	std::vector<std::string> PasswordsVector;
	std::vector<User> UsersVec;
	std::map<std::string, User*> UserMap;
	std::vector<std::string> Userlines;
	std::vector<std::string> variables;
	Wt::WString Wuser;
	Wt::WString Wpass;
	Wt::WText *Logged;
	Wt::WText *SuccessA;
	Wt::WColor *Color;
	std::string usernamein;
	std::string passwordin;
	std::ofstream myfile;
	std::ifstream infile;
	std::string fullstring = "";
	int registerFlag = 0;
	bool SuccessfulLog = false;
//Wt::WLineEdit::selectedText	(		)	const


//std::string Wt::WString::toUTF8() const

};
#endif
