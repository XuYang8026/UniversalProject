//
//  PersonListLogic.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/7/14.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "PersonListLogic.h"
#import "GetWaterFallListAPI.h"
#import "PersonModel.h"

@interface PersonListLogic()
@property (nonatomic,copy) NSArray * imgArray;
@property (nonatomic,copy) NSArray * nickNameArray;
@property (nonatomic,copy) NSArray * hobbysArray;
@property (nonatomic,copy) NSArray * fromArray;
@end

@implementation PersonListLogic


-(instancetype)init{
    self = [super init];
    if (self) {
        _dataArray = @[].mutableCopy;
        _imgArray = @[@"http://d.hiphotos.baidu.com/zhidao/wh%3D600%2C800/sign=76dcee959358d109c4b6a1b4e168e087/11385343fbf2b211389b08a5cb8065380dd78ea0.jpg",@"http://www.soideas.cn/uploads/allimg/110626/2126221034-5.jpg",@"http://scimg.jb51.net/touxiang/201705/2017053121043719.jpg",@"http://scimg.jb51.net/touxiang/201706/20170609172558191.jpg",@"http://www.qqleju.com/uploads/allimg/160818/18-065635_493.jpg",@"http://img1.touxiang.cn/uploads/allimg/111029/1_111029111038_26.jpg",@"http://img2.zol.com.cn/up_pic/20120705/z1vsowZWoKbr.jpg",@"http://www.soideas.cn/uploads/allimg/110524/2246442634-17.jpg",@"http://dynamic-image.yesky.com/600x-/uploadImages/upload/20140909/upload/201409/25u12gkmr3ujpg.jpg",@"http://www.qqleju.com/uploads/allimg/160213/13-053516_87.jpg",@"http://d.hiphotos.baidu.com/zhidao/wh%3D450%2C600/sign=4aca31fad02a60595245e91e1d0418ad/a8773912b31bb051e3dc6e1b317adab44aede00d.jpg",@"http://img4.duitang.com/uploads/item/201312/05/20131205171748_BeJcN.thumb.600_0.jpeg",@"http://cdn.duitang.com/uploads/item/201312/05/20131205171746_MxNX8.thumb.600_0.jpeg"];
        _nickNameArray = @[@"上官无情",@"慕容空",@"玩的差瘾挺大",@"快枪手",@"YoYo产品经理",@"亲我一口能咋地",@"Rain"];
        _hobbysArray = @[@"四环有套房",@"人之初性本善，玩心眼都滚蛋",@"不约炮，年前已约满",@"弹琴，跳舞，书法，古筝，茶艺我都不会，我只会打王者荣耀",@"喜欢电影，音乐，旅游，爬山，徒步，淘宝，摄影，画画，话剧，美食，吹的我都累了",@"健身，游泳，阅读，打游戏",@"活好不粘人"];
        _fromArray = @[@"北京 学生",@"上海 模特",@"青岛 美容师",@"四川 八线小演员",@"新疆 游击队",@"东北 二人转演员"];
    }
    return self;
}

#pragma mark ————— 拉取数据 —————
-(void)loadData{

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        //模拟成功
        if (_page == 0) {
            [_dataArray removeAllObjects];
        }
        for (int i = 0; i < 10; i++) {
            
            PersonModel *model = [PersonModel new];
            model.picture = _imgArray[arc4random()%_imgArray.count];
            model.headImg = _imgArray[arc4random()%_imgArray.count];
            model.nickName = _nickNameArray[arc4random()%_nickNameArray.count];
            model.hobbys = _hobbysArray[arc4random()%_hobbysArray.count];
            model.age = @"28岁";
            model.city = _fromArray[arc4random()%_fromArray.count];
            model.juli = i%2==0 ? @"0.5km" : @"1800km";
            
            model.width = 150;
            model.height = 150;
            
            [_dataArray addObject:model];
        }
        if (self.delegagte && [self.delegagte respondsToSelector:@selector(requestDataCompleted)]) {
            [self.delegagte requestDataCompleted];
        }

    });
    
    //发起请求 示例
//    GetWaterFallListAPI *req = [GetWaterFallListAPI new];
//    [req startWithCompletionBlockWithSuccess:^(__kindof YTKBaseRequest * _Nonnull request) {
//        NSLog(@"请求成功");
//    } failure:^(__kindof YTKBaseRequest * _Nonnull request) {
//        NSLog(@"请求失败 %@",req.message);
//    }];
}

@end
