# chatserver
可以工作在nginx tcp负载均衡环境中的集群聊天服务器和客户端源码 基于muduo实现 redis mysql

编译方式：
cd build
rm -rf *
cmake ..
make

chatserver 目录下
bin：ChatClient ChatServer 可执行文件
build：编译的中间文件
include：头文件
src：源文件，包含客户端和服务端
thirdparty：包含json.hpp文件
autobuild.sh：自动编译脚本

