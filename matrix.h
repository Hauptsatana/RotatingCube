#pragma once
#include <assert.h>

// ���������� ��� �������� ��������� template �� .h � .cpp
// ������� ���������� ���������� � .h

// n - ����� �����, m - ����� ��������
template <class T, int n, int m>
class Matrix {

private:
	int check(int row, int column) const {
		assert(row >= 0 && row < n && column >= 0 && column < m);
		return row * n + column;
	}

protected:
	T* data = new T[n*m];
	
	T safeGet(int row, int column) {
		return data[row * n + column];
	}

public:
	// ������� �������
	Matrix() : Matrix(0) {}
	// ���������� ������������ ���������
	Matrix(T value) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				data[i * n + j] = value;
			}
		}
	}
	// ���������� ����������� - ����� ������� � �������
	Matrix(const Matrix<T, n, m>& matr) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				data[i * n + j] = matr.data[i * n + j];
			}
		}
	}
	// ���������� - ������� ������ �� ������
	~Matrix() {
//		delete[] data;
	}

	// ������ � ���������
	inline T get(int row, int column) const {
		return data[check(row, column)];
	}
	inline void set(int row, int column, T value) {
		data[check(row, column)] = value;
	}

	// ��������� ������
	template <int q>
	const Matrix<T, n, q> operator* (const Matrix<T, m, q>& right) const {
		Matrix<T, n, q> res;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < q; j++) {
				double sumProd = 0;
				for (int k = 0; k < m; k++) {
					sumProd += this->get(i, k) * right.get(k, j);
				}
				res.set(i, j, sumProd);
			}
		}
		return res;
	}

	template <int q>
	Matrix<T, n, q>& operator*= (const Matrix<T, m, q>& right) {
		Matrix<double, n, q> res = (*this) * right;
		this = &res;
		return res;
	}
};