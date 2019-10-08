# proto

```shell
protoc -I=$SRC_DIR --CPP_OUT=$DST_DIR $SRC_DIR/addressbook.proto
# 示例中执行
protoc --cpp_out=/tmp addressbook.proto
# 编译read.cpp
g++ addressbook.pb.cc read.cpp -o read `pkg-config --cflags --libs protobuf`
# 编译write.cpp
g++ addressbook.pb.cc write.cpp -o write `pkg-config --cflags --libs protobuf`
```