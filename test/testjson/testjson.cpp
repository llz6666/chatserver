#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// json 序列化示例一
void func1() {
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello, what are you doing now?";

    string sendBuf = js.dump();
    //cout << js << endl;
    cout << sendBuf.c_str() << endl;
}

// json 序列化示例二
void func2() {
    json js;
    // 还可以添加数组
    js["id"] = {1,2,3,4,5};
    // 添加key-value
    js["name"] = "zhang san";

    // 添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";

    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};
    cout << js << endl;
}

// json 序列化示例三
void func3() {
    json js;

    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);

    js["list"] = vec;

    // 直接序列化一个map容器
    map<int, string> mp;
    mp.insert({1, "黄山"});
    mp.insert({2, "华山"});
    mp.insert({3, "泰山"});

    js["path"] = mp;
    string sendBuf = js.dump(); // json数据对象 -》 序列化 json字符串
    cout << sendBuf << endl;
}

// json 反序列化示例一
string rec_func1() {
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello, what are you doing now?";

    string sendBuf = js.dump();
    //cout << js << endl;
    //cout << sendBuf.c_str() << endl;
    return sendBuf;
}

// json 反序列化示例二
string rec_func2() {
    json js;
    // 还可以添加数组
    js["id"] = {1, 2,3,4,5};
    // 添加key-value
    js["name"] = "zhang san";

    // 添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";

    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};
    //cout << js << endl;
    return js.dump();
}

// json 反序列化示例三
string rec_func3() {
    json js;

    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);

    js["list"] = vec;

    // 直接序列化一个map容器
    map<int, string> mp;
    mp.insert({1, "黄山"});
    mp.insert({2, "华山"});
    mp.insert({3, "泰山"});

    js["path"] = mp;
    string sendBuf = js.dump(); 
    //cout << sendBuf << endl;
    return sendBuf;
}

int main() {
    //func1();
    //func2();
    //func3();

    string recvBuf = rec_func3();
    // 数据的反序列化 json字符串 -》 反序列化 数据对象（看作容器，方便访问）
    json jsbuf = json::parse(recvBuf);

    /*cout << jsbuf["id"] << endl;
    auto arr = jsbuf["id"];
    cout << arr[2] << endl;

    auto msgjs = jsbuf["msg"];
    cout << msgjs["zhang san"] << endl;*/

    vector<int> vec = jsbuf["list"]; // js对象里面的数组类型，直接放入vector容器中
    for (int &v : vec) {
        cout << v << " ";
    }
    cout << endl;

    map<int, string> mymap = jsbuf["path"];
    for (auto &p : mymap) {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;

    return 0;
}
