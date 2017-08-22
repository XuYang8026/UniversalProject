//
//  EmitterViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/25.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "EmitterViewController.h"

@interface EmitterViewController ()

@end

@implementation EmitterViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor =[UIColor blackColor];
    self.isHidenNaviBar = YES;
    self.StatusBarStyle = UIStatusBarStyleDefault;
    [self showAnimation];
}


-(void)showAnimation{
    switch (_animation_type) {
        case 0://彩带
            [self caiDai];
            break;
            
        case 1://下雪
            [self snow];
            break;
        case 2://下雨
            [self rain];
            break;
        case 3://烟花
            [self fire];
            break;
            
        default:
            break;
    }
}

-(void)snow{
    // 创建粒子Layer
    CAEmitterLayer *snowEmitter = [CAEmitterLayer layer];
//    snowEmitter.preservesDepth = YES;//是否开启三维空间模式

//    snowEmitter.emitterDepth = 2.0;//发射器的深度，有时可能会产生立体效果
    // 粒子发射位置
    snowEmitter.emitterPosition = CGPointMake(KScreenWidth/2,-20);
    // 发射源的尺寸大小
    snowEmitter.emitterSize = self.view.bounds.size;
    // 发射模式
    snowEmitter.emitterMode = kCAEmitterLayerSurface;
    // 发射源的形状
    snowEmitter.emitterShape = kCAEmitterLayerLine;
    // 创建雪花类型的粒子
    CAEmitterCell *snowflake = [CAEmitterCell emitterCell];
    // 粒子的名字
    snowflake.name = @"snow";
    // 粒子参数的速度乘数因子
    snowflake.birthRate = 60.0;  //每秒生成数量
    snowflake.lifetime = 60;        //生存时间
    // 粒子速度
    snowflake.velocity = 50.0;
//    // 粒子的速度范围
    snowflake.velocityRange = 40;
    // 粒子y方向的加速度分量
    snowflake.yAcceleration = 20;
    // 周围发射角度
    snowflake.emissionRange = 0.5 * M_PI;
    // 子旋转角度范围
    snowflake.spinRange = 0.25 * M_PI;
    snowflake.contents = (id)[[UIImage imageNamed:@"snow"] CGImage];
    // 设置雪花形状的粒子的颜色
    snowflake.color = [[UIColor whiteColor] CGColor];
    //缩放范围
    snowflake.scaleRange = 0.3f;
    snowflake.scale = 0.15f;
    //设置透明度变化范围
    
    //设置粒子透明变化速度 越小 越块
//    snowflake.alphaSpeed = 0;
    //透明度范围
//    snowflake.alphaRange = -100;
    
    snowEmitter.shadowOpacity = 1.0;
    snowEmitter.shadowRadius = 0.0;
    snowEmitter.shadowOffset = CGSizeMake(0.0, 0.0);
    // 粒子边缘的颜色
    snowEmitter.shadowColor = [[UIColor whiteColor] CGColor];
    // 添加粒子
    snowEmitter.emitterCells = @[snowflake];
    
    // 将粒子Layer添加进图层中
    [self.view.layer addSublayer:snowEmitter];
}
//下雨
-(void)rain{
    //发射器
    CAEmitterLayer *rainEmitter =[CAEmitterLayer layer];
    
    rainEmitter.emitterShape    = kCAEmitterLayerLine;
    rainEmitter.emitterMode     = kCAEmitterLayerOutline;
//    rainEmitter.emitterSize     = self.view.bounds.size;
    rainEmitter.emitterSize     = CGSizeMake(KScreenWidth*2, KScreenHeight);
    rainEmitter.renderMode      = kCAEmitterLayerAdditive;
    rainEmitter.emitterPosition = CGPointMake(0, -20);
    //水滴
    CAEmitterCell *rainflake    = [CAEmitterCell emitterCell];
    rainflake.birthRate         = 50;   //每秒发出的数量
    
    //rainflake.speed             = 10;   //速度
    rainflake.velocity          = 200;   //加速度
    rainflake.velocityRange     = 75;   //加速度范围
    rainflake.yAcceleration     = 500;  //重力
    
//    rainflake.emission = 0.3 * M_PI;
//    rainflake.spin = 0.1 * M_PI;
    
    rainflake.emissionLatitude = 0.1 *M_PI;
//    rainflake.emissionLongitude =  M_PI_2; // 方向，M_PI_2 右斜
    
    rainflake.contents          = (id)[UIImage imageNamed:@"rain"].CGImage;
    rainflake.color             = [UIColor whiteColor].CGColor;
    rainflake.lifetime          = 3;   //生命周期
    rainflake.scale             = 0.3;  //缩放
    rainflake.scaleRange        = 0.2;
    
    //水花
    CAEmitterCell *rainSpark =[CAEmitterCell emitterCell];
    
//    rainSpark.birthRate         = 1;
//    rainSpark.velocity          = 0;
//    //rainSpark.emissionRange     = M_PI;//180度
//    //rainSpark.yAcceleration     = 40;
//    rainSpark.scale             = 0.5;
//    rainSpark.contents          = (id)[UIImage imageNamed:@"snow"].CGImage;
//    rainSpark.color=[UIColor whiteColor].CGColor;
//    rainSpark.lifetime          =  0.3;
    
    //
    
    // and finally, the sparks
    CAEmitterCell* spark = [CAEmitterCell emitterCell];
    
    spark.birthRate            = 50;       //炸开后产生40花
    spark.velocity             = 50;       //速度
    spark.velocityRange        = 20;
    spark.emissionRange        = M_PI;   // 360 度
    spark.yAcceleration        = 40;         // 重力
    spark.lifetime             = 0.5;
    
    spark.contents          = (id) [[UIImage imageNamed:@"snow"] CGImage];
    spark.scaleSpeed        = 0.2;
    spark.scale             = 0.2;
    spark.color =[UIColor whiteColor].CGColor;
    spark.alphaSpeed        =- 0.25;
    spark.spin              = 2* M_PI;
    spark.spinRange         = 2* M_PI;
    
    rainEmitter.emitterCells    = @[rainflake];
    rainflake.emitterCells      = @[rainSpark];
    rainSpark.emitterCells      = @[spark];
    
    [self.view.layer addSublayer:rainEmitter];

}

