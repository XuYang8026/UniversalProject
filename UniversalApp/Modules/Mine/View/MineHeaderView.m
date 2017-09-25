//
//  MineHeaderView.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/6/13.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "MineHeaderView.h"
#import "NickNameLbel.h"

@interface MineHeaderView()

@property(nonatomic, strong) UIImageView *bgImgView; //背景图
@property(nonatomic, strong) NickNameLbel *nickNameView; //昵称容器 包含昵称 性别 等级
@property(nonatomic, strong) UILabel *showIDLabel; //展示的ID
@property(nonatomic, strong) UILabel *signatureLabel; //展示的ID

@end

@implementation MineHeaderView

-(void)setUserInfo:(UserInfo *)userInfo{
    _userInfo = userInfo;
    
    UIImage *bgImg = [[UIImage imageNamed:@"my_back_img"] imageByBlurRadius:15 tintColor:nil tintMode:0 saturation:1 maskImage:nil];
    
    [self.bgImgView setImage:bgImg];
    
    self.signatureLabel.text = userInfo.signature;
    if (!userInfo.signature) {
        [self.signatureLabel mas_updateConstraints:^(MASConstraintMaker *make) {
            make.height.mas_equalTo(0);
        }];
    }else{
        [self.signatureLabel mas_updateConstraints:^(MASConstraintMaker *make) {
            make.height.mas_equalTo(0);
        }];
    }
    
//未登录状态展示
    if (userInfo) {
        self.showIDLabel.text = NSStringFormat(@"ID: %@",userInfo.idcard);
        [self.nickNameView setNickName:userInfo.nickname sex:userInfo.sex age:26 level:userInfo.degreeId];
//        [self.headImgView setImageWithURL:[NSURL URLWithString:userInfo.photo] placeholder:[UIImage imageWithColor:KGrayColor]];
        [self.headImgView sd_setImageWithURL:[NSURL URLWithString:userInfo.photo] placeholderImage:[UIImage imageWithColor:KGrayColor]];
    }else{
        self.showIDLabel.text = @"";
        [self.nickNameView setNickName:@"未登录" sex:0 age:0 level:0];
        [self.headImgView setImageWithURL:[NSURL URLWithString:@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503377311744&di=a784e64d1cce362c663f3480b8465961&imgtype=0&src=http%3A%2F%2Fww2.sinaimg.cn%2Flarge%2F85cccab3gw1etdit7s3nzg2074074twy.jpg"] placeholder:[UIImage imageWithColor:KGrayColor]];
    }
}
#pragma mark ————— 头像点击 —————
-(void)headViewClick{
    if (self.delegate && [self.delegate respondsToSelector:@selector(headerViewClick)]) {
        [self.delegate headerViewClick];
    }
}
#pragma mark ————— 昵称点击 —————
-(void)nickNameViewClick{
    if (self.delegate && [self.delegate respondsToSelector:@selector(nickNameViewClick)]) {
        [self.delegate nickNameViewClick];
    }
}
-(UIImageView *)bgImgView{
    if (!_bgImgView) {
        _bgImgView = [UIImageView new];
        [self addSubview:_bgImgView];
        [_bgImgView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.top.right.bottom.mas_equalTo(0);
        }];
    }
    return _bgImgView;
}

-(YYAnimatedImageView *)headImgView{
    if (!_headImgView) {
        _headImgView = [YYAnimatedImageView new];
        _headImgView.contentMode = UIViewContentModeScaleAspectFill;
        
        _headImgView.userInteractionEnabled = YES;
        [_headImgView addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(headViewClick)]];
        
        ViewRadius(_headImgView, (90*Iphone6ScaleWidth)/2);
        [self addSubview:_headImgView];
        [_headImgView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.width.height.mas_equalTo(90*Iphone6ScaleWidth);
            make.bottom.mas_equalTo(_nickNameView.mas_top).offset(-12);
            make.centerX.mas_equalTo(self);
        }];
    }
    return _headImgView;
}

-(NickNameLbel *)nickNameView{
    if (!_nickNameView) {
        _nickNameView = [NickNameLbel new];
        [self addSubview:_nickNameView];
        [_nickNameView addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(nickNameViewClick)]];
        [_nickNameView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.bottom.mas_equalTo(_showIDLabel.mas_top).offset(-6);
            
            make.centerX.mas_equalTo(self);
        }];
    }
    return _nickNameView;
}

-(UILabel *)showIDLabel{
    if (!_showIDLabel) {
        _showIDLabel = [UILabel new];
        _showIDLabel.font = SYSTEMFONT(12);
        _showIDLabel.textColor = KWhiteColor;
        [self addSubview:_showIDLabel];
        [_showIDLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.bottom.mas_equalTo(_signatureLabel.mas_top).offset(-4);
            make.centerX.mas_equalTo(self);
        }];
    }
    return _showIDLabel;
}

-(UILabel *)signatureLabel{
    if (!_signatureLabel) {
        _signatureLabel = [UILabel new];
        _signatureLabel.font = SYSTEMFONT(14);
        _signatureLabel.textColor = KWhiteColor;
        [self addSubview:_signatureLabel];
        [_signatureLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.bottom.mas_equalTo(self).offset(-16);
            make.height.mas_equalTo(15);
            make.centerX.mas_equalTo(self);
        }];
    }
    return _signatureLabel;
}
@end
