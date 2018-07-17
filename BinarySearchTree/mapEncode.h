#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class mapEncode {

private:
	// Map Class variables
	map<char, string> encodedMap;
	string encodedMsg;
public:
	//Builds the tree
	void mapBuilder(char mapKey, string code); //to build the map
	// Returns encoded
	string toEncode(string word); //to encode text

};