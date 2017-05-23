//
//  UserManager.h
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/22.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UserInfo.h"

typedef NS_ENUM(NSInteger, UserLoginStatus){
    kUserLoginStatusThird = 0x01 << 0,//第三方登录
    kUserLoginStatusPwd = 0x01 << 1,///账号登录,自己
};

#define isLogin [UserManager sharedUserManager].isLogined
#define curUser [UserManager sharedUserManager].curUserInfo
/**
 包含用户相关服务
 */
@interface UserManager : NSObject

SINGLETON_FOR_HEADER(UserManager)

//当前用户
@property (nonatomic, strong) UserInfo *curUserInfo;
@property (nonatomic, assign) UserLoginStatus loginStatus;
@property (nonatomic, assign) BOOL isLogined;

@end
