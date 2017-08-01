//
//  TableViewCell.h
//  UniversalApp
//
//  Created by 徐阳 on 2017/8/1.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CellModel.h"

@interface TableViewCell : UITableViewCell

@property (nonatomic,strong) CellModel * model;
@end
