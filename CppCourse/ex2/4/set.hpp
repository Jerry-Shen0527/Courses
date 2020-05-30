#ifndef  SET
#define SET
#include"link_list.hpp"
#include<utility>

using namespace link_list;
namespace set {
	template<typename T>
	class Set :public LinkList<T>
	{
	public:
		Set();
		Set(istream&);
		Set(const Set& new_set) { this->list_copy(new_set); }
		Set(Set&& new_set) noexcept;
		Set(std::initializer_list<T> list);

		virtual void push(const T&, int index = 0);

		Set& operator= (Set rhs) { link_list::swap(*this, rhs); return *this; }
	private:
	};


	template<typename T>
	Set<T>::Set() :LinkList<T>()
	{
	}

	template<typename T>
	Set<T>::Set(std::initializer_list<T> list) : Set()
	{
		auto beg = list.begin();
		while (beg != list.end())
		{
			push(*beg);
			++beg;
		}
	}

	template<typename T>
	Set<T>::Set(istream& in) : Set()
	{
		this->head->set_ptr(new DataItem<T>);
		DataItem<T>* temp = this->head;
		while (in >> *(temp->get_ptr()))
		{
			if ((this->find(temp->get_ptr()->data())) != this->number_of_items)
				continue;

			temp->get_ptr()->set_ptr(new DataItem<T>);
			temp = temp->get_ptr();
			++this->number_of_items;
		}
		in.clear();
	}

	template<typename T>
	void Set<T>::push(const T & item, int index)
	{
		if (this->find(item) != -1)
			return;
		else
			LinkList<T>::push(item);
	}

	template<typename T>
	Set<T> union_set(const Set<T> & set1, const Set<T> & set2)
	{
		Set<T> temp = set1;
		for (int i = 0; i < set2.size(); i++)
			temp.push(set2[i]);
		return temp;
	}
	template<typename T>
	Set<T> inter_set(const Set<T> & set1, const Set<T> & set2)
	{
		Set<T>temp_set;
		for (int i = 0; i < set1.size(); i++)
		{
			T temp = set1[i];
			if (set2.find(temp) != -1)
				temp_set.push(temp);
		}
		return temp_set;
	}

	template<typename T>
	Set<T>::Set(Set<T> && new_set)noexcept
	{

		this->head = new_set.head;
		this->number_of_items = new_set.number_of_items;
		new_set.head = nullptr;
	}

	template<typename T>
	Set<T> differ_set(const Set<T> & lhs, const Set<T> & rhs)
	{
		Set<T> temp = lhs;
		int index = 0;
		for (int i = 0; i < rhs.size(); i++)
		{
			if (((index = temp.find(rhs[i])) != -1))
				temp.pop(index);
		}
		return temp;
	}
};
#endif // ! SETS

