# RiskPerception

网易易盾 iOS 设备风控 SDK 的 CocoaPods 二进制分发仓库。由 BTNetwork 与 BTHttpClient 共同依赖，避免各自内置同名 XCFramework 导致冲突。

## 接入

```ruby
source 'https://github.com/BaiTu-iOS/baitu-specs.git'
source 'https://cdn.cocoapods.org/'
pod 'RiskPerception', '3.5.2'
```

包含 `RiskPerception.xcframework`（静态库）及 `RiskPerceptionPlugin.xcframework`（动态库），支持 iOS arm64 与模拟器 arm64/x86_64，最低 iOS 11。CocoaPods 负责链接及动态插件嵌入。原有 `import RiskPerception` 与 `<RiskPerception/HTProtect.h>` 不变。

依赖方应移除自身 podspec 中的这两份 vendored_frameworks，统一声明 `s.dependency 'RiskPerception', '3.5.2'`。源码与二进制 subspec 均应继承此依赖，避免仅源码接入时有效。已将 SDK 静态链接进旧组件二进制的产物需要重新构建，修改 podspec 不能清除旧产物里的符号。

本仓库按组件发布版本 `3.5.2` 管理，二进制沿用现有组件中的文件，不修改供应商产物：主 framework 的 CFBundleShortVersionString 为 1.8.0（build 1740），Plugin 为 1.0（build 1）。这些 bundle 元数据不作为 Pod 发布版本。

SDK 属于网易，使用须遵循供应商许可协议，本仓库不另行授予 SDK 使用许可。SDK 仍由宿主统一初始化一次；两个网络组件共存时，BTHttpClient 的 `shuMei`、`yiDunProductID` 设为 nil，由 BTNetwork 初始化。
