![](https://i.loli.net/2020/12/10/BW8HVtKTbISrPYv.png)

# GeoIP2 · CN
🇨🇳 最小巧、最准确、最实用的 中国大陆 IP 段 + GeoIP2 数据库 🇨🇳

## 🔖 设计初衷
目前市面上绝大多数的代理工具都依赖于 GeoIP2 数据库判断地址所属地。它们的规则结尾部分一般都会有一条类似 `GEOIP, CN`，用来查询目的 IP 地址是否属于中国大陆，从而判断是否直连。

这些代理工具通常使用的 GeoIP2 数据库是来自于 MaxMind 的 [GeoLite2](https://dev.maxmind.com/geoip/geoip2/geolite2/) 免费数据库。这个数据库目前存在一下几个问题：

* 获取不便：从 2019 年 12 月 30 日起，必须注册后才能下载
* 数据量大：数据库庞大，包含全球的 IP 地址段，约 4 MB
* 准确度低：对中国大陆的 IP 地址判定不准，如：香港阿里云的 IP 被判定为新加坡、中国大陆等

新的政策要求注册才能下载会增加时间成本，而且会让自动化下载的难度大大增加。

庞大的数据量无可厚非，但是对于大多数中国大陆的用户来说，仅需要去判断 IP 的地理位置是否属于中国大陆境内，其他国家的 IP 一律代理。过多的数据量会增加载入时间，降低查询效率；

而最致命的问题就是准确度低，这会导致代理工具查询后得到错误，做出错误的分流判定，最终导致用户体验不佳，如：网站无法访问、访问缓慢等问题。

## 🥳 项目介绍
项目选取更新较为频繁、广受好评、准确度高的 **ipip.net** 和 **纯真** IP 数据库的中国大陆 IP 地址段信息进行合并、去重、整理操作，最终生成仅含有中国大陆 IP 信息的 GeoIP2 数据库。准确度高、用户使用体验好。

GeoIP2 数据库的大小仅为 111 KB，对比原来庞大的 4 MB 数据库，显得非常小巧实用，加载时间极短、查询效率极高。

项目直接托管于 GitHub，并使用 CDN 全球分发，无需注册，下载速度极快。

项目每隔 3 天通过全自动化部署自我更新，时刻保持最佳体验。

### 📥 下载链接
| 📦 项目 | 📃 文件 | 🐙 GitHub RAW | 🚀 CDN 加速 | 🔧 适用范围
|  :--:  |  :--:  |     :--:     |     :--:    | ---- |
| IP-CIDR 列表 | CN-ip-cidr.txt | [点我下载](https://github.com/Hackl0us/GeoIP2-CN/raw/release/CN-ip-cidr.txt) | [点我起飞](https://cdn.jsdelivr.net/gh/Hackl0us/GeoIP2-CN@release/CN-ip-cidr.txt) | 防火墙、较老的代理工具等 | 
| GeoIP2 数据库 | Country.mmdb | [点我下载](https://github.com/Hackl0us/GeoIP2-CN/raw/release/Country.mmdb) | [点我起飞](https://cdn.jsdelivr.net/gh/Hackl0us/GeoIP2-CN@release/Country.mmdb) | Surge, Shadowrocket,<br>QuantumultX, Clash<br>等较新的代理工具|

对于网络状况良好、无污染的环境下，建议选择 GitHub RAW 的方式下载，因为可以第一获取到最新的资源，因为服务器在境外，可能下载响应时间和速度稍长，但因为文件小，所以通常问题不大。

对于网络状况不好，存在污染的环境下，建议选择 CDN 加速的方式下载，速度非常快。但是可能存在缓存未更新的情况，很可能下载到旧的资源。

### 🙋🏻‍♂️ 使用方式

⚠️ 注意：任何代理工具在使用本项目提供的数据库前，请务必确保以下 3 点（请根据工具语法调整规则）：
* 禁用与 中国大陆 IP 地址段 直连策略 相关的规则或规则集
    ``` bash
    RULE-SET, https://handsome.hackl0us.com/China-IP.list, DIRECT # 务必禁用或删除
    GEOIP, CN, DIRECT # 与上一条类似的规则与本条规则不可共存
    ```

* 规则中使用 `GEOIP, CN, DIRECT` 来调用数据库查询，且该条规则建议紧随最终规则之上，避免多余的 DNS 查询，降低效率。
    ``` bash
    ... 省略诸多规则 ...
    GEOIP, CN, DIRECT # 建议在这里使用规则
    FINAL, PROXY # 最终规则
    ```

* 规则中不可以存在其他国家或地区的 `GEOIP` 规则，因为数据库中仅包含中国大陆地区的 IP 地址段记录
    ``` bash
    GEOIP, US, PROXY # 错误，无法查询到相关记录
    GEOIP, AU, PROXY # 错误，无法查询到相关记录
    GEOIP, HK, PROXY # 错误，无法查询到相关记录
    GEOIP, CN, DIRECT # 正确
    ```

#### Surge 

**Surge for macOS**

⚠️ 软件版本要求 `4.0.2 (1215) [Beta]` 或更高

打开软件 Dashboard > Setting > General > 在 GeoIP Database 处粘贴上方复制的 `Country.mmdb` 下载链接，点击 Update Now 即可。

**Surge for iOS / iPadOS** 

⚠️ 软件版本要求 `4.10.0 (1851) [TestFlight]` 或更高

打开 App > Home 页面拉至最下 > More Settings > GeoIP Database > 在 CUSTOM GEOIP DATABASE URL 处粘贴上方复制的 `Country.mmdb` 下载链接，点击 Update Now 即可。

#### Clash 及其衍生工具

**ClashX 和 ClashX Pro**
⚠️ 软件版本要求 `1.31.2` 或更高

打开「配置」> 「实验性功能」> 「更新 IP 数据库」，在「自定义下载地址」处粘贴上方复制的 `Country.mmdb` 下载链接，点击确定即可。

**Clash for Windows**

工具开发者 [Fndroid](https://github.com/Fndroid/clash_for_windows_pkg) 暂未在工具提供内提供可以自定义 GeoIP 数据库的方式，目前需要使用手动替换的方式来使用项目中提供的数据库。

配置方式：打开软件控制面板 > General 选项卡 > 点击 Home Directory 区域下方的 「Open Directory」 > 用本项目提供的 `Country.mmdb` 数据库替换弹出窗口中的同名文件 > 重新启动工具

**OpenClash for OpenWRT**

工具开发者 [@vernesong](https://github.com/vernesong/OpenClash) 已经积极跟进，在 `v0.40.17` 版本中已经添加了自定义 GEOIP 和自定义大陆 IP 段的功能，并将本项目提供的数据库作为选项提供，非常友好。

配置方式：打开 OpenClash 配置页面 > 全局设置 > GEOIP 数据库订阅 >  下拉菜单中选择本项目 > 保存并应用。另外可以根据个人偏好，设定数据库更新时间间隔（本项目每 3 天更新一次）。

**Clash for Android**

工具开发者 [@Kr328](https://github.com/Kr328/ClashForAndroid) 明确表示不会支持自定义 GeoIP 数据库功能，态度非常坚决。给出的原因是「没有有效的校验手段」和「应用不针对中国大陆用户设计」，具体原因可以查看:

* [Kr328/ClashForAndroid#749](https://github.com/Kr328/ClashForAndroid/issues/749) 
* [Kr328/ClashForAndroid#411 (comment)](https://github.com/Kr328/ClashForAndroid/issues/411#issuecomment-640780469)


#### ShadowRocket 和 Quantumult X
直接在 Safari 中打开 `Country.mmdb` 下载链接，Safari 下载完毕后页面下方会提示 “在...中打开”，点击完成导入。


## 🏅 版权声明

本项目 Fork 自 [JMVoid/ipip2mmdb](https://github.com/JMVoid/ipip2mmdb) 项目，并由 [Hackl0us](https://github.com/Hackl0us) 加以调整和修改。

项目中所使用的 IP 地址信息来自于 [17mon/china_ip_list](https://github.com/17mon/china_ip_list)（基于 ipip.net）和 [metowolf/iplist](https://github.com/metowolf/iplist) （基于 纯真 IP）。

GeoIP® 商标版权归 [MaxMind](https://www.maxmind.com/) 公司所有。

项目的 Soial Preview 图片来源于 [Wikimedia Commons](https://commons.wikimedia.org/wiki/File:Chinese_Dragon.svg)，其版权信息为 [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/)。
