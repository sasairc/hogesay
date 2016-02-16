hogesay
===

xxxsayの簡単なテンプレート。		
基本的な仕様は[yasuna](https://github.com/sasairc/yasuna)に準じます。

## Require settings

### ./Makefile

`TARGET`変数に指定された値がプログラムの実行ファイル名になります。		
加えて、`$(TARGET)-quotes`が標準の辞書ファイル名、`_$(TARGET).zsh`がzsh用補完ファイル名です。


### ./src/config.h

以下は`--help`や`--version`を指定した場合の情報及び、連絡先を設定する定数です。

```c
#define PROGNAME        ""
#define DESCRIPTION     ""

#define VERSION         0
#define PATCHLEVEL      0
#define SUBLEVEL        0
#define EXTRAVERSION    ""

#define AUTHOR          ""
#define MAIL_TO         ""
```


### ./quotes/*-quotes

`$(TARGET)-quotes`として辞書ファイルを配置して下さい。		
フォーマットはベタ書きと[polyaness辞書ファイル標準仕様](https://github.com/844196/polyaness/blob/master/dictionary_spec.md)をサポートしています。

## License

`polyaness.{c,h}`は[MIT](https://raw.githubusercontent.com/sasairc/libpolyaness/master/LICENSE)、他は[WTFPL version 2](http://www.wtfpl.net/txt/copying/)です。		
名称の通り、コードの改変や再頒布、好きなライセンスへの変更等、自由に使って頂いて構いません。
