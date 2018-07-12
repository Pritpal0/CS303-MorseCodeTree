#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class mapEncode {

private:
	map<char, string> encodedMap;
	string encodedMsg;
public:

	void mapBuilder(char mapKey, string code); //to build the map

	string toEncode(string word); //to encode text

};