<div align="center">

# 🔌 51 单片机实验合集

**51 单片机（STC89C52 / 普中开发板）学习与实践记录**

[![51MCU](https://img.shields.io/badge/MCU-8051-red?style=flat-square)](https://www.stcmcudata.com/)
[![Keil](https://img.shields.io/badge/Keil-C51-394049?style=flat-square)](https://www.keil.com/)

</div>

---

## 🧪 内容概览

按日期组织的 Keil C51 工程，覆盖 51 单片机常用外设与经典实验：

| 分类 | 实验 |
|---|---|
| **LED 基础** | 点亮 LED · LED 闪烁 · 流水灯 · 流水灯 PLUS |
| **按键** | 独立按键控制（状态 / 二进制 / 移位）· 矩阵键盘密码锁 |
| **数码管与显示** | 静态数码管 · 动态数码管 · LCD1602 液晶屏 · LED 点阵屏（图形 / 动画） |
| **定时与中断** | 定时器时钟 · 定时器扫描按键数码管 |
| **蜂鸣器** | 播放提示音 · 播放音乐 |
| **串口通信** | 串口发送数据 · 电脑串口控制 LED |
| **时钟与存储** | DS1302 实时闹钟 · DS1302 可调时钟 · AT24C02 数据存储 |
| **传感器** | DS18B20 温度读取 · DS18B20 温度报警器 |
| **AD / DA** | AD 模数转换 · DA 数模转换 · LED 呼吸灯 |
| **电机** | 直流电机调速 · 红外遥控电机调速 · 红外遥控 |
| **综合项目** | `project/`、`晴天/`（蜂鸣器演奏）等 |

## 🚀 运行方法

1. 用 **Keil C51** 打开实验目录下的 `.uvprojx` 工程
2. 编译生成 `.hex`，用 STC-ISP 下载到开发板
3. 部分实验（如 LCD1602、点阵屏）需要按开发板接线

## 📁 目录结构

```text
single-chip-microcomputer/
├── 7-14点亮一个LED/
├── 7-15LED闪烁/
├── ...
├── 8-11红外遥控/
├── project/
├── 晴天/
└── README.md
```

> 欢迎一起交流单片机技术，这里会不定时更新。
