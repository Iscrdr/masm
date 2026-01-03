# C语言数据结构与算法分阶段学习计划

---

## 第一阶段：基础数据类型、数组与字符串

**目标**：掌握基本数据类型、数组和字符串操作，理解算法复杂度。

### 核心知识点
- 基本数据类型：int, float, char, bool
- 数组：一维数组、二维数组、下标访问、遍历、插入、删除
- 字符串：字符数组，拼接、查找、截取、反转
- 算法复杂度概念：O(1)、O(n)、O(n²)

### 练习题
1. 反转一个整数数组
2. 查找数组中最大值和最小值
3. 判断字符串是否是回文
4. 实现字符串长度函数 `strlen`，不用库函数

### 示例（C语言）
```c
#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "level";
    int len = strlen(s);
    int flag = 1;
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-1-i]){
            flag = 0;
            break;
        }
    }
    if(flag) printf("回文\n");
    else printf("不是回文\n");
    return 0;
}
```

---

## 第二阶段：链表、栈与队列

**目标**：理解动态存储结构和基本线性数据结构。

### 核心知识点
- 链表：单向链表、双向链表，节点的增删
- 栈（LIFO）：数组/链表实现
- 队列（FIFO）：循环队列、双端队列
- 递归基础：递归与栈的关系

### 练习题
1. 单链表反转
2. 用栈实现括号匹配
3. 用队列实现任务调度
4. 递归求阶乘和斐波那契数列

### 示例（C语言）
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    Node* head = malloc(sizeof(Node));
    head->val = 1;
    head->next = malloc(sizeof(Node));
    head->next->val = 2;
    head->next->next = malloc(sizeof(Node));
    head->next->next->val = 3;
    head->next->next->next = NULL;

    head = reverse(head);

    Node* curr = head;
    while(curr != NULL){
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
    return 0;
}
```

---

## 第三阶段：哈希表与集合

**目标**：掌握键值映射和查找优化技巧。

### 核心知识点
- 哈希表：键值对、哈希函数、冲突解决（链地址法、开放地址法）
- 集合操作：增、删、查
- 去重、交集、并集

### 练习题
1. 数组中出现次数最多的元素
2. 判断两个数组是否有交集
3. 实现简单哈希映射（链地址法）

---

## 第四阶段：树

**目标**：理解非线性数据结构。

### 核心知识点
- 二叉树、二叉搜索树（BST）
- 树的遍历：前序、中序、后序、层序
- 树的增删查操作

### 练习题
1. 实现 BST 插入和查找
2. 二叉树前序遍历
3. 求二叉树最大深度

---

## 第五阶段：图

**目标**：掌握复杂关系结构和图算法。

### 核心知识点
- 图的表示：邻接矩阵、邻接表
- 遍历：DFS、BFS
- 拓扑排序
- 最短路径：Dijkstra、Floyd

### 练习题
1. 邻接表实现图的构建
2. DFS 和 BFS 遍历图
3. 拓扑排序

---

## 第六阶段：排序与查找

**目标**：掌握常用排序算法与查找算法。

### 核心知识点
- 排序：冒泡、选择、插入、快速、归并、堆排序
- 查找：顺序查找、二分查找
- 时间复杂度分析

### 练习题
1. 手写快速排序
2. 手写归并排序
3. 使用二分查找查找元素

---

## 第七阶段：动态规划与贪心

**目标**：掌握算法思维与优化技巧。

### 核心知识点
- 动态规划：背包问题、最长公共子序列
- 贪心算法：活动选择、最小生成树（Kruskal、Prim）
- 子问题拆解与状态转移

### 练习题
1. 背包问题（01 背包）
2. 最长递增子序列
3. 贪心算法实现活动选择问题

---

## 第八阶段：综合应用

**目标**：将数据结构与算法结合，解决实际问题。

### 练习题
1. LRU 缓存实现
2. 图的最短路径求解
3. 表达式求值（栈 + 栈顶操作）
4. 模拟一个简单数据库索引（树 + 哈希表结合）

---

## 学习方法建议
1. 每阶段先理解概念，再手写实现
2. 记录时间和空间复杂度
3. 每章练习题都手写代码
4. 循序渐进：不要跳过前几阶段
5. 复盘：做完题目要分析改进点，优化实现

