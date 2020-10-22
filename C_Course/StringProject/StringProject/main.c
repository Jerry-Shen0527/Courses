#include<stdio.h>

//勉强具有一定的多态性

#include"string_ptr.h"

//#include"string_arr.h"

void notice()
{
	printf("1.Input a string\n2.Print a string (i)\n3.String length of i (i)\n4. Concatenent strings (i,j)\n5.Comparing two strings (i,j)\n6.Copy string from i place to place j (i,j)\n7.Insert j to i at position (i,j,position)\n8.The n character substring of string i, starting from j(i,j,n)\n9Find string j in string i(i,j)\n10.Print them all!\n");
}

int main()
{
	int key = 0;
	int index = 0;
	int index2 = 0;

	int pos = 0;
	int pos2 = 0;
	notice();

	while (scanf("%d", &key))
	{
		
		switch (key)
		{
		case 0:
			exit(0);
			break;
		case 1:
			getchar();
			string_read();
			break;

		case 2:
			scanf("%d", &index);
			string_print(index);
			break;

		case 3:
			scanf("%d", &index);
			printf("%d\n", string_len(index));
			break;

		case 4:
			scanf("%d%d", &index, &index2);
			string_cat(index, index2);
			break;

		case 5:
			scanf("%d%d", &index, &index2);
			string_compare(index, index2);
			break;
		case 6:
			scanf("%d%d", &index, &index2);
			string_cpy(index, index2);
			break;

		case 7:
			scanf("%d%d%d", &index, &index2, &pos);
			string_insert(index, index2, pos);
			break;

		case 8:
			scanf("%d%d%d", &index, &pos, &pos2);
			string_sub(index, pos,pos2);
			break;

		case 9:
			scanf("%d%d", &index, &index2);
			printf("%d\n", string_find_sub(index, index2));
			break;
		case 10:
			string_print_all();
			break;

		default:
			break;
		}
		notice();
	}

}
