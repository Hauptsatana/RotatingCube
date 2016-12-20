#pragma once
#include "matrix.h"

// Вектор-строка
template<class T, int m>
class VectorH : public Matrix<T, 1, m> {

public:

	VectorH() : VectorH(0) {}
	VectorH(T value) : Matrix(value) {}
	VectorH(const VectorH<T, m>& vector) : Matrix<T, 1, m>(vector) {}
	VectorH(const Matrix<T, 1, m>& matr) : Matrix<T, 1, m>(matr) {}

	// Доступ к элементам
	const inline T get(int index) const {
		return Matrix<T, 1, m>::get(0, index);
	}
	inline void set(int index, T value) {
		Matrix<T, 1, m>::set(0, index, value);
	}

	// Добавление элемента в конец
	VectorH<T, m + 1>* addItem(const T item) const {
		VectorH<T, m + 1>* res = new VectorH<T, m + 1>();
		for (int i = 0; i < m; i++) {
			res->set(i, this->data[i]);
		}
		res->set(m, item);
		return res;
	}
};