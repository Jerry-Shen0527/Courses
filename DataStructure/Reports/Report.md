# 上机实验报告

PB17081531 沈鹏飞

## KMP算法

### 需求分析

##### 1.支持大小写字符的匹配，如a和A是相匹配的；

a和A的匹配是自反对称传递的，因此可以直接视为等价的元素。

##### 2.支持通配符，用*表示通配字符，则*可以和任何字符匹配，如a*可以和aa、ab、ac相匹配。

通配符所表示的相等元素不能视为等价。通配符作为桥梁，导致内部匹配失位不能被检出。因此不能使用next[j+1]=next[k+1]，只能做到next[j+1]=k+1。



`例如字串为abcx###a*cy##adcz，考察y和z的next数组值。假设主串出现apcx，并且在###中不出现匹配，那么如果采用next[j+1]=next[k+1]来优化，会出现成功匹配的结果，而这显然是错误的。`



### 概要设计

KMP算法会使搜索的时间减少，尤其是子串和主串经常出现部分匹配的情况。利用一部分辅助空间来分析字子串的信息，可以使得搜索时明确下一次判断的位置。程序有两个模块：查找和建立next数组。

### 详细设计



##### 建立数组部分

```c++
void set_next(string& son)
{
	index[0] = -1;
	int i = 0, j = -1;
	while (i < son.size()-1)
	{
		if ((j == -1) || compare(son[i], son[j]))
		{
			i++; j++;
			if (!compare(son[i], son[j]))index[i] = j;
			else index[i] = j；
		}
		else
			j = next(j);
	}
}
```



##### 搜索部分

```c++
int kmp_find(string& dad, string& son)
{
	set_next(son);
	int j = 0;
	for (int i = 0; i < dad.size();)
	{
		if (j == -1){i++; j++;}
		if (compare(dad[i],son[j])){i++; j++;}
		else j = next(j);
		if (j==son.size())
			return i - son.size();
	}
	return -1;//匹配失位则返回-1
}
```

##### 判断相等

```c++
bool compare(char a, char b)//为通配符定义新的比较函数
{
	if (a == '*' || b == '*' || a == b||abs(a-b)=='a'-'A')
		return true;
	return false;
}
```



### 算法时空分析

时间、空间复杂度都为O(m+n)。

### 算法测试分析

对于任意合规范的输入都能够成功找到第一个成功匹配的位置，不会出现错判和漏判。



## 表达式求值

### 需求分析

##### 输入的运算数可以是任何整数，如-12×24^3+16/2（其中^为幂运算符）

实际实现实现了小数形式的输入。运算过程中以C++课程实现的有理数作为运算基本对象，因此在运算（只涉及分数）的时候不会出现舍入误差。

##### 输出求值过程中运算符栈、操作数栈、输入字符和主要操作的变化过程

本来就会需要利用这些栈，只需要加入输出功能即可。

##### 若为非法输入则报错

在读取数据时做判断。当括号不匹配或是不能运算时就让栈的溢出或是弹空栈来进行判断。

### 概要设计

栈利用自编的模板来实现。

程序一共包括个模块：

比较运算符优先级的函数。将运算符包裹成一个类，赋值时检查是否属于运算符中的一个，重载运算符来进行运算优先级的比较。

运算：直接计算和从栈中弹出两个操作数来进行计算。

读取：将一个表达式分解操作数和操作符。本代码将读取和运算糅合到了一起，因为会出现小数的读取。

### 详细设计

##### 关于运算符：

```c++
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
```



##### 栈的设计：

```c++
template <typename T>
	class LinkList
	{
		template<typename TT>
		friend void swap(LinkList<TT>&, LinkList<TT>&);
	public:
		LinkList() : head(new DataItem<T>), number_of_items(0) {}
		LinkList(LinkList&&) noexcept;
		LinkList(std::istream&);
		LinkList(const LinkList&);
		LinkList(std::initializer_list<T> list);

		void operator=(const T&) const { std::cerr << "Trying to copy to a const."; } //Prevent copying to a const.
		LinkList& operator=(const LinkList);//同时实现移动赋值和拷贝赋值
		virtual ~LinkList();

		//为了继承时复用插入代码
		virtual void push(const T& in, int index = 0) { insert(in, index); } //After inserting, the added item will have the index of the provided index.
		virtual T pop(int index = 0) { return remove(index); }//希望T类型最好定义了移动拷贝函数，否则会进行拷贝

		//const保护
		const T& operator[](int i) const { return get_elem(i); }
		T& operator[](int i) { return get_elem(i); }
		int size() const { return number_of_items; }
		int find(const T&) const;//-1 marks fail to findlist_


	protected:
		int number_of_items = 0;
		void insert(const T&, int index);//After inserting, the added item will have the index of the provided index.
		T remove(int index);
		DataItem<T>* head;
		void list_copy(const LinkList&);

	private:
		T& get_elem(const int i) const;
	};
```

##### 栈的数据项的设计

```C++
template <typename T>
class DataItem
{

	template<typename TT>  friend istream& operator>> (istream&, DataItem<TT>&);
public:
	DataItem() : ptr(nullptr),item() { }
	DataItem(const DataItem &new_item) : item(new_item.item), ptr(new_item.ptr) {}
	DataItem(const T &in, DataItem *new_ptr = nullptr) : item(in), ptr(new_ptr) {} //此处可以通过一步转换将T类型直接转换为data_item类型

	DataItem &operator=(const DataItem &new_item);
	void operator=(const T &in) const { std::cerr << "Trying to copying to a const." << std::endl; }

	DataItem *set_ptr(DataItem *const); //The pointer can be a const and it may point to a const.
	DataItem *get_ptr() { return ptr; }

	const T& data() const { return item; }
	T& data() { return item; }

	~DataItem() {}

  private:
	T item;
	DataItem *ptr = nullptr;
};
```

事实上封装无力。是第一次设计较复杂的类型关系，还考虑了向集合的扩展。以后再写这种练习代码时应该考虑一次只做一件事情并且做得漂亮一点。

##### 计算和读取：

~~~c++
extern Rational calculator(string expression)
{
	expression += '#';
	LinkList<opt> opt_stash;
	LinkList<Rational> opr_stash;
	Rational result = 0;
	opt_stash.push('#');
	int flag = 0;
	bool flag_followed_opt = true;//连续出现的符号，如 +( 符号的出现 
	bool repeat_flag = false;//运行过程中以达到一个新的符号来判断数字部分的结尾，同时还要满足负号的实现
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
~~~
以上部分实现了对小数的读取。

~~~C++
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
			}

			else if (compare(opt_stash[0], *i) == 0)
			{
				opt_stash.pop();
			}
			else
			{ 
				opr_stash.push(calc(opr_stash.pop(), opr_stash.pop(), opt_stash.pop()));
				i--;
				repeat_flag = true;
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
~~~

以上部分整体来说逻辑结构比较复杂，编写时也比较耗时。效率是足够高的，但是可读性不强，主要原因是读取、计算混在一起。设计时先将负数作为一种单独情况进行完整考虑并排除其影响，之后遇到符号后标志着操作数读取结束，进行数据存储。将此符号与栈顶操作符进行比较，决定将符号入栈还是进行栈顶的运算。

### 算法时空分析

空间最大为栈长，即为表达式的长度。时间最长为每个操作数和运算符都入栈一次，也为表达式长度。

### 算法测试分析

对于所有合法输入均能给出正确的结果，对于不合法的输入能够给出最早出现第一个错误的位置的信息。