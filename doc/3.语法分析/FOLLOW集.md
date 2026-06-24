一、文法：

        E  → T E'
        E' → + T E' | ε
        T  → F T'
        T' → * F T' | ε
        F  → ( E ) | id
二、规则：  
- 规则1：开始符号 FOLLOW(S) 含 $
- 规则2： A → αBβ，FOLLOW(B) += FIRST(β) - {ε}
- 规则3：B 在末尾，或 β ⇒ ε，FOLLOW(B) += FOLLOW(A)

三、逐个解释
### 1、FOLLOW(E)
    1、E是开始符号 ，FOLLOW(E) 包含 $
    2、看 F → ( E ) ，E后面是），直接加入 FOLLOW(E) += { ) }
    最终：FOLLOW(E) = { $, ) }
### 2、FOLLOW(E')

    E' 出现在：
        E → T E'
    E' 在末尾 → 用规则3：
        FOLLOW(E') += FOLLOW(E)
    所以：FOLLOW(E') = { $, ) }
### 3、FOLLOW(T)
T 出现在：    E → T E'
* 1、  T 后面是 E' 
用规则2：
    
        FOLLOW(T) += FIRST(E') - {ε}
        FIRST(E') = { +, ε }
        所以：
        FIRST(E') - {ε} = { + }
        得到：
        FOLLOW(T) += { + }

* 2、因为 E' → ε（可空）,用规则3：

        FOLLOW(T) += FOLLOW(E)
        FOLLOW(E) = { $, ) }，
最终：

        FOLLOW(T) = { +, ), $ }

* ### 4、FOLLOW(T')

        T' 出现在： T → F T'
        T' 在末尾 → 规则3：
            FOLLOW(T') += FOLLOW(T)
        所以：
            FOLLOW(T') = { +, ), $ }
### 5、FOLLOW(F)
F 出现在：T → F T'

* 1、F 后面是 T'，用规则2：

            FOLLOW(F) += FIRST(T') - {ε}
    FIRST(T') = { *, ε }
    所以：

        FIRST(T') - {ε} = { * }
    得到：
        FOLLOW(F) += { * }

* 2、因为 T' → ε，用规则3：

        FOLLOW(F) += FOLLOW(T)
    FOLLOW(T) = { +, ), $ }
最终：

    FOLLOW(F) = { *, +, ), $ }

总结：

| 非终结符 | FOLLOW来源直觉        |
| ---- | ----------------- |
| E    | 起始符 + 被括号包围       |
| E'   | 跟随 E（因为 E → T E'） |
| T    | 后面可能是 + 或结束或 )    |
| T'   | 跟随 T              |
| F    | 后面可能是 * 或整个表达式结束  |

FOLLOW 的本质就是：

    “这个符号后面可能出现什么终结符”
它完全由：

    “后面紧跟谁”
    “能不能推出 ε”
    “能不能回传 FOLLOW”

三件事决定。
