# bioinfo

## Mortal Fibonacci
- 寿命が`M`世代で尽きる動物の、`N`世代後までの総数を求める
  - 成人するまでに`1`世代かかり、以降`M-2`世代に渡って子供を産む
  - `M`->`inf`とすると普通のfibonacci
- 愚直にやると時間計算量空間計算量共に`O(NM)`
- これ[tdpcF](https://tdpc.contest.atcoder.jp/tasks/tdpc_semiexp)に似てるな...と気づき
- 結局時間計算量`O(N)`、空間計算量`O(N+M)`解が書けた
  - `N, M <= 10^8`くらいまでなら1秒以内に計算完了
  - 実は世代ごとに計算する必要はなくて、親と子だけ計算すれば良い
  - 親の総数はqueueを使って管理

## Smith-Wateman
- [link](https://en.wikipedia.org/wiki/Smith–Waterman_algorithm)
- 解説追加するかも
- （11/3）[7ma7x](https://github.com/7ma7X)さんにindex周りのミスを指摘していただきました.ありがとうございます.

質問・訂正などあれば[@sifi_border](https://twitter.com/sifi_border)までお願いします
