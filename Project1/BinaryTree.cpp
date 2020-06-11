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
		if (parent->getVal() < val)
			parent->setLeft(newNode);
		// Use right
		else
			parent->setRight(newNode);
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
		if (current->getRight() != nullptr)
		{
			TreeNode* min = nullptr;
			TreeNode* minParent = nullptr;
			// Get min node thats larger than current
			getMin(current->getRight(), &min, &minParent);

			// Update current val
			current->setVal(min->getVal());

			// If min is dirrectly off of current
			if (min == current->getRight())
				current->setRight(min->getRight());
			// If min is somewhere left
			else
				minParent->setLeft(min->getRight());
			// Min is 'moved' to current; delete it
			delete min;
		}
		// No right on current
		else
		{
			// If current is the root, change it
			if (current == root)
				root = current->getLeft();
			// Update the parent's pointer
			else if (current == parent->getLeft())
				parent->setLeft(current->getLeft());
			else
				parent->setRight(current->getLeft());
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
		if (current->getVal() < val)
		{
			// Get the next node and repeat
			if (current->getLeft() != nullptr)
			{
				// Update current
				current = current->getLeft();
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
		else if (current->getVal() > val)
		{
			// Get the next node and repeat
			if (current->getRight() != nullptr)
			{
				// Update current
				current = current->getRight();
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
		if (current->getVal() < val)
		{
			// Get the next node and repeat
			if (current->getLeft() != nullptr)
			{
				// Update current and parent
				parent = current;
				current = current->getLeft();
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
		else if (current->getVal() > val)
		{
			// Get the next node and repeat
			if (current->getRight() != nullptr)
			{
				// Update current and parent
				parent = current;
				current = current->getRight();
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
		if (current->getLeft() != nullptr)
		{
			// Update parent, then current
			parent = current;
			current = current->getLeft();
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