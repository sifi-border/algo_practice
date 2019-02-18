# data_structure

## BIT/フェニック木
- [wiki](https://ja.wikipedia.org/wiki/フェニック木)
- 一点更新、prefixの部分和が`O(logN)`で可能
  - これを利用するとprefixでなくても部分和が`O(logN)`で求まる
- bit[x] に右端が x で長さ x & -x の区間の和をもたせる
  - x & -x で一番右端に立っているbitが求まる
- BIT上で二分探索することでsetのk番目の数が`O(logN)`で求まる
- 最大値についても、一点更新と区間のgetmaxが`O(logN)`で求まる
- **1-indexedなので注意**

## Matrix
- 行列演算用ライブラリ
	- [半環ならok](https://www.hamayanhamayan.com/entry/2017/03/08/160757)
- 単位元に注意
	- 例えば(非負整数,xor,and)なら `plus_base = 0, mul_base = 0b1111111...1`
TODO
- rankを求める
- det(行列式)を求める

## ModStructure
- 俗に言うMod取り構造体
- 代入演算子以外はほぼ網羅している（多分）
- 法とする整数はコンパイル時に決定していないと使えないので注意
- 参考にした提出
	- https://atcoder.jp/contests/dp/submissions/3943361
	- https://atcoder.jp/contests/dp/submissions/3942402
- pが素数である場合、拡張ユークリッドの互除法を用いて逆元が`O(log(x))`で求まる
	- 再帰を使うのが一般的っぽいがtouristのコードを参考にwhileで実装した

## UnionFind/DisjointSet
- 二つの要素が同じ集合に属しているかを`O(α(N))`で判定
	- 経路圧縮+rank（集合の要素の多い方にMerge）

## SBV/簡潔ビットベクトル(作成中...)
- [詳細](http://d.hatena.ne.jp/takeda25/20140201/1391250137#20140201fn5)
- 簡潔データ構造=bit数に比例した空間計算量
	- Nbitだと`N+o(N)`bitのメモリで良い
- rank,selectが`O(1)`

質問・訂正などあれば[@sifi_border](https://twitter.com/sifi_border)までお願いします
