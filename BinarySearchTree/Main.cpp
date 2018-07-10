#include "BST.h"
string encode(string secret, map <char, string> this_is_cheating) {
	string encoded;
	for (int i = 0; i < secret.length(); i++) {
		encoded += this_is_cheating[secret[i]];
		encoded += " ";
	}
	return encoded;
}

int main() {
	map<char, string> ugh;
	BST World_Tree;
	string line;
	string code;
	char letter;
	ifstream file_input("morse.txt");

	while (file_input.good())
	{
		getline(file_input, line);
		letter = line[0];
		code = line.substr(1,line.length());
		ugh[letter] = code;
		World_Tree.insert(letter, code);
	}
	system("pause");
}