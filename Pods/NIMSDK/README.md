# NIM iOS SDK
[网易云信](http://netease.im)是由网易发布的一款 IM 云服务产品。此仓库是云信 iOS SDK 的发布仓库。

## 使用方法
* 通过  [release](https://github.com/netease-im/NIM_iOS_SDK/releases) 下载相应 SDK 包

* 使用 CocoaPods 集成
  
  * 完整版 : 使用 'pod NIMSDK' 集成。

  * 轻量版(无实时音视频库) : 使用 'pod NIMSDK_LITE' 集成

## 结构
* SDK
  * NIMSDK （IM 模块)
    * Libs (依赖第三方库)
    * NIMSDK.framework (静态库文件)
  * NIMAVChat （音视频模块）
    * Libs (依赖第三方库)
    * NIMAVChat.framework (静态库文件)
  
## 特殊说明

众所周知，iOS 仅支持静态库 (iOS 8 之前)，这导致开发者在集成各种第三方库和 SDK 时常常会碰到符号文件冲突的问题，因为不同的第三方库 和 SDK 常常会依赖相同的库，如几乎所有和安全相关的库都会依赖 openssl。云信为了最大程度地方便上层开发，一方面会尽量避免引入不需要的第三方库，同时也会对一些第三方库进行重命名以保证不出现符号文件冲突的问题。但是由于某些库的特殊性，我们仍不得不原原本本地引入，无法做完整的修改。一种规避的方法是算法同时依赖同一份底层库代码，而这种库将各种第三方库进行分离，也就提供了这一可能性。

举个🌰，在同时使用云信和支付宝 SDK 时，会发生符号文件冲突的问题，原因是它们都依赖了 openssl。解决方案是下载这个仓库文件后，移除 Libs 目录下的 libssl.a 和 libcrypto.a。

