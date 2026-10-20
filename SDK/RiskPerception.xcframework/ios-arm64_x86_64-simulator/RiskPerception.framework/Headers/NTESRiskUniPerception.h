//
//  NTESRiskUniPerception.h
//  RiskPerception
//

#import <Foundation/Foundation.h>
#import <RiskPerception/AntiCheatResult.h>

NS_ASSUME_NONNULL_BEGIN

#ifndef RiskPerceptionHTPCallbackDefined
#define RiskPerceptionHTPCallbackDefined
typedef void (^HTPCallback)(int code, NSString *msg, NSString *content);
#endif

#ifndef RiskPerceptionGetTokenCallbackDefined
#define RiskPerceptionGetTokenCallbackDefined
typedef void (^GetTokenCallback)(AntiCheatResult *result);
#endif

#ifndef NTESRiskRequestCmdIDDefined
#define NTESRiskRequestCmdIDDefined
typedef enum {
    Cmd_GetHTPVersion = 7,  // SDK版本
    Cmd_GetDeviceId = 20,   // 获取服务端设备指纹
} RequestCmdID;
#endif

#ifndef NTESRiskOldPerceptionAPIDeprecated
#define NTESRiskOldPerceptionAPIDeprecated DEPRECATED_MSG_ATTRIBUTE("旧主接口已废弃，请使用 HTProtect。")
#endif

__attribute__((visibility("default")))
@interface NTESRiskUniPerception : NSObject

+ (NTESRiskUniPerception *)fomentBevelDeadengo NTESRiskOldPerceptionAPIDeprecated;

- (void)init:(NSString *)productId
    callback:(nullable HTPCallback)callback NTESRiskOldPerceptionAPIDeprecated;

- (AntiCheatResult *)getToken:(NSString *)businessId
                  withTimeout:(int)timeout NTESRiskOldPerceptionAPIDeprecated;

- (AntiCheatResult *)getToken:(NSString *)businessId
                  withTimeout:(int)timeout
                     useCache:(BOOL)useCache NTESRiskOldPerceptionAPIDeprecated;

- (void)getTokenAsync:(NSString *)businessId
          withTimeout:(int)timeout
      completeHandler:(GetTokenCallback)callback NTESRiskOldPerceptionAPIDeprecated;

- (void)getTokenAsync:(NSString *)businessId
          withTimeout:(int)timeout
             useCache:(BOOL)useCache
      completeHandler:(GetTokenCallback)callback NTESRiskOldPerceptionAPIDeprecated;

- (NSString *)ioctl:(RequestCmdID)request
           withData:(NSString *)data NTESRiskOldPerceptionAPIDeprecated;

@end

NS_ASSUME_NONNULL_END
