//
//  NTESRiskUniConfiguration.h
//  RiskPerception
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#ifndef NTESRiskOldConfigurationAPIDeprecated
#define NTESRiskOldConfigurationAPIDeprecated DEPRECATED_MSG_ATTRIBUTE("旧配置接口已废弃，请使用 HTProtectConfig。")
#endif

__attribute__((visibility("default")))
@interface NTESRiskUniConfiguration : NSObject

+ (void)setServerType:(NSInteger)type NTESRiskOldConfigurationAPIDeprecated;
+ (void)setChannel:(NSString *)channel NTESRiskOldConfigurationAPIDeprecated;
+ (void)setExtraDataValue:(NSString *)value forKey:(NSString *)key DEPRECATED_MSG_ATTRIBUTE("Please use [NTESRiskUniConfiguration setExtraData:forValue:].");
+ (void)setExtraData:(NSString *)key forValue:(NSString *)value NTESRiskOldConfigurationAPIDeprecated;
+ (void)setHost:(NSString *)host NTESRiskOldConfigurationAPIDeprecated;

@end

NS_ASSUME_NONNULL_END
