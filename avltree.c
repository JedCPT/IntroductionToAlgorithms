
#include "stdlib.h"
#include "bin.h"
#include "time.h"


typedef struct Node Node;
typedef struct Tree Tree;


struct Node {
	Node * left, * right, * parent;
	size_t height;
	int balance;
	int value;
};

struct Tree{
	Node * root;
};


#include "treeprint.h"

#define LEFT_HEIGHT(node) (node->left != NULL ? node->left->height: -1)
#define RIGHT_HEIGHT(node) (node->right != NULL ? node->right->height: -1)


Node * new_Node(int value) {
	Node * new  = malloc(sizeof(Node));
	new->value  = value;
	new->left   = NULL;
	new->right  = NULL;
	new->parent = NULL;
	new->height = -1;
	return new;
}

Tree * new_Tree (void)  {
	Tree * new = malloc(sizeof(Tree));
	new->root = NULL;
	return new;
}

void update(Node * node) {
	node->height = max(LEFT_HEIGHT(node), RIGHT_HEIGHT(node)) + 1;
	node->balance = RIGHT_HEIGHT(node) - LEFT_HEIGHT(node);
}


/*                z                           z
 *          +---+---+                     +---+---+
 *          y                             x
 *      +---+---+         --->        +---+---+
 *		x                                     y
 *
 * Leaving the remaing sub trees in the logical places.
 */
void right_rotate(Node * node_x) {
	
	Node * node_y = node_x->parent;
	Node * node_z = node_y->parent;

	node_y->parent = node_x;
	node_y->left = node_x->right;

	node_x->right = node_y;
	node_x->parent = node_z;


	if (node_z != NULL) {
		if (node_y == node_z->left) {
			node_z->left = node_x;
		}
		else {
			node_z->right = node_x;
		}
	// Update the stats of each node that was altered in the rotation.
		update(node_z);
	}
	update(node_x);
	update(node_y);
}


/*          z                                 z
 *      +---+---+                         +---+---+
 *              y                                 x
 *          +---+---+         --->            +---+---+
 *                  x                         y
 *
 * Leaving the remaing sub trees in the logical places.
 */                       
void left_rotate(Node * node_x) {
	Node * node_y = node_x->parent;
	Node * node_z = node_y->parent;

	node_y->parent = node_x;
	node_y->right = node_x->left;

	node_x->left = node_y;
	node_x->parent = node_z;

	if (node_z != NULL) {
		if (node_y == node_z->left) {
			node_z->left = node_x;
		}
		else  {
			node_z->right = node_x;
		}

	//Update the stats of each node that was altered in the rotaion.
		update(node_z);
	}


	update(node_x);
	update(node_y);
}

// Recursively move up the tree from node.
// Returns the new root if the root is changed
// in a rotation.
Node *  balance_tree(Node * node) {
	update(node);

	if (node->balance == 2) {
		if (node->right->balance < 0) {
			right_rotate(node->right->left);
		}
	    left_rotate(node->right);
	}

	if (node->balance == -2) {	
		if (node->left->balance > 0) {
			left_rotate(node->left->right);
		}
		right_rotate(node->left);
	}	


	if (node->parent != NULL) {
		return balance_tree(node->parent);
	}
	return node;
		
}


// Standard binary tree insert funtion.
Node * _insert (Node * node, Node * new) {
	Node ** address = (new->value < node->value) ? &node->left: &node->right;
	if (*address == NULL) {
		*address = new;
		(*address)->parent = node;
		return *address;
	}
	else {
		return _insert(*address, new);
	}
}

// AVL tree insert. It uses the normal binary insert function
// and then balances the tree recursively from the new node up.
Tree * insert (Tree * tree, Node * new) {
	// The case that the node is first
	if (tree->root == NULL) {
		tree->root = new;
	}
	else  {
		_insert(tree->root, new);
				
	}
	// Balance the tree which returns the new root
	tree->root = balance_tree(new);
	return tree;
}



Node * search(Node * root, int num) {
	if (root->value == num) {
		return root;
	}
	if (root->left != NULL && num < root->value)  {
		return search(root->left, num);
	}
	if (root->right != NULL) {
		return search(root->right, num);
	}
	return NULL;
}




void inOrder(Node * root) {
	if (root->left != NULL) {
		inOrder(root->left);
	}
	printf("%d,", root->value);
	if (root->right != NULL) {
		inOrder(root->right);
	}
}


int main(void) {
	Tree * tree = new_Tree();

	size_t length = 15;
	int * array = malloc(sizeof(int) * length);

	srand(time(NULL));
	genRandomArray(array, length, 1000);

	for (size_t i = 0; i < length; i++) {
		insert(tree, new_Node(array[i]));
	}
	print_t(tree->root);
	inOrder(tree->root);



	return 0;
}
