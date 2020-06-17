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
#include "WtEnvironment.h"

/*
bool loginApplication::CheckLogin(std::string RegName, std::string RegPass){



	for(int i = 0; i < this->UsersVec.size(); i++){
//make this a map traversal
		if(this->UsersVec[i].getName() == RegName){
			if(this->UsersVec[i].getPassword() == RegPass){
				return true;
			}
		}
	}
	return false;




}
*/
bool loginApplication::CheckLoginMap(std::string RegName, std::string RegPass){

	auto it = this->UserMap.find(RegName);
	if(it != this->UserMap.end()){
		if((it->second->getName() == RegName)){
			if((it->second->getPassword() == RegPass)){
				return true;
			}
		}
	}
	return false;
/*
	for(int i = 0; i < this->UsersVec.size(); i++){
//make this a map traversal
		if(this->UsersVec[i].getName() == RegName){
			if(this->UsersVec[i].getPassword() == RegPass){
				return true;
			}
		}
	}
	return false;


*/

}

int loginApplication::CheckRegisterMap(std::string RegName, std::string RegPass){
//flag = 1 good
//flag = 0 start
//flag = 2 bad name
//flag = 3 bad password// make this a map traversal
	if(this->UserMap.find(RegName) != this->UserMap.end()){
		return 2;
	}
	


	for(int i = 0; i < this->PasswordsVector.size(); i++){
		if(this->PasswordsVector[i] == RegPass){
			return 3;
		}
//		if(this->UsersVec[i].getPassword() == RegPass){
//			return 3;
//		}
	}
	return 1;


}
/*
int loginApplication::CheckRegister(std::string RegName, std::string RegPass){
//flag = 1 good
//flag = 0 start
//flag = 2 bad name
//flag = 3 bad password// make this a map traversal
	for(int i = 0; i < this->UsersVec.size(); i++){
		if(this->UsersVec[i].getName() == RegName){
			return 2;
		}
		if(this->UsersVec[i].getPassword() == RegPass){
			return 3;
		}
	}
	return 1;


}
*/

void loginApplication::UserInputterMap(){

	std::vector<std::string> variables;
	std::string indiv;
	std::string line;
	this->infile.open("Users1info.txt");
	while(std::getline(this->infile, line)){
		this->Userlines.push_back(line);
	}
	for(int j = 0; j < this->Userlines.size(); j++){
		std::stringstream ss(this->Userlines[j]);
		while(getline(ss, indiv, ' ')){
			variables.push_back(indiv);
		}
		ss.clear();
		User *aUser = new User(variables[0], variables[1]);
		//this->UsersVec.push_back(*aUser);
		//add user to map with username as the key and USER as the value
		this->PasswordsVector.push_back(variables[1]);
		this->UserMap.insert(std::pair <std::string, User*> (variables[0], aUser));	
		variables.clear();
	}		


}
/*
void loginApplication::UserInputter(){

	std::vector<std::string> variables;
	std::string indiv;
	std::string line;
	this->infile.open("Users1info.txt");
	while(std::getline(this->infile, line)){
		this->Userlines.push_back(line);
	}
	for(int j = 0; j < this->Userlines.size(); j++){
		std::stringstream ss(this->Userlines[j]);
		while(getline(ss, indiv, ' ')){
			variables.push_back(indiv);
		}
		ss.clear();
		User *aUser = new User(variables[0], variables[1]);
		this->UsersVec.push_back(*aUser);
		//add user to map with username as the key and USER as the value
		variables.clear();
	}		


}
*/	

