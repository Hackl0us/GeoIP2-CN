![](https://i.loli.net/2020/12/10/BW8HVtKTbISrPYv.png)

# GeoIP2 · CN
🇨🇳 小巧精悍、准确、实用 GeoIP2 数据库 🇨🇳

## 🔖 项目背景
目前市面上绝大多数的代理工具都依赖于 GeoIP2 数据库判断地址所属地。它们的规则结尾部分一般都会有一条类似 `GEOIP, CN`，用来查询目的 IP 地址是否属于中国大陆，从而判断是否直连。

这些代理工具通常使用的 GeoIP2 数据库是来自于 MaxMind 的 [GeoLite2](https://dev.maxmind.com/geoip/geoip2/geolite2/) 免费数据库。这个数据库目前存在一下几个问题：

* 获取不便：从 2019 年 12 月 30 日起，必须注册后才能下载
* 数据量大：数据库庞大，包含全球的 IP 地址段，约 4 MB
* 准确度低：对中国大陆的 IP 地址判定不准，如：香港阿里云的 IP 被判定为新加坡、中国大陆等

新的政策要求注册才能下载会增加时间成本，而且会让自动化下载的难度大大增加。

庞大的数据量无可厚非，但是对于大多数中国大陆的用户来说，仅需要去判断 IP 的地理位置是否属于中国大陆境内，其他国家的 IP 一律代理。过多的数据量会增加载入时间，降低查询效率；

而最致命的问题就是准确度低，这会导致代理工具查询后得到错误，做出错误的分流判定，最终导致用户体验不佳，如：网站无法访问、访问缓慢等问题。

## 🥳 项目优势
### 👓 准确度高
项目选取更新较为频繁、广受好评、准确度高的 **ipip.net** 和 **纯真** IP 数据库的中国大陆 IP 地址段信息进行合并、去重、整理操作，最终生成仅含有中国大陆 IP 信息的 GeoIP2 数据库。准确度高、用户使用体验好。

### ⚛️ 实用精悍
GeoIP2 数据库的大小仅为 100 KB 左右，对比原来庞大的数据库，显得非常小巧实用，加载时间极短、查询效率极高。

项目仅包含大陆用户需要的中国 IP 地址段，无需获取多余的其他国家或地区的 IP 地址，完美贴合使用需求。

### 🌍 CDN 分发
项目直接托管于 GitHub，并使用 CDN 全球分发，瞬间即可完成数据库的下载和加载，在较差的网络环境下也较容易完成数据库的更新。

### 🤖️ 自动化更新
项目每隔 3 天通过全自动化部署自动更新，时刻保持最佳体验，无需人工干预。

## 📥 下载链接
| 📦 项目 | 📃 文件 | 🐙 GitHub RAW | 🚀 CDN 加速 | 🔧 适用范围
|  :--:  |  :--:  |     :--:     |     :--:    | ---- |
| IP-CIDR 列表 | CN-ip-cidr.txt | [点我下载](https://github.com/Hackl0us/GeoIP2-CN/raw/release/CN-ip-cidr.txt) | [点我起飞](https://cdn.jsdelivr.net/gh/Hackl0us/GeoIP2-CN@release/CN-ip-cidr.txt) | 防火墙、较老的代理工具等 |
| GeoIP2 数据库 | Country.mmdb | [点我下载](https://github.com/Hackl0us/GeoIP2-CN/raw/release/Country.mmdb) | [点我起飞](https://cdn.jsdelivr.net/gh/Hackl0us/GeoIP2-CN@release/Country.mmdb) | Surge, Shadowrocket,<br>QuantumultX, Clash<br>等较新的代理工具|

对于网络状况良好、无污染的环境下，建议选择 GitHub RAW 的方式下载，因为可以第一获取到最新的资源，因为服务器在境外，可能下载响应时间和速度稍长，但因为文件小，所以通常问题不大。

对于网络状况不好，存在污染的环境下，建议选择 CDN 加速的方式下载，速度非常快。但是可能存在缓存未更新的情况，很可能下载到旧的资源。

## 📲️ 配置方式
请参考项目 [Wiki](https://github.com/Hackl0us/GeoIP2-CN/wiki) 提供的文档教程，在各个工具中自定义 GeoIP2 数据库。

目前 Wiki 中已经添加了如下工具的配置教程，欢迎大家在 Issues 中补充：

* [☄️ Surge](https://github.com/Hackl0us/GeoIP2-CN/wiki/Surge)
  * Surge 配置文件修改
  * Surge for iOS 图形化配置
  * Surge for macOS 图形化配置
* [🎡 Quantumult X](https://github.com/Hackl0us/GeoIP2-CN/wiki/Quantumult-X)
* [🚀 Shadowrocket](https://github.com/Hackl0us/GeoIP2-CN/wiki/Shadowrocket)
* [🐱 Clash](https://github.com/Hackl0us/GeoIP2-CN/wiki/Clash)
  * ClashX / ClashX Pro (macOS)
  * Clash for Windows
  * OpenClash (OpenWRT)
  * Clash for Android
  * Stash (iOS)

## ⚠️ 注意事项
1. **禁用或删除** 与 **中国大陆 IP 地址段** 相关的规则或规则集
    ``` bash
    RULE-SET, https://handsome.hackl0us.com/China-IP.list, DIRECT # 禁用或删除类似规则
    GEOIP, CN, DIRECT # 与上一条类似的规则与本条规则不可共存
    ```

2.  GEOIP-CN 查询规则建议**紧随最终规则之上**，以避免域名规则被忽略导致判断错误。
    ``` bash
    # ... 省略其他规则 ...
    GEOIP, CN, DIRECT # 👀 建议在这里使用规则
    FINAL, PROXY # ⬇️ 最终规则
    ```

3. 规则中**不可以**存在其他国家或地区的 `GEOIP` 查询规则，因为项目提供的数据库中**仅包含中国大陆地区的 IP 地址段记录**
    ``` bash
    GEOIP, US, PROXY # ❌ 错误，无法查询到相关记录
    GEOIP, AU, PROXY # ❌ 错误，无法查询到相关记录
    GEOIP, HK, PROXY # ❌ 错误，无法查询到相关记录
    GEOIP, CN, DIRECT # ✅ 正确
    ```

## 🏅 版权声明

本项目 Fork 自 [JMVoid/ipip2mmdb](https://github.com/JMVoid/ipip2mmdb) 项目，并由 [Hackl0us](https://github.com/Hackl0us) 加以调整和修改。

项目中所使用的 IP 地址信息来自于 [17mon/china_ip_list](https://github.com/17mon/china_ip_list)（基于 ipip.net）和 [metowolf/iplist](https://github.com/metowolf/iplist) （基于 纯真 IP）。

GeoIP® 商标版权归 [MaxMind](https://www.maxmind.com/) 公司所有。

项目的 Soial Preview 图片来源于 [Wikimedia Commons](https://commons.wikimedia.org/wiki/File:Chinese_Dragon.svg)，其版权信息为 [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/)。
