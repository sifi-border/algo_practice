//激遅N-QueenSolver

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define rep(n, i) for (int i = 0; i < n; i++)


long long score = 0;

void print_board(const vector<string> &board, int N)
{
	rep(N, i)
	{
		rep(N, j) cout << board[i][j];
		cout << endl;
	}
	cout << endl;
}

bool check(const vector<string> &board, int n, int row, int col)
{
	//同じ行
	rep(n, j)
	{
		if (j != col && board[row][j] == 'o') return false;
	}

	int sch = 1, j = col-row;
	//斜め
	rep(n, i)
	{
		if (i == row)
		{
			sch = -1;
			j += sch;
			continue;
		}
		if (j < 0)
		{
			if (sch == -1) break;
			i = i - j - 1;
			j = 0;
			continue;
		}
		if (board[i][j] == 'o') return false;
		j += sch;
	}

	return true;
}

void dfs(vector<string> board, int n, int k)
{
	if (k == n)
	{
		score++;
		//printf("%lld\n", score);
		//print_board(board, n);
		return;
	}

	rep(n, i)
	{
		vector<string> cand = board;
		cand[i][k] = 'o';
		if (check(cand, n, i, k))
		{
			dfs(cand, n, k+1);
		}
	}

	return;
}

void solve(void)
{
	int N;
	cin >> N;

	vector<string> board(N);

	rep(N, i) rep(N, j) board[i].push_back('x');

	dfs(board, N, 0);

	cout << score << "patterns." << endl;
}

int main(void)
{
	cout << "Solving N-Queen Problem." << endl;
	solve();
	cout << "yui(*-v・)yui" << endl;
	return 0;
}
