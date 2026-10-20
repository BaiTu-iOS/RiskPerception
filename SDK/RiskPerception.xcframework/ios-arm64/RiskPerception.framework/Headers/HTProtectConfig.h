//
//  HTProtectConfig.h
//  RiskPerception
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

__attribute__((visibility("default")))
@interface HTProtectConfig : NSObject

/**
 *  设置服务器所属地区
 *
 *  默认使用中国大陆服务。需要接入其他区域服务时设置对应类型，具体取值请以接入文档和商务开通区域为准。
 */
@property (nonatomic, assign) NSInteger serverType;

/**
 *  设置渠道信息
 *
 *  用于在数据上报中标识 App 渠道，例如 App Store、企业渠道等。为空时使用默认渠道。
 */
@property (nonatomic, copy, nullable) NSString *channel;

/**
 *  设置服务访问域名
 *
 *  用于私有化、测试环境或指定服务域名。可传入完整 http/https 地址，也可传入域名，由 SDK 自动补全 https。
 */
@property (nonatomic, copy, nullable) NSString *host;

/**
 *  设置额外透传信息
 *
 *  额外信息会随设备数据上报透传给服务端。key 和 value 均应为字符串。
 */
@property (nonatomic, copy) NSDictionary<NSString *, NSString *> *extraData;

@end

NS_ASSUME_NONNULL_END
