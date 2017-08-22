//
//  MineTableViewCell.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/6/12.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "MineTableViewCell.h"

@interface MineTableViewCell()

@property (nonatomic, strong) UIImageView *titleIcon;//标题图标
@property (nonatomic, strong) UILabel *titleLbl;//标题
@property (nonatomic, strong) UILabel *detaileLbl;//内容
@property (nonatomic, strong) UIImageView *arrowIcon;//右箭头图标

@end

@implementation MineTableViewCell

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        
    }
    return self;
}

-(void)setCellData:(NSDictionary *)cellData{
    _cellData = cellData;
    if (cellData) {
        if (cellData[@"title_icon"]) {
            [self.titleIcon setImage:ImageWithFile(cellData[@"title_icon"])];
            [_titleIcon mas_updateConstraints:^(MASConstraintMaker *make) {
                make.left.mas_equalTo(KNormalSpace);
                make.centerY.mas_equalTo(self);
                make.width.height.mas_equalTo(17);
            }];
        }else{
            [self.titleIcon mas_updateConstraints:^(MASConstraintMaker *make) {
                make.left.mas_equalTo(0);
                make.width.height.mas_equalTo(0);
            }];
        }
        
        if (cellData[@"titleText"]) {
            self.titleLbl.text = cellData[@"titleText"];
        }
        
        if (cellData[@"detailText"]) {
            self.detaileLbl.text = cellData[@"detailText"];
            [_detaileLbl mas_updateConstraints:^(MASConstraintMaker *make) {
                make.left.mas_equalTo(_titleLbl.mas_right).offset(10);
                make.centerY.mas_equalTo(self);
                make.right.mas_equalTo(self.arrowIcon.mas_left).offset(- 10);
            }];
        }else{
            [_detaileLbl mas_updateConstraints:^(MASConstraintMaker *make) {
                make.left.mas_equalTo(_titleLbl.mas_right).offset(0);
                make.centerY.mas_equalTo(self);
                make.right.mas_equalTo(self.arrowIcon.mas_left).offset(0);
            }];
        }
        if (cellData[@"arrow_icon"]) {
            [self.arrowIcon setImage:ImageWithFile(cellData[@"arrow_icon"])];
            [_arrowIcon mas_updateConstraints:^(MASConstraintMaker *make) {
                make.right.mas_equalTo(-KNormalSpace);
                make.top.mas_equalTo(KNormalSpace);
                make.width.height.mas_equalTo(22);
                make.centerY.mas_equalTo(self);
            }];
            
        }else{
            [_arrowIcon mas_updateConstraints:^(MASConstraintMaker *make) {
                make.right.mas_equalTo(0);
                make.top.mas_equalTo(KNormalSpace);
                make.width.height.mas_equalTo(0);
                make.centerY.mas_equalTo(self);
            }];
        }
    }
}

-(UIImageView *)titleIcon{
    if (!_titleIcon) {
        _titleIcon = [UIImageView new];
        [self addSubview:_titleIcon];
        [_titleIcon mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(KNormalSpace);
            make.centerY.mas_equalTo(self);
            make.width.height.mas_equalTo(0);
        }];
    }
    return _titleIcon;
}
-(UILabel *)titleLbl{
    if (!_titleLbl) {
        _titleLbl = [UILabel new];
        _titleLbl.font = SYSTEMFONT(15);
        _titleLbl.textColor = KBlackColor;
        [self addSubview:_titleLbl];
        [_titleLbl mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(_titleIcon.mas_right).offset(10);
            make.centerY.mas_equalTo(self);
        }];
    }
    return _titleLbl;
}

-(UILabel *)detaileLbl{
    if (!_detaileLbl) {
        _detaileLbl = [UILabel new];
        _detaileLbl.font = SYSTEMFONT(12);
        _detaileLbl.textColor = KGrayColor;
        _detaileLbl.textAlignment = UITextAlignmentRight;
        [self addSubview:_detaileLbl];
        
        [_detaileLbl mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(_titleLbl.mas_right).offset(10);
            make.centerY.mas_equalTo(self);
            make.right.mas_equalTo(self.arrowIcon.mas_left).offset(- 10);
        }];
    }
    return _detaileLbl;
}

-(UIImageView *)arrowIcon{
    if (!_arrowIcon) {
        _arrowIcon = [UIImageView new];
        [self addSubview:_arrowIcon];
        
        [_arrowIcon mas_makeConstraints:^(MASConstraintMaker *make) {
            make.right.mas_equalTo(-KNormalSpace);
            make.top.mas_equalTo(KNormalSpace);
            make.width.height.mas_equalTo(22);
            make.centerY.mas_equalTo(self);
        }];
    }
    return _arrowIcon;
}
@end
