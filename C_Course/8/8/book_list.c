#include<stdio.h>
#include<stdlib.h>

typedef struct Book {
	int id;
	char name[20];
	char author[20];
	char press[20];
	double price;
	struct Book * next;
}BOOK;



BOOK* insert_head(BOOK* head)
{
	BOOK* new_node = (BOOK*)malloc(sizeof(BOOK));
	new_node->next = head;

	printf("The name:");
	scanf("%s", &new_node->name);

	printf("The id:");
	scanf("%d", &new_node->id);

	printf("The author:");
	scanf("%s", &new_node->author);

	printf("The press:");
	scanf("%s", &new_node->press);

	printf("The price:");
	scanf("%lf", &new_node->price);

	return new_node;
}

void print(BOOK * head)
{

	while (head)
	{
		printf("%10d%15s", head->id, head->name);

		printf("%10s", head->author);

		printf("%8.1lf%10s", head->price, head->press);

		printf("\n");
		head = head->next;
	}
	printf("\n");
}

BOOK* delete_one(BOOK* head)
{
	int temp_id = 0;
	printf("The id that you want to delete:");
	scanf("%d", &temp_id);

	BOOK* temp_head = head;

	if (head==NULL)
	{
		return head;
	}

	if (head->next==NULL)
	{
		if (head->id==temp_id)
		{
			free(head);
			head = NULL;
		}
		return head;
	}

	while (head->next)
	{
		if (head->id==temp_id&&temp_head==head)
		{
			head = head->next;
			free(temp_head);
			temp_head = head;
			continue;
		}
		if ((head->next->id)==temp_id)
		{
			BOOK * temp = head->next;
			head->next = head->next->next;
			free(temp);
		}
		else
		{
			head = head->next;
		}
	}
	return temp_head;

}

int search(BOOK* head,int given_id)
{
	while ( head)
	{
		if (head->id==given_id)
		{
			return 1;
		}
		else
		{
			head = head->next;
		}
	}
	return 0;
}

int main()
{
	BOOK * head = NULL;

	int choice;
	printf("1.Insert a BOOK\n2.Print all the information\n3.Delete someone with their id\n4.Search for an item\n");
	while (scanf("%d",&choice))
	{
		switch (choice)
		{
		
		case 1:
			head = insert_head(head);
			break;
		case 2:
			print(head);
			break;
		case 3:
			head=delete_one(head);
			break;
		case 4:
			printf("The id wanted:");
			scanf("%d", &choice);

			if (search(head,choice))
			{
				printf("Found!\n");
			}
			else
			{
				printf("Not found!\n");
			}

		default:
			break;
		}
		printf("1.Insert a BOOK\n2.Print all the information\n3.Delete someone with their id\n4.Search for an item\n");
	}

}