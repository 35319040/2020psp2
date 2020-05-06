# 課題4 レポート

bb35319040 藤井英梨花

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
DATEという、id gender heightsをメンバーとした構造体をつくった。
読んだデータを格納するためのpersonという配列を準備した。
heights IDsのファイルをそれぞれ開き、準備した構造体の配列に格納した。
入力した学籍番号がリストにあるかループを利用し、確認する。
あれば、入力した学籍番号に対応する各々を、なければ、no dateと出力されるように実装した。
また、heights.csvにはgender,heights(cm)という文があり、IDs.csvと対応しなくなるので、一行分空読みをした。

## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
input the filename of sample height:../sample/heights.csv
input the filename of sample ID:../sample/IDs.csv
------------------
Which ID's data do you want?:45313125
ID=45313125
gender=FEMALE
height=152.40
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```


## 修正履歴

[comment #20200506]
- OKです．
