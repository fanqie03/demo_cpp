`gcc -E main.c -o main.i` - 预处理（生成预处理完的文件）

`gcc -S main.i -o` - 编译（生成汇编代码）

`gcc -c main.s -o main.o` - 汇编（生成中间目标文件）

`gcc main.o -o main` - 链接（生成可执行程序）