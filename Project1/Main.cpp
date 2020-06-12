#include "raylib.h"
#include "BinaryTree.h"
#include "TextboxClass.h"
#include "ButtonClass.h"
#include <string>


// Draw the tree's nodes using its hierachy, with root at 'x, y' 
// and distanced using 'spacing'
void drawTree(TreeNode* root, int spacing, int x, int y);
// Draw the node at 'x, y'
void drawNode(TreeNode* node, int x, int y);


int main()
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HIGHT = 600;

	InitWindow(SCREEN_WIDTH, SCREEN_HIGHT, "Binary Tree demo");
	SetTargetFPS(60);


	// Binary tree of values
	BinaryTree* tree = new BinaryTree();

	// Textbox and buttons for GUI
	TextboxClass textbox(Rectangle{ 325, SCREEN_HIGHT - 75, 150, 50 }, 9, 23);
	ButtonClass insertBtn(Rectangle{ 100, SCREEN_HIGHT - 75, 150, 30 }, "insert", 15);
	ButtonClass removeBtn(Rectangle{ 550, SCREEN_HIGHT - 75, 150, 30 }, "remove", 15);


	// Main loop
	while (!WindowShouldClose())
	{
		// Get input
		textbox.update();

		// Buttons can only be clicked if there is text to use
		if (!textbox.isEmpty())
		{
			if (insertBtn.isClicked())
				tree->insert(std::stoi(textbox.getTextAndClear()));
			if (removeBtn.isClicked())
				tree->remove(std::stoi(textbox.getTextAndClear()));
		}


		// Draw
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// Draw the tree, given it exists
		if (tree->getRoot() != nullptr)
			drawTree(tree->getRoot(), SCREEN_WIDTH / 2.1f, SCREEN_WIDTH / 2, 50);

		// Draw GUI
		textbox.draw();
		insertBtn.draw();
		removeBtn.draw();


		EndDrawing();
	}

	CloseWindow();
	return 0;
}


void drawTree(TreeNode* root, int spacing, int x, int y)
{
	// If the node doesnt exist, dont run
	if (root == nullptr)
		return;

	// Halve the spacing so nodes get closer as it goes down
	spacing /= 2;


	// Draw this node
	drawNode(root, x, y);

	// Check children
	if (root->left != nullptr)
	{
		// Draw line then continue child, moving them down and over
		DrawLine(x, y, x - spacing, y + 70, RED);
		drawTree(root->left, spacing, x - spacing, y + 70);
	}
	if (root->right != nullptr)
	{
		// Draw line then continue child, moving them down and over
		DrawLine(x, y, x + spacing, y + 70, RED);
		drawTree(root->right, spacing, x + spacing, y + 70);
	}

	// Draw this node after the lines
	drawNode(root, x, y);
}

// Custom text function that draws using x and y as centered
void drawTextCustom(std::string text, int posX, int posY, int fontSize, Color color)
{
	DrawText(text.c_str(), posX - MeasureText(text.c_str(), fontSize) / 2, posY - fontSize / 2, fontSize, color);
}

void drawNode(TreeNode* node, int x, int y)
{
	// Draw circle with value inside
	DrawCircle(x, y, 22, SKYBLUE);
	drawTextCustom(std::to_string(node->val), x, y, 20, BLACK);
}