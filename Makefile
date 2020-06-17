Login.wt: Login.o WtEnvironment.o LoginMain.o
	g++ Login.o WtEnvironment.o LoginMain.o -o Login.wt -lwthttp -lwt

Login.o: Login.cpp
	g++ -std=c++14 -c Login.cpp -lwthttp -lwt

WtEnvironment.o: WtEnvironment.cpp
	g++ -std=c++14 -c WtEnvironment.cpp -lwthttp -lwt

LoginMain.o: LoginMain.cpp
	g++ -std=c++14 -c LoginMain.cpp -lwthttp -lwt

clean:
	rm *.o Login.wt
