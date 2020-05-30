#include<climits>
#include <initializer_list>
#include<iostream>
using std::ostream;
struct Node
{
	Node(int i = 0) :left(nullptr), right(nullptr), data(i), balance_index(0) ,parent(nullptr){};
	Node* left;
	Node* right;
	Node* parent;
	Node* link(Node*, bool);//0Á´ÔÚ×ó±ß£¬1Á´ÔÚÓÒ±ß
	int data;
	int balance_index;
};

class BssTree
{
public:
	BssTree() :rootnode(INT_MAX) {}
	~BssTree();

	int insert(int i);
	void insert(std::initializer_list<int>);
	int remove(int i);
	void clear() { this->~BssTree(); }
	
	void mid_traverse(void(*func)(int)) { mid_traverse(func, rootnode.left); }
	void print(ostream& os) { TreePrint(rootnode.left, 0,os); }
private:

	void TreePrint(Node* T, int level,ostream&);
	Node* LL_rotate(Node* node);
	Node* RR_rotate(Node* node);
	Node* LR_rotate(Node* node);
	Node* RL_rotate(Node* node);
	void delete_node(Node*);
	void mid_traverse(void(*func)(int), Node* node);
	 
	Node rootnode;

};

