#include <iostream>
#include <stack>
using namespace std;
template<typename T>
class Queue
{
public:
    Queue(){}
    ~Queue(){}
    void push(T item)
    {
        s1.push(item);
    }
    
    T pop()
    {
        if(s2.empty())
        {
            while (!s1.empty())
            {
                T item = s1.top();
                s2.push(item);
                s1.pop();
            }
        }
        if(s2.empty())
        {
            throw "Error";
        }
        else
        {
            T item = s2.top();
            s2.pop();
            return item;
        }
    }
    
    T front()
    {
        if (!s2.empty())
        {
            T item = s2.top();
            return item;
        }
        else
        {
            while (!s1.empty())
            {
                T item = s1.top();
                s2.push(item);
                s1.pop();
            }
            if(s2.empty())
            {
                throw "Error";
            }
            else
            {
                T item = s2.top();
                return item;
            }
        }
    }
    
private:
    std::stack<T> s1;
    std::stack<T> s2;
};


int main()
{
    Queue<int> Q;
    Q.push(8);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    int a = Q.front();
    Q.pop();
    printf("a:%d\n",a);
    int b = Q.front();
    Q.pop();
    printf("b:%d\n",b);
    int c = Q.front();
    Q.pop();
    printf("c:%d\n",c);
    int d = Q.front();
    Q.pop();
    printf("d:%d\n",d);
    return 0;
}