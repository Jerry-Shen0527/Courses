#ifndef BINARYTREE
#define BINARYTREE

#include"node.hpp"
#include<vector>
#define LEFT 0
#define RIGHT 1

using std::vector;
template<typename T>
class BinaryTree
{
public:
	BinaryTree() :root(nullptr);
	~BinaryTree();

	vector<bool> find(T&);
	T& fetch_data(vector<bool>&);
	void insert_item(const T&);
	void insert_item(const T&, vector<bool>&);


	
private:
	TreeNode* root;

	void set_thread();
	void pre_traverse(void (*func)(const T&));
	void mid_traverse(void (*func)(const T&));
	void tail_traverse(void (*func)(const T&));


	
};

#endif // !
