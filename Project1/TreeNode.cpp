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