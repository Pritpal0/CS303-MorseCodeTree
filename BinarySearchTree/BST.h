#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

struct Node {
private:
	char letter; // This will hold the letter vaule
	string code; // This will hold the position of the Node
	Node* left_side; // This is the left side of the tree
	Node* right_side; // This is the right side of the tree
	Node* root; // This will be the root that leads to this Node

public:
	// This is the defualt constructor
	Node() {
		left_side = NULL;
		right_side = NULL;
		root = NULL;
	};
	Node(Node* previous) {
		left_side = NULL;
		right_side = NULL;
		root = previous;
	};
	char get_letter() { return letter; };
	string get_code() { return code; };
	Node* get_left() { return left_side; };
	Node* get_right() { return right_side; };
	void set_letter(char update_letter) {
		letter = update_letter;
	};
	void set_code(string update_code) {
		code = update_code;
	};
	void set_leafs(Node* left_leaf, Node* right_leaf) {
		left_side = left_leaf;
		right_side = right_leaf;
	};
};

class BST
{
private:
	Node* ROOT = new Node();
	int tree_counter = 0;

public:
	BST() {
		create_tree(ROOT, tree_counter);
	};
	void create_tree(Node* prev_root, int tree_counter); // Make a blank tree
	void insert(char the_letter, string the_position);
	char decode(string message);

	//Add more later
};