## ELF格式详解
1. Header文件头
2. 程序头
3. 节区头
4. 常见Section/Segment
5. 动态链接机制
6. ELF的加载机制
7. 如何手写一个最小ELF
8. 如何用C解析ELF
9. 调试工具与实战技巧

### :one: ELF Header文件头

|ELF Header|
:-----
|Program Header Table(PH)|
|Section Header Table(SH)|
|Section /Segments|

#### 关键字段

|字段|说明|
|:---|:---|
|e_idnt|魔数0x7F 'E' 'L' 'F'、位数、字节序等|
|e_type|文件类型(可执行/共享库/重定位/核心转储)|
|e_machine|CPU架构(x86_64=0x3E)|
|e_entry|程序入口地址|
|e_phoff|程序表头偏移|
|e_shoff|节头表偏移|
|e_phnum|Program Header数量|
|e_shnum|Section Header数量|
|e_shstrndx|Section 字符串表的索引|

### :two: Program Header Table(程序头表)
程序头表告诉操作系统如何将ELF加载到内存
每个Entry描述了一个Segment(段)，Segment是运行时期概念（给操作系统调用）,而Section是编译、链接阶段概念（给链接器用）
常见Segment类型
常见Segment类型：
|类型|说明|
|:---|:---|
|PT_LOAD|可加载段（程序代码，数据等）|
|PT_DYNAMIC|动态链接信息|
|PT_INTERP|动态链接器路径|
|PT_NOTE|notes,例如core dump|
|PT_PHDR|程序表头自身位置|
|PT_TLS|线程本地存储|
加载可执行文件时，内核大致执行：
```
mmap(segment->p_offset, segment->p_vaddr，segment->p_filesz, segment->p_flags)
```
### :three: Section Header Table（节区头表）
节区对连接器（ld）、二进制分析工具有用
常见Section
|Section|功能|
|:---|:----|
|.text|代码段|
|.data|已经初始化数据|
|.bss|未初始化数据（不占文件空间）|
|.rodata|只读常量|
|.symtab|符号表|
|.strtab|字符串表|
|.rel.text/.rela.text|重定位信息|
|.dynamic|动态链接区|
|.plt|Procedure Linkage Table|
|.got|Global Offset Table|

Section Header 的关键字段
| 字段        | 含义                     |
| --------- | ---------------------- |
| sh_name   | 名字（在 `.shstrtab` 中的偏移） |
| sh_type   | 类型（如 SHT_PROGBITS）     |
| sh_addr   | 加载后的虚拟地址               |
| sh_offset | 在文件中的偏移                |
| sh_size   | 大小                     |
| sh_flags  | 可执行/可写/可读等             |

```
readelf -S a.out
```
### :four: ELF 核心结构布局图
```
ELF Header
Program Header Table
  ├── PT_INTERP (ld-linux.so)
  ├── PT_LOAD text
  ├── PT_LOAD data
  ├── PT_DYNAMIC
  ├── PT_GNU_STACK
  └── ...
Section Header Table
  ├── .text
  ├── .rodata
  ├── .data
  ├── .bss
  ├── .plt
  ├── .got
  ├── .dynamic
  └── ...
```
### :five: 动态连接机制（PLT/GOT）

动态链接的核心结构：
PLT（Procedure Linkage Table）

用于延迟解析动态库函数调用
例如 printf@plt

GOT（Global Offset Table）
存储动态符号的真实地址。
1. 流程（延迟绑定）：
2. 调用某函数：跳到 PLT stub
3. 如果第一次调用，PLT 跳到 dynamic linker
4. dynamic linker 查找实际地址
5. 将地址写入 GOT
6. 之后再次调用直接从 GOT 取地址（不再进入 ld.so）

### :six: ELF 的加载过程（Linux 内核）

1. 读取 ELF Header
2. 查找 PT_INTERP，决定使用哪个动态链接器（如 ld.so）
3. mmap 所有 PT_LOAD 段到内存
4. 将权限设置为 r-x / rw-
5. 如果有动态链接：
      a. 启动 ld.so
      b. 解析依赖
      c. 进行重定位
6. 跳转到 e_entry（程序入口）

### :seven: 手写一个可执行的ELF


