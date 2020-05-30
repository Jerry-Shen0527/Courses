#include<string>

class Account
{
public:
	Account(int user_id = 0, int user_balance = 0) :id(user_id), balance(user_balance) { char temp[100]; _itoa_s(user_id, temp, 10); name += temp; }
	Account( std::string user_name, int user_id = 0, int user_balance = 0) :id(user_id), name(user_name), balance(user_balance) {}
	~Account();

	bool withdraw(int money) {
		if (money <= balance) { balance -= money; return true; }
		else
		{
			return false;
		}
	}
	void deposit(int money) { balance += money; }

	int get_id() { return id; }

	std::string get_name() { return name; }

	int get_balance() { return balance; }
	void set_balance(int money) { balance = money; }

private:
	int id;
	std::string name;
	int balance;
};


Account::~Account()
{
}