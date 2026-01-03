# LESS 学习教程（含可运行 Demo）

> 本文通过 **知识点 + 可运行 Demo** 的方式，系统讲解 LESS，适合已有 HTML / CSS / JS 基础，但在样式组织与整合上遇到问题的前端开发者。

---

## 一、LESS 是什么？

LESS 是一种 **CSS 预处理器**，在 CSS 之上增加了：

- 变量
- 嵌套
- 混合（Mixin）
- 继承（Extend）
- 运算
- 模块化拆分

LESS 文件最终会被 **编译成普通 CSS**，浏览器并不知道 LESS 的存在。

---

## 二、Demo 项目结构

```
less-demo/
├─ index.html
├─ dist/
│  └─ styles.css        // 编译后的 CSS
└─ src/
   └─ styles/
      ├─ variables.less // 变量
      ├─ base.less      // 基础样式
      ├─ layout.less   // 布局
      ├─ buttons.less  // 组件
      └─ main.less     // 入口文件
```

---

## 三、LESS 安装与编译

### 1. 安装 LESS

```bash
npm install -g less
```

### 2. 编译 LESS

```bash
lessc src/styles/main.less dist/styles.css
```

---

## 四、核心知识点 + Demo

---

### 1️⃣ 变量（Variables）

**src/styles/variables.less**

```less
@primary-color: #3498db;
@secondary-color: #2ecc71;
@text-color: #333;
@bg-color: #f4f4f4;

@font-base: 16px;
@font-title: 24px;
@space: 12px;
```

📌 作用：  
- 避免「全局搜颜色」
- 支持统一主题 / 换肤

---

### 2️⃣ 嵌套（Nesting）

**src/styles/layout.less**

```less
@import "variables.less";

.container {
  width: 80%;
  margin: 40px auto;
  background: @bg-color;

  .header {
    font-size: @font-title;
    padding: @space;
    background: @primary-color;
    color: #fff;
  }

  .content {
    padding: @space;
    color: @text-color;
  }
}
```

✅ 编译后：

```css
.container .header {}
.container .content {}
```

📌 建议：嵌套 **不超过 3 层**

---

### 3️⃣ 混合（Mixin）

**src/styles/buttons.less**

```less
@import "variables.less";

.button(@bg, @color) {
  padding: @space;
  border-radius: 6px;
  background: @bg;
  color: @color;
  cursor: pointer;
  text-decoration: none;
  display: inline-block;
}

.btn-primary {
  .button(@primary-color, #fff);
}

.btn-secondary {
  .button(@secondary-color, #fff);
}
```

📌 使用场景：  
- 按钮
- 卡片
- 阴影 / 动画模板

---

### 4️⃣ 继承（Extend）

**src/styles/base.less**

```less
@import "variables.less";

.btn-base {
  padding: @space;
  font-size: @font-base;
  border-radius: 4px;
}

.btn-primary {
  &:extend(.btn-base);
  background: @primary-color;
  color: #fff;
}
```

📌 Mixin vs Extend：

| 对比 | Mixin | Extend |
|----|----|----|
| 是否复制代码 | 是 | 否 |
| 灵活性 | 高 | 一般 |
| 推荐度 | ⭐⭐⭐⭐ | ⭐⭐ |

👉 实战中 **Mixin 用得更多**

---

### 5️⃣ 运算（Operations）

```less
@box-width: 300px;

.card {
  width: @box-width;
  padding: @space * 2;
  margin-bottom: @space + 8px;
}
```

📌 常见用途：  
- 栅格布局
- 自适应间距

---

### 6️⃣ 响应式（Media Query）

```less
.container {
  width: 80%;

  @media (max-width: 768px) {
    width: 95%;
  }
}
```

📌 LESS 可以让媒体查询 **写在组件内部**，更符合组件化思维

---

### 7️⃣ 模块化入口文件

**src/styles/main.less**

```less
@import "variables.less";
@import "base.less";
@import "layout.less";
@import "buttons.less";
```

📌 原则：  
- 只编译 main.less  
- 其他文件全部当模块

---

## 五、HTML Demo

**index.html**

```html
<!DOCTYPE html>
<html lang="zh-CN">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>LESS Demo</title>
  <link rel="stylesheet" href="dist/styles.css">
</head>
<body>
  <div class="container">
    <div class="header">LESS 学习 Demo</div>
    <div class="content">
      <p>这是一个使用 LESS 编写样式的示例页面</p>
      <a class="btn-primary">主按钮</a>
      <a class="btn-secondary">次按钮</a>
    </div>
  </div>
</body>
</html>
```

---

## 六、学习路线建议（结合你当前水平）

### 第 1 周
- 变量 / 嵌套 / 编译
- 手写 1 个页面

### 第 2 周
- Mixin + 模块拆分
- 重构旧 CSS

### 第 3 周
- 响应式 + 组件化
- 整合第三方 Demo

### 第 4 周
- LESS + Webpack / Vite
- 真实项目落地

---

## 七、关键经验总结（非常重要）

✅ LESS 解决的是：  
- 样式冲突
- 样式不可维护
- Demo 无法整合

❌ LESS 解决不了：  
- 不合理的 DOM 结构
- 过深的选择器

👉 **LESS + BEM + 组件化思维 = 稳定页面效果**

---

> 如果你愿意，下一步我可以：  
> - 用 **LESS + BEM** 重写一个“容易乱的 Demo”  
> - 或把你现在的 CSS 帮你重构成 LESS
