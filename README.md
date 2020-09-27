

### 简介
本项目将ipip中国地址转换 MaxMind mmdb的格式。由于MaxMind会把部分污染的IP错误归类为中国地址，导致不定时出现无法代理的情况。而IPIP提供的分类更为准确。因此这是一个临时解决方案，用于将ipip的china_ip_list转成MaxMind数据库格式并用于clash分流。

### 使用
对于Clash用户只需要直接下载Country.mmdb并覆盖原来的Country.mmdb
Country.mmdb只包含中国的ip列表，并没有其他国家数据
每月自动从 [ipip](https://raw.githubusercontent.com/17mon/china_ip_list/master/china_ip_list.txt) 抓取china_ip_list进行转换

### 代码及下载
源代码在master branch
生成mmdb库在release branch下载

### 链接
| 文件 | release分支 |
| ------ | ------ | 
|Country.mmdb | [链接](https://raw.githubusercontent.com/JMVoid/ipip2mmdb/release/Country.mmdb) |

### 扩展
verify代码用来验证在2020.9月发现某些IP会被MaxMind错误归类为中国IP