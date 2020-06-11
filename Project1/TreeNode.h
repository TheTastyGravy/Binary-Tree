#pragma once
class TreeNode
{
public:
	TreeNode(int val);
	TreeNode(int val, TreeNode* left, TreeNode* right);
	~TreeNode();


	// The value held by the node
	int val;
	// The left branching node
	TreeNode* left;
	// The right branching node
	TreeNode* right;
};