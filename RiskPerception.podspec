# Created by yuxilong on 2026/10/20.
Pod::Spec.new do |s|
  s.name = 'RiskPerception'
  s.version = '3.5.2'
  s.summary = '网易易盾设备风控 SDK，共享二进制依赖。'
  s.homepage = 'https://github.com/BaiTu-iOS/RiskPerception'
  s.author = { 'yuxilong' => '305758560@qq.com' }
  s.license = { :type => 'Commercial', :text => 'Copyright NetEase. Use of the SDK is subject to the vendor license agreement.' }
  s.source = { :git => 'https://github.com/BaiTu-iOS/RiskPerception.git', :tag => s.version.to_s }
  s.ios.deployment_target = '11.0'
  s.static_framework = true
  # 主 SDK 为静态库，配套 Plugin 为动态库，交由 CocoaPods 统一链接和嵌入。
  s.vendored_frameworks = 'SDK/RiskPerception.xcframework', 'SDK/RiskPerceptionPlugin.xcframework'
  s.frameworks = 'Foundation', 'UIKit', 'CoreLocation', 'CoreTelephony', 'SystemConfiguration', 'Security'
  s.libraries = 'c++'
end
