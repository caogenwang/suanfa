#include<iostream>
using namespace std;
class Demo{
public:
    Demo():data(0){}
    ~Demo();
    void display(){
        cout<<"ok"<<endl;
    }
    int data;
};
int main()
{
    Demo *ptr = nullptr;
    ptr->display();
    ptr->data = 2;
    return 0;
}