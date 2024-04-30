//
// Created by yee on 2024/4/29.
//

#ifndef QT_LAB1_OBJECTMETA_H
#define QT_LAB1_OBJECTMETA_H

#endif //QT_LAB1_OBJECTMETA_H

#include <iostream>
#include <string>
#include <map>
#include <variant>
using namespace std;

int globalID = 0;


struct ObjectMeta{
    // 类的信息
    string type; // 对象类型
    int id; // 对象UID

    // 创建属性map
    std::map<std::string, std::variant<int, double, std::string>> PropertyMap;
};