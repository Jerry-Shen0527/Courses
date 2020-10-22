#include<stdio.h>
#include<stdlib.h>

typedef struct stu
{
	int num;
	char name[16];
	char sex;
	int age;
	double grade;
	struct stu * next;
}stu;

stu* insert_head(stu* head)
{
	stu* new_node = (stu*)malloc(sizeof(stu));
	new_node->next = head;

	printf("The name:");
	scanf("%s", &new_node->name);

	printf("The id:");
	scanf("%d", &new_node->num);

	printf("The sex:");
	scanf("%d", &new_node->sex);

	printf("The age:");
	scanf("%d", &new_node->age);

	printf("The grade:");
	scanf("%lf", &new_node->grade);

	return new_node;
}

void print(stu * head)
{

	while (head)
	{
		printf("%10d%15s", head->num, head->name);
		if (head->sex==0)
		{
			printf("    W    ");
		}
		else
		{
			printf("    M    ");
		}

		printf("%8.1lf%5d", head->grade, head->age);

		printf("\n");
		head = head->next;
	}
	printf("\n");
}

stu* delete_one(stu* head)
{
	int temp_age = 0;
	printf("The age that you want to delete:");
	scanf("%d", &temp_age);

	stu* temp_head = head;

	if (head==NULL)
	{
		return head;
	}

	if (head->next==NULL)
	{
		if (head->age==temp_age)
		{
			free(head);
			head = NULL;
		}
		return head;
	}

	while (head->next)
	{
		if (head->age==temp_age&&temp_head==head)
		{
			head = head->next;
			free(temp_head);
			temp_head = head;
			continue;
		}
		if ((head->next->age)==temp_age)
		{
			stu * temp = head->next;
			head->next = head->next->next;
			free(temp);
		}
		else
		{
			head = head->next;
		}
	}
	print(temp_head);
	return temp_head;
}

int main()
{
	stu * head = NULL;

	int choice;
	printf("1.Insert a student\n2.Print all the information\n3.Delete someone with their age\n");
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
		default:
			break;
		}
		printf("1.Insert a student\n2.Print all the information\n3.Delete someone with their age\n");
	}


}