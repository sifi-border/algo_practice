#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const string base = "ATCG";

int basemapping(char c)
{
	if (c == 'A') return 0;
	if (c == 'T') return 1;
	if (c == 'C') return 2;
	if (c == 'G') return 3;
	return -1;
}

//fasta formatで与えられたstrandを返す関数
string readg()
{
	string res = "";

	char nowc;

	while(~scanf("%c\n", &nowc))
	{
		if (nowc == '>') break;
		if (basemapping(nowc) >= 0) res.push_back(nowc);
	}

	return res;
}

void solve(void)
{

	string s1, s2, ns;

	//入力はfasta formatで与えられているとする
	cin >> ns;
	s1 = readg();
	cin >> ns;
	s2 = readg();

	cout << s1 << endl << s2 << endl;

	//二本のstrandの長さ
	int l1 = s1.size(), l2 = s2.size();
	//scoreを格納する二次元配列、０で初期化
	vector<vector <int> > aliscore(l1+1, vector<int>(l2+1, 0));
	//配列中の最高スコア
	int max_score = 0;

	for (int i = 0; i <= l1; i++) for (int j = 0; j <= l2; j++)
	{
		if (i == 0 || j == 0)
		{
			continue;
		}
		int res = 0;
		res = max(res, aliscore[i-1][j-1] + (s1[i-1] == s2[j-1] ? 3 : -4));
		res = max(res, aliscore[i][j-1] - 5);
		res = max(res, aliscore[i-1][j] - 5);
		aliscore[i][j] = res;
		max_score = max(max_score, res);
	}

	cout << max_score << endl;

	int ni = -1, nj = -1;

	for (int i = l1; i >= 0; i--) for (int j = l2; j >= 0 ; j--)
	{
		if (aliscore[i][j] == max_score)
		{
			ni = i, nj = j;
			//loopを抜ける
			i = -1, j = -1;
			break;
		}
	}

	string ans = "";

	while(aliscore[ni][nj] > 0)
	{
		if (s1[ni] == s2[nj] || aliscore[ni][nj] == aliscore[ni-1][nj-1] - 4)
		{
			ans.push_back(s1[ni]);
			ni--;
			nj--;
			continue;
		}
		if (aliscore[ni][nj] == aliscore[ni][nj-1] - 5)
		{
			nj--;
			continue;
		}
		if (aliscore[ni][nj] == aliscore[ni-1][nj] - 5)
		{
			ni--;
			continue;
		}
	}

	reverse(ans.begin(), ans.end());

	cout << ans << endl;

}

int main(void){
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
