#include"node.hpp"

bool compare(int i, int j)//i<j时返回值为true
{
	if (i == -1) return 0;
	if (j == -1)return 1;
	return i <= j;
}

void print(Node head[][size])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{ 
			cout << '(' << head[i][j].next << ',' << head[i][j].distance << ')' << "      ";
		}
		cout << endl;
	}
	cout << endl;
}


void Floyd(Node head[][size])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				if ((!compare(head[j][k].distance, add(head[i][k].distance, head[j][i].distance)))&& add(head[i][k].distance, head[j][i].distance)!=-1)
				{
					//cout << "add node " << i << endl;
					head[j][k].distance = add(head[i][k].distance, head[j][i].distance);
					head[j][k].next = head[j][i].next;
					//print(head);
				}
			}
		}
	}
}


int main()
{
	Node head[size][size];

	while (true)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				head[i][j].next = j;
				head[i][j].distance = -1;
			}
		}

		head[0][1].set_next(1, 10);
		head[0][3].set_next(3, 30);
		head[0][4].set_next(4, 100);
		head[1][2].set_next(2, 50);
		head[2][4].set_next(4, 10);
		head[3][2].set_next(2, 20);

		head[3][4].set_next(4, 60);

		for (int i = 0; i < size; i++)
		{
			head[i][i].set_next(i, 0);
		}

		int temp1, temp2, temp3, temp4;
		cout << "起点: ";
		cin >> temp1;
		cout << "终点: ";
		cin >> temp2;
		cout << "拥塞起点: ";
		cin >> temp3;
		cout << "拥塞终点: ";
		cin >> temp4;


		head[temp3][temp4].set_next(-1, -1);

		//print(head);

		Floyd(head);

		//for (int i = 0; i < size; i++)
		//{
		//	for (int j = 0; j < size; j++)
		//	{
		//		cout <<head[i][j].next<<','<< head[i][j].distance << "    ";
		//		
		//	}
		//	cout << endl;
		//}

		if (head[temp1][temp2].distance == -1) cout << "无法到达" << endl;
		else
		{
			cout << "距离为" << head[temp1][temp2].distance << endl;

			cout << temp1;
			while (temp1 != temp2)
			{
				temp1 = head[temp1][temp2].next;
				cout << "   ->   " << temp1;
			}
		}
		cout << endl;
	}
}