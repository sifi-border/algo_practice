# algo"rhythm"
## N-Queen Solver
- [8Queen](https://ja.wikipedia.org/wiki/エイト・クイーン)を一般化したやつ
- Queenの置き方の総数を出力（回転、鏡像は区別していない）
- nqueen.cppとnqueenR.cppではアルゴリズムは一緒
  - 今見ている列にひとつずつQueenを置いていき、`check`関数で`true`が帰って来れば再帰で次の列を埋めていく
- nqueen.cppは愚直に`vector<string>`を書き換えているので遅い
- nqueenR.cppではその反省を生かし一次元配列`vector<int>`を用いて、i番目の要素を「i列には何行目にQueenがいるか」に対応させた
  - 結果`check`関数での斜め方向のcheckも実装が楽になった
  - `board[i-j] != i-j`と`board[i-j] != i+j`を見るだけなので
### 課題
- 高速化（今だと`N<=13`が限界なので）
- 回転・鏡像の判定の実装
- 関数型言語での実装
- Nを横軸に実行時間をplot

## bioinfo
bioinfoっぽい題材の問題とかアルゴリズムとか
- Mortal Fibonacci
- Smith–Waterman algorithm

## data_structure
競技プログラミングで使うデータ構造とか
- BIT(Binary Indexed Tree)
- SBV(Succinct Bit Vector)


質問・訂正などあれば[@sifi_border](https://twitter.com/sifi_border)までお願いします
