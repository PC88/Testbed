#pragma once
/// REFERENCES
/// A great deal of this code was learned from tutorials at https://www.youtube.com/channel/UClEEsT7DkdVO_fkrBw0OTrA
/// this proved to be a great learning resource for this particular task
/// there is also some input from "Data Structures & Algorithms in C++" Second edition.

enum TraversalType { Inorder, Preorder, Postorder};

struct BSTNode
{
public:

	BSTNode* left = nullptr;
	BSTNode* right = nullptr;
	int m_ID;
	//int elements = 0; // number of elements at this BSTNodes sub trees  -PC

	TraversalType traversalType = Inorder;

	BSTNode(int ID);
	virtual ~BSTNode();

	// functions
	BSTNode* GetNewBSTNode(int ID);

	bool IsBinarySearchTree(BSTNode* root);

	bool IsSubtreeLesser(BSTNode* root, int value);
	bool IsSubtreeGreater(BSTNode* root, int value);

	void Print(BSTNode* root);

	BSTNode* Search(BSTNode* root, int ID, TraversalType);

	//traversal searches - PC
	BSTNode* InorderSearch(BSTNode* root, int ID);
	BSTNode* PreorderSearch(BSTNode* root, int ID);
	BSTNode* PostorderSearch(BSTNode* root, int ID);

	BSTNode* Insert(BSTNode* root, int ID); // traversals corrected must be preorder, or root can be Null -PC

	BSTNode* DeleteBSTNode(BSTNode* root, int ID);
	BSTNode* FindMin(BSTNode* root);

};

