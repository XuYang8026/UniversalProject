//
//  XZPickView.h
//  XZPickView
//
//  Created by 赵永杰 on 17/3/24.
//  Copyright © 2017年 zhaoyongjie. All rights reserved.
//

#import <UIKit/UIKit.h>
@class XZPickView;

@protocol XZPickViewDataSource <NSObject>

@required

- (NSInteger)numberOfComponentsInPickerView:(XZPickView *)pickerView;

- (NSInteger)pickerView:(XZPickView *)pickerView numberOfRowsInComponent:(NSInteger)component;

@end

@protocol XZPickViewDelegate <NSObject>

- (NSString *)pickerView:(XZPickView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component;

- (void)pickView:(XZPickView *)pickerView confirmButtonClick:(UIButton *)button;

@optional
- (NSAttributedString *)pickerView:(XZPickView *)pickerView attributedTitleForRow:(NSInteger)row forComponent:(NSInteger)componen;

- (void)pickerView:(XZPickView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component;

@end

@interface XZPickView : UIView

@property (nonatomic, weak) id<XZPickViewDelegate> delegate;
@property (nonatomic, weak) id<XZPickViewDataSource> dataSource;
- (instancetype)initWithFrame:(CGRect)frame title:(NSString *)title;
- (void)show;
- (void)dismiss;
// 选中某一行
- (void)selectRow:(NSInteger)row inComponent:(NSInteger)component animated:(BOOL)animated;
// 获取当前选中的row
- (NSInteger)selectedRowInComponent:(NSInteger)component;

//刷新某列数据
-(void)pickReloadComponent:(NSInteger)component;
//刷新数据
-(void)reloadData;

@end
