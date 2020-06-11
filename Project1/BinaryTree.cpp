#include "BinaryTree.h"

BinaryTree::BinaryTree(TreeNode* root) :
	root(root)
{
}

BinaryTree::BinaryTree(int rootVal) :
	root(new TreeNode(rootVal))
{
}

BinaryTree::~BinaryTree()
{
}



void BinaryTree::insert(int val)
{
	// Edge case for empty tree
	if (root == nullptr)
	{
		root = new TreeNode(val);
		return;
	}

	TreeNode* parent = nullptr;

	// Get the node closest to val
	if (search(val, &parent))
	{
		// Create new node
		TreeNode* newNode = new TreeNode(val);

		// Set parent's correct pointer to the new node
		// Use left
		if (parent->val < val)
			parent->left = newNode;
		// Use right
		else
			parent->right = newNode;
	}
}

void BinaryTree::remove(int val)
{
	TreeNode* current = nullptr;
	TreeNode* parent = nullptr;


	// Search for the node to delete. If it doesnt exist, do nothing
	if (search(val, &current, &parent))
	{
		// If right exists
		if (current->right != nullptr)
		{
			TreeNode* min = nullptr;
			TreeNode* minParent = nullptr;
			// Get min node thats larger than current
			getMin(current->right, &min, &minParent);

			// Update current val
			current->val = min->val;

			// If min is dirrectly off of current
			if (min == current->right)
				current->right = min->right;
			// If min is somewhere left
			else
				minParent->left = min->right;
			// Min is 'moved' to current; delete it
			delete min;
		}
		// No right on current
		else
		{
			// If current is the root, change it
			if (current == root)
				root = current->left;
			// Update the parent's pointer
			else if (current == parent->left)
				parent->left = current->left;
			else
				parent->right = current->left;
			// Current is now unused; delete it
			delete current;
		}
	}
}


bool BinaryTree::search(int val, TreeNode** outNodePtr)
{
	// Edge case for empty tree
	if (root == nullptr)
		return false;

	TreeNode* current = root;

	// Loop ends when node is found or determined not to exist
	while (true)
	{
		// Use left
		if (current->val < val)
		{
			// Get the next node and repeat
			if (current->left != nullptr)
			{
				// Update current
				current = current->left;
				continue;
			}
			// Node of val doesnt exist
			else
			{
				// Update out to the nearest node
				*outNodePtr = current;
				return false;
			}
		}
		// Use right
		else if (current->val > val)
		{
			// Get the next node and repeat
			if (current->right != nullptr)
			{
				// Update current
				current = current->right;
				continue;
			}
			// Node of val doesnt exist
			else
			{
				// Update out to the nearest node
				*outNodePtr = current;
				return false;
			}
		}
		// Current == val
		else
		{
			*outNodePtr = current;
			return true;
		}
	}
}

bool BinaryTree::search(int val, TreeNode** outNodePtr, TreeNode** outParentPtr)
{
	// Edge case for empty tree
	if (root == nullptr)
		return false;

	TreeNode* current = root;
	TreeNode* parent = nullptr;

	// Loop ends when node is found or determined not to exist
	while (true)
	{
		// Use left
		if (current->val < val)
		{
			// Get the next node and repeat
			if (current->left != nullptr)
			{
				// Update current and parent
				parent = current;
				current = current->left;
				continue;
			}
			// Node of val doesnt exist
			else
			{
				// Update out to the nearest node
				*outNodePtr = current;
				*outParentPtr = parent;
				return false;
			}
		}
		// Use right
		else if (current->val > val)
		{
			// Get the next node and repeat
			if (current->right != nullptr)
			{
				// Update current and parent
				parent = current;
				current = current->right;
				continue;
			}
			// Node of val doesnt exist
			else
			{
				// Update out to the nearest node
				*outNodePtr = current;
				*outParentPtr = parent;
				return false;
			}
		}
		// Current == val
		else
		{
			*outNodePtr = current;
			*outParentPtr = parent;
			return true;
		}
	}
}


void BinaryTree::getMin(TreeNode* root, TreeNode** outNodePtr, TreeNode** outParentPtr)
{
	TreeNode* current = root;
	TreeNode* parent = nullptr;

	// Loop ends when node is found or determined not to exist
	while (true)
	{
		// If left exists
		if (current->left != nullptr)
		{
			// Update parent, then current
			parent = current;
			current = current->left;
			continue;
		}
		// This is furthest left node, therefore min
		else
		{
			// Set out pointers and return that its found
			*outParentPtr = parent;
			*outNodePtr = current;
			return;
		}
	}
}