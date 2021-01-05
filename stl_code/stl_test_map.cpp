#include <iostream>
#include <map>
#include <utility>
using namespace std;

class myNode{
public:
    myNode(int _x,int _y):x(_x),y(_y){}
    ~myNode(){}
    bool operator<(const myNode &node) const//编译器会自动给每一个函数加一个this指针。
    {                                       //在一个类的函数后面加上const后，就表明这个函数是不能改变类的成员变量的
        return this->x < node.x;      //（加了mutable修饰的除外）。实际上，也就是对这个this指针加上了const修饰
    }
    bool operator()(const myNode& __x, const myNode& __y) const
    {
        return __x.x < __y.x;
    }
    int x;
    int y;
    // int z;
};

int main()
{
    myNode n1(1,10);
    myNode n2(2,12);
    myNode n3(3,13);
    myNode n4(4,14);
    myNode n5(5,15);
    myNode n6(6,16);
    map<myNode,int> mymap;
    map<myNode,int> mymap2;
    mymap.insert(make_pair(n2,102));
    mymap.insert(make_pair(n1,101));
    mymap.insert(make_pair(n6,106));
    mymap.insert(make_pair(n3,103));
    mymap.insert(make_pair(n4,104));
    mymap.insert(make_pair(n5,105));

    for (map<myNode,int>::iterator it = mymap.begin(); it != mymap.end(); it++)
    {
        myNode node = it->first;
        int value = it->second;
        cout<<"key: "<<node.x<<" "<<node.y<<endl;
        cout<<"value: "<<value<<endl;
        cout<<"--------- "<<endl;
    }
    

    int n = n3(n2,n1);
    cout << "n: "<<n<<endl;
    /*获取一个分配器*/
    auto alloc =  mymap.get_allocator();

    /*max size*/
    cout<<"max: "<<mymap.max_size()<<endl;
}