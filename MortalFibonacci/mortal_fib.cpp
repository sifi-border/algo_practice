/*
mortal fibonacci

input N, M
output 寿命がM世代で尽きる動物の、N世代後の総数

time computational complexity　O(N)Solver

long long でも余裕で桁が溢れるのでMOD1000000007上で計算した方が現実味ある？
*/

#include <iostream>
#include <vector>
#include <queue>

#define rep(n, i) for (int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

void solve(void)
{
	int N, M;
	cin >> N >> M;

	//dpメモ
	vector<ll> dp(N, 0);
	//生存している親を世代毎に管理
	queue<ll> q;
	//生存している親の総数（qの要素の総和）
	ll parents = 0LL;

	//最初は子供が一羽
	dp[0] = 1LL;

	rep(N-1, n)
	{
		//n世代目の子供はn+1世代目で親になる
		ll children = dp[n] - parents;
		q.push(children);
		//n+1世代目の親はn世代目の子供の分増えて、寿命がきた親の分減る
		//n+1世代目の総数はn世代目の総数に加えて、n世代目の親の分（子供が生まれるので）増えて、寿命がきた親の分減る
		if ((int)q.size() >= M)
		{
			dp[n+1] = dp[n] - q.front() + parents;
			parents += children - q.front();
			q.pop();
		}
		else
		{
			dp[n+1] = dp[n] + parents;
			parents += children;
		}
	}

	cout << dp[N-1] << endl;

}

int main(void)
{
	cout << "Solving Mortal Fibonacci Rabbits..." << endl;
	solve();
	cout << "yui(*-v・)yui" << endl;
	return 0;
}
