//
//  FFTagsView.h
//  dfds
//
//  Created by liwei on 17/3/13.
//  Copyright © 2017年 liwei. All rights reserved.
//

#import <UIKit/UIKit.h>
@class FFTagsView;

typedef void(^tagBtnClicked)(FFTagsView *aTagsView, UIButton *sender, NSInteger tag);

@interface FFTagsViewConfig : NSObject

@property (nonatomic) CGFloat itemHerMargin;            //item之间的左右间距
@property (nonatomic) CGFloat itemVerMargin;            //item之间的上下间距
@property (nonatomic) CGFloat itemHeight;               //item的高度
@property (nonatomic) CGFloat itemContentEdgs;          //item标题距左右边缘的距离
@property (nonatomic) CGFloat topBottomSpace;           //最顶部和最底部的item距离俯视图顶部和底部的距离(无间距时可设为0.1)

@property (nonatomic) CGFloat fontSize;                     //字体大小  默认12
@property (nonatomic,strong) UIColor *normalTitleColor;
@property (nonatomic,strong) UIColor *selectedTitleColor;
@property (nonatomic,strong) UIColor *backgroundColor;
@property (nonatomic,strong) UIImage *normalBgImage;
@property (nonatomic,strong) UIImage *selectedBgImage;


//是否有边框  默认没有边框
@property (nonatomic) BOOL hasBorder;
@property (nonatomic) CGFloat borderRadius;
@property (nonatomic) CGFloat borderWidth;
@property (nonatomic) CGFloat borderColor;

//是否可以选中默认为NO (YES时为单选)
@property (nonatomic) BOOL isCanSelected;
@property (nonatomic) BOOL isCanCancelSelected; //是否可以取消选中

@property (nonatomic) BOOL isMulti;
@property (nonatomic,copy) NSString *singleSelectedTitle;     //单个选中对应的标题(初始化时默认选中的)
@property (nonatomic,copy) NSArray *selectedDefaultTags;      //多个选中对应的标题数组(初始化时默认选中的)



@end



@interface FFTagsView : UIView

///点击回调
@property (nonatomic,copy) tagBtnClicked tagBtnClickedBlock;

@property (nonatomic,strong) UIImageView *bgImageView;
///对应单选 当前选中的tag按钮
@property (nonatomic,strong) UIButton *selectedBtn;
//多个选中对应的标题数组
@property (nonatomic,copy) NSMutableArray *multiSelectedTags;
/*
    必须给父视图设置一个宽度
 */
-(instancetype)initWithFrame:(CGRect)frame tagsArray:(NSArray *)tagsArr config:(FFTagsViewConfig *)config;

- (CGFloat)heighttagsArray:(NSArray *)tagsArr config:(FFTagsViewConfig *)config;

@end
