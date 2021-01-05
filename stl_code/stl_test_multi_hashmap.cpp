#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;



class myNode{
public:
    myNode(int _x,int _y):x(_x),y(_y){}
    ~myNode(){}
    // bool operator<(const myNode &node) const//编译器会自动给每一个函数加一个this指针。
    // {                                       //在一个类的函数后面加上const后，就表明这个函数是不能改变类的成员变量的
    //     return this->x < node.x;      //（加了mutable修饰的除外）。实际上，也就是对这个this指针加上了const修饰
    // }
    // bool operator==(const myNode& __n) const
    // {
    //     return this->x == __n.x;
    // }
    int x;
    int y;
    int z;
    int m;
    int a;
    int b;
    int c;
};


namespace std {
    template <> //function-template-specialization
        class hash<myNode>{
        public :
            size_t operator()(const myNode &__n ) const
            {
                return hash<int>()(__n.x) ^ hash<int>()(__n.y);
            }
    };

    template<>
    struct equal_to<myNode>{//等比的模板定制
    public:
        bool operator()(const myNode &__n, const myNode &__m) const
        {
            return (__n.x+__n.y)==(__m.x+__m.y);
        }
        
    };
};



struct hash_name{
	size_t operator()(const myNode & p) const{
		return hash<int>()(p.y) + hash<int>()(p.x);
	}
};

//用一个函数包装类来包裹住函数
size_t person_hash( const myNode & p ) 
{
    return hash<int>()(p.y) + hash<int>()(p.x);
}
//声明如下方式
unordered_multimap<myNode,int,function<size_t( const myNode& p )> > map;
//方法3：模板定制

int main()
{
    myNode n1(1,10);
    myNode n2(2,12);
    myNode n3(3,8);
    myNode n4(4,14);
    myNode n5(5,6);
    myNode n6(6,16);
    myNode n7(11,0);

    unordered_multimap<myNode,int> myMap;
    cout<<"init_size: "<<sizeof(myMap)<<endl;
    myMap.insert(make_pair(n1,101));
    myMap.insert(make_pair(n2,102));
    myMap.insert(make_pair(n3,103));
    myMap.insert(make_pair(n4,104));
    myMap.insert(make_pair(n5,105));
    myMap.insert(make_pair(n6,106));
    myMap.insert(make_pair(n7,107));
    myMap.insert(make_pair(n6,108));
    myMap.insert(make_pair(n7,109));
    myMap.insert(make_pair(n7,110));
    myMap.insert(make_pair(n6,111));
    myMap.insert(make_pair(n7,112));

    for (unordered_multimap<myNode,int,hash_name>::iterator it = myMap.begin(); it != myMap.end(); it++)
    {
        myNode node = it->first;
        int value = it->second;
        cout<<"key: "<<node.x<<" "<<node.y<<endl;
        cout<<"value: "<<value<<endl;
        cout<<"--------- "<<endl;
    }

    typedef unordered_multimap<myNode,int>::iterator unorder_it;
    pair<unorder_it,unorder_it> ret = myMap.equal_range(n1);
    for (unorder_it it = ret.first; it != ret.second; it++)
    {
        myNode tn = it->first;
        cout<<tn.x<<endl;
        cout<<tn.y<<endl;
        cout<<it->second<<endl;
        cout<<"--------- "<<endl;
    }
    cout<<"size: "<<myMap.size()<<endl;
    cout<<"bucker: "<<myMap.bucket_count()<<endl;
    for (int i = 0; i < myMap.bucket_count(); i++)
    {
        cout<<"bucker["<<i<<"]: "<<myMap.bucket_size(i)<<endl;
    }
    
    
    cout<<"max_size: "<<myMap.max_bucket_count()<<endl;
    unique_ptr
}