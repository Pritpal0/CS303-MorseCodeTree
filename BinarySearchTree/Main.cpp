#include "BST.h"
#include "mapEncode.h"

int main() {
	//Change variables here
	char left = '_';
	char right = '.';

	BST MorseCodeTree(left, right);
	mapEncode MorseCodeMap;

	string line;
	char letter;

	

	//Change this text to the desired text to encode. spaces do not work at the moment
	string text = "Hello";

	ifstream file_input("morse.txt");

	while (file_input.good()) //read the file untill the end of the file
	{
		getline(file_input, line); //read the whole line into 1 string
		letter = line[0]; //take the first index, 0 and assign that to the letter
		line = line.substr(1,line.length()); //removes the letter from the string and only keeps the morse code
		MorseCodeTree.insert(letter, line); //inserts the letter and the code into the desired node
		MorseCodeMap.mapBuilder(letter, line); //builds the map for the morse code to later decode
	}

	cout << "Note: There is no upper/lower case differentiation in Morse code; just the alphabet." << endl;
	cout << endl;

	string encodedtxt = MorseCodeMap.toEncode(text); //returns the text in morse code
	cout << "Message " << '"' << text << '"'<< " Encoded is: " << '"' << encodedtxt << '"' << endl;
	cout << endl;

	//decodes the morse code text into words
	cout << "Message " << '"' << encodedtxt << '"' << " Decodes to: " << '"' << MorseCodeTree.decode(encodedtxt) << '"' << endl;
	cout << endl;

	system("pause");
}