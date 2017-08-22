//
//  BaseTableViewCell.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/6/19.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "BaseTableViewCell.h"

@interface BaseTableViewCell()

@property(nonatomic,strong) UILabel *customDetailLabel;//label

@end

@implementation BaseTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    if(self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]){
        [self setupUI];
    }
    return self;
}
#pragma mark ————— 初始化页面 —————
- (void)setupUI
{
    
}

-(void)setCustomDetailText:(NSString *)customDetailText{
    _customDetailText = customDetailText;
    self.customDetailLabel.text = customDetailText;
}

-(UILabel *)customDetailLabel{
    if (!_customDetailLabel) {
        _customDetailLabel = [UILabel new];
        [self addSubview:_customDetailLabel];
        _customDetailLabel.font = SYSTEMFONT(14);
        _customDetailLabel.textColor = KGrayColor;
        _customDetailLabel.textAlignment = UITextAlignmentRight;
        [_customDetailLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.right.mas_equalTo(-15);
            make.centerY.mas_equalTo(self);
        }];
    }
    return _customDetailLabel;
}
@end
