/*
* SuccinctBitVector
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

struct SBV
{
	//N:bitの長さ
	const uint64_t N;
	//uint64_tでbitを持つので,要素数はceil(n/64)でよい
	const uint64_t N_block_sz = 64;

	const uint32_t log2ofN = log(N) / log(2);

	//Rl,Rsのsize
	const uint32_t L_sz = log2ofN * log2ofN;
	const uint32_t S_sz = log2ofN / 2;
	const uint32_t L_block_sz = N / L_sz + 1;
	const uint32_t S_block_sz = N / S_sz + 1;

	//rank,selectを使う前に前処理をしておかないといけない
	bool preproisdone = 0;

	vector<uint64_t> Bit, RL, RS;

	explicit SBV(uint64_t n) : N(n)
	{
		RL.assign(L_block_sz, 0);
		RS.assign(S_block_sz, 0);
		Bit.assign((N + N_block_sz - 1) / N_block_sz + 1, 0);
	}

	//Bit[pos]のbitを指定
	void bitmake(uint64_t b, uint64_t pos)
	{
		assert((b == 0 || b == 1) && pos < N);
		uint64_t mask = 1ULL<<(pos%N_block_sz);
		if (b & 1ULL)
		{
			Bit[pos/N_block_sz] |= mask;
		}
		else
		{
			Bit[pos/N_block_sz] &= ~mask;
		}
	}

	//Bit[pos]のbitを返す
	uint64_t bittake(uint64_t pos)
	{
		assert(pos < N);
		return Bit[pos/N_block_sz] >> (pos%N_block_sz) & 1ULL;
	}

	//前計算
	void dicmake()
	{
		uint64_t bitcount = 0ULL, Rs_count = 0ULL;
		for (uint64_t p = 0; p < N; p++)
		{
			if (p % L_sz == 0)
			{
				RL[p / L_sz] = bitcount;
			}
			if (p % S_sz == 0)
			{
				RS[p / S_sz] = Rs_count;
				Rs_count = 0ULL;
			}
			if (bittake(p))
			{
				bitcount++;
				Rs_count++;
			}
		}
		preproisdone = 1;
	}

	uint64_t popcount(uint64_t x)
	{
		x = (x & 0x5555555555555555ULL) + ((x & 0xAAAAAAAAAAAAAAAAULL)>>1);
		x = (x & 0x3333333333333333ULL) + ((x & 0xCCCCCCCCCCCCCCCCULL)>>2);
		x = (x & 0x0F0F0F0F0F0F0F0FULL) + ((x & 0xF0F0F0F0F0F0F0F0ULL)>>4);

		return (x * 0x0101010101010101ULL) >> 56;
	}

	//rank[0,pos)
	uint64_t rank(uint64_t b, uint64_t pos)
	{
		uint64_t p = pos-1;
		assert((b == 0 || b == 1) && p < N && preproisdone);
		//多分違っている
		uint64_t res = RL[p/L_sz] + RS[p/S_sz] + popcount(Bit[p/N_block_sz] << (S_sz-(p%S_sz)-1));
		if (b == 0) res = p-res+1;
		return res;
	}




};

int main(void)
{
	SBV sbv(1<<8);
	sbv.bitmake(1,1);
	sbv.bitmake(1,1<<7);
	sbv.dicmake();
	cout << sbv.rank(0,1<<8) << endl;
	return 0;
}
