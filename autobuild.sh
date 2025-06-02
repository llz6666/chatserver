#!/bin/bash

set -x  # 启用调试模式，打印每一步执行的命令

# 清空 build 目录
rm -rf $(pwd)/build/*

# 进入 build 目录
cd $(pwd)/build

# 运行 CMake 和 make
cmake ..
make
    
