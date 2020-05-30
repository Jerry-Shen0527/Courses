#pragma once
#include<iostream>
using namespace std;
#define size 5

struct Node
{
	Node() { next = -1; distance = -1; }

	int next;
	int distance;

	void set_next(int i, int j);
};

inline int add(int i, int j)
{
	if ((i == -1) || (j == -1)) return -1;
	else return i + j;
}
