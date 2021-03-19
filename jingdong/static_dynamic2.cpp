#include<iostream>
using namespace std;

class B{
public:
    void DoSomething(){
        cout<<"B:DoSomething"<<endl;
    }
    virtual void vfun(int i=10){
        cout<<"B:vfun,param:"<<i<<endl;
    }

};

class D: public B{
public:
    void DoSomething(){
        cout<<"D:DoSomething"<<endl;
    }

    virtual void vfun(int i=20){
        cout<<"D:vfun,param:"<<i<<endl;
    }

};

int main()
{
    D* pD=new D();// pD的静态类型是它声明的类型D*，动态类型也是D*
    B* pB=pD;     // pB的静态类型是它声明的类型B*，动态类型是pB所指的对象pD的类型D*

    pD->DoSomething(); //D:DoSomething , pD的静态类型是它声明的类型D*，动态类型也是D*
    pB->DoSomething(); //B:DoSomething , pB的静态类型是它声明的类型B*，动态类型是pB所指的对象pD的类型D*

    /*默认参数不同*/
    pD->vfun();//D:vfun,param:20
    pB->vfun();//D:vfun,param:10
    /*
        缺省参数是静态绑定的，pD->vfun()，pD的静态类型是D*，所以它的缺省参数是20；
        而pB的静态类型是B*，所以pB->vfun()的缺省参数是10
        “绝不重新定义继承而来的缺省参数（Never redefine function’s inherited default parameters value.）”
    */
}