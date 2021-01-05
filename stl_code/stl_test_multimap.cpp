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
};


int main()
{
    myNode n1(1,10);
    myNode n2(2,12);
    myNode n3(3,13);
    myNode n4(4,14);
    myNode n5(5,15);
    myNode n6(6,16);

    multimap<myNode,int> myMultiMap;
    myMultiMap.insert(make_pair(n1,101));
    myMultiMap.insert(make_pair(n1,102));
    myMultiMap.insert(make_pair(n2,103));
    myMultiMap.insert(make_pair(n2,104));
    myMultiMap.insert(make_pair(n2,105));
    myMultiMap.insert(make_pair(n3,106));
    typedef multimap<myNode,int>::iterator iterMulmap;
    for (iterMulmap it = myMultiMap.begin(); it != myMultiMap.end(); it++)
    {
        myNode node = it->first;
        int value = it->second;
        cout<<"key: "<<node.x<<" "<<node.y<<endl;
        cout<<"value: "<<value<<endl;
        cout<<"--------- "<<endl;
    }

    /*一些算法函数*/
    iterMulmap it = myMultiMap.lower_bound(n2);
    myNode tn = it->first;
    cout<<tn.x<<endl;
    cout<<tn.y<<endl;
    cout<<it->second<<endl;
    cout<<"--------- "<<endl;
    iterMulmap its = myMultiMap.find(n2);//
    myNode tn1 = its->first;
    cout<<tn1.x<<endl;
    cout<<tn1.y<<endl;
    cout<<its->second<<endl;
    cout<<"--------- "<<endl;

    pair<iterMulmap,iterMulmap> ret = myMultiMap.equal_range(n2);
    for (iterMulmap it = ret.first; it != ret.second; it++)
    {
        myNode tn2 = its->first;
        cout<<tn2.x<<endl;
        cout<<tn2.y<<endl;
        cout<<it->second<<endl;
        cout<<"--------- "<<endl;
    }
    



}
