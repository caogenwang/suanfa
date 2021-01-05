#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    // string s;
    // cout<<"length: "<<s.length()<<endl;
    // vector<int> v;
    // cout<<"capacity: "<<v.capacity() <<endl;

    // s="hello";
    // cout<<"length: "<<s.length()<<endl;
    // cout<<"max: "<<s.max_size()<<endl;
    // s.push_back('c');
    // cout<<s<<endl;
    // string s2=s+" world!";
    // cout<<s2<<endl;

    // string str("cat,dog,cat,pig,little cat,hotdog,little pig,angry dog");
    // size_t catPos = str.find("cat",0);

    // if (catPos == string::npos) {
    //     printf("没有找到字符串\n");
    //     return 0;
    // }

    // while (catPos != string::npos) {
    //     cout << "在索引 " << catPos << " 处找到字符串" << endl;
    //     catPos = str.find("cat", catPos + 1);
    // }

    string str("Hello,World!");
    cout<<"length: "<<str.length()<<endl;
    cout<<"max: "<<str.max_size()<<endl;
    str.erase(5,6);                    // 删除从索引位置 5 开始的 6 个字符
    cout << "str 为：" << str << endl;
    cout<<"length: "<<str.length()<<endl;
     cout<<"max: "<<str.max_size()<<endl;
    return 0;
}