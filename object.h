//
// Created by yee on 2024/4/29.
//

#ifndef QT_LAB1_OBJECT_H
#define QT_LAB1_OBJECT_H

#endif //QT_LAB1_OBJECT_H

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include "ObjectMeta.h"
#include "event.h"
using namespace std;



class Object{
public:
    explicit Object(string name); // 类构造函数
    ~Object(); // 析构函数

    string name; // 类名

    ObjectMeta *objectMeta = new ObjectMeta; // 创建类的元对象
    const ObjectMeta *metaObject() const; // 返回指向此对象的元对象的指针

    template<typename T>
    void setProperty(const string &key, const T &value); // 添加动态属性

    template<typename T>
    T getProperty(const string &key); // 获取属性值

    int propertiesNum() const; // 返回类的属性的个数

    // 定义事件监听相关
    void addEventListener(const string &eventName, const EventHandler &handler); // 添加事件监听器
    void dispatchEvent(const Event &event); // 分发事件


};

Object::Object(std::string name) {
    this->name = std::move(name);
    globalID += 1;

    // 为object元对象结构体指针赋值
    objectMeta->id = globalID;
}

Object:: ~Object() {
    cout << "this object has been deleted" << endl;
}

const ObjectMeta *Object::metaObject() const{
    return objectMeta;
}

// 添加动态属性
template<typename T>
void Object::setProperty(const string &key, const T &value){
    if (this->getProperty<T>(key) == nullptr){
        objectMeta->PropertyMap.emplace(key, value);
    }else{
        objectMeta->PropertyMap[key] = value; // 键值对(key, value)已经存在,更新value的值
    }
}

// 获得动态属性
template<typename T>
T Object::getProperty(const string &key){
    auto iter = objectMeta->PropertyMap.find(key);
    if (iter != objectMeta->PropertyMap.end()){
        return iter->second; //返回对应的value
    }else{
        // 未找到这个key的value，输出错误信息
        std::cout << "This property" << "'" << key << "'" << "does not exit!" << std::endl;
        return nullptr;
    }
}

// 返回类的属性的个数
int Object::propertiesNum() const{
    return objectMeta->PropertyMap.size();
}

// 添加事件监听器
void Object::addEventListener(const string &eventName, const EventHandler &handler){
    
}

// 分发事件
void Object::dispatchEvent(const Event &event){

}
