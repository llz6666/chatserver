# chatserver 集群聊天服务器（基于 muduo、redis、MySQL）
这是一个高性能的集群聊天系统，采用 **muduo 网络库** 实现，使用 **Redis 发布订阅机制** 做跨服务器通信，并通过 **MySQL** 管理用户数据。支持在 **Nginx TCP 负载均衡** 环境中部署，实现真正的分布式高并发聊天服务。

## 项目结构
chatserver/
├── bin/ # 编译后生成的可执行文件 ChatClient / ChatServer  
├── build/ # CMake 构建中间目录  
├── include/ # 头文件  
├── src/ # 源文件（客户端、服务端核心逻辑）  
├── thirdparty/ # 第三方依赖（如 json.hpp）  
├── autobuild.sh # 自动构建脚本  
└── README.md # 项目说明文档  

## 编译方式：  
```bash  
cd build  
rm -rf *  
cmake ..  
make  
或使用自动脚本：  
./autobuild.sh  

## 功能特性
 客户端与服务端基于 TCP 长连接通信

 支持私聊和群聊

 用户注册、登录、好友添加

 离线消息存储

 Redis 发布/订阅实现跨服务器转发

 聊天记录持久化到 MySQL

 可部署于 Nginx TCP 负载均衡后端，实现服务扩展

## 第三方依赖
muduo - 高性能 C++ 网络库

Redis - 内存数据结构存储系统

MySQL - 关系型数据库

nlohmann/json - 现代 C++ JSON 库


