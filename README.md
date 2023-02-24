# STAB_Arduino

PlatformIOのUnit testをNativeで実行するときに使うArduino.hのスタブ

## 概要

PlatformIOでユニットテストするときにPC上でテストしたい。
その時に時刻やセンサー類をスタブで接続し状態をPC上で模擬をしたい場面があった。
そのためこのプロジェクトを作成した。


## 使い方

* 本レポジトリをlibフォルダに格納してください。「Arduino.h」が競合する場合がありますのでご留意ください。
  * https://github.com/MasterAkari/STAB_Arduino

* test用のenv設定を実施してください。

```ini
[env:test_native]
platform = native
test_build_src = true
platform_packages =
    tool-cppcheck@1.260.0
check_tool = cppcheck
check_flags = --enable=all
```

* PlatformIOの"Advanced"からTest/Checkが使用可能になります。

## その他

### ライセンス

Stringクラスは別ライブラリから借用中
