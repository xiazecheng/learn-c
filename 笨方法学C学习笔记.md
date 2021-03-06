## 	笨方法学C语言 学习笔记

### 练习1~7

>printf()函数打印变量

- 使用 `int`声明，使用 `%d` 来打印
- 使用 `float` 或 `double` 声明，使用 `%f `来打印
- 使用 `char` 来声明 ，以 ' （单引号）的单个字符来表示，使用 `%c `来打印
- 使用 `char name []` 来声明，以周围带有  "  的一些字符来表示， 使用` %s `来打印（字符串）
- 使用 `long` 声明，使用 `%ld `来打印 （长整型）

Tips:  '\0' 空字节字符，实际上是数字0



### 练习8

> 在32位计算机中各个类型所占字节（1个字节8位）

- `int` 占4个字节
- `char` 占1个字节


> sizeof 关键字

- `type *ptr *sizeof(ptr)* `结果为4 (指针存放的内存地址，存放一个地址需要4个字节)
- `char ss[] = "01233456789";`  `sizeof(*ss)`结果是1，`*ss`是第一个字符 



### **练习9**

> 初始化

- 在数组中，`int` 类型如果没有初始化，用 0 填充
- 在数组中，`char` 类型如果没有初始化，用 '\0' 填充

可以用 `char *name` 创建字符串（推荐使用）



补充说明

> main 函数参数说明

| 参数           | 含义     |
| ------------ | ------ |
| int argc     | 代表参数个数 |
| char *argv[] | 代表参数   |

> 转换符说明

| 转换符    | 含义                        |
| ------ | ------------------------- |
| %a(%A) | 浮点数、十六进制数字和p-(P-)记数法(C99) |
| %c     | 字符                        |
| %d     | 有符号十进制整数                  |
| %f     | 浮点数(包括float和doulbe)       |
| %e(%E) | 浮点数指数输出[e-(E-)记数法]        |
| %g(%G) | 浮点数不显无意义的零"0"             |
| %i     | 有符号十进制整数(与%d相同)           |
| %u     | 无符号十进制整数                  |
| %o     | 八进制整数 e.g.0123            |
| %x(%X) | 十六进制整数0f(0F) e.g.0x1234   |
| %p     | 指针                        |
| %s     | 字符串                       |
| %%     | "%"                       |


### 练习15

> 指针词库

| 声明                  | 含义                                       |
| ------------------- | ---------------------------------------- |
| type *ptr           | type 类型的指针，名为 ptr                        |
| \*ptr               | ptr 所指向                                  |
| \*(ptr + i)         | (ptr 所指向的位置加上 i )的值（以字节为单位的话，应该是 ptr 所指向的位置再加上 sizeof(type) * i ） |
| ptr++               | 自增ptr指向的位置                               |
| &thing              | thing 的内存地址                              |
| type  *ptr = &thing | 名为ptr， type类型的指针， 值设置为 thing 的地址         |


### 练习16

> struct 结构体

- 在C语言中，可以使用结构体（struct）来存放一组不同类型的数据
- 结构体是一种集合，它里面包含了多个变量或数组，它们的类型可以相同，也可以不同，每个这样的变量或数组都称为结构体的成员（member）
- 结构体成员的定义方式与变量和数组的定义方式相同，只是不能初始化。
- 如果结构体是指针的形式，可以通过` x->y` （是 `(*x).y `的简写）来访问和设置成员变量（自己的理解）
- 如果结构体不是以指针的形式创建，可以通过` x.y `来访问和设置成员变量

> malloc 函数

- 所在头文件 `stdlib.h`


- 用于内存分配，向 OS 申请一块原始内存
- 参数 : 申请内存的大小。 例：`sizeof( struct name)`

> assert 函数

- 所在头文件 `assert.h`


- 用来确保从 `malloc` 得到一块有效内存（是否返回 `NULL` ）

> strdup 函数

- 所在头文件 `string.h`
- 用于复制字符串，行为类似 `malloc` 函数，但是它同时会将原来的字符串复制到新创建的内存

> free 函数

- 所在头文件 `stdlib.h`


- 调用 `free` 函数之前要先确保变量不为 `NULL` （通过 `assert` 函数）


