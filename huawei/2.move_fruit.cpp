#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

/*
  带空格的输入，需要读取一行
  因为输入空格会被截断
    string str;
    char a[30];
    for (int i = 0; i < 30; i++)
    {
        a[i] = '\0';
    }
    while (cin.getline(a,30))
    {
        str = a;
        cout<<str<<endl;
    }
*/
struct Data{
    string fruit;
    int num;
    int weight;
    Data(string _fruit,int _num,int _weight)
    :fruit(_fruit),num(_num),weight(_weight){}
};
int main()
{
    string str;
    int n = 0;
    int index = 1;
    map<string,Data> mSents;
    set<string> keys;
    vector<string> order;
    return 0;
}