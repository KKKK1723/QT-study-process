# QtCreator 按键与定时器事件 Demo 介绍文档

## 项目概述
本 Demo 是在 QtCreator 上开发的一个简单示例项目，展示了 Qt 框架中按键事件和定时器事件的结合使用。通过一个直观的界面，我们实现了按键控制窗口状态与控件移动，以及定时更新时间显示的功能。项目旨在帮助开发者理解 Qt 的事件处理机制，并对比两种定时器实现方式的适用场景。

## 功能描述

### 1. 按键控制功能
本项目通过捕获键盘按键事件，实现了以下功能：

- **全屏与缩小切换**  
  - **全屏模式**：按住 `Ctrl` 并同时按下 `M` 键，界面将切换为全屏显示。  
  - **恢复正常**：在全屏模式下按下 `Esc` 键，界面恢复到初始大小。  
- **按钮移动**  
  - 使用方向键（`上`、`下`、`左`、`右`）控制界面上按钮的位置。  
  - 每次按键移动 5 个像素，支持长按连续移动，提供流畅的操作体验。

### 2. 定时器功能
本项目集成了定时器机制，用于动态更新界面上的时间显示：

- **实时时间显示**  
  - 界面上有一个 LCD 显示控件，每隔 1 秒更新一次当前时间，格式为 `hh:mm:ss`。  
  - 时间显示通过定时器自动刷新，无需用户干预。  
- **两种定时器实现**  
  - **QTimer 类**：基于信号槽的高级接口，用于本项目的时间更新功能。  
  - **timerEvent**：低层次的事件处理方式，支持多个定时器管理（在本 Demo 中作为备用方案）。

## 运行说明
1. 在 QtCreator 中打开项目并编译运行。  
2. 启动程序后，界面将显示一个可移动的按钮和一个 LCD 时间显示控件。  
3. 操作方式：  
   - 按 `Ctrl + M` 进入全屏模式。  
   - 按 `Esc` 退出全屏模式。  
   - 使用方向键（`↑`、`↓`、`←`、`→`）移动按钮。  
   - 观察 LCD 控件，每秒自动更新当前时间。

## 定时器方法对比
本 Demo 展示了 Qt 中两种定时器机制的特点，供开发者参考选择：

- **QTimer 类**  
  - **特点**：基于信号槽机制，配置简单，易于动态调整。  
  - **优点**：代码直观，适合与界面元素交互的任务。  
  - **适用场景**：如本项目中的时间显示更新，强调简洁性和维护性。  
- **定时器事件**  
  - **特点**：通过重写事件处理函数实现，属于低层次控制。  
  - **优点**：无需额外对象，直接嵌入类中，适合集中管理多个定时器。  
  - **适用场景**：适用于需要精细控制或复杂定时任务的场景。

## 项目意义
通过本 Demo，开发者可以：  
- 掌握 Qt 中按键事件的捕获与处理方法。  
- 理解定时器事件的工作原理及其两种实现方式的差异。  
- 学习如何将事件驱动编程应用于实际界面开发中。  

详细介绍:https://blog.csdn.net/2401_87117051/article/details/146193056?spm=1001.2014.3001.5501
