# chatserver 集群聊天服务器（基于 muduo、redis、MySQL）
这是一个高性能的集群聊天系统，采用 **muduo 网络库** 实现，使用 **Redis 发布订阅机制** 做跨服务器通信，并通过 **MySQL** 管理用户数据。支持在 **Nginx TCP 负载均衡** 环境中部署，实现真正的分布式高并发聊天服务。

## 项目结构
chatserver/  
bin/：#编译后生成的可执行文件 ChatClient ChatServer 可执行文件  
build：编译的中间文件
include：头文件
src：源文件，包含客户端和服务端
thirdparty：包含json.hpp文件
autobuild.sh：自动编译脚本

编译方式：  

cd build
rm -rf *
cmake ..
make