- 用于交还通过 `malloc` 和 `strdup` 得到的内存，不这么则会出现 "内存"



### 练习17

> \#define

- define是C语言中的预处理命令，它用于宏定义，可以提高源代码的可读性，为编程提供方便

- 文本替换，例：

  ```c
  #define MAX 10
  ```

- 函数定义，例：

  ```c
  #define MAX(a,b) ((a) > (b) ? (a) : (b))
  ```
  - *注意点:*

    - `#define Add(a,b) a+b`:

      > 在一般使用的时候是没有问题的，但是如果遇到如：c * Add(a,b) * d的时候就会出现问题，代数式的本意是a+b然后去和c，d相乘，但是因为使用了define（它只是一个简单的替换），所以式子实际上变成了c\*a + b\*d。

    - `#define pin (int*)`:

      > pin a,b;
      > 本意是a和b都是int型指针，但是实际上变成int* a,b;
      > a是int型指针，而b是int型变量。
      > 这是应该使用typedef来代替define，这样a和b就都是int型指针了。

  - 单行定义，例：

  ```c
  #define A(x) T_##x	// A(1) -> T_1
  #define B(x) #@x	// B(1)	-> '1'
  #define C(x) #x		// C(1)	-> "1"
  ```

- 多行定义，例：

  ```c
  #define MACRO(arg1,arg2) do { \
  test1; \
  test2; \
  }while(0)
  ```


- 定义宏和取消宏的方法：定义一个宏使用`#define`，取消一个宏定义使用`#undef`

- 使用宏进行条件编译，格式如下：`#ifdef … (#else) … #endif`

- 用define来处理头文件被头文件或者源文件包含的情况

  ```c
  #ifndef _HELLO_H_
  #define _HELLO_H_
  ...
  //文件内容
  ...
  #endif
  ```



> exit 函数

- 所在头文件 `stdlib.h`
- `exit(0)` 正常退出
- `exit(x)` (x不为0) 异常退出 

> errno 外部变量

- 所在头文件 `errno.h`


- 记录系统的最后一次错误代码

> perror 函数

- 所在头文件 `errno.h`


- 打印上一个函数发生错误的原因

> fopen 函数

- 所在头文件 `stdio.h`
- 函数原型 `FILE * fopen(const char * path, const char * mode)`;
- 打开文件，文件顺利打开后，指向该流的文件指针就会被返回。如果文件打开失败则返回NULL，并把错误代码存在 errno 中

> fread 函数

- 所在头文件 `stdio.h`
- 读取文件，函数原型 `size_t fread ( void *buffer,  size_t size,  size_t count,  FILE *stream);` 
  - *buffer： 用于接收数据的内存地址*
  - *size： 要读的每个数据项的字节数，单位是字节*
  - *count： 要读 count 个数据项，每个数据项 size 个字节*
  - *stream： 输入流*

> fclose 函数

- 所在头文件 `stdio.h`
- 函数原型 `int fclose( FILE *fp );`
- 关闭一个流

> rewind 函数

- 将文件内部的指针重新指向一个流的开头

> atoi 函数

- 所在头文件 `stdlib.h`
- 函数原型 `int atoi(const char *nptr);`
- 把字符串转换成整型

> NULL

- NULL 就是0，所以可以转成布尔值

> 堆和栈的内存分配

- 堆：电脑中的剩余内存，可以通过 malloc 访问它获取更多内存， OS会使用内部函数为你注册一块内存区域，并返回指向它的指针。当你使用完这片区域时，你应该使用 free 把它交还给OS，使之能被其他程序复用。如果你不这样做就会导致程序“泄漏”内存，但是Valgrind 会帮你监测这些内存泄漏
- 栈：是一个特殊的内存区域，它储存了每个函数的创建的临时变量，它们对于该函数为局部变量。它的工作机制是，函数的每个函数都会“压入”栈中，并且可以在函数内部使用。它是一个真正的栈数据结构，所以是后进先出的。这对于 main中所有类似 `char section` 和 `int id` 的局部变量也是相同的。使用栈的优点是，当函数退出时C编译器会从栈中“弹出”所有变量来清理。这非常简单，也防止了栈上变量的内存泄漏
  - *栈是一种特殊的线性表。其特殊性在于限定插入和删除数据元素的操作只能在线性表的一端进行*
