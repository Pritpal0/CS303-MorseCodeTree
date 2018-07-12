#include "mapEncode.h"

void mapEncode::mapBuilder(char mapKey, string code)
{
	encodedMap[mapKey] = code; //encodes each morse code to a letter
}

string mapEncode::toEncode(string word)
{
	//for loop to take the word input and covert each letter to a morse code
	for (int i = 0; i < word.length(); i++) {
		word[i] = tolower(word[i]); //lowers every letter because There is no upper/lower case differentiation in Morse code; just the alphabet.
		encodedMsg += encodedMap[word[i]];
		encodedMsg += " "; //adds a space
	}
	return encodedMsg; //returns the encoded messages
}