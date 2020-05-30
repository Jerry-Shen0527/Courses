#ifndef QUEUE
#define QUEUE

#include<cstdlib>
#include<utility>
#include<iostream>

//使用环形队列，稍微繁琐一点。不过这样子手动管理还是要尝试一次。new方法对于realloc没有直接实现，因此采用C风格来写
template<typename T>//只能存储长度已知的数
class Queue
{
public:
	Queue() : head_index(0), tail_index(0), size(0), queue_length(1) { element = (T*)malloc(queue_length * sizeof(T)); }
	~Queue() { free(element); }
	Queue(Queue&);
	Queue(Queue&&) noexcept;
	Queue& operator=(Queue);


	void enqueue(T elem);
	T dequeue();
	size_t get_size() { return size; }
	size_t get_length() { return queue_length; }

	bool empty() { return (!size); }

private:
	T* element;
	int head_index, tail_index;
	size_t size;
	size_t queue_length;
};



template<typename T>
Queue<T>::Queue(Queue& new_queue)
{
	element = (T*)malloc(new_queue.queue_length * sizeof(T));
	head_index = new_queue.head_index;
	tail_index = new_queue.tail_index;
	queue_length = new_queue.queue_length;
	size = new_queue.size;
	for (size_t i = 0; i < queue_length; i++)
	{
		element[i] = new_queue.element[i];
	}//深拷贝，但是会有一些额外的拷贝。有一些元素会在队伍外，可以添加头尾指针先后顺序的判断来提高一点拷贝性能
}

template<typename T>
Queue<T>::Queue(Queue&& new_queue) noexcept
{
	element = new_queue.element;
	head_index = new_queue.head_index;
	tail_index = new_queue.tail_index;
	queue_length = new_queue.queue_length;
	size = new_queue.size;
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue new_queue)
{
	std::swap(element, new_queue.element);
	head_index = new_queue.head_index;
	tail_index = new_queue.tail_index;
	queue_length = new_queue.queue_length;
	size = new_queue.size;

	return *this;
}

template<typename T>
void Queue<T>::enqueue(T item)
{
	if (size == 0)
		element[tail_index] = item;

	tail_index = (tail_index + 1) % queue_length;

	if (size == queue_length)
	{
		element = (T*)realloc(element, 2 * queue_length * sizeof(T));
		for (int i = 0; i < tail_index; i++)
		{
			element[queue_length + i] = element[i];
		}
		tail_index += queue_length;
		queue_length *= 2;
	}

	element[tail_index] = item;
	size++;

}
template<typename T>
T Queue<T>::dequeue()
{
	if (size == 0) {
		std::cerr << "Trying to dequeue an empty queue!" << std::endl;
		return 0;
	}

	size--;
	return element[head_index++];

}




#endif // !INT_QUEUE
