#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdexcept>
#include <iostream>
#include "data_item.hpp"
//Visual Studio写模板类要求在头文件内实现类的成员函数，否则会链接失败
namespace link_list
{
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

	template<typename T>
	void swap(LinkList<T>& lhs, LinkList<T>& rhs)
	{
		std::swap(lhs.number_of_items, rhs.number_of_items);
		std::swap(lhs.head, rhs.head);
	}

	template<typename T>
	LinkList<T>::LinkList(LinkList&& rr) noexcept
	{
		head = rr.head;
		number_of_items = rr.number_of_items;
		rr.head = nullptr;

	}

	template <typename T>
	LinkList<T>::LinkList(std::istream& in) : LinkList<T>()
	{
		head->set_ptr(new DataItem<T>);
		DataItem<T>* temp = head;
		while (in >> *(temp->get_ptr()))
		{
			temp->get_ptr()->set_ptr(new DataItem<T>);
			temp = temp->get_ptr();
			++number_of_items;
		}
		in.clear();
	}

	template<typename T>
	LinkList<T>::LinkList(const LinkList& new_list) :LinkList<T>()
	{
		list_copy(new_list);
	}

	template<typename T>
	LinkList<T>::LinkList(std::initializer_list<T> list):LinkList()
	{
		auto beg = list.begin();
		while (beg!=list.end())
		{
			push(*beg);
			++beg;
		}
	}

	template<typename T>
	int LinkList<T>::find(const T& in) const
	{
		int index = 0;
		DataItem<T>* temp_ptr = head->get_ptr();
		while (temp_ptr && !(temp_ptr->data() == in))
		{
			++index;
			temp_ptr = temp_ptr->get_ptr();
		}
		if (temp_ptr) return index;
		return -1;

	}


	template<typename T>
	void LinkList<T>::list_copy(const LinkList& in)
	{
		if (!in.head->get_ptr())
		{
			LinkList<T> temp;//empty
			swap(*this, temp);
		}//将原始对象置换与一临时对象置换，原始对象会随临时对象销毁
		DataItem<T>* temp_in = in.head->get_ptr(), * temp_this = head;
		while (temp_in)
		{
			temp_this = temp_this->set_ptr(new DataItem<T>);
			*temp_this = *temp_in;
			temp_in = temp_in->get_ptr();
		}
		number_of_items = in.number_of_items;
	}

	template <typename T>
	T& LinkList<T>::get_elem(const int index) const
	{
		DataItem<T>* temp = head->get_ptr();
		try
		{
			if (index >= number_of_items)
				throw std::out_of_range("Index is larger than the number_of_items.");
		}
		catch (const std::out_of_range & e)
		{
			std::cerr << e.what() << '\n';
			exit(0);
		}

		for (int i = 0; i < index && temp; i++)
			temp = temp->get_ptr();

		return temp->data();
	}

	template<typename T>
	LinkList<T>& LinkList<T>::operator=(LinkList<T> in)
	{
		link_list::swap(*this, in);
		return *this;
	}

	template <typename T>
	LinkList<T>::~LinkList()
	{
		while (head)
		{
			DataItem<T>* temp = head;
			head = head->get_ptr();
			delete temp;
		}
		//std::cerr << "delete function called" << std::endl;
	}

	template <typename T>
	void LinkList<T>::insert(const T & in, int index)
	{
		DataItem<T>* temp = head;
		if (index > number_of_items)
		{
			throw std::out_of_range("input index is larger than the size");
			return;
		}
		for (int i = 0; i < index; i++)
			temp = temp->get_ptr();
		temp->set_ptr(new DataItem<T>(in, temp->get_ptr()));
		++number_of_items;
	}

	template<typename T>
	T LinkList<T>::remove(int index)
	{
		try {
			if (index > number_of_items - 1)
			{
				throw std::out_of_range("index is bigger than the size when removing");
			}
		}
		catch (const std::out_of_range & e)
		{
			std::cerr << e.what() << '\n';
			return T();
		}
		DataItem<T>* cur = head;
		for (int i = 0; cur && i < index; i++)
			cur = cur->get_ptr();
		DataItem<T>* temp = cur->get_ptr();
		auto temp_data = temp->data();//一次拷贝
		cur->set_ptr(cur->get_ptr()->get_ptr());
		delete temp;
		--number_of_items;
	//	std::cout << "removed something" << std::endl;
		return temp_data;//如果T未定义移动构造则又一次拷贝
	}
}
#endif
