## 静态库

静态库必须按照`lib[name].a`的规则命名

## 动态链接库的创建和使用

1. 生成动态库

```
gcc -fpic -shared -o libpr.so pr1.c pr2.c
```

2. 隐式调用动态库 - 编译使调用库函数代码时指明动态库的位置和名字

```
gcc -o main_so main.c ./libpr.so
./main_so
```

3. 显示调用动态库 - 会查找/usr/lib,/lib目录下的动态函数库，若生成的库不在里面，则使用以下方式

    1. 把libpr.so复制到/usr/lib或/lib
    2. export LD_LIBRARY_PATH=$(pwd)
    3. 在/etc/ld.so.conf加入生成的库的目录，然后执行/sbin/ldconfig

    > /etc/ld.so.conf存放的是链接器和加载器搜索共享库时要检查的目录

采用第二种方案：

```
export LD_LIBRARY_PATH=$(pwd)
gcc -o main_so_2 main.c -L. -lpr
./main_so_2
```