#pragma once
#include <iostream>
using namespace std;

typedef float elemType;

class Matrix
{

	friend Matrix operator+(const Matrix&, const Matrix&);
	friend Matrix operator*(const Matrix&, const Matrix&);
public:
	Matrix(const elemType*);
	Matrix(elemType a11 = 0., elemType a12 = 0., elemType a13 = 0., elemType a14 = 0.,
		elemType a21 = 0., elemType a22 = 0., elemType a23 = 0., elemType a24 = 0.,
		elemType a31 = 0., elemType a32 = 0., elemType a33 = 0., elemType a34 = 0.,
		elemType a41 = 0., elemType a42 = 0., elemType a43 = 0., elemType a44 = 0.);
	int rows() { return 4; }
	int cols() { return 4; }
	ostream& print(ostream&) const;
	void operator+=(const Matrix&);
	elemType operator() (int row, int col) const { return _matrix[row][col]; }            //这里的const就是为了能够重载 operator(), 用()来访问matrix的数据，而不用直接访问成员变量_matrix
	elemType& operator() (int row, int col) { return _matrix[row][col]; }                //返回引用是为了能够当左值,左值可以被修改，故不是const

private:
	elemType _matrix[4][4];
};


inline
ostream& operator<<(ostream& os, const Matrix& m) {
	return m.print(os);
}

ostream& Matrix::print(ostream& os) const {
	for(int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			cout << _matrix[i][j] << " ";
			if (j == 3) os << endl;
		}
	return os;
}

void Matrix::operator+=(const Matrix& m) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			_matrix[i][j] += m._matrix[i][j];
}

Matrix::Matrix(const elemType* array) {
	int array_index = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			_matrix[i][j] = array[array_index++];
}

Matrix::Matrix(elemType a11, elemType a12, elemType a13, elemType a14,
	elemType a21, elemType a22, elemType a23, elemType a24,
	elemType a31, elemType a32, elemType a33, elemType a34,
	elemType a41, elemType a42, elemType a43, elemType a44) {
	_matrix[0][0] = a11; _matrix[0][1] = a12;
	_matrix[0][2] = a13; _matrix[0][3] = a14;
	_matrix[1][0] = a21; _matrix[1][1] = a22;
	_matrix[1][2] = a23; _matrix[1][3] = a24;
	_matrix[2][0] = a31; _matrix[2][1] = a32; 
	_matrix[2][2] = a33; _matrix[2][3] = a34;
	_matrix[3][0] = a41; _matrix[3][1] = a42;
	_matrix[3][2] = a43; _matrix[3][3] = a44;
}

Matrix operator+(const Matrix& m1, const Matrix& m2) {
	Matrix result(m1);                                  //编译器自动提供的默认拷贝构造函数，bit by bit copy
	result += m2;
	return result;
}

Matrix operator*(const Matrix& m1, const Matrix& m2) {
	Matrix result;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			result(i, j) = 0;
			for (int k = 0; k < 4; k++)
				result(i, j) += m1(i, k) * m2(k, j);
		}
	return result;
}