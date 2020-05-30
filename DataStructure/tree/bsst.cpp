#include "bsst.hpp"
#include<algorithm>
#include<iostream>
using namespace std;
Node* Node::link(Node* newnode, bool l)//0链在左边，1链在右边
{
	if (l)right = newnode;
	else left = newnode;
	if (newnode)newnode->parent = this;
	return newnode;
}

void BssTree::mid_traverse(void(*func)(int), Node* node)
{
	if (node) {
		if (node->left) mid_traverse(func, node->left);
		func(node->data);
		if (node->right) mid_traverse(func, node->right);
	}
}

Node* BssTree::LL_rotate(Node* node)
{
	Node* temp = node->left;
	node->link(temp->right,0);
	node->balance_index -= (temp->balance_index+1);
	temp->link(node, 1);
	temp->balance_index -= 1;
	return temp;
}

Node* BssTree::RR_rotate(Node* node)
{
	Node* temp = node->right;
	node->link(temp->left, 1);
	node->balance_index += (1-temp->balance_index);
	temp->link(node, 0);
	temp->balance_index += 1;
	return temp;
}

Node* BssTree::LR_rotate(Node* node)
{
	auto temp = node->left->right;
	switch (temp->balance_index)
	{
	case -1:
		node->left->balance_index = +1;
		node->balance_index = 0;
		break;
	case 1:
		node->left->balance_index = 0;
		node->balance_index = -1;
		break;
	case 0:
		node->left->balance_index = 0;
		node->balance_index = 0;
	}
	auto debug = node->left;
	debug->link(temp->left, 1);

	auto temp2 = node->left;
	node->link(temp->right, 0);
	temp->link(node, 1);
	temp->link(temp2, 0);
	temp->balance_index = 0;
	return temp;
}

Node* BssTree::RL_rotate(Node* node)
{
	auto temp = node->right->left;
	switch (temp->balance_index)
	{
	case 1:
		node->right->balance_index = -1;
		node->balance_index = 0;
		break;
	case -1:
		node->right->balance_index = 0;
		node->balance_index = 1;
		break;
	case 0:
		node->right->balance_index = 0;
		node->balance_index = 0;
	}
	auto debug = node->right;
	debug->link(temp->right, 0);

	auto temp2 = node->right;
	node->link(temp->left, 1);
	temp->link(node, 0);
	temp->link(temp2, 1);
	temp->balance_index = 0;
	return temp;
}

void BssTree::delete_node(Node* node)
{
		if (node->left)  delete_node(node->left);
		if (node->right) delete_node(node->right);
		delete node;
}

void BssTree::TreePrint(Node* T, int level,ostream& os)
{
	if (!T)				//如果指针为空，返回上一层
	{
		return;
	}
	TreePrint(T->right, level + 1,os);	//打印右子树，并将层次加1
	for (int i = 0; i < level; i++)	//按照递归的层次打印空格
	{
		os << "              ";
	}
	os << T->data << endl;	//输出根结点
	TreePrint(T->left, level + 1,os);	//打印左子树，并将层次加1
}

BssTree::~BssTree()
{
	if (rootnode.left)
	delete_node(rootnode.left);
}

int BssTree::insert(int i)
{
	Node* follower, * node;
	Node* balance_node;
	 follower = &rootnode;
	 node = balance_node = rootnode.left;
	
	while (node)
	{
		follower = node;
		if (i > node->data) node = node->right;
		else if (i < node->data)node = node->left;
		else return 0;
		if (node && (node->balance_index != 0))
		{
			balance_node = node;
		}
	}

	node = balance_node;
	while (node)//从最近可能失衡结点到插入结点，依次改变平衡因子
	{
		follower = node;
		if (i > node->data)
		{
			node = node->right;
			follower->balance_index -= 1;
		}
		else if (i < node->data)
		{
			node = node->left;
			follower->balance_index += 1;
		}
	}

	if (i < follower->data)
		follower->link(new Node(i), 0);
	else
		follower->link(new Node(i), 1);

	if (balance_node&&balance_node->balance_index == 2)
	{
		if (balance_node->left->balance_index == 1) {
			if (balance_node->parent->left == balance_node) {
				auto temp = balance_node->parent;
				temp->link(LL_rotate(balance_node), 0);
			}
			else
			{
				auto temp = balance_node->parent;
				temp->link(LL_rotate(balance_node), 1);
			}
		}
		else if (balance_node->left->balance_index == -1)
		{
			if (balance_node->parent->left == balance_node) {
				auto temp = balance_node->parent;
				temp->link(LR_rotate(balance_node), 0);
			}
			else
			{
				auto temp = balance_node->parent;//凡是这样的写法都不能做简化，原因可能是编译器会先求参数，而经过rotate之后结点就已经变了
				temp->link(LR_rotate(balance_node), 1);
			}
		}
	}
	else if (balance_node&&balance_node->balance_index == -2)
	{
		if (balance_node->right->balance_index == -1) {
			if (balance_node->parent->left == balance_node) {
				auto temp = balance_node->parent;
				temp->link(RR_rotate(balance_node), 0);
			}
			else
			{
				auto temp = balance_node->parent;
				temp->link(RR_rotate(balance_node), 1);
			}
		}
		else if (balance_node->right->balance_index == 1)
		{
			if (balance_node->parent->left == balance_node) {
				auto temp = balance_node->parent;
				temp->link(RL_rotate(balance_node), 0);
			}
			else
			{
				auto temp = balance_node->parent;
				temp->link(RL_rotate(balance_node), 1);
			}
		}
	}
	return 1;
}