loginApplication::loginApplication(const Wt::WEnvironment& env) 
					: Wt::WApplication(env){
	
//std::string Wt::WString::toUTF8	(		)	const

	Wt::WApplication::useStyleSheet("style1.css");
	Wt::WApplication::setBodyClass("body");
	setTitle("Login/Registration");
	Wt::WContainerWidget *w2 = root()->addWidget(std::make_unique<Wt::WContainerWidget>());
	w2->setWidth(Wt::WLength("100%"));
	//w2->resize(150, 150);
	w2->setStyleClass("container1");
	
	Wt::WContainerWidget *w3 = root()->addWidget(std::make_unique<Wt::WContainerWidget>());
	w3->setWidth(Wt::WLength("100%"));
	//w2->resize(150, 150);
	w3->setStyleClass("container2");
	
	Wt::WContainerWidget *w4 = root()->addWidget(std::make_unique<Wt::WContainerWidget>());
	w4->setWidth(Wt::WLength("100%"));
	//w2->resize(150, 150);
	w4->setStyleClass("container3");

	Wt::WContainerWidget *w5 = root()->addWidget(std::make_unique<Wt::WContainerWidget>());
	w5->setWidth(Wt::WLength("100%"));
	//w2->resize(150, 150);
	w5->setStyleClass("container4");
	auto vbox = w2->setLayout(Wt::cpp14::make_unique<Wt::WVBoxLayout>());

	auto itemer = Wt::cpp14::make_unique<Wt::WText>("ProAuthy");
	itemer->setStyleClass("box-1");
	vbox->addWidget(std::move(itemer));
  
	auto itemer2 = Wt::cpp14::make_unique<Wt::WText>("Log in to the Project User System");
	itemer2->setStyleClass("box-main");
	vbox->addWidget(std::move(itemer2));	
	

	auto itemer3 = Wt::cpp14::make_unique<Wt::WText>("Gavin Cobb\n2020");
	itemer3->setStyleClass("box-3");
	vbox->addWidget(std::move(itemer3));	

	//auto result = Wt::cpp14::make_unique<Wt::WTemplate>(Wt::WString::tr("simpleForm-template"));
	//auto nameer = w2->addWidget("nameer", Wt::cpp14::make_unique<Wt::WLineEdit>());
	//nameer->setPlaceholderText("first name");
	//auto buttoner = result->bindWidget("buttoner", Wt::cpp14::make_unique<Wt::WPushButton>("OK"));
	//nameEdit = w2->addWidget(std::make_unique<Wt::WLineEdit>());
	//auto out = result->bindWidget("out", Wt::cpp14::make_unique<Wt::WText>());
	//buttoner->clicked().connect([=] {
	//out->setText("Hello, " + nameer->text() + "! I just want to help you... You"
         //        + " could complete this simple form by adding validation.");
	//});
	this->UserInputterMap();
	this->nameEdit = w3->addWidget(Wt::cpp14::make_unique<Wt::WLineEdit>("Username"));
	this->nameEdit->setFocus();
	auto loginbutton = w4->addWidget(Wt::cpp14::make_unique<Wt::WPushButton>("Log In"));

	auto registerbutton = w4->addWidget(Wt::cpp14::make_unique<Wt::WPushButton>("Register"));
	//button->setMargin(5, Wt::Side::Left);
	
	this->nameEdit->setStyleClass("Susername");
//	w3->addWidget(std::make_unique<Wt::WBreak>());
	this->passEdit = w3->addWidget(Wt::cpp14::make_unique<Wt::WLineEdit>("Password"));
	this->passEdit->setFocus();
	this->passEdit->setStyleClass("Spassword");

	loginbutton->setStyleClass("button");
	
	registerbutton->setStyleClass("registerbutton");
	Logged = root()->addWidget(std::make_unique<Wt::WText>(""));
	Logged->hide();
	Logged->setStyleClass("LoggedUser");
	
	SuccessA = w4->addWidget(std::make_unique<Wt::WText>(""));
	SuccessA->hide();
		
	SuccessA->setStyleClass("registeredUser");
	
	auto LoginSignal = [=]{
		Logged->hide();
		this->Wuser = this->nameEdit->displayText();
		this->Wpass = this->passEdit->displayText();

		this->usernamein = this->Wuser.toUTF8();
		this->passwordin = this->Wpass.toUTF8();
		this->successFlag = this->CheckLoginMap(this->usernamein, this->passwordin);
		if(this->successFlag == true){
			this->SuccessfulLog = true;
			//figure out whether to make a copy of the user object by index and creating a copy without pushing it back. 
//or if it can be done using pointers
//change from vectors to something that indexes by value
//check when they created their account and depending on how new you should for loop through the vectors from a deifferent angle
			this->SuccessA->show();
			this->success = this->Lsuccess + usernamein;
			this->SuccessA->setText(this->success);
			Logged->show();
			this->loggedText = "Online: " + usernamein;
			this->Logged->setText(loggedText);
		}
		else{
			
			SuccessA->show();
			this->success = this->LFail;
			this->SuccessA->setText(this->success);
		}
		

	};
	loginbutton->clicked().connect(std::bind(LoginSignal));
	
	auto RegisterSignal = [=]{
		Logged->hide();
		this->Wuser = this->nameEdit->displayText();
		this->Wpass = this->passEdit->displayText();

		this->usernamein = this->Wuser.toUTF8();
		this->passwordin = this->Wpass.toUTF8();
		this->registerFlag = this->CheckRegisterMap(this->usernamein, this->passwordin);
		if(this->registerFlag == 1){
	//check for username and check for password function	
    			User *newUser = new User(this->Wuser.toUTF8(), this->Wpass.toUTF8());
			this->PasswordsVector.push_back(this->passwordin);
			this->UserMap.insert(std::pair <std::string, User*> (this->usernamein, newUser));
			//this->UsersVec.push_back(*newUser);	
			this->fullstring = newUser->getName();
			this->fullstring = this->fullstring + " " + newUser->getPassword();
			this->myfile.open("users1info.txt", std::ios::app);
			this->myfile << fullstring << "\n";
			this->myfile.close();
		//create function that checks if username and password are unused, if so successflag is true
			//if(this->successFlag == true){
			SuccessA->show();
			this->success = this->Rsuccess + newUser->getName();
			this->SuccessA->setText(this->success);
		}
		else if(this->registerFlag == 2){
			
			SuccessA->show();
			this->SuccessA->setText(this->UFail);
		}
		else if(this->registerFlag == 3){
			SuccessA->show();
			this->SuccessA->setText(this->PFail);
		}
		else{
			SuccessA->show();
			this->SuccessA->setText("An Error Has Occured");
		}
		this->registerFlag = 0;
		
			//}
	};
	registerbutton->clicked().connect(std::bind(RegisterSignal));
/*
	auto LoginSignal = [=]{
		Logged->hide();
		this->Wuser = this->nameEdit->displayText();
		this->Wpass = this->passEdit->displayText();

		this->usernamein = this->Wuser.toUTF8();
		this->passwordin = this->Wpass.toUTF8();
		this->successFlag = this->CheckLogin(this->usernamein, this->passwordin);
		if(this->successFlag == true){
			this->SuccessfulLog = true;
			//figure out whether to make a copy of the user object by index and creating a copy without pushing it back. 
//or if it can be done using pointers
//change from vectors to something that indexes by value
//check when they created their account and depending on how new you should for loop through the vectors from a deifferent angle
			this->SuccessA->show();
			this->success = this->Lsuccess + usernamein;
			this->SuccessA->setText(this->success);
			Logged->show();
			this->loggedText = "Online: " + usernamein;
			this->Logged->setText(loggedText);
		}
		else{
			
			SuccessA->show();
			this->success = this->LFail;
			this->SuccessA->setText(this->success);
		}
		

	};
	loginbutton->clicked().connect(std::bind(LoginSignal));
	
	auto RegisterSignal = [=]{
		Logged->hide();
		this->Wuser = this->nameEdit->displayText();
		this->Wpass = this->passEdit->displayText();

		this->usernamein = this->Wuser.toUTF8();
		this->passwordin = this->Wpass.toUTF8();
		this->registerFlag = this->CheckRegister(this->usernamein, this->passwordin);
		if(this->registerFlag == 1){
	//check for username and check for password function	
    			User *newUser = new User(this->Wuser.toUTF8(), this->Wpass.toUTF8());
			this->UsersVec.push_back(*newUser);	
			this->fullstring = newUser->getName();
			this->fullstring = this->fullstring + " " + newUser->getPassword();
			this->myfile.open("users1info.txt", std::ios::app);
			this->myfile << fullstring << "\n";
			this->myfile.close();
		//create function that checks if username and password are unused, if so successflag is true
			//if(this->successFlag == true){
			SuccessA->show();
			this->success = this->Rsuccess + newUser->getName();
			this->SuccessA->setText(this->success);
		}
		else if(this->registerFlag == 2){
			
			SuccessA->show();
			this->SuccessA->setText(this->UFail);
		}
		else if(this->registerFlag == 3){
			SuccessA->show();
			this->SuccessA->setText(this->PFail);
		}
		else{
			SuccessA->show();
			this->SuccessA->setText("An Error Has Occured");
		}
		this->registerFlag = 0;
		
			//}
	};
	registerbutton->clicked().connect(std::bind(RegisterSignal));
	
*/	
	//take info from username and password and store them in strings

	//create function that registers

	//w2->addWidget(std::make_unique<Wt::WBreak>());
	//passEdit = w2->addWidget(std::make_unique<Wt::WLineEdit>());	

	//passEdit->setStyleClass("Spass");
	/*
	//std::ofstream myfile;
	//std::ifstream infile;
	//infile.open("Users.txt");
	std::string line;
	//std::vector<User> UsersVec;
        bool flag = true;
	std::string usernamer;
	std::string passworder;
	int answer;
	infile.open("Users1info.txt");
	//count = 0;
	std::string indiv;
	while(std::getline(infile, line)){
		Userlines.push_back(line);
	}
	
	for(int j = 0; j < Userlines.size(); j++){
		std::stringstream ss(Userlines[j]);
		while(getline(ss, indiv, ' ')){
			variables.push_back(indiv);
		}
		ss.clear();
		User *aUser = new User(variables[0], variables[1]);
		UsersVec.push_back(*aUser);
		variables.clear();
	}		
	//	if(count == 0){
	//		aUser.setName(line);
	//		count++;
	//	}
	//	if(count == 1){
	//	aUser.setPass(line);
	//	count = 0; 
	//	}
	
        while(flag == true){
    		std::cout << "do you want to add a user? 1 or 0\n";
		std::cin >> answer;
  		if(answer == 0){
			flag = false;
			break;
		}
		std::cout << "What is your username?\n";
		std::cin >> usernamer;
		std::cout << "What is your password\n";
		std::cin >> passworder;
		
		myfile.open("users1info.txt", std::ios::app);
		myfile << usernamer << " " << passworder << "\n";
		myfile.close();
    		User *newUser = new User(usernamer, passworder);
		UsersVec.push_back(*newUser);
	}
	std::cout << "\nThe Users in the login system and their passwords so far\n";
		//while (std::getline(infile, line, ' ')) {
			infile.open("Users1info.txt");
			for(int i = 0; i < UsersVec.size(); i++){
				std::cout << "Username: " << UsersVec[i].getName() << "\n";
				std::cout <<	"Password: " << UsersVec[i].getPassword() << "\n";
			}
	infile.close();
}

*/
}


