//
//  RiskPerceptionPlugin.h
//  RiskPerceptionPlugin
//
//  Created by 汤庸 on 2026/1/4.
//

#import <Foundation/Foundation.h>

@interface RiskPerceptionPlugin : NSObject

// init接口：供主SDK调用，开启定位监听和处理
+ (instancetype)sharedInstance;

@end
