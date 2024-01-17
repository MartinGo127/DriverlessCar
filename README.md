# 基于easyX的无人小车自动驾驶仿真系统

> 2024.01.14从有道云笔记迁移

## 一、软件系统设计

### 1.1 基本概念

### 1.2 架构设计

继承依赖关系类图，如下：

![](D:/桌面/工作就业/自动驾驶/pics/2024-01-14-03-21-52.png)


头文件

* planning_base.h
* car.h
* traffic.h
* road.h
* scenario_base.h
* scenario_straight.h
* main.h

源代码

* planning_base.cpp
* car.cpp
* traffic.cpp
* road.cpp
* scenario_base.cpp
* scenario_staright.cpp
* main.cpp

基类`planning_base.h`，添加需要依赖头文件，并定义全局变量(当变量很多时可以专门写为conf配置文件专门调整，与主程序解耦)

```
constexpr auto SCREEN_WIDTH = 1200.0;   // easyX窗口宽
constexpr auto SCREEN_HEIGHT = 1200.0;  // easyX窗口高
constexpr auto PI = 3.1415926535;       // 圆周率
constexpr auto SHOWCIRCLE = false;      // 是否显示轨迹线
constexpr auto CHANGETIME = 1000;       // 换挡时间
constexpr auto DELAYTIME = 20;          // 帧间隔
```

### 1.3 车辆动力学模型分析

`const`和`constexpr`的区别

* const: 在运行时计算
* constexpr: 在编译时计算，有更多的优化空间

```
// 当变量a,b用在非常量表达式时，a只有在运行时计算a=15，而b可以提前编译出结果，提高运行效率
const int a = 5 * 3;    
constexpr int b = 5 * 3;
```

## 二、直行场景

> 详细笔记图例分析见日报

`.h`写类，方法声明
`.cpp`写方法定义

### 1. `Point`类

完成**点类**编写

1. 定义全局函数`delay()`，思路非常类似django项目使用的`AcGameObject`递归调用`requestAnimationFrame()`实现不断地刷新渲染。这里也是由游戏/仿真引擎介入升级提高的地方。
2. 定义`Ponit`的数据结构和成员方法，包括绘制、移动、旋转和求距离。所有方法均为**原子操作**，不可再分，是后续一些车辆运动场景的**基类**

### 2. `Car`类

> 所有车定义的基类，后续需要定义新车时，继承一下`CarBase`就可以。

重点：

1. pmid和p_center有什么区别？
   1. pmid：车辆几何中心点，对应plf,prr和plr,prf的连线交点
   2. p_center：车辆旋转的中心点，对应Rof,Ror,Rif,Rir
2. 车辆旋转和转向分别以那个点为坐标原点旋转？为什么？
   1. 旋转：pmid
   2. 转向：p_center
3. 轨迹线如何绘制？
   1. 以p_center为原点，进行极坐标旋转

#### 声明

类成员：

* 成员变量：车长，7个姿态点，3个姿态角，3种速度，3种加速度，以及5种转弯半径。
* 成员函数：初始化、析构函数，3个中点更新函数，车辆/轨迹线绘制函数，打印信息以及**单帧前进**和**单帧转向**

注意：其中7个姿态点均使用智能指针`unique_ptr`构建`Point`类型对象，这里估计由于后面会有很多操作对这些点进行改变所以使用智能指针统一管理其引用次数和生命周期。

```
unique_ptr<Point> pmid;
unique_ptr<Point> pmidf;
unique_ptr<Point> plf;
unique_ptr<Point> prr;
```

#### 姿态点

由于姿态点使用智能指针`unique_ptr`取代了**裸指针**，则创建对象时，需要取代`new Point(x, y)`，使用`make_unique<Point>(x, y)`实现。

这里`make_unique()`是一个函数，接受**一个类型**和**传入参数**并返回一个`unique_ptr`指针，指向新分配的对象，该对象具有默认构造参数。

```
pmid = make_unique<Point>(pos_x, pos_y);
```

#### 旋转

对于`pmid`是一个指针类型，传参接受`Point`类型，所以需要**解引用**

但是为什么是`pmid`和`p_center`有什么区别？

```
plf->turnPoint(*pmid, heading_theta);
```


#### 轨迹线

根据自转中心，以及自旋角绘制轨迹线？

```
circle(*p_center, delta_theta);
```

### `Traffic`类

非常容易，写一个静态锥桶即可

### `Road`类

一个`RoadBase`基类，一个`RoadNormal`一般类，后者继承前者，并重写`showRoad()`的纯虚函数以实现多态







