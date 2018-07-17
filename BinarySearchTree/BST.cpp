#include "BST.h"

void BST::create_tree(Node* prev_root, int tree_counter) {
	// This will create a blank tree of level 4
	if (tree_counter == 4) {
		return;
	}
	// This are used to build the tree down, they are dummy nodes that will be filled later
	Node* temp_left = new Node(prev_root);
	Node* temp_right = new Node(prev_root);
	// This connects the tree
	prev_root->set_leafs(temp_left, temp_right);
	tree_counter++;
	// We recursively made the tree of it will end once the tree is at a depth of 4
	create_tree(temp_left, tree_counter);
	create_tree(temp_right, tree_counter);
}

void BST::insert(char the_letter, string the_position)
{
	// We start at the root
	Node* update_node = ROOT;
	// This will move down the tree to the right position
	for (int i = 0; i < the_position.length(); i++)
	{
		// here we check if we are going left or right
		if (the_position[i] == move_left) { 
			update_node = update_node->get_left();
		}
		else if (the_position[i] == move_right) {
			update_node = update_node->get_right();
		}
	}
	// set the values
	update_node->set_letter(the_letter);
	update_node->set_code(the_position);
}


string BST::decode(string message)
{
	string decodedMsg;

	int i = 0;
	// This loop will decode the message
	while (i < message.length()) {
		Node* update_node = ROOT; // used to find the letter

		// This will go through the tree
		for (i; i < message.length(); i++)
		{
			// Check if we are going left, right, or if its the end of the code
			if (message[i] == move_left) {
				update_node = update_node->get_left();
			}
			else if (message[i] == move_right) {
				update_node = update_node->get_right();
			}
			//if a space is detected in the morse code, will break instead of searching for it in the node
			else if (message[i] == ' ') {
				i++;
				break;
			}
		}
		// If there is a code that does not have a value then till be a space instead
		if(update_node->get_letter() != NULL)
		decodedMsg += update_node->get_letter(); //adds the letter that was found at the node to a existing string which keeps track of the word
		else {
			decodedMsg += " ";
		}

	}
	return decodedMsg;
}

