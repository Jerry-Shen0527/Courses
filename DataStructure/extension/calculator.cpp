#include"../linear_list/link_list.hpp"
#include"../../CppCourse/ex2/3/Rational.hpp"
#include<string>
using link_list::LinkList;
#define DEBUG
#ifdef DEBUG
using namespace std;
#endif // DEBUG



template<typename T>
void print_status(LinkList<T>& stash);
class opt
{
public:
	opt() :oprt(0) {}
	opt(char in) {
		if (!(in == '+' || in == '-' || in == '/' || in == '*' || in == '#' || in == '(' || in == ')' || in == '^')) std::cerr << "Wrong input.";
		else oprt = in;
	}//一步转换
	char oprt;
};
#ifdef DEBUG
ostream& operator<<(ostream& out, const opt& opt) { out << opt.oprt; return out; }
#endif // DEBUG

Rational calc(Rational lhs, Rational rhs, opt opt);
int compare(opt lhs, opt rhs);

extern Rational calculator(string expression)
{
	expression += '#';
	LinkList<opt> opt_stash;
	LinkList<Rational> opr_stash;
	Rational result = 0;
	opt_stash.push('#');
	int flag = 0;
	bool flag_followed_opt = true;//连续出现的符号，如 +( 符号的出现 
	bool minus_flag = false;
	bool repeat_flag = false;
	Rational temp = 0;
	for (auto i = expression.begin(); i != expression.end(); i++)
	{
		if (isdigit(*i))
		{
			flag_followed_opt = false;
			repeat_flag = false;
			if (!flag)
			{
				temp = temp * 10 + ((*i) - '0');
			}
			else
			{
				Rational m = (*i) - '0';
				for (size_t i = 0; i < flag; i++)
					m = m / 10;
				temp = temp + m;
				flag++;
			}
		}
		else if (*i=='.')
		{
			flag = 1;
		}
		else if(*i == '+' ||* i == '-' || *i == '/' || *i == '*'||*i=='#'||*i=='('||*i==')'||*i=='^')
		{
			if ((!repeat_flag)&&(flag_followed_opt) && *i == '-')
			{
				flag_followed_opt = true;
				minus_flag = true;
			}
			if (!flag_followed_opt)
			{
				if(minus_flag)
				opr_stash.push(0-temp);
				else opr_stash.push(temp);
				minus_flag = false;
			}
			if(!minus_flag)
			if (compare(opt_stash[0], *i) == -1)
			{
				opt_stash.push(*i);
#ifdef DEBUG
				//cout << "operator:" << endl;
				//print_status(opt_stash);
				//cout << "operand:" << endl;
				//print_status(opr_stash);
#endif // DEBUG
			}

			else if (compare(opt_stash[0], *i) == 0)
			{
				
				opt_stash.pop();
#ifdef DEBUG
				//cout << "operator:" << endl;
				//print_status(opt_stash);
				//cout << "operand:" << endl;
				//print_status(opr_stash);
#endif // DEBUG
			}
			else
			{
#ifdef DEBUG
				//cout << "operator:" << endl;
				//print_status(opt_stash);
				//cout << "operand:" << endl;
				//print_status(opr_stash);
#endif // DEBUG

				opr_stash.push(calc(opr_stash.pop(), opr_stash.pop(), opt_stash.pop()));
				i--;
				repeat_flag = true;

#ifdef DEBUG
				//cout << "operator:" << endl;
				//print_status(opt_stash);
				//cout << "operand:" << endl;
				//print_status(opr_stash);
#endif // DEBUG

			}
			flag_followed_opt = true;
			flag = 0;
			temp = 0;

		}
		else
		{
			std::cout << "wrong input of the first charactor " << *i << std::endl;
			return 0;
		}
	}

	return opr_stash[0];
}

Rational calc(Rational lhs, Rational rhs, opt opt)
{
	switch (opt.oprt)
	{
	case'+':return lhs + rhs;
	case'-':return lhs - rhs;
	case'*':return lhs * rhs;
	case'/':return lhs / rhs;
	case'^':return pow(lhs, rhs);
	}
	return -1;
}





int compare (opt lhs, opt rhs)
{
	switch (lhs.oprt)
	{
	case'+':
	case'-':
		switch (rhs.oprt)
		{
		case'+':
		case'-':return 1;
		case'*':
		case'/':return -1;
		case'(':return -1;
		case')':return 1;
		case'#':return 1;
		case'^':return -1;
		}
	
	case'*':
	case'/':
		switch (rhs.oprt)
		{
		case'+':
		case'-':return 1;
		case'*':
		case'/':return 1;
		case'(':return -1;
		case')':return 1;
		case'#':return 1;
		case'^':return -1;
		}
	case'(':
		switch (rhs.oprt)
		{
		case'+':
		case'-':return -1;
		case'*':
		case'/':return -1;
		case'(':return -1;
		case')':return 0;
		case'#':return 1;
		case'^':return -1;
		}
	case')':
		switch (rhs.oprt)
		{
		case'+':
		case'-':
		case'*':
		case'/':
		case'(':
		case')':
		case'^':
		case'#':return 1;
		}
	case'#':
		switch (rhs.oprt)
		{
		case'+':
		case'-':
		case'*':
		case'/':
		case'(':
		case'^':
		case')':return -1;
		case'#':return 0;
		}
	case'^':
		switch (rhs.oprt)
		{
		case'+':
		case'-':return 1;
		case'*':
		case'/':return 1;
		case'(':return -1;
		case')':return 1;
		case'#':return 1;
		case'^':return 1;
		}
	}
}

#ifdef DEBUG
template<typename T>
void print_status(LinkList<T>& stash)
{
	for (int i  =stash.size()-1; i >=0; i--)
	{
			cout << stash[i] << ' ';
	}
	cout << endl;
}

int main()
{
	std::string temp;
	while (cin >> temp) {
		cout << calculator(temp).number() << endl;
	}
}
#endif // DEBUG
