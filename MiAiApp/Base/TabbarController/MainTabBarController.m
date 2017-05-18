//
//  MainTabBarController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "MainTabBarController.h"

#import "RootNavigationController.h"
#import "HomeViewController.h"
#import "MakeFriendsViewController.h"
#import "MsgViewController.h"
#import "MineViewController.h"

@interface MainTabBarController ()<tabbarDelegate>


@end

@implementation MainTabBarController

- (void)viewDidLoad {
    [super viewDidLoad];
    //初始化tabbar
    [self setUpTabBar];
    
    //添加子控制器
    [self setUpAllChildViewController];

}
//取出系统自带的tabbar并把里面的按钮删除掉
-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:YES];
    for ( UIView * child in  self.tabBar.subviews) {
        
        if ([child isKindOfClass:[UIControl class]]) {
            [child removeFromSuperview];
        }
    }
}

-(void)setUpTabBar{
    TabBar *customTabBar = [[TabBar alloc]init];
    customTabBar.delegate = self;
    //    customTabBar.backgroundColor = [UIColor redColor];
    customTabBar.frame = self.tabBar.bounds;
    self.costomTabBar = customTabBar;
    [self.tabBar addSubview:customTabBar];
    
}
-(void)tabBar:(TabBar *)tabBar didselectedButtonFrom:(int)from to:(int)to{
    NSLog(@"%d, %d", from, to);
    self.selectedIndex = to;
    NSLog(@"%lu", (unsigned long)self.selectedIndex);
    
}

-(void)setUpAllChildViewController{
    HomeViewController *homeVC = [[HomeViewController alloc]init];
    [self setupChildViewController:homeVC title:@"首页" imageName:@"icon_tabbar_homepage" seleceImageName:@"icon_tabbar_homepage_selected"];
    
    MakeFriendsViewController *makeFriendVC = [[MakeFriendsViewController alloc]init];
    [self setupChildViewController:makeFriendVC title:@"交友" imageName:@"icon_tabbar_onsite" seleceImageName:@"icon_tabbar_onsite_selected"];
    
    MsgViewController *msgVC = [[MsgViewController alloc]init];
    [self setupChildViewController:msgVC title:@"消息" imageName:@"icon_tabbar_merchant_normal" seleceImageName:@"icon_tabbar_merchant_selected"];
    
    MineViewController *mineVC = [[MineViewController alloc]init];
    [self setupChildViewController:mineVC title:@"我的" imageName:@"icon_tabbar_mine" seleceImageName:@"icon_tabbar_mine_selected"];
    
}

-(void)setupChildViewController:(UIViewController*)controller title:(NSString *)title imageName:(NSString *)imageName seleceImageName:(NSString *)selectImageName{
    //    controller.title = title;
    controller.tabBarItem.title = title;//跟上面一样效果
    controller.tabBarItem.image = [UIImage imageNamed:imageName];
    controller.tabBarItem.selectedImage = [UIImage imageNamed:selectImageName];
    
    //包装导航控制器
    RootNavigationController *nav = [[RootNavigationController alloc]initWithRootViewController:controller];
    controller.title = title;
    //UINavigationController *nav = [[UINavigationController alloc]initWithRootViewController:controller];
    [self addChildViewController:nav];
    
    [self.costomTabBar addTabBarButtonWithItem:controller.tabBarItem];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
