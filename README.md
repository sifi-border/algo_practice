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

## Gochiusaじゃんけん
- [link](https://jyanken.kirarafantasia.com/game)
### 概要
- 香風智乃さん(以下chinoとする)と6回じゃんけんをする
- はじめにグーチョキパー(以下RSPとする)のいづれかが書かれたカードが6枚配られ、その中から一枚選んでじゃんけん
	- player（宮子、なでしこ、唯）の手札はRRSSPP,chinoの手札はRRRSSP
	- 使ったカードはもう戻らない
- playerのみ**3回**手持ちのカードを好きなカードに交換できる
- 6回のうち勝った回数に応じてplayerの満腹ゲージが溜まって、100%にするときららファンタジア内で報酬がもらえる
### 注釈
- chinoちゃんの手はrandomに決まるとした。
	- 「次のじゃんけんで勝率が最も高くなる」ような手を出す戦略(RRSvsRSPでPなど)ではないっぽい...
	- もっと高度な戦略かもしれません
### DONE
- モンテカルロでシュミレートしたところ、playerもランダムに手を出すとした時...
	- 6回のうち勝つ回数の期待値は二人とも$2$回程度
	- chinoに勝ち越す確率（つまり6回のうちより多く勝つ確率）は$0.6$程度っぽい
### TODO
- 3回の手札入れ替えを実装
- dpで最適化
- DQN

## bioinfo
bioinfoっぽい題材の問題とかアルゴリズムとか
- Mortal Fibonacci
- Smith–Waterman algorithm

## data_structure
競技プログラミングで使うデータ構造とか
- BIT(Binary Indexed Tree)
- SBV(Succinct Bit Vector)


質問・訂正などあれば[@sifi_border](https://twitter.com/sifi_border)までお願いします
