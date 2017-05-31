//
//  GameInfo.h
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/31.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GameInfo : NSObject

PropertyLongLong(gold_coin);//金币数
PropertyLongLong(flow);//流量币
PropertyLongLong(growth_value);//成长值
PropertyNSInteger(level);//用户等级
PropertyLongLong(cash);//现金

@end
