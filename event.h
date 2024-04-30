//
// Created by yee on 24-4-30.
//

#ifndef QT_LAB1_EVENT_H
#define QT_LAB1_EVENT_H

#endif //QT_LAB1_EVENT_H

#include <iostream>
#include <string>
#include <functional>
#include <map>
using namespace std;


struct Event
{
    // 设置事件相关属性值
    string name; // 对应事件类型
    string data; // 事件内容
};

// 定义 事件处理函数类型(处理器)
typedef function<void(const Event &)>EventHandler;

// 创建map存储处理事件类型为key的多个事件处理器EventHandler(value)
std::map<std::string, vector<EventHandler>> eventListeners;
