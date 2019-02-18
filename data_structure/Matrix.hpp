/*
verified @ https://atcoder.jp/contests/dp/submissions/4317098
verified @ https://atcoder.jp/contests/abc009/submissions/4317492
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template<class T>
struct Matrix
{
	vector<vector<T>> A;

	Matrix(size_t n) : A(n, vector<T>(n, 0)) {}
	Matrix(size_t h, size_t w) : A(h, vector<T>(w, 0)) {}
	Matrix(vector<vector<T>> &X) : A(X) {}

	inline vector<T> &operator[](int idx) {return A[idx];}
	inline const vector<T> &operator[](int idx) const {return A[idx];}

	size_t height() const {return A.size();}
	size_t width()  const {return A[0].size();}

	//ex)auto E = Matrix<int>::E(3);
	static Matrix E(int n)
	{
		Matrix e(n);
		for (int i = 0; i < n; i++) e[i][i] = 1;
		return e;
	}

	Matrix operator+(const Matrix &B) const
	{
		size_t h = this->height(), w = this->width();
		assert(h == B.height() && w == B.width());
		Matrix C(h, w);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				C[i][j] = (*this)[i][j] + B[i][j];
			}
		return C;
	}

	Matrix operator-(const Matrix &B)
	{
		size_t h = this->height(), w = this->width();
		assert(h == B.height() && w == B.width());
		Matrix C(h, w);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				C[i][j] = (*this)[i][j] - B[i][j];
			}
		return C;
	}

	Matrix operator*(const Matrix &B)
	{
		size_t h = this->height(), x = this->width(), w = B.width();
		assert(x == B.height());
		Matrix C(h, w);
		for (size_t i = 0; i < h; i++)
			for (size_t k = 0; k < x; k++)
				for (size_t j = 0; j < w; j++)
				{
					C[i][j] += (*this)[i][k] * B[k][j];
				}
		return C;
	}

	Matrix &operator+=(const Matrix &B) { return (*this) = (*this) + B; }
	Matrix &operator-=(const Matrix &B) { return (*this) = (*this) - B; }
	Matrix &operator*=(const Matrix &B) { return (*this) = (*this) * B; }

	Matrix power(long k)
	{
		auto n = this->height();
		assert(k >= 0 && this->width() == n);
		auto R = Matrix<T>::E(n), C = Matrix(*this);
		while(k)
		{
			if (k&1) R *= C;
			C *= C;
			k >>= 1;
		}
		return R;
	}

	friend ostream &operator<<(ostream &o, const Matrix &A)
	{
		for (int i = 0; i < A.height(); i++)
		{
			for (int j = 0; j < A.width(); j++)
			{
				o << A[i][j] << " ";
			}
			o << endl;
		}
		return o;
	}
};