-(void)fire{
    //cell产生在底部,向上移动
    CAEmitterLayer *fireworkdEmitter =[CAEmitterLayer layer];
    CGRect viewBounds = self.view.layer.bounds;
    
    fireworkdEmitter.emitterPosition =CGPointMake(viewBounds.size.width/2, viewBounds.size.height);
    fireworkdEmitter.emitterMode = kCAEmitterLayerOutline;
    fireworkdEmitter.emitterShape = kCAEmitterLayerLine;
    fireworkdEmitter.renderMode = kCAEmitterLayerAdditive;
    fireworkdEmitter.seed = (arc4random()%100)+1;
    
    //创建火箭cell
    CAEmitterCell *rocket = [CAEmitterCell emitterCell];
    rocket.birthRate = 1;
    rocket.emissionRange = 0.25 *M_PI;
    rocket.velocity = 300;
    rocket.velocityRange = 75;
    rocket.lifetime =1.02;
    
    rocket.contents = (id)[UIImage imageNamed:@"DazFire"].CGImage;
    rocket.scale = 0.5;
    rocket.scaleRange =0.5;
    rocket.color = [UIColor redColor].CGColor;
    rocket.greenRange = 1.0;
    rocket.redRange = 1.0;
    rocket.blueRange = 1.0;
    rocket.spinRange =M_PI;
    
    //破裂对象不能被看到,但会产生火花
    //这里我们改变颜色,因为火花继承它的值
    CAEmitterCell *fireCell =[CAEmitterCell emitterCell];
    
    fireCell.birthRate          = 1;
    fireCell.velocity           = 0;
    fireCell.scale              = 1;
    fireCell.redSpeed           =- 1.5;
    fireCell.blueSpeed          =+ 1.5;
    fireCell.greenSpeed         =+ 1.5;        // shifting
    fireCell.lifetime           = 0.34;
    
    
    // and finally, the sparks
    CAEmitterCell* spark = [CAEmitterCell emitterCell];
    
    spark.birthRate            = 400;       //炸开后产生400个小烟花
    spark.velocity             = 125;       //速度
    spark.emissionRange        = 2* M_PI;   // 360 度
    spark.yAcceleration        = 40;         // 重力
    spark.lifetime             = 3;
    
    spark.contents          = (id) [[UIImage imageNamed:@"snow"] CGImage];
    spark.scaleSpeed        =- 0.2;
    
    spark.greenSpeed        =- 0.1;
    spark.redSpeed          =+ 0.1;
    spark.blueSpeed         =- 0.1;
    
    spark.alphaSpeed        =- 0.25;
    
    spark.spin              = 2* M_PI;
    spark.spinRange         = 2* M_PI;
    
    fireworkdEmitter.emitterCells        = [NSArray arrayWithObject:rocket];
    rocket.emitterCells                  = [NSArray arrayWithObject:fireCell];
    fireCell.emitterCells                = [NSArray arrayWithObject:spark];
    
    [self.view.layer addSublayer:fireworkdEmitter];

}
-(void)caiDai
{
    CAEmitterLayer *snowEmitter = [CAEmitterLayer layer];
    //例子发射位置
    snowEmitter.emitterPosition = CGPointMake(kScreenWidth/2,-30);
    snowEmitter.preservesDepth=YES;
    //    snowEmitter.lifetime=0.1;
    
    //发射源的尺寸大小
    snowEmitter.emitterSize = CGSizeMake(kScreenWidth*2, KScreenHeight);
    //发射模式
    snowEmitter.emitterMode = kCAEmitterLayerOutline;
    //发射源的形状
    snowEmitter.emitterShape = kCAEmitterLayerLine;
    
    NSMutableArray *cellArr=[[NSMutableArray alloc]init];
    for (int i=1; i<9; i++) {
        CAEmitterCell *snowflake = [CAEmitterCell emitterCell];
        snowflake.birthRate		= 10.0;
        snowflake.lifetime		= 4.0;
        
        snowflake.velocity		= 150;				// falling down slowly
        snowflake.velocityRange = 30;
        snowflake.yAcceleration = 100;
        snowflake.emissionRange = M_PI;		// some variation in angle
        snowflake.spinRange		= M_PI;		// slow spin
        
        snowflake.contents		= (id) [[UIImage imageNamed:[NSString stringWithFormat:@"stepPk_win_colour%d",i]] CGImage];
        //        snowflake.color			= [[UIColor colorWithRed:0.600 green:0.658 blue:0.743 alpha:1.000] CGColor];
        [cellArr addObject:snowflake];
    }
    snowEmitter.shadowOpacity = 1.0;
    snowEmitter.shadowRadius = 0.0;
    snowEmitter.shadowOffset = CGSizeMake(0.0, 1.0);
    //粒子边缘的颜色
    //    snowEmitter.shadowColor = [[UIColor redColor] CGColor];
    
    snowEmitter.emitterCells = cellArr;
    [self.view.layer addSublayer:snowEmitter];
    
}



- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
