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
		if (the_position[i] == '.') {
			update_node = update_node->get_left();
		}
		else if (the_position[i] == '_') {
			update_node = update_node->get_right();
		}
	}
	update_node->set_letter(the_letter);
	update_node->set_code(the_position);
}

char BST::decode(string message)
{
	Node* find = ROOT;
	Node* update_node = ROOT;
	for (int i = 0; i < message.length(); i++)
	{
		if (message[i] == '.') {
			update_node = update_node->get_left();
		}
		else if (message[i] == '_') {
			update_node = update_node->get_right();
		}
	}
	return update_node->get_letter();
}

