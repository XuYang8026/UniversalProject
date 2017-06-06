//
//  HeaderModel.h
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/23.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OpenUDID.h"

/**
 header 参数model
 */
@interface HeaderModel : NSObject

PropertyLongLong(userid);//用户ID
PropertyString(imei);//设备号
PropertyNSInteger(os_type);//0未知,1安卓,2IOS
PropertyString(version);//当前APP版本
PropertyString(channel);//来源渠道 苹果使用：@"App Store"
PropertyString(clientId);//客户端唯一标示，后台用来判断是否更换设备
PropertyNSInteger(versioncode);//内部维护的应用版本 随版本递增
PropertyString(mobile_model);//手机型号
PropertyString(mobile_brand);//手机品牌

@end
