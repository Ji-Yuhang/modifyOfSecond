序列化和反序列化依赖 boost 库的 serialization

centos 安装 boost
```
sudo yum install boost boost-devel boost-doc
```

编译式链接 boost_serialization
```
g++ client.cpp -lboost_serialization -o client
g++ server.cpp -lboost_serialization -o server
```

如果出错，修改boost_serialization 为 boost-serialization
```
g++ client.cpp -lboost-serialization -o client
g++ server.cpp -lboost-serialization -o server
```

