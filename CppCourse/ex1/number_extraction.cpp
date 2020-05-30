#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream in("sun.txt");
    ofstream out("numbers.txt", ofstream::trunc);
    string temp;
    while (in >> temp)
    {
        int number = 0;
        bool flag = false;
        for (int i = 0; i < temp.size(); i++)
        {
            if (isdigit(temp[i]))
            {
                number = number * 10 + ((int)temp[i] - '0');
                flag = true;
            }

            else if (flag)
            {
                out << number << ' ';
                flag = false;
                number = 0;
            }
        }
    }

    out.close();
}