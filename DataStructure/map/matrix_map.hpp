#include<vector>

using std::vector;

class Matrix
{
public:
	Matrix() :head(nullptr), x(0), y(0) {}
	Matrix(int x, int y);
	Matrix(const Matrix& new_matrix) { x = new_matrix.x; y = new_matrix.y; }
	Matrix(const Matrix&& new_matrix) noexcept { x = new_matrix.x; y = new_matrix.y; head = new_matrix.head; }
	Matrix& operator=(Matrix new_matrix) { std::swap(head, new_matrix.head); std::swap(x, new_matrix.x); std::swap(y, new_matrix.y); }
	~Matrix();
	int* operator[](int i) { if(i)return head + x * i; }
private:
	int* head;
	int x, y;
};

Matrix::Matrix(int xx, int yy) :x(xx), y(yy)
{
	head = new int[xx * yy];
}

Matrix::~Matrix()
{
	delete[] head;
}


template<typename T>
class MatrixMap
{
public:

	MatrixMap();
	~MatrixMap();

private:
	int size;
	std::vector<T> data;
	int* matrix;
};

template<typename T>
MatrixMap<T>::MatrixMap()
{
}

template<typename T>
MatrixMap<T>::~MatrixMap()
{
}