#ifndef DATAITEM
#define DATAITEM
#include <iostream>

using std::istream;

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

template<typename T>
istream& operator >>(istream& in,DataItem<T>& _this)
{
	in >> _this.item;
	return in;
}


template <typename T>
DataItem<T> &DataItem<T>::operator=(const DataItem &new_item)
{
	ptr = new_item.ptr;
	item = new_item.item;
	return *this;
}

template <typename T>
DataItem<T> *DataItem<T>::set_ptr(DataItem *const new_ptr)
{
	ptr = new_ptr;
	return new_ptr;
}


#endif
