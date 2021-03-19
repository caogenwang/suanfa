#include<iostream>
using namespace std;

class B{
public:
    void DoSomething(){
        cout<<"B:DoSomething"<<endl;
    }

    virtual void vfun(){
        cout<<"B:vfun"<<endl;
    }

};
class C: public B{
public:
    //首先说明一下，这个子类重新定义了父类的no-virtual函数，
    //这是一个不好的设计，会导致名称遮掩；这里只是为了说明动态绑定和静态绑定才这样使用。 

    void DoSomething(){
        cout<<"C:DoSomething"<<endl;
    }

    virtual void vfun(){
        cout<<"C:vfun"<<endl;
    }

};

class D: public B{
public:
    void DoSomething(){
        cout<<"D:DoSomething"<<endl;
    }

    virtual void vfun(){
        cout<<"D:vfun"<<endl;
    }

};

int main()
{
    D* pD=new D();// pD的静态类型是它声明的类型D*，动态类型也是D*
    B* pB=pD;     // pB的静态类型是它声明的类型B*，动态类型是pB所指的对象pD的类型D*

    pD->DoSomething(); //D:DoSomething , pD的静态类型是它声明的类型D*，动态类型也是D*
    pB->DoSomething(); //B:DoSomething , pB的静态类型是它声明的类型B*，动态类型是pB所指的对象pD的类型D*

    pD->vfun();//D:vfun
    pB->vfun();//D:vfun
    //指针和引用的动态类型和静态类型可能会不一致，但是对象的动态类型和静态类型是一致的。
    //总结：只有虚函数才使用的是动态绑定，其他的全部是静态绑定。

    D d;
    d.DoSomething();//D:DoSomething
    d.vfun();//D:vfun

    //当缺省参数和虚函数一起出现的时候情况有点复杂，极易出错。我们知道，
    //虚函数是动态绑定的，但是为了执行效率，缺省参数是静态绑定的
    
}