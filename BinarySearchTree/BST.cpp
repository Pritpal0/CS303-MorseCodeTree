#include "BST.h"

void BST::create_tree(Node* prev_root, int tree_counter) {
	if (tree_counter == 4) {
		return;
	}
	Node* temp_left = new Node(prev_root);
	Node* temp_right = new Node(prev_root);
	prev_root->set_leafs(temp_left, temp_right);
	tree_counter++;
	create_tree(temp_left, tree_counter);
	create_tree(temp_right, tree_counter);
}

void BST::insert(char the_letter, string the_position)
{
	Node* update_node = ROOT;
	for (int i = 0; i < the_position.length(); i++)
	{
		if (the_position[i] == move_left) {
			update_node = update_node->get_left();
		}
		else if (the_position[i] == move_right) {
			update_node = update_node->get_right();
		}
	}
	update_node->set_letter(the_letter);
	update_node->set_code(the_position);
}


string BST::decode(string message)
{
	string decodedMsg;

	int i = 0;
	while (i < message.length()) {
		Node* find = ROOT;
		Node* update_node = ROOT;

		for (i; i < message.length(); i++)
		{

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
			else {
			}
		}
		if(update_node->get_letter() != NULL)
		decodedMsg += update_node->get_letter(); //adds the letter that was found at the node to a existing string which keeps track of the word
		else {
			decodedMsg += " ";
		}

	}
	return decodedMsg;
}

