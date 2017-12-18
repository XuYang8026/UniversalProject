
## 最近更新
已对iOS11 & iPhone X 适配, 适配参考：[10分钟适配 iOS 11 & iPhone X](http://www.jianshu.com/p/94d3fdc0f20d)
###### 欢迎各路大神小白加群  iOS 超级码农交流群：538549344

## 源码下载
建议在此页面直接下载，若网络不佳屡次失败，可尝试通过百度云下载地址下载：[源码下载](https://pan.baidu.com/s/1nv88S0x)
#

## 简介
`UniversalProject`是基于MVC架构的iOS轻量级框架，封装了各种基类、基于猿题库YTKNetwork的网络服务、工具库，基于NavigationController的瀑布流/转场动画/粒子动画以及常用功能demo，已适配iOS11 & iPhone X。欢迎交流 & Star🌟 

原文传送门 http://www.jianshu.com/p/d553096914ff
#

## iOS 从0到1搭建高可用App框架

    最近在搭建新项目的iOS框架，一直在思考如何才能搭建出高可用App框架，能否避免后期因为代码质量问题的重构。
    以前接手过许多“烂代码”，架构松散，底层混乱，缺少规范，导致团队开发时代码风格迥异，
    清晰的项目结构和良好的代码规范是保证产品质量的关键，
    下面分享一下我的架构思路。


## 效果图：

<div align=center><img width="375" height="667" src="https://github.com/XuYang8026/UniversalProject/blob/master/Gif/demo.gif"/></div>


## 架构图：

<div align=center><img src="http://upload-images.jianshu.io/upload_images/743749-077e818f4b5f9f6e.png?imageMogr2/auto-orient/strip"/></div>

架构原则：易读性、易维护性、易扩展性。

## 一、思考

做好一件事，花在思考上的时间应该多于执行。

首先根据产品需求和设计图，脑中先建立一个产品架构：

1. 产品的定位是什么。

社交？媒体？游戏？运动？音视频？电商……要搞清楚你要做一个什么类型的App，不同类型的产品，技术选型也有所不同，在这我是搭建一个基础App架构，可以在此基础上拓展社交、电商、音视频等！

2. 技术选型

根据当前产品的需求以及未来可能有的需求（我怎么知道未来会有什么需求？可以参照竞品，可以发挥想象，如果产品说：“我们要做IM文字聊天，只做文字！不做音视频，以后都不做！” 类似这样的承诺，你如果信了他的邪……后面的故事就精彩了。。哈哈哈哈哈哈。。。。所以说这时候你就要考虑到后面会有语音+视频聊天，在设计的时候不要偷懒，预留一定空间，当某天产品反悔的时候，你可以微微一笑，从容应对。

一把拉回话题，接着说技术选型，通常我会选择一些当下比较热门、好用的第三方框架，例如：YYKit ，YYKit 是一组庞大、功能丰富的 iOS 组件，包含Model解析、图片加载、缓存等基础服务，都是基于Category设计的，使用方便且性能高于一些老的框架，用过的都说好。

其他框架的选择可以根据项目需求，去GitHub上搜索，星星多的每个都看一下，会给你增加一些思路。

程序猿长得可以保守，思想一定不能太保守。

## 二、搭建目录结构

![image](http://upload-images.jianshu.io/upload_images/743749-5eec25e5a69c7138.jpg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

目录图解
如上图，我是这样搭建App目录结构的，从下到上，使用Pods管理第三方框架，将第三方框架进行二次封装，供给顶层使用，尽可能减少各模块之间的耦合度，只为更清晰。

## 三、封装基础类

![image](http://upload-images.jianshu.io/upload_images/743749-f88f1bf3414b0d65.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


1. AppDelegate是应用的代理，应用级的事件都委托它处理，包含启动退出、推送等事件，以及IM、支付等第三方的回调，这使得AppDelegate内代码庞大，错综复杂，十分不利于阅读和维护，因此我新增了一个AppDelegate+AppService类别，用来处理生命周期之外的业务，AppDelegate作为事件入口，具体实现直接调用类别里的方法，只为更清晰。



![image](http://upload-images.jianshu.io/upload_images/743749-49f4c9f96e3d50fa.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
2. Modules包含了应用内的功能模块，根据底部Tab栏划分并关联实体文件夹（默认是虚拟的要手动建立实体文件夹拖进来），每个模块内使用的是MVC模式，有人会问为什么多了Resource和Service文件夹，MVC是一种设计思想，并非死套路就仨文件夹，根据实际需求适当增加，在这我选择在Service封装数据请求，VC里调用拿数据即可，至于Resource为什么在这，我认为当功能模块层级较多时，每个大功能模块都对应许多资源，对应到模块内用起来方便，当然也可以放到最外层的Resource文件夹里，建立对应的模块名称，在这儿我是选择把公共的放到最外层Resource里，功能相关的放到模块里的Resource文件夹内，只为更清晰。




![image](http://upload-images.jianshu.io/upload_images/743749-2480121eaccecc3c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
3. Manager的定义是全局基础服务，通常使用类方法或者单例来实现，主要包含对应用、用户的管理和服务，例如网络状态监听，广告页应用介绍页等；用户快速登录退出操作以及登录状态的获取等。只为更清晰。




![image](http://upload-images.jianshu.io/upload_images/743749-dd03de0737474c9b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
4. Utils文件夹内主要包含全局通用工具，来源于对三方框架的二次封装，或是自己写的工具类。在这个项目里，我封装了带AES加密网络请求工具，全局Toast提示，广告页等。只为更清晰。





![image](http://upload-images.jianshu.io/upload_images/743749-116d59c9061d2495.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
5. Base文件夹用来存放项目的基类，基类作用包含一些定制化的内容，例如页面样式，空数据页面等，使用基类来实现，可以统一控制，利于维护，减少冗余，也为更清晰。





![image](http://upload-images.jianshu.io/upload_images/743749-e70733d5f2138425.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
6. 第三方文件夹放一些第三方的类库和对第三方封装，比如第三方登录、支付、IM等，现在项目我还没有添加第三方框架。

7.全局宏顾名思义是定义了一些全局通用宏。我这里定义了四个：

UtilsMacros定义的是一些工具宏，比如获取屏幕宽高，系统版本，数据类型验证等；

URLMacros定义服务器接口地址以及环境开关；

FontAndColorMacros定义全局用的色值、字体大小，这里建议跟设计师共同维护一个设计规范，例如：定义一个主色调宏 MainColor，色值是 0x333333，我们全局使用MainColor宏作为背景颜色，当某天App改版，色值改变，我们只需要去更改 0x333333即可，其他代码不需要动，同时也能一定程度约束设计师，不要随便增加一种颜色，非常接近的颜色应当使用一个。如果设计师不愿意维护这个规范，你可以尝试打一架，打不过的话，就只能自己维护了，只为更清晰。

ThirdMacros 包含第三方框架相关的定义，例如keySecret等。只为更清晰。





![image](http://upload-images.jianshu.io/upload_images/743749-93424ab96e246b60.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
8. 资源文件，上面说到过，这里我是存放了全局的一些资源文件，功能模块的我放到了模块内的Resource文件夹内，个人喜好，只为更清晰。



![image](http://upload-images.jianshu.io/upload_images/743749-5a0d548626865465.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
9. CocoaPods是iOS项目的依赖管理工具，开发iOS项目不可避免地要使用第三方开源库，CocoaPods的出现使得我们可以节省设置和第三方开源库的时间。



本文只是阐述本人近期架构的出发点和整体思路，代码的具体实现没有细说，感兴趣的可以下载源码阅读

欢迎各路大神提出更好的架构思想大家一起学习交流

## 下面对你也许有帮助：

[Xcode 9 快速跳转到定义新姿势（Jump to Definition）](http://www.jianshu.com/p/9c81e9de272b)

[适配iOS11 - UITableview UICollectionView MJRefresh下拉刷新错乱](http://www.jianshu.com/p/a6e5cc20a008)

[10分钟适配 iOS 11 & iPhone X](http://www.jianshu.com/p/94d3fdc0f20d)

[iOS 团队编码规范 —— 团队开发需要共同遵守的代码规范](http://www.jianshu.com/p/1f0618a2ba9b)

[代码注释，教你用快捷键+代码块实现快速注释 —— 让注释不再是负担，快捷键帮你解决](http://www.jianshu.com/p/78b8693d87cd)

[通用工具类宏定义 —— 进一步提升编码效率](http://www.jianshu.com/p/2c55fcfeecb5)

以上属于臭码农原创，若有雷同属巧合，如有错误望指正，转载请标明来源和作者。

简书地址：http://www.jianshu.com/p/d553096914ff

by：臭码农