- 理清内存的最简单的方式时遵守这条原则： 如果你的变量并不是从 `malloc `中获取的，也不是从一个 `malloc` 中获取的函数中获取的， 那么它在栈上
- 值得关注堆和栈的三个主要问题
  - *如果你从 `malloc` 中获取了一块内存， 并且把指针放在了栈上， 那么当函数退出时， 指针会被弹出而丢失*
  - *如果你在栈上存放了大量数据（比如大结构体和数组），那么会产生“栈溢出”并且程序会终止。这种情况下应该通过 `malloc` 放在堆上*
  - *如果你获取了指向栈上变量的指针， 并且将它用于传参或从函数返回，接收它的函数会产生“段错误”。因为实际的数据被弹出而消失，指针也会指向被释放的内存*

> strncpy 函数 

- 所在头文件 `string.h`
- 函数原型 `char *strncpy(char *dest,char *src,size_t n);`
- 复制字符串src中的内容（字符，数字、汉字....）到字符串dest中，复制多少由size_tn的值决定。如果src的前n个字符不含NULL字符，则结果不会以NULL字符结束。如果n<src的长度，只是将src的前n个字符复制到dest的前n个字符，不自动添加'\0'，也就是结果dest不包括'\0'，需要再手动添加一个'\0'。如果src的长度小于n个字节，则以NULL填充dest直到复制完n个字节。src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符长度+'\0'。


---

### 练习18

> typedef

- 使用关键字 `typedef `可以为类型起一个新的别名
- `typedef` 可以给数组、指针、结构体等类型定义别名
- `typedef` 还可以为函数指针类型定义别名

> 函数指针

- 可以函数名作为函数指针类型的参数，只要函数符合函数指针的原型

---

### 练习19

> 快速查看预处理器所做事情的方法

```c
cpp xxx.c | less
```

- 可以看到你使用`#include`包含的其他文件的内容

> \#ifndef

- C预处理器可以通过条件判断来忽略一部分代码，`#ifndef` 是如果没有被定义的意思
- 它会检查是否已经出现过 #define xxx，如果已经出现，就跳过这段代码

> void 作用

- 对函数返回的限定，当函数不需要返回值时，必须使用void限定。例如： `void func(int, int)`
- 对函数参数的限定，当函数不允许接受参数时，必须使用void限定。例如：` int func(void)`
- void指针，由于void指针可以指向任意类型的数据，亦即可用任意数据类型的指针对void指针赋值，因此还可以用void指针来作为函数形参，这样函数就可以接受任意数据类型的指针作为参数。


> \#define NEW(T,N) Object_new(sizeof(T), T##Proto, N)

- 这条语句创建了一个宏，就像模板函数一样，无论你在哪里编写左边的代码，都会展开成右边的代码。这条语句仅仅是对我们通常调用的`Object_new`制作了一个快捷方式，并且避免了潜在的调用错误。在宏这种工作方式下，`T`、`N`还有`New`都被“注入”进了右边的代码中。`T##Proto`语法表示“将Proto连接到T的末尾”，所以如果你写下`NEW(Room, "Hello.")`，就会在这里变成`RoomProto`(完整展开：Object_new( sizeof(Room), RoomProto, "Hello." ))。

> \#define _(N) proto.N

- 这个宏是一种为对象系统设计的“语法糖”，将`obj->proto.blah`简写为`obj->_(blah)`。它不是必需的，但是它是一个接下来会用到的有趣的小技巧。

> Makefile构建程序

```c
CFLAGS=-Wall -g

all: ex19

ex19: object.o

clean:
  rm -f ex19
```

这个`Makefile`所做的事情仅仅是让`ex19`依赖于`object.o`。还记得`make`可以根据扩展名构建不同的文件吗？这相当于告诉`make`执行下列事情：

- 当我运行`make`时，默认的`all`会构建`ex19`。
- 当它构建`ex19`时，也需要构建`object.o`，并且将它包含在其中。
- `make`并不能找到`object.o`，但是它能发现`object.c`文件，并且知道如何把`.c`文件变成`.o`文件，所以它就这么做了。
- 一旦`object.o`文件构建完成，它就会运行正确的编译命令，从`ex19.c`和`object.o`中构建`ex19`。

