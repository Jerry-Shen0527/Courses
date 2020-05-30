#include<iostream>
using namespace std;

#define size 20


int arr[size];

void swap(int* i, int* j)
{
	auto a = *i;
	*i = *j;
	*j = a;
}

void fast_sort(int* beg, int* end)
{

	if (beg < end)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
		swap(beg, beg + rand() % (end - beg));
		int* head = beg, * tail = end;
		int key = *beg;
		while (head != tail)
		{
			while (*tail >= key && tail != head) tail--;
			*head = *tail;
			if (head == tail) break;
			while (*head < key && tail != head) head++;
			*tail = *head;
		}
		*head = key;

		fast_sort(beg, head);
		fast_sort(head + 1, end);

	}
}

int main()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (2 * size);
	}
	fast_sort(arr, arr + size - 1);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}

}