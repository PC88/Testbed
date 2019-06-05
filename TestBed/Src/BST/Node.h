#pragma once
/// REFERENCES
/// A great deal of this code was learned from tutorials at https://www.youtube.com/channel/UClEEsT7DkdVO_fkrBw0OTrA
/// this proved to be a great learning resource for this particular task
/// there is also some input from "Data Structures & Algorithms in C++" Second edition.

enum Species { NoSpecies, Tyrannosaurus, Velociraptor, Brontosaurus, Deinocheirus };
enum TimePeriod { NoTimePeriod, Jurassic, Triassic, Cretaceous };
enum DinoType { NoType, Carnivorous, Herbivorous, Ombnivorous };
enum TraversalType { Inorder, Preorder, Postorder};

struct Node
{
public:

	Node* left = nullptr;
	Node* right = nullptr;
	int dinoID;
	//int elements = 0; // number of elements at this Nodes sub trees  -PC

	Species species = NoSpecies;
	TimePeriod timePeriod = NoTimePeriod;
	DinoType dinoType = NoType;
	TraversalType traversalType = Inorder;

	Node(int ID, Species spec, TimePeriod tp, DinoType dt);
	virtual ~Node();

	// functions
	Node* GetNewNode(int ID, Species, TimePeriod, DinoType);

	bool IsBinarySearchTree(Node* root);

	bool IsSubtreeLesser(Node* root, int value);
	bool IsSubtreeGreater(Node* root, int value);

	void Print(Node* root);

	Node* Search(Node* root, int ID, TraversalType);

	//traversal searches - PC
	Node* InorderSearch(Node* root, int ID);
	Node* PreorderSearch(Node* root, int ID);
	Node* PostorderSearch(Node* root, int ID);

	Node* Insert(Node* root, int ID, Species, TimePeriod, DinoType); // traversals corrected must be preorder, or root can be Null -PC

	Node* DeleteNode(Node* root, int ID);
	Node* FindMin(Node* root);

};

