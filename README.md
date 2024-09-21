# ★修正が追い付いてないです。最新ファームウェアで使う場合はmsx0.hのIOT_PORTを0x58に修正してください。

# msx-z88dk
<p>z88dkによるクロス開発環境でMSX0のアプリを作って楽しむリポジトリーです。</p>

## ライブラリ
### msx0.h msx0.c
MSX0 StackのIOT命令をC言語から使うための関数群です。
### msx0lcd.h msx0lcd.c
キャラクタLCD(1602)をMSX0から使うための関数群です。
### msx0env.h msx0env.c
温湿度気圧センサー(ENV.III)をMSX0から使うための関数群です。<br>
気圧はまだ対応していません。

## サンプル
### envsampl.c
温湿度気圧センサー(ENV.III)のサンプルプログラムです。<br>
気圧はまだ対応していません。
### lcdsampl
キャラクタLCD(1602)のサンプルプログラムです。
### lcdclock
キャラクタLCD(1602)で時刻を表示するプログラムです。<br>
時刻の取得にはCLOCK-IC(MSX2以降)を使用しています。

## 写真
![sht30](https://github.com/chikuwa-empire/msx-z88dk/assets/124578804/0187934b-fc42-4d12-ac02-f7b6c0664a09)<br>
![1602](https://github.com/chikuwa-empire/msx-z88dk/assets/124578804/089ad95c-2a35-4145-9959-789c79549dee)
