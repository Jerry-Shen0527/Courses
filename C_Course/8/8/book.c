//#include<stdio.h>
//#include<stdlib.h>
//
//#define N 10
//
//typedef struct {
//	int year;
//	int month;
//	int day;
//} Date;
//
//
//typedef struct BOOK{
//	int id;
//	char name[20];
//	char author[20];
//	char press[20];
//	double price;
//	Date date;
//} BOOK;
//
//BOOK books[N];
//
void swap(BOOK *book1, BOOK * book2)
{
	int temp_id = book1->id;
	book1->id = book2->id;
	book2->id = temp_id;

	char temp[20];

	strcpy(book1->name, temp);
	strcpy(book2->name,book1->name);
	strcpy(temp,book2->name);

	strcpy(book1->author, temp);
	strcpy(book2->author, book1->author);
	strcpy(temp, book2->author);
	strcpy(book1->press, temp);
	strcpy(book2->press, book1->press);
	strcpy(temp, book2->press);
	strcpy(book1->name, temp);


	double temp_price;

	temp_price = book1->price;
	book1->price = book2->price;
	book2->price = temp_price;

	int temp_int;


	temp_id = book1->date.year;
	book1->date.year = book2->date.year;
	book2->date.year = temp_id;

	temp_id = book1->date.month;
	book1->date.month = book2->date.month;
	book2->date.month = temp_id;
	temp_id = book1->date.day;
	book1->date.day = book2->date.day;
	book2->date.day = temp_id;
}
//
void sort(BOOK *book_arr)
{
	for (int i = 0; i < N; i++)
	{
		int max = book_arr[i].id;
		int index = i;
		for (int j = i + 1; j < N; j++)
		{
			if (book_arr[j].id > max)
			{
				max = book_arr[j].id;
				index = j;
			}
		}
		swap(book_arr + i, book_arr + index);
	}
}
//
//int main()
//{
//	for (int i = 0; i < N; i++)
//	{
//		books[i].id = rand() % 100;
//	}
//
//	sort(books);
//
//	for (int i = 0; i < N; i++)
//	{
//		printf("%5d", books[i].id);
//	}
//	system("pause");
//}