#include"account.hpp"
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<Account> people;
	for (int i = 0; i < 10; i++)
	{
		people.push_back(Account(i, 1000));
	}

	int temp;
	cout << "Enter an id:" << endl;
	while (cin >> temp)
	{
		int exit_flag = 0;
		for (auto& c : people)
		{
			if (c.get_id() == temp)
			{
				cout << "Welcome " << c.get_name() << "!" << endl;
				cout << "Main menu" << endl << " 1.check balance" << endl << " 2.withdraw" << endl << " 3.deposit" << endl << " 4.exit" << endl;
				while (cin >> temp)
				{
					switch (temp)
					{
					default:cout << "Wrong input, please try again" << endl;
						break;
					case 1:
						cout << "Balance: " << c.get_balance() << endl;
						break;
					case 2:
						cout << "How much do you want to withdraw?" << endl;
						cin >> temp;
						if (!c.withdraw(temp)) cout << "You don't have that much money." << endl;
						break;
					case 3:
						cout << "How much do you want to deposit?" << endl;
						cin >> temp;
						c.deposit(temp);
						break;
					case 4:
						exit_flag = 1;
						break;
					}
					if (exit_flag) break;
					cout << "Main menu" << endl << " 1.check balance" << endl << " 2.withdraw" << endl << " 3.deposit" << endl << " 4.exit" << endl;
				}
				if (exit_flag) break;
			}
		}
		cout << "Enter an id:" << endl;
	}
}
