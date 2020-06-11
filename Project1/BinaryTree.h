#pragma once
#include "TreeNode.h"

class BinaryTree
{
public:
	BinaryTree(TreeNode* root);
	BinaryTree(int rootVal);
	~BinaryTree();


	// Is the tree empty?
	bool isEmpty() { return root != nullptr; }

	// Add a node of 'val' to the tree
	void insert(int val);
	// Remove a node of 'val' from the tree
	void remove(int val);
	// Search for node of 'val', with out pointer for the node
	bool search(int val, TreeNode** outNodePtr);
	// Search for node of 'val', with out pointer for the node and its parent
	bool search(int val, TreeNode** outNodePtr, TreeNode** outParentPtr);

private:
	// Get the minimum node from 'root', with out pointers for the node and its parent
	void getMin(TreeNode* root, TreeNode** outNodePtr, TreeNode** outParentPtr);

	TreeNode* root;
};