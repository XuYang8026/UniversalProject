//
//  WaterFallCollectionViewCell.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/6/22.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "WaterFallCollectionViewCell.h"

@interface WaterFallCollectionViewCell()

@property(nonatomic,strong) UIImageView *photoImgView;//头像



@end

@implementation WaterFallCollectionViewCell

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
    }
    return self;
}

#pragma mark ————— 初始化页面 —————
-(void)setupUI{
    
}

#pragma mark ————— 数据渲染页面 —————
-(void)setImageName:(NSString *)imageName{
    _imageName = imageName;
    [self.photoImgView setImage:IMAGE_NAMED(_imageName)];
}

#pragma mark ————— 控件 懒加载 —————
-(UIImageView *)photoImgView{
    if (!_photoImgView) {
        _photoImgView = [UIImageView new];
        _photoImgView.contentMode = UIViewContentModeScaleAspectFill;
        [self addSubview:_photoImgView];
        [_photoImgView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.edges.mas_equalTo(self);
        }];
    }
    return _photoImgView;
}

@end
