# data_structure

## BIT/フェニック木
- [wiki](https://ja.wikipedia.org/wiki/フェニック木)
- 一点更新、prefixの部分和が`O(logN)`で可能
  - これを利用するとprefixでなくても部分和が`O(logN)`で求まる
- bit[x] に右端が x で長さ x & -x の区間の和をもたせる
  - x & -x で一番右端に立っているbitが求まる
- BIT上で二分探索することでsetのk番目の数が`O(logN)`で求まる
- 最大値についても、一点更新と区間のgetmaxが`O(logN)`で求まる
- **1-indexed**なので注意

質問・訂正などあれば[@sifi_border](https://twitter.com/sifi_border)までお願いします
