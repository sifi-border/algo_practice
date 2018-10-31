#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 200020;

template<typename T>
struct BIT
{
	int N;
	vector<T> bit;

	BIT (int X)
	{
		bit = vector<T>(X+1, 0);
		N = X+1;
	}

	void add(int idx, T w)
	{
		for (int x = idx; x <= N; x += x&-x)
		{
			bit[x] += w;
		}
	}

	T sum(int idx)
	{
		T res = 0;
		for (int x = idx; x > 0; x -= x&-x) res += bit[x];
		return res;
	}

	void chmax(int idx, T w)
	{
		for (int x = idx; x <= N; x += x&-x)
		{
			bit[x] = max(bit[x], w);
		}
	}


	T getmax(int idx)
	{
		T res = 0;
		for (int x = idx; x > 0; x -= x&-x) res = max(res, bit[x]);
		return res;
	}

};

void solve(void)
{
	//verified ARC033C(https://beta.atcoder.jp/contests/arc033/tasks/arc033_3)

	int Q, T, X;
	cin >> Q;
	BIT<int> bit(MAX);

	while(Q--)
	{
		cin >> T >> X;
		if(T == 1)
		{
			bit.add(X, 1);
		}
		else
		{
			int l = -1, r = MAX, mid = (l+r)/2;
			while(abs(l-r)>1)
			{
				(bit.sum(mid) < X ? l : r) = mid;
				mid = (l+r)/2;
			}
			cout << r << endl;
			bit.add(r, -1);
		}
	}

}

int main(void)
{
	solve();
 	return 0;
}