> 结构体替代使用

- 当A结构体的第一个字段是另外一个结构体B时，可以将A当成B来使用，具体分解如下：
  - 我调用了`NEW(Room, "Hello.")`，C预处理器会将其展开为`Object_new(sizeof(Room), RoomProto, "Hello.")`。
  - 执行过程中，在`Object_new`的内部我分配了`Room`大小的一块内存，但是用`Object *el`来指向它。
  - 由于C将`Room.proto`字段放在开头，这意味着`el`指针实际上指向了能访问到完整`Object`结构体的，足够大小的一块内存。它不知道这块内存叫做`proto`。
  - 接下来它使用`Object *el`指针，通过`*el = proto`来设置这块内存的内容。要记住你可以复制结构体，而且`*el`的意思是“`el`所指向对象的值”，所以整条语句意思是“将`el`所指向对象的值赋给`proto`”。
  - 由于这个谜之结构体被填充为来自`proto`的正确数据，这个函数接下来可以在`Object`上调用`init`，或者`destroy`。但是最神奇的一部分是无论谁调用这个函数都可以将它们改为想要的东西。

> ex19,我自己的理解：NEW(xxx结构体, "说明")被展开为Object_new(sizeof(xxx结构体), xxxProto proto, "说明")。初始化xxxProto，给xxxProto设置object.c中的默认实现。然后分配了一块xxx结构体大小的内存，因为xxx结构体的第一个字段是Object proto, 而xxxProto本质上就是一个Object结构体， 所以可以把xxx结构体当成xxxProto来使用。*el = proto，将el的所指向的对象的值赋给proto，我的理解是告诉Object *el对应的结构体实现（可以把Object理解为一个interface，但是这个interface已经有了默认的实现，而各个xxxProto就是对它不同的实现。）。然后el调用的方法就是xxxProto所重新实现的方法，如果没有重新实现则调用object.c中的默认实现。



### 练习20

> \##\_\_VA_ARGS\_\_

```c
#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
```

- \_\_VA_ARGS\_\_  总体来说就是将左边宏中 ... 的内容原样抄写在右边 \_\_VA_ARGS\_\_ 所在的位置
- 当左边宏中的 ... 可变参数为空时会多一个“,”，编译器会报错，“##”的作用就是让编译器忽略\_\_VA_ARGS\_\_前面的逗号。

> \_\_FILE\_\_

- 宏在预编译时会替换成当前的源文件名

> \_\_FUNCTION\_\_

- 宏在预编译时会替换成当前的函数名称

> \_\_LINE\_\_

- 宏在预编译时会替换成当前的行号

> Makefile 中宏定义

- CFLAGS=-Dxxx（-D后面紧跟宏定义，不能有空格）

> 为什么不像`die`一样使用函数呢?

- 原因是需要在错误处理时使用`file:line`的数值和`goto`操作。如果你在函数在内部执行这些，你不会得到错误真正出现位置的行号，并且`goto`的实现也相当麻烦。

---

### 练习21

> 可用的数据类型

- `int`：存储普通的整数，默认为32位大小。ps：`int`在32或64位环境下为32位，但它不应该被看作平台无关的。如果需要用到平台无关的定长整数，请使用`int(n)_t`。
- `double`：存储稍大的浮点数。
- `float`：存储稍小的浮点数。
- `char`：存储单字节。
- `void`：表示“无类型”，用于声明不返回任何东西的函数，或者所指类型不明的指针，如 `void *thing`。
- `enum`：枚举类型，类似于整数，也可以转换为整数，但是通过符号化的名称访问或设置。当`switch`语句中没有覆盖到所有枚举的元素时，一些编译器会发出警告。



> 类型修饰符号（符号修饰符只对char和\*\*\* int 有效。\*\*\* int 默认为signed，而char根据具体实现，可以默认为signed，也可以为unsigned）

