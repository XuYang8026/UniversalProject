//
//  HSBaseCellModel.h
//  HSSetTableView
//
//  Created by hushaohui on 2017/4/18.
//  Copyright © 2017年 ZLHD. All rights reserved.
//


@interface HSBaseCellModel : NSObject

/**
 基础属性
 */
//@property (nonatomic,  copy)   NSString   *cellClass;  ///<该模型绑定的cell类名
@property (nonatomic,  assign)   NSInteger   identifier;  ///<唯一标识符(更新会用到)
@property (nonatomic, assign)  UITableViewCellSelectionStyle   selectionStyle;//选中cell效果
@property (nonatomic, assign)  CGFloat    cellHeight;  ///<cell高度(默认有高度)
//@property (nonatomic, assign)  CGFloat separateHeight;  ///<分割线高度
//@property (nonatomic, strong)  UIColor *separateColor;  ///<分割线颜色
//@property (nonatomic, assign)  CGFloat separateOffset;  ///<分割线左边间距(默认为0)
//@property (nonatomic,  copy)   ClickActionBlock actionBlock;///<cell点击事件

@property (nonatomic, copy  ) NSString   *title;///<cell标题(默认左边)
@property (nonatomic, copy)   NSString *detailText;  ///右边详细文本
@property (nonatomic, assign) BOOL isShowArrow;//是否显示右箭头

@end
