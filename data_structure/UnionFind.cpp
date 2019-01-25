#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

struct unionfind
{
	//rankのオーバーフローに注意
	vector<int> par, rank;
	unionfind(int n)
	{
		par.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i++)
		{
			par[i] = i;
			rank[i] = 1;
		}
	}

	bool same(int u, int v)
	{
		return root(u) == root(v);
	}

	void unite(int u, int v)
	{
		if (same(u, v)) return;
		u = root(u), v = root(v);
		if (rank[u] > rank[v]) swap(u, v);
		par[u] = v;
		rank[v] += rank[u];
	}

	int root(int v)
	{
		if (par[v] == v) return v;
		return par[v] = root(par[v]);
	}
};

//verified at https://atc001.contest.atcoder.jp/tasks/unionfind_a

void solve()
{
	int N, Q;
	cin >> N >> Q;
	unionfind uf(N);
	while (Q--)
	{
		int p, a, b;
		scanf("%d%d%d", &p, &a, &b);
		if (p)
		{
			printf("%s\n", uf.same(a, b) ? "Yes" : "No");
		}
		else
		{
			uf.unite(a, b);
		}
	}
}

int main(void)
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
