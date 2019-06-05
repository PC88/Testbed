#include "Node.h"
#include "iostream"
//#include "Src\App\LogSystem\Logger.h"
/// REFERENCES
/// A great deal of this code was learned from tutorials at https://www.youtube.com/channel/UClEEsT7DkdVO_fkrBw0OTrA
/// this proved to be a great learning resource for this particular task
/// there is also some input from "Data Structures & Algorithms in C++" Second edition.

Node::Node(int ID, Species spec, TimePeriod tp, DinoType dt)
	:dinoID(ID), species(spec), timePeriod(tp), dinoType(dt)
{
}

Node::~Node()
{
}

Node * Node::Insert(Node* root, int ID, Species s, TimePeriod tp, DinoType dt)
{
	if (root == nullptr) // root
	{
		root = GetNewNode(ID, s, tp, dt);
	}
	else if (ID <= root->dinoID) // left
	{
		root->left = Insert(root->left, ID, s, tp, dt);
	}
	else // right
	{
		root->right = Insert(root->right, ID, s, tp, dt);
	}
	return root;
}


Node * Node::DeleteNode(Node * root, int ID)
{
	if (root == nullptr)
	{
		return root;
	}
	else if (ID < root->dinoID)
	{
		root->left = DeleteNode(root, ID);
	}
	else if (ID > root->dinoID)
	{
		root->right = DeleteNode(root->right, ID);
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
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else // case 3 two children
		{
			Node* temp = FindMin(root->right);
			root->dinoID = temp->dinoID;
			root->right = DeleteNode(root->right, temp->dinoID);
		}
	}
	return root;
}

Node * Node::FindMin(Node * root)
{
	if (root->left)
	{
		FindMin(root->left);
	}
	return root;
}

Node * Node::GetNewNode(int ID, Species s, TimePeriod tp, DinoType dt)
{
	Node* newNode = new Node(ID, s, tp, dt);
	return newNode;
}

bool Node::IsBinarySearchTree(Node * root)
{
	if (root == nullptr)
	{
		return true;
	}
	if (IsSubtreeLesser(root->left, root->dinoID)
		&& IsSubtreeGreater(root->right, root->dinoID)
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

bool Node::IsSubtreeLesser(Node * root, int ID)
{
	if (root == nullptr)
	{
		return true;
	}
	if (root->dinoID <= ID
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

bool Node::IsSubtreeGreater(Node * root, int ID)
{
	if (root == nullptr)
	{
		return true;
	}
	if (root->dinoID > ID
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

Node* Node::Search(Node * root, int ID, TraversalType tt) // the tree you wish to search, the ID of what you want, the type of traversal you want -PARAMS
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

Node * Node::InorderSearch(Node * root, int ID)
{
	if (root == nullptr) // first null check
	{
		return root;
	}
	else if (ID < root->dinoID) // left 
	{
		return InorderSearch(root->left, ID);
	}
	else if (root->dinoID == ID) // root
	{
		return root;
	}
	else // right
	{
		return InorderSearch(root->right, ID); 
	}
}

Node * Node::PreorderSearch(Node * root, int ID)
{
	if (root == nullptr) // first null check
	{
		return root;
	}
    if (root->dinoID == ID) // root
	{
		return root;
	}
	else if (ID < root->dinoID) // left
	{
		return PreorderSearch(root->left, ID);
	}
	else // right
	{
		PreorderSearch(root->right, ID);
	}
}

Node * Node::PostorderSearch(Node * root, int ID)
{
	if (root == nullptr) // first null check
	{
		return root;
	}
	if (ID < root->dinoID) // left
	{
		return PreorderSearch(root->left, ID);
	}
	else if (ID > root->dinoID) // right
	{
		PreorderSearch(root->right, ID);
	}
	else // root
	{
	    return root;
	}
}

void Node::Print(Node * root)
{
	std::cout << "Dino ID: " << root->dinoID << std::endl;
	std::cout << "Dino Species: " << root->species << std::endl;
	std::cout << "Dino TimePeriod: " << root->timePeriod << std::endl;
	std::cout << "Dino Type: " << root->dinoType << std::endl;
}
