//
//  HTProtect.h
//  RiskPerception
//

#import <Foundation/Foundation.h>
#import <RiskPerception/AntiCheatResult.h>
#import <RiskPerception/HTProtectConfig.h>

NS_ASSUME_NONNULL_BEGIN

#ifndef RiskPerceptionHTPCallbackDefined
#define RiskPerceptionHTPCallbackDefined
/**
 *  初始化回调
 *
 *  @param code                     初始化结果码
 *  @param msg                      初始化结果说明
 *  @param content                  初始化返回内容，失败时通常为空字符串
 */
typedef void (^HTPCallback)(int code, NSString *msg, NSString *content);
#endif

#ifndef RiskPerceptionGetTokenCallbackDefined
#define RiskPerceptionGetTokenCallbackDefined
/**
 *  异步获取 Token 回调
 *
 *  @param result                   Token 获取结果，包含 code、codeStr、token 等信息
 */
typedef void (^GetTokenCallback)(AntiCheatResult *result);
#endif

#ifndef NTESRiskRequestCmdIDDefined
#define NTESRiskRequestCmdIDDefined
/**
 *  数据查询类型
 */
typedef enum {
    Cmd_GetHTPVersion = 7,  // 获取 SDK 版本
    Cmd_GetDeviceId = 20,   // 获取服务端设备指纹
} RequestCmdID;
#endif

__attribute__((visibility("default")))
@interface HTProtect : NSObject

/**
 *  获取 HTProtect 单例对象
 *
 *  @return                         HTProtect 单例
 */
+ (instancetype)sharedInstance;

/**
 *  初始化 SDK
 *
 *  客户端启动后调用一次。初始化会保存产品上下文、应用配置、拉取在线配置，并在初始化成功后触发一次后台 Token 预取。
 *
 *  @param productId                易盾官网注册的产品 ID，不能为空
 *  @param config                   SDK 配置对象，可为空；为空时使用默认配置
 *  @param callback                 初始化完成回调，可为空
 */
- (void)init:(NSString *)productId
      config:(nullable HTProtectConfig *)config
    callback:(nullable HTPCallback)callback NS_SWIFT_NAME(initialize(_:config:callback:));

/**
 *  同步获取 Token
 *
 *  不能在主线程调用。接口会优先返回有效缓存 Token；无有效缓存时返回本地兜底 Token，并异步触发后台刷新。
 *
 *  @return                         Token 获取结果
 */
- (AntiCheatResult *)getToken;

/**
 *  异步获取实时 Token
 *
 *  用于初始化后主动暖 Token，或业务需要明确触发实时刷新时调用。
 *
 *  @param callback                 Token 获取完成回调，不能为空
 */
- (void)getTokenAsync:(GetTokenCallback)callback;

/**
 *  数据查询
 *
 *  当前仅支持 Cmd_GetHTPVersion 和 Cmd_GetDeviceId。
 *
 *  @param request                  查询类型
 *  @param data                     查询参数，当前保留参数，可传空字符串
 *
 *  @return                         查询结果；不支持的查询返回空字符串
 */
- (NSString *)ioctl:(RequestCmdID)request withData:(NSString *)data;

/**
 *  数据签名
 *
 *  @param dataString               需要签名的数据，不能为空
 *
 *  @return                         数据签名值，失败返回 nil
 */
- (NSString *)getDataSign:(NSString *)dataString;

/**
 *  数据签名
 *
 *  @param data                     需要签名的数据，不能为空
 *
 *  @return                         数据签名值，失败返回 nil
 */
- (NSString *)getDataSignWithData:(NSData *)data;

/**
 *  白盒加密 V2 版本
 *
 *  @param alg                      加密算法
 *  @param data                     需要加密的原文
 *  @param error                    错误信息
 *
 *  @return                         加密成功后的 base64 字符串，失败返回 nil
 */
- (NSString *)safeCommToServer:(int)alg
                       withData:(NSData *)data
                          error:(NSError **)error;

/**
 *  白盒加密 V2 版本
 *
 *  @param alg                      加密算法
 *  @param data                     需要加密的原文
 *  @param error                    错误信息
 *
 *  @return                         加密成功后的二进制数据，失败返回 nil
 */
- (NSData *)safeCommToServerByte:(int)alg
                         withData:(NSData *)data
                            error:(NSError **)error;

/**
 *  白盒加密 V30 版本
 *
 *  @param version                  加密版本
 *  @param alg                      加密算法
 *  @param data                     需要加密的原文
 *  @param isCrucial                是否关键数据
 *  @param error                    错误信息
 *
 *  @return                         加密成功后的 base64 字符串，失败返回 nil
 */
- (NSString *)safeCommToServerV30:(int)version
                               alg:(int)alg
                          withData:(NSData *)data
                         isCrucial:(bool)isCrucial
                             error:(NSError **)error;

/**
 *  白盒加密 V30 版本
 *
 *  @param version                  加密版本
 *  @param alg                      加密算法
 *  @param data                     需要加密的原文
 *  @param isCrucial                是否关键数据
 *  @param error                    错误信息
 *
 *  @return                         加密成功后的二进制数据，失败返回 nil
 */
- (NSData *)safeCommToServerByteV30:(int)version
                                 alg:(int)alg
                            withData:(NSData *)data
                           isCrucial:(bool)isCrucial
                               error:(NSError **)error;

/**
 *  白盒解密原接口
 *
 *  @param alg                      加密算法
 *  @param timeout                  超时时间，单位秒
 *  @param data                     base64 编码字符串对应的二进制数据
 *  @param error                    错误信息
 *
 *  @return                         解密后的二进制数据，失败返回 nil
 */
- (NSData *)safeCommFromServer:(int)alg
                        timeout:(int)timeout
                       withData:(NSData *)data
                          error:(NSError **)error;

/**
 *  白盒解密 V2 版本
 *
 *  @param alg                      加密算法
 *  @param timeout                  超时时间，单位秒
 *  @param string                   base64 编码后的密文字符串
 *  @param error                    错误信息
 *
 *  @return                         解密后的二进制数据，失败返回 nil
 */
- (NSData *)safeCommFromServer:(int)alg
                        timeout:(int)timeout
                     withString:(NSString *)string
                          error:(NSError **)error;

/**
 *  白盒解密 V2 版本
 *
 *  @param alg                      加密算法
 *  @param timeout                  超时时间，单位秒
 *  @param data                     密文二进制数据
 *  @param error                    错误信息
 *
 *  @return                         解密后的二进制数据，失败返回 nil
 */
- (NSData *)safeCommFromServerByte:(int)alg
                            timeout:(int)timeout
                           withData:(NSData *)data
                              error:(NSError **)error;

/**
 *  HTP 签名
 *
 *  @param alg                      签名算法
 *  @param version                  签名版本
 *  @param data                     需要签名的原文
 *  @param error                    错误信息
 *
 *  @return                         签名成功后的字符串，失败返回 nil
 */
- (NSString *)htpSign:(int)alg
              version:(int)version
             withData:(NSData *)data
                error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
