//
//  HeaderModel.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/23.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "HeaderModel.h"

@implementation HeaderModel

-(instancetype)init{
    self = [super init];
    if (self) {
        self.userid = 0;
        self.imei = [OpenUDID value];
        self.os_type = 2;
        self.version = kApplication.appVersion;
        self.channel = @"App Store";
        self.clientId = [OpenUDID value];
        self.versioncode = 1;
        self.mobile_model = [UIDevice currentDevice].machineModelName;
        self.mobile_brand = [UIDevice currentDevice].machineModel;
    }
    return self;
}
@end