- `unsigned`：修改类型，使它不包含任何负数，同时上界变高。
- `signed`：可以储存正数和负数，但是上界会变为（大约）一半，下界变为和上界（大约）等长。
- `long`：对该类型使用较大的空间，使它能存下更大的数，通常使当前大小加倍。
- `short`：对该类型使用较小的空间，使它存储能力变小，但是占据空间也变成一半。
- `const`：表示变量在初始化之后不能改变。
- `valatile`：表示会做最坏的的打算，编译器不会对它做任何优化。通常仅在对变量做一些奇怪的事情时才会用到它。
- `register`：强制让编译器将这个变量保存在寄存器中，并且也可以无视它。目前的编译器更善于处理在哪里存放变量，所以应该只在确定这样会提升性能时使用它。



> 类型转换，C使用了一种“阶梯形类型提升”的机制，它会观察运算符两边的变量，并且在运算之前将较小边的变量转换为较大边。这个过程按照如下顺序：

1. `long double`
2. `double`
3. `float`
4. `long long`
5. `long`
6. `int (short, char)`（PS： `short` 和 `char` 会在运算之前转换成 `int `。同种类型的 `unsigned` 和 `signed` 运算， `signed` 保持字节不变转换成 `unsigned`。）




> 补充：原码、反码、补码

- 原码：将一个整数，转换成二进制，就是其原码。如单字节的5的原码为：0000 0101；-5的原码为1000 0101。

- 反码：正数的反码就是其原码；负数的反码是将原码中，除符号位以外，每一位取反。如单字节的5的反码为：0000 0101；-5的反码为1111 1010。

- 补码：正数的补码就是其原码；负数的反码+1就是补码。如单字节的5的补码为：0000 0101；-5的原码为1111 1011。

  在计算机中，正数是直接用原码表示的，如单字节5，在计算机中就表示为：0000 0101。负数用补码表示，如单字节-5，在计算机中表示为1111 1011。

  ​

> 类型大小，`stdint.h`为定长的整数类型定义了一些`typedef`，同时也有一些用于这些类型的宏。这比老的`limits.h`更加易于使用，因为它是不变的。这些类型如下：

| typedef  | 含义       |
| -------- | -------- |
| int8_t   | 8位符号整数   |
| uint8_t  | 8位无符号整数  |
| int16_t  | 16位符号整数  |
| uint16_t | 16位无符号整数 |
| int32_t  | 32位符号整数  |
| uint32_t | 32位无符号整数 |
| int64_t  | 64位符号整数  |
| uint64_t | 64位无符号整数 |

> ps：当用于对类型大小有要求的特定平台时，可以使用这些类型。如果你怕麻烦，不想处理平台相关类型的今后潜在的扩展的话，也可以使用这些类型。



下面的模式串为 (u)int(BITS)_t ，其中前面的 u 代表 unsigned ，BITS 是所占位数的大小。这些模式串返回了这些类型的最大（或最小）值。

| 模式串         | 含义                                       |
| ----------- | ---------------------------------------- |
| INT(N)_MAX  | N 位符号整数的最大正值，例如 INT16_MAX                |
| INT(N)_MIN  | N 位符号整数的最小负值                             |
| UINT(N)_MAX | N 位无符号整数的最大正值。为什么不定义其最小值，是因为最小值是0，不可能出现负值 |

<font color="red">notice:要注意，不要从字面上在任何头文件中去找 INT(N)_MAX 的定义。这里的 N 应该为特定整数，比如8、16、32、64，甚至可能是128。我在这个练习中使用了这个记法，就不需要显式写出每一个不同的组合了。</font>

在 stdint.h 中，对于 size_t 类型和足够存放指针的整数也有一些宏定义，以及其它便捷类型的宏定义。编译器至少要保证它们为某一大小，并允许它们为更大的大小。

