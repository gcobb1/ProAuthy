/*****
Author: Gavin Cobb
Title: User Authentification system
Alternate Title: ProAuthy
Version 1.0
Date: 01 March 2020
Description: A User Authentification System Application that can be used to authenticate users by Username and Password. Passwords may be recovered and reset based on authentification questions. Users data is retrieved efficiently using different algorithms based on the size of Database. This Backend, with adjustments, is used to service authentification on my other projects. Test out a few options and create an account while on any device!
*****/


#include <Wt/WApplication.h>
#include "Login.h"
#include "WtEnvironment.h"


int main(int argc, char **argv){

//creates instance of wt server
	return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
		return std::make_unique<loginApplication>(env);
	});
}


