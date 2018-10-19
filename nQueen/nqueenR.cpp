//ちょい早N-QueenSolver

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define Rep(b, e, i) for (int i = b; i <= e; i++)
#define rep(n, i) for (int i = 0; i < n; i++)


long long pattern_count = 0;

void print_board(const vector<int> &board, int N)
{
	rep(N, i)
	{
		rep(N, j) cout << (board[i] == j ? 'o' : 'x');
		cout << endl;
	}
	cout << endl;
}

bool check(const vector<int> &board, int row, int col)
{
	//同じ行
	rep(col, j)
	{
		if (board[j] == row) return false;
	}

	//斜め
	Rep(1, col, j)
	{
		if (board[col-j] + j == board[col] || board[col-j] - j == board[col])
		{
			return false;
		}
	}

	return true;
}

void rec(vector<int> board, int n, int k)
{
	if (k == n)
	{
		pattern_count++;
		//printf("%lld\n", pattern_count);
		//print_board(board, n);
		return;
	}

	rep(n, i)
	{
		vector<int> cand = board;
		cand[k] = i;
		if (check(cand, i, k))
		{
			rec(cand, n, k+1);
		}
	}

	return;
}

void solve(void)
{
	int N;
	cin >> N;

	vector<int> board(N, -1);

	rec(board, N, 0);

	cout << pattern_count << "patterns." << endl;
}

int main(void)
{
	cout << "Solving N-Queen Problem..." << endl;
	solve();
	cout << "yui(*-v・)yui" << endl;
	return 0;
}
