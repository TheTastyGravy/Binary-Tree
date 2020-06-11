#pragma once
class TreeNode
{
public:
	TreeNode(int val);
	TreeNode(int val, TreeNode* left, TreeNode* right);
	~TreeNode();


	// Set the value
	void setVal(int val) { this->val = val; }
	// Set the left pointer
	void setLeft(TreeNode* left) { this->left = left; }
	// Set the right pointer
	void setRight(TreeNode* right) { this->right = right; }

	// Return the nodes value
	int getVal() { return val; }
	// Return the node to the left
	TreeNode* getLeft() { return left; }
	// Return the node to the right
	TreeNode* getRight() { return right; }

private:
	int val;
	TreeNode* left;
	TreeNode* right;
};