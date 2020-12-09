# GeoIP2 · CN
🇨🇳 最小巧、最准确、最实用的 中国大陆 IP 段 + GeoIP2 数据库 🇨🇳

## 🔖 设计原因
目前市面上绝大多数的代理工具都依赖于 GeoIP 数据库判断地址所属地。它们的规则结尾部分一般都会有一条类似 `GEOIP, CN`，用来查询目的 IP 地址是否属于中国大陆，从而判断是否直连。

这些代理工具通常使用的 GeoIP 数据库是来自于 MaxMind 的 [GeoLite2](https://dev.maxmind.com/geoip/geoip2/geolite2/) 免费数据库。这个数据库目前存在一下几个问题：

* 获取不便：从 2019 年 12 月 30 日起，必须注册后才能下载
* 数据量大：数据库庞大，包含全球的 IP 地址段，约 4 MB
* 准确度低：对中国大陆的 IP 地址判定不准，如：香港阿里云的 IP 被判定为新加坡、中国大陆等

新的政策要求注册才能下载会增加时间成本，而且会让自动化下载的难度大大增加。

庞大的数据量无可厚非，但是对于大多数中国大陆的用户来说，仅需要使用 GEOIP = CN 的地址段做判断即可，其他国家的 IP 一律代理。过多的数据量会增加载入时间，降低查询效率；

而最致命的问题就是准备度低，这会导致代理工具查询后得到错误，做出错误的分流判定，最终导致用户体验不佳，如：网站无法访问、访问缓慢等问题。

## 🥳 项目介绍
项目选取更新较为频繁、广受好评、准确度高的 **ipip.net** 和 **纯真** IP 数据库的中国大陆 IP 地址段信息进行合并、去重、整理操作，最终生成仅含有中国大陆 IP 信息的 GeoIP 数据库。准确度高、用户使用体验好。

GeoIP 数据库的大小仅为 111 KB，对比原庞的 4 MB 数据库，显得非常小巧实用，加载时间极短、查询效率极高。

项目直接托管于 GitHub，并使用 CDN 全球分发，无需注册，下载速度极快。

项目每隔 3 天通过全自动化部署自我更新，时刻保持最佳体验。

### 📥 下载链接
| 📦 项目 | 📃 文件 | 🐙 GitHub RAW | 🚀 CDN 加速 | 
|  :--:  |  :--:  |     :--:     |     :--:    |
| IP-CIDR 列表 | geoip-cn.txt | [点我下载](https://github.com/Hackl0us/GeoIP-CN/raw/master/artifacts/geoip-cn.txt) | [点我起飞](https://cdn.jsdelivr.net/gh/Hackl0us/GeoIP-CN@master/artifacts/geoip-cn.txt) |
| GeoIP2 数据库 | Country.mmdb | [点我下载](https://github.com/Hackl0us/GeoIP-CN/raw/master/artifacts/Country.mmdb) | [点我起飞](https://cdn.jsdelivr.net/gh/Hackl0us/GeoIP-CN@master/artifacts/Country.mmdb) |

对于网络状况良好、无污染的环境下，建议选择 GitHub RAW 的方式下载，因为可以第一获取到最新的资源，因为服务器在境外，可能下载响应时间和速度稍长，但因为文件小，所以通常问题不大。

对于网络状况不好，存在污染的环境下，建议选择 CDN 加速的方式下载，速度非常快。但是可能存在缓存未更新的情况，很可能下载到旧的资源。

### 🙋🏻‍♂️ 使用方式
* 中国 IP-CIDR 列表 (`geoip-cn.txt`)：可供防火墙、较老的代理工具使用
* 中国 GeoIP2 数据库 (`Country.mmdb`)：可供 Surge / Clash 等代理工具使用

#### Surge 
Surge 用户请确保你的软件版本满足以下要求：

* Surge for macOS: `4.0.2 (1215)` 或更高
* Surge for iOS / iPadOS: `4.10.0 (1851)` 或更高

macOS 💻 配置方式：Setting - General - GeoIP Database 处粘贴上方复制的 `Country.mmdb` 下载链接，点击 Update Now 即可。

iOS / iPadOS 📱 配置方式： Home 页面拉至最下 - More Settings - 
GeoIP Database - CUSTOM GEOIP DATABASE URL 处粘贴上方复制的 `Country.mmdb` 下载链接，点击 Update Now 即可。

#### Clash
Clash 用户直接通过上面链接下载 `Country.mmdb` 并替换掉 Clash 配置文件夹下的同名文件即可。

## 🏅 版权说明
本项目 Fork 自 [JMVoid/ipip2mmdb](https://github.com/JMVoid/ipip2mmdb) 项目，并由 [Hackl0us](https://github.com/Hackl0us) 加以调整和修改。

项目中所使用的 IP 地址信息来自于 [17mon/china_ip_list](https://github.com/17mon/china_ip_list)（基于 ipip.net）和 [metowolf/iplist](https://github.com/metowolf/iplist) （基于 纯真 IP）。