#ifndef NODE
#define NODE

template<typename T>
class TreeNode
{
public:
	TreeNode(TreeNode* nleft = nullptr, TreeNode* nright = nullptr) :data{ 0 },  left(nleft), right(nright), thread(0) { }
	TreeNode(const T& in_data, TreeNode* nleft = nullptr, TreeNode* nright = nullptr) :data(in_data), left(nleft), right(nright), thread(0) {  }
	~TreeNode() {}

	TreeNode* get_left();
	TreeNode* get_right();

	TreeNode* set_left(TreeNode*);
	TreeNode* set_right(TreeNode*);

	bool is_thread() { return thread; }
	bool set_thread(bool n) { return thread = n; }

private:
	T data;
	TreeNode* left;
	TreeNode* right;
	bool thread;

};

template<typename T>
inline TreeNode<T>* TreeNode<T>::get_left()
{
	return left;
}

template<typename T>
inline TreeNode<T>* TreeNode<T>::get_right()
{
	return right;
}

template<typename T>
inline TreeNode<T>* TreeNode<T>::set_left(TreeNode* node)
{
	return left = node;
}

template<typename T>
inline TreeNode<T>* TreeNode<T>::set_right(TreeNode* node)
{
	return right = node;
}
#endif // !node