void BssTree::insert(std::initializer_list<int> list)
{
	for (auto c : list)
		insert(c);
}

int BssTree::remove(int i)
{
	Node* follower, * node, * to_be_delete = nullptr;
	Node* balance_node;
	follower = &rootnode;
	node = balance_node = rootnode.left;

	while (node)
	{
		follower = node;
		if (i > node->data) node = node->right;
		else if (i < node->data)node = node->left;
		else {
			to_be_delete = node;
			if (node->left && node->right)
				if (node->balance_index >= 0) node = node->left;
				else node = node->right;
			else
			{
				follower = node; break;
			}
		}
	}
	if (to_be_delete) {
		to_be_delete->data = follower->data;//实现了交换的目的
		if (follower->parent->left == follower)
		{
			auto debug = follower->parent;
			debug->link(follower->left ? follower->left : follower->right, 0);
			delete follower;
			debug->balance_index -= 1;
			follower = debug;
		}
		else
		{
			auto debug = follower->parent;
			debug->link(follower->left ? follower->left : follower->right, 1);
			delete follower;
			debug->balance_index += 1;
			follower = debug;
		}
		while (follower != &rootnode && follower->balance_index == 0)
		{
			auto debug = follower->parent;
			debug->balance_index += (debug->left == follower ? -1 : 1);
			follower = follower->parent;
		}
		follower = follower;
		while (follower != &rootnode) {
			if (follower && follower->balance_index == 2)
			{
				if (follower->left->balance_index >= 0) {
					if (follower->parent->left == follower) {
						auto temp = follower->parent;
						temp->link(LL_rotate(follower), 0);
						follower = temp->left;
					}
					else
					{
						auto temp = follower->parent;
						temp->link(LL_rotate(follower), 1);
						follower = temp->right;
					}
				}
				else if (follower->left->balance_index == -1)
				{
					if (follower->parent->left == follower) {
						auto temp = follower->parent;
						temp->link(LR_rotate(follower), 0);
						follower = temp->left;
					}
					else
					{
						auto temp = follower->parent;
						temp->link(LR_rotate(follower), 1);
						follower = temp->right;
					}
				}
			}
			else if (follower && follower->balance_index == -2)
			{
				if (follower->right->balance_index <= 0) {
					if (follower->parent->left == follower) {
						auto temp = follower->parent;
						temp->link(RR_rotate(follower), 0);
						follower = temp->left;
					}
					else
					{
						auto temp = follower->parent;
						temp->link(RR_rotate(follower), 1);
						follower = temp->right;
					}
				}
				else if (follower->right->balance_index == 1)
				{
					if (follower->parent->left == follower) {
						auto temp = follower->parent;
						temp->link(RL_rotate(follower), 0);
						follower = temp->left;
					}
					else
					{
						auto temp = follower->parent;
						temp->link(RL_rotate(follower), 1);
						follower = temp->right;
					}
				}
			}
			else break;
			while (follower != &rootnode && follower->balance_index == 0)
			{
				auto debug = follower->parent;
				debug->balance_index += (debug->left == follower ? -1 : 1);
				follower = follower->parent;
			}
		}
	}
	else
	{
		return 0;
	}
	return 1;
}