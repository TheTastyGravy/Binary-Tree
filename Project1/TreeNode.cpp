#include "TreeNode.h"

TreeNode::TreeNode(int val) :
	val(val),
	left(nullptr),
	right(nullptr)
{
}

TreeNode::TreeNode(int val, TreeNode* left, TreeNode* right) :
	val(val),
	left(left),
	right(right)
{
}

TreeNode::~TreeNode()
{
}


/*

bool TreeNode::getLeft(TreeNode** outPtr)
{
	// Set out pointer and return if it exists
	if (left != nullptr)
		*outPtr = left;

	return (left != nullptr);
}

bool TreeNode::getRight(TreeNode** outPtr)
{
	// Set out pointer and return if it exists
	if (right != nullptr)
		*outPtr = right;

	return (right != nullptr);
}

*/