| 宏定义               | 含义                                   |
| ----------------- | ------------------------------------ |
| int_least(N)_t    | 至少 N 位的整数                            |
| uint_least(N)_t   | 至少 N 位的无符号整数。                        |
| INT_LEAST(N)_MAX  | int_least(N)_t 类型的最大值                |
| INT_LEAST(N)_MIN  | int_least(N)_t 类型的最小值。               |
| UINT_LEAST(N)_MAX | uint_least(N)_t 的最大值。                |
| int_fast(N)_t     | 与 int_least(N)_t 相似，但是是至少 N 位的“最快”整数 |
| uint_fast(N)_t    | 至少 N 位的“最快”无符号整数                     |
| INT_FAST(N)_MAX   | int_fast(N)_t 的最大值                   |
| INT_FAST(N)_MIN   | int_fast(N)_t 的最小值                   |
| UINT_FAST(N)_MAX  | uint_fast(N)_t 的最大值。                 |
| intptr_t          | 足够存放指针的符号整数                          |
| uintptr_t         | 足够存放指针的无符号整数                         |
| INTPTR_MAX        | intptr_t 的最大值                        |
| INTPTR_MIN        | intptr_t 的最小值                        |
| UINTPTR_MAX       | uintptr_t的最大值                        |
| intmax_t          | 系统中可能的最大尺寸的整数类型                      |
| uintmax_t         | 系统中可能的最大尺寸的无符号整数类型                   |
| INTMAX_MAX        | intmax_t 的最大值                        |
| INTMAX_MIN        | intmax_t 的最小值                        |
| UINTMAX_MAX       | uintmax_t 的最大值                       |
| PTRDIFF_MIN       | ptrdiff_t 的最小值                       |
| PTRDIFF_MAX       | ptrdiff_t 的最大值                       |
| SIZE_MAX          | size_t 的最大值                          |



> 可用的运算符

这是一个全面的列表，关于你可以在C中使用的全部运算符。这个列表中我会标明一些东西：

| 运算符名称 | 含义                              |
| ----- | ------------------------------- |
| 二元运算符 | 该运算符有左右两个操作数：X + Y              |
| 一元运算符 | 该运算符作用于操作数本身 -X                 |
| 前缀    | 该运算符出现在操作数之前：++X                |
| 后缀    | 通常和前缀版本相似，但是出现在操作数之后，并且意义不同：X++ |
| 三元运算符 | 只有一个三元运算符，意思是“三个操作数”：X ? Y : Z  |



> 算数运算符

下面是基本的算数运算符，我将函数调用 '()' 放入其中因为它更接近“算数”运算。

| 运算符      | 含义         |
| :------- | ---------- |
| ()       | 函数调用       |
| *（二元运算符） | 乘法         |
| /        | 除法         |
| +（二元运算符） | 加法         |
| +（一元运算符） | 无变化        |
| ++（后缀）   | 读取变量然后自增   |
| ++（前缀）   | 自增变量然后读取   |
| --（后缀）   | 读取变量然后自减   |
| --（前缀）   | 自减变量然后读取   |
| -（二元运算符） | 减法         |
| -（一元运算符） | 取反，可用于表示负数 |



> 数据运算

它们用于以不同方式和形式访问数据。

| 运算符      | 含义                         |
| -------- | -------------------------- |
| ->       | 结构体指针的成员访问。一元 * 和 . 运算符的复合 |
| .        | 结构体值的成员访问                  |
| []       | 取数组下标。二元 + 和一元 * 运算符的复合    |
| sizeof   | 取类型或变量大小                   |
| &（一元运算符） | 取地址                        |
| *（一元运算符） | 取值（提领地址）                   |



> 逻辑运算符

它们用于测试变量的等性和不等性。

| 运算符  | 含义        |
| :--- | :-------- |
| <    | 小于        |
| <=   | 小于等于      |
| ==   | 等于（并不是赋值） |
| >    | 大于        |
| \>=  | 大于等于      |



> 位运算符

它们更加高级，用于修改整数的原始位。

| 运算符   | 含义        |
| ----- | --------- |
| &（二元） | 位与        |
| <<    | 左移        |
| \>>   | 右移        |
| ^     | 位异或       |
| \|    | 位或        |
| ~     | 取补（翻转所有位） |



> 布尔运算符

用于真值测试，仔细学习三元运算符，它非常有用。

| 运算符  | 含义                           |
| ---- | ---------------------------- |
| !    | 取非                           |
| &&   | 与                            |
| \|\| | 或                            |
| ?:   | 三元真值测试，X ? Y : Z读作 “若X则Y否则Z“ |



> 赋值运算符

复合赋值运算符在赋值同时执行运算。大多数上面的运算符都可以组成复合赋值运算符。

