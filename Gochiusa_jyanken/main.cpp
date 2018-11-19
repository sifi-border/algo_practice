//https://jyanken.kirarafantasia.com/game
#include <iostream>
#include <random>
#include <vector>
#include <cassert>

using namespace std;

//メルセンヌツイスターで一様乱数を生成
random_device seed_gen;
mt19937 mt(seed_gen());

struct player
{
	//残り手札の枚数
	int res;
	//残り手札(6bitで表す)
	int hand;
	//勝つと+1,それ以外は0
	int score;
	//初期カード
	string cards;

	player (string init_card)
	{
		res = 6;
		hand = (1<<7)-1;
		score = 0;
		cards = init_card;
	}

	void reset()
	{
		res = 6;
		hand = (1<<7)-1;
		score = 0;
	}

	void print_hand()
	{
		int b = hand;
		for (int i = 0; i < 6; i++)
		{
			printf("%d", b&1);
			b >>= 1;
		}
		printf("\n");
	}

	char choose_card()
	{
		assert(res > 0);

		//下から何番目のbitか
		int r = mt()%res, idx = -1;

		for (int i = 0; i < 6; i++)
		{
			if (hand>>i & 1)
			{
				if (r == 0)
				{
					idx = i;
					break;
				}
				r--;
			}
		}

		assert(idx >= 0 && hand>>idx & 1);

		int mask = ((1<<7)-1)^(1<<idx);

		hand &= mask;

		res--;

		return cards[idx];

	}

};

void judge(player& p, player&q)
{
	assert(p.res > 0 && p.res == q.res);

	char ph = p.choose_card(), qh = q.choose_card();

	//printf("%c vs %c\n", ph, qh);

	if (ph == qh) return;
	else if (ph - qh == 'R' - 'S' || ph - qh == 'S' - 'P' || ph - qh == 'P' - 'R') p.score++;
	else q.score++;

	return;

}

void restart(player& p, player&q)
{
	p.reset();
	q.reset();
	return;
}

int main(void)
{
	//Rock, Scissors, Paper
	player sifi_border("RRSSPP"), chino("RRRSSP");

	//chino.print_hand();

	int N = 100000;

	double sum = 0, sum2 = 0;
	int cnt = 0;

	for (int l = 0; l < N; l++)
	{
		restart(sifi_border, chino);
		for (int i = 0; i < 6; i++)
		{
			judge(sifi_border, chino);
		}
		sum += sifi_border.score;
		sum2 += chino.score;
		cnt += sifi_border.score > chino.score;
	}

	printf("sifi_border:%lf\n", sum / N);
	printf("chino:%lf\n", sum2 / N);
	printf("win:%d\n", cnt);

	/*output
	sifi_border:1.997080
	chino:2.000190
	win:60059
	*/

	return 0;
}
