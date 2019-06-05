#include "BSTNode.h"
#include "iostream"
/// REFERENCES
/// A great deal of this code was learned from tutorials at https://www.youtube.com/channel/UClEEsT7DkdVO_fkrBw0OTrA
/// this proved to be a great learning resource for this particular task
/// there is also some input from "Data Structures & Algorithms in C++" Second edition.

BSTNode::BSTNode(int ID)
	:m_ID(ID)
{
}

BSTNode::~BSTNode()
{
}

BSTNode * BSTNode::Insert(BSTNode* root, int ID)
{
	if (root == nullptr) // root
	{
		root = GetNewBSTNode(ID);
	}
	else if (ID <= root->m_ID) // left
	{
		root->left = Insert(root->left, ID);
	}
	else // right
	{
		root->right = Insert(root->right, ID);
	}
	return root;
}


BSTNode * BSTNode::DeleteBSTNode(BSTNode * root, int ID)
{
	if (root == nullptr)
	{
		return root;
	}
	else if (ID < root->m_ID)
	{
		root->left = DeleteBSTNode(root, ID);
	}
	else if (ID > root->m_ID)
	{
		root->right = DeleteBSTNode(root->right, ID);
	}
	else
	{
		if (root->left == nullptr && root->right == nullptr) // case 1: No child
		{
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr) // case 2 One child
		{
			BSTNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr)
		{
			BSTNode* temp = root;
			root = root->left;
			delete temp;
		}
		else // case 3 two children
		{
			BSTNode* temp = FindMin(root->right);
			root->m_ID = temp->m_ID;
			root->right = DeleteBSTNode(root->right, temp->m_ID);
		}
	}
	return root;
}

BSTNode * BSTNode::FindMin(BSTNode * root)
{
	if (root->left)
	{
		FindMin(root->left);
	}
	return root;
}

BSTNode * BSTNode::GetNewBSTNode(int ID)
{
	BSTNode* newBSTNode = new BSTNode(ID);
	return newBSTNode;
}

bool BSTNode::IsBinarySearchTree(BSTNode * root)
{
	if (root == nullptr)
	{
		return true;
	}
	if (IsSubtreeLesser(root->left, root->m_ID)
		&& IsSubtreeGreater(root->right, root->m_ID)
		&& IsBinarySearchTree(root->left)
		&& IsBinarySearchTree(root->right))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BSTNode::IsSubtreeLesser(BSTNode * root, int ID)
{
	if (root == nullptr)
	{
		return true;
	}
	if (root->m_ID <= ID
		&& IsSubtreeLesser(root->left, ID)
		&& IsSubtreeLesser(root->right, ID))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BSTNode::IsSubtreeGreater(BSTNode * root, int ID)
{
	if (root == nullptr)
	{
		return true;
	}
	if (root->m_ID > ID
		&& IsSubtreeGreater(root->left, ID)
		&& IsSubtreeGreater(root->right, ID))
	{
		return true;
	}
	else
	{
		return false;
	}
}

BSTNode* BSTNode::Search(BSTNode * root, int ID, TraversalType tt) // the tree you wish to search, the ID of what you want, the type of traversal you want -PARAMS
{
	if (tt == TraversalType::Inorder)
	{
		return InorderSearch(root, ID);
	}
	else if (tt == TraversalType::Preorder)
	{
        return PreorderSearch(root, ID);
	}
	else
	{
		return PostorderSearch(root, ID);
	}
}

BSTNode * BSTNode::InorderSearch(BSTNode * root, int ID)
{
	if (root == nullptr) // first null check
	{
		return root;
	}
	else if (ID < root->m_ID) // left 
	{
		return InorderSearch(root->left, ID);
	}
	else if (root->m_ID == ID) // root
	{
		return root;
	}
	else // right
	{
		return InorderSearch(root->right, ID); 
	}
}

BSTNode * BSTNode::PreorderSearch(BSTNode * root, int ID)
{
	if (root == nullptr) // first null check
	{
		return root;
	}
    if (root->m_ID == ID) // root
	{
		return root;
	}
	else if (ID < root->m_ID) // left
	{
		return PreorderSearch(root->left, ID);
	}
	else // right
	{
		PreorderSearch(root->right, ID);
	}
}

BSTNode * BSTNode::PostorderSearch(BSTNode * root, int ID)
{
	if (root == nullptr) // first null check
	{
		return root;
	}
	if (ID < root->m_ID) // left
	{
		return PreorderSearch(root->left, ID);
	}
	else if (ID > root->m_ID) // right
	{
		PreorderSearch(root->right, ID);
	}
	else // root
	{
	    return root;
	}
}

void BSTNode::Print(BSTNode * root)
{
	std::cout << "Dino ID: " << root->m_ID << std::endl;
}
