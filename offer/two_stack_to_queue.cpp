#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <fstream>
#include <limits.h>
#include <vector>
using namespace std;

template<class T>
class Queue{
public:
    void push(T item);
    void pop();
    T back();
    T front();
    bool empty();
    int size();
private:
    stack<T> s1;
    stack<T> s2;
};

template<class T>
void Queue<T>::push(T item)
{
    s1.push(item);
}

template<class T>
void Queue<T>::pop()
{
     if (s1.empty() && s2.empty())
            return;

    if (!s2.empty()){
        s2.pop();
    }
    else
    {
        while (s1.size() > 0)
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
    }
}

template<class T>
T Queue<T>::back()
{
    if (s1.empty() && s2.empty())
            return 0;

    if (!s1.empty())
    {
        return s1.top();
    }
    else
    {
        while (s2.size() > 0)
        {
            s1.push(s2.top());
            s2.pop();
        }
        return s1.top();
    }
}

template<class T>
T Queue<T>::front()
{
    if (s1.empty() && s2.empty())
            return 0;

    if (!s2.empty())
    {
        return s2.top();
    }
    else
    {
        while (s1.size() > 0)
        {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
}

template<class T>
bool Queue<T>::empty()
{
    return (s1.empty() && s2.empty());
}

template<class T>
int Queue<T>::size()
{
    return (s1.size() + s2.size());
}


int main(int argc,char**argv)
{
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    printf("******1*****\n");
    q.pop();
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    printf("******2*****\n");
    q.pop();
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    printf("******3*****\n");
    q.pop();
    q.pop();
    printf("******4*****\n");
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;

}