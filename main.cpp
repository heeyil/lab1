#include <iostream>
#include <string>
#include "object.h"
using namespace std;


int main ()
{
    map<string, int> MyMap;

    MyMap.emplace("a", 1);
    MyMap.emplace("a", 2);

    auto iter = MyMap.find("a");
    if (iter != MyMap.end()){
        cout << "a:" << iter->second << endl; //返回对应的value
    }else{
        // 未找到这个key的value，输出错误信息
        cout << "This property" << "does not exit!" << endl;
    }
}