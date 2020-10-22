#include<stdio.h>
#include<Windows.h>

typedef struct Student
{
	int id;
	char name[20];
	double course1;
	double course2;
	double course3;
	double average;
} Student;




Student stu_arr[5];

void calc_ave()
{
	for (int i = 0; i < 5; i++)
	{
		stu_arr[i].average = 1 / 3.0*(stu_arr[i].course1 + stu_arr[i].course2 + stu_arr[i].course3);
	}
}

void swap(Student *student1, Student * student2)
{
	int temp_id = student1->id;
	student1->id = student2->id;
	student2->id = temp_id;

	char temp[20];

	strcpy(temp, student1->name);
	strcpy(student1->name, student2->name);
	strcpy(student2->name, temp);

	double temp_course;

	temp_course = student1->course1;
	student1->course1 = student2->course1;
	student2->course1 = temp_course;

	temp_course = student1->course2;
	student1->course2 = student2->course2;
	student2->course2 = temp_course;

	temp_course = student1->course3;
	student1->course3 = student2->course3;
	student2->course3 = temp_course;

	temp_course = student1->average;
	student1->average = student2->average;
	student2->average = temp_course;
}
//
void sort(Student *student_arr)
{
	calc_ave();
	for (int i = 0; i < 5; i++)
	{
		int max = student_arr[i].average;
		int index = i;
		for (int j = i + 1; j < 5; j++)
		{
			if (student_arr[j].average > max)
			{
				max = student_arr[j].average;
				index = j;
			}
		}
		swap(student_arr + i, student_arr + index);
	}
}


void print(FILE * ptr)
{
	for (int i = 0; i < 5; i++)
	{
		fprintf(ptr, "%d\n%s\n%f\n%f\n%f\n", stu_arr[i].id, stu_arr[i].name, stu_arr[i].course1, stu_arr[i].course2, stu_arr[i].course3);
	}
}

int main()
{
	FILE *fp1;

	if ((fp1 = fopen("C:\\Users\\10069\\Desktop\\stud_sort.txt", "r")) == NULL)
	{
		printf("File not opened!\n");
		exit(0);
	}

	int i = 0;
	while (fscanf(fp1, "%d%s%lf%lf%lf", &(stu_arr[i].id), stu_arr[i].name, &(stu_arr[i].course1), &(stu_arr[i].course2), &(stu_arr[i].course3)) != EOF)
	{
		i++;
	}

	print(stdout);

	fclose(fp1);

	system("pause");

}

