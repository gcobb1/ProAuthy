#ifndef LOG_IN_H
#define LOG_IN_H

/*****
Author: Gavin Cobb
Date: March 2020

The Purpose of this file is to store the class and member functions declarations for the backend that creates manipulations for the front end to correlate to
*****/



#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <map>



class User{
public:
	User(){
		this->userName = "guest";
		this->passWord = "guest1";
	}
	User(std::string name1, std::string password1){
		this->userName = name1;
		this->passWord = password1;
	//	myfile.open("Users.txt");
	//	myfile << name1 << " " << password1 << "\n";
	//	myfile.close();
	}
	void setName(std::string namer){
		this->userName = namer;
	}
	void setPass(std::string passer){
		this->passWord = passer;
	}
	std::string getName(){
		return this->userName;
	}
	std::string getPassword(){
		return this->passWord;
	}
//	friend std::vector<User>
	~User(){
		delete this;
	}
private:
	//std::ofstream myfile;
	std::string userName;
	std::string passWord;
};
#endif
