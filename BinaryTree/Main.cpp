#include <iostream>

/**
 * The Tree structure can be thought as the following format:
 * 
 * You have a root node at the very top and this node has child nodes, and each node
 * has its own child nodes as well.
 * 
 * The Binary Tree has the rule of each node has no more than 2 child 
 * nodes (left node and right node or null).
 */

struct Node
{
	int data;
	Node* left;
	Node* right;
};

class BinaryTree
{
private:
	Node* root;

public:
	BinaryTree()
		: root(nullptr)
	{}
	~BinaryTree()
	{
		DestroyTree();
	}
	BinaryTree(BinaryTree& other) = delete;

	void Insert(int value)
	{
		if (root != nullptr)
		{
			Insert(value, root);
			return;
		}

		root = new Node();
		root->data = value;
		root->left = nullptr;
		root->right = nullptr;
	}
	Node* Search(int value)
	{
		return Search(value, root);
	}
	void DestroyTree()
	{
		DestroyTree(root);

		std::cout << "Tree deleted." << std::endl;
	}

private:
	void Insert(int value, Node* leaf)
	{
		// check if it will add to left
		if (value < leaf->data)
		{
			if (leaf->left != nullptr)
				Insert(value, leaf->left);
			else
			{
				leaf->left = new Node();
				leaf->left->data = value;
				leaf->left->left = nullptr;
				leaf->left->right = nullptr;
			}
		}
		// check if it will add to right
		else if (value >= leaf->data)
		{
			if (leaf->right != nullptr)
				Insert(value, leaf->right);
			else
			{
				leaf->right = new Node();
				leaf->right->data = value;
				leaf->right->left = nullptr;
				leaf->right->right = nullptr;
			}
		}
	}
	Node* Search(int value, Node* leaf)
	{
		if (leaf != nullptr)
		{
			if (value == leaf->data)
				return leaf;

			if (value < leaf->data)
				return Search(value, leaf->left);

			return Search(value, leaf->right);
		}

		std::cout << "Value not found." << std::endl;

		return nullptr;
	}
	void DestroyTree(Node* leaf)
	{
		if (leaf != nullptr)
		{
			DestroyTree(leaf->left);
			DestroyTree(leaf->right);
			delete leaf;
		}
	}
};

int main()
{
	std::cout << "Binary Trees!" << std::endl;

	BinaryTree* tree = new BinaryTree();

	tree->Insert(10);

	std::cin.get();
}