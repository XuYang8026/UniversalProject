//
//  UserInfo.h
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/23.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import <Foundation/Foundation.h>
@class GameInfo;

typedef NS_ENUM(NSInteger,UserGender){
    UserGenderUnKnow = 0,
    UserGenderMale, //男
    UserGenderFemale //女
};

@interface UserInfo : NSObject

PropertyLongLong(userid);//用户ID
PropertyString(idcard);//展示用的用户ID
PropertyString(photo);//头像
PropertyString(nickname);//昵称
@property (nonatomic, assign) UserGender sex;//性别
PropertyString(imId);//IM账号
PropertyString(imPass);//IM密码
PropertyNSInteger(degreeId);//用户等级
PropertyString(signature);//个性签名
@property (nonatomic, strong) GameInfo *info;//游戏数据

@end
