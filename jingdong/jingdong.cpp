#include<iostream>
using namespace std;
class Demo{
public:
    Demo():data(0){}
    ~Demo();
    void display(){
        cout<<"ok"<<endl;
    }
    virtual void vfun(){
        cout<<"vfun"<<endl;
    }
    int data;
};
int main()
{
    Demo *ptr = nullptr;
    ptr->display();
    ptr->vfun();
    return 0;
}