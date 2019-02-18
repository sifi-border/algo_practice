#include <iostream>
#include <cassert>

using namespace std;

template <int p>
struct Modint
{
	int value;

	Modint() : value(0) {}
	Modint(long x) : value(x >= 0 ? x % p : (p + x % p) % p) {}

	inline Modint &operator+=(const Modint &b)
	{
		if ((this->value += b.value) >= p) this->value -= p;
		return (*this);
	}
	inline Modint &operator-=(const Modint &b)
	{
		if ((this->value += p - b.value) >= p) this->value -= p;
		return (*this);
	}
	inline Modint &operator*=(const Modint &b)
	{
		this->value = (int)((1LL * this->value * b.value) % p);
		return (*this);
	}
	inline Modint &operator/=(const Modint &b)
	{
		(*this) *= b.inverse();
		return (*this);
	}

	Modint operator+(const Modint &b) const { return Modint(*this) += b; }
	Modint operator-(const Modint &b) const { return Modint(*this) -= b; }
	Modint operator*(const Modint &b) const { return Modint(*this) *= b; }
	Modint operator/(const Modint &b) const { return Modint(*this) /= b; }

	inline Modint &operator++(int) { return (*this) += 1; }
	inline Modint &operator--(int) { return (*this) -= 1; }

	inline bool operator==(const Modint &b) const { return this->value == b.value; }
	inline bool operator!=(const Modint &b) const { return this->value != b.value; }
	inline bool operator<(const Modint &b) const { return this->value < b.value; }
	inline bool operator<=(const Modint &b) const { return this->value <= b.value; }
	inline bool operator>(const Modint &b) const { return this->value > b.value; }
	inline bool operator>=(const Modint &b) const { return this->value >= b.value; }

	//requires that "this->value and p are co-prime"
	// a_i * v + a_(i+1) * p = r_i
	// r_i = r_(i+1) * q_(i+1) * r_(i+2)
	// q == 1 (i > 1)
	// reference: https://atcoder.jp/contests/agc026/submissions/2845729 (line:93)
	inline Modint inverse() const
	{
		assert(this->value != 0);
		int r0 = p, r1 = this->value, a0 = 0, a1 = 1;
		while (r1)
		{
			int q = r0 / r1;
			r0 -= q * r1;
			swap(r0, r1);
			a0 -= q * a1;
			swap(a0, a1);
		}
		return Modint(a0);
	}

	friend istream &operator>>(istream &is, Modint<p> &a)
	{
		long t;
		is >> t;
		a = Modint<p>(t);
		return is;
	}
	friend ostream &operator<<(ostream &os, const Modint<p> &a)
	{
		return os << a.value;
	}
};

/*
verified @ https://atcoder.jp/contests/abc034/submissions/4316971
*/

const int MOD = 1e9 + 7;

using Int = Modint<MOD>;

int main(void)
{
	Int ans(1), W, H;
	cin >> W >> H;
	W--, H--;

	for (Int i(2); i <= W + H; i++)
	{
		ans *= i;
	}
	for (Int i(2); i <= W; i++)
	{
		ans /= i;
	}
	for (Int i(2); i <= H; i++)
	{
		ans /= i;
	}
	cout << ans << endl;

	return 0;
}