| 运算符  | 含义    |
| ---- | ----- |
| =    | 赋值    |
| %=   | 取余赋值  |
| &=   | 位与赋值  |
| *=   | 乘法赋值  |
| +=   | 加法赋值  |
| -=   | 减法赋   |
| /=   | 除法赋值  |
| <<=  | 左移赋值  |
| \>>= | 右移赋值  |
| ^=   | 位异或赋值 |
| \|=  | 位或赋值  |



> 可用的控制结构

下面是一些你没有接触过的控制结构：

| 结构       | 用法                                       |
| -------- | ---------------------------------------- |
| do-while | do { ... } while(X); 首先执行花括号中的代码，之后再跳出前测试 X 表达式 |
| break    | 放在循环中用于跳出循环                              |
| continue | 跳到循环尾                                    |
| goto     | 跳到你已经放置 label 的位置，你已经在 dbg.h 中看到它了，用于跳到 error 标签 |

---

### 练习22

> extern

- `extern`关键字告诉编译器这个变量已经存在， 但是它在别的“外部区域”里。通常它的意思是一个.c文件要用到另一个.c文件中定义的变量。（例如本章中在`ex22.h`头文件中定义了`extern int THE_SIZE`， 而`ex22_main.c`包含了`ex22.h`， 所以可以访问`ex22.c`中定义的`int THE_SIZE`变量（全局变量）。）

> static

- `static`关键字某种意义上是`extern`的反义词， 意思是这个变量只能在当前的`.c`文件中使用， 程序的其他部分不可访问。（可以提供`get`和`set`方法来设置、访问`static`变量）

> static（函数）

- 如果你使用`static`在函数中声明变量，它和文件中的`static`定义类似，但是只能够在该函数中访问。它是一种创建某个函数的持续状态的方法，但事实上它更少用于现代的C语言，因为它们很难和线程一起使用。

> 作用域，栈和bug

- 代码块中创建新的变量（外部已有变量）时， 在退出代码块之前会拥有自己的值， 并且屏蔽掉外部的变量。退出方法块后将被弹出栈（被释放）， 不影响外部变量的值。
- 在函数体中定义的变量通常是在栈上，用malloc, calloc, realloc等分配内存的函数分配得到的就是在堆上。在所有函数体外定义的是全局量，加了static修饰符后不管在哪里都存放在全局区（静态区）,在所有函数体外定义的static变量表示在该文件中有效，不能extern到别的文件用，在函数体内定义的static表示只在该函数体内有效。

> 编程C代码时需要遵循的规则

- 不要隐藏某个变量， 这可能会产生一些隐蔽的bug，你认为你改变了某个变量但实际上没有。（代码块中创建新变量（外部已有变量））。
- 避免过多的全局变量，尤其是跨越多个文件。如果必须的话，要使用读写器函数。（类似`java`中的`get`、`set`方法）
- 在你不清楚的情况下，应该把它放在堆上。不要依赖于栈的语义，或者指定区域，而是要直接使用`malloc`创建它。
- 不要使用函数级的静态变量。它们并不有用，而且当你想要使你的代码运行在多线程环境时，会有很大的隐患。对于良好的全局变量，它们也非常难于寻找。

>  值传递

- 形参是实参的拷贝，改变形参的值并不会影响外部实参的值。从被调用函数的角度来说，值传递是单向的（实参->形参），参数的值只能传入，不能传出。当函数内部需要修改参数，并且不希望这个改变影响调用者时，采用值传递。

> 指针传递

- 形参为指向实参地址的指针，当对形参的指向操作时，就相当于对实参本身进行的操作

> 引用传递

- 形参相当于是实参的“别名”，对形参的操作其实就是对实参的操作，在引用传递过程中，被调函数的形式参数虽然也作为局部变量在栈中开辟了内存空间，但是这时存放的是由主调函数放进来的实参变量的地址。被调函数对形参的任何操作都被处理成间接寻址，即通过栈中存放的地址访问主调函数中的实参变量。正因为如此，被调函数对形参做的任何操作都影响了主调函数中的实参变量。

> gcc 命令参数说明（目前为止知道的）

- -c: 只编译，不链接成为可执行文件
- -o: 指定要生成的可执行文件的名称
- -g: 用于给生成的可执行文件加上调试信息，只有这样才可使用`gdb`调试
- -Wall: 打开gcc的所有警告
- -D: 定义宏

