#include <iostream>
#include <vector>
#include <memory>
#include <unistd.h>
using namespace std;

void display(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<endl;
    }
    cout<<"-------------"<<endl;
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,0};
    // vector<int> vec(arr,arr+7);
    vector<int> vec;
    vector<int> vec1;
    // vec.reserve(1);
    // cout<<"size: "<<vec.size()<<endl;
    // cout<<"capacity: "<<vec.capacity()<<endl;
    // display(vec);

    // cout<<"size: "<<vec.size()<<endl;
    // cout<<"capacity: "<<vec.capacity()<<endl;
    // display(vec);


    // vec.resize(5);
    // cout<<"size: "<<vec.size()<<endl;
    // cout<<"capacity: "<<vec.capacity()<<endl;
    // display(vec);

    for(int i=0;i<10;i++)
    {
        vec.push_back(i);
    }
    vec.insert(vec.begin()+2,10);
    display(vec);
    cout<<"size: "<<vec.size()<<endl;
    cout<<"capacity: "<<vec.capacity()<<endl;

    vec.pop_back();
    display(vec);
    cout<<"size: "<<vec.size()<<endl;
    cout<<"capacity: "<<vec.capacity()<<endl;

    // vec.erase(vec.begin()+6);//删除中间，做了copy
    // display(vec);
    // cout<<"size: "<<vec.size()<<endl;
    // cout<<"capacity: "<<vec.capacity()<<endl;

    // vec.clear();
    // cout<<"size: "<<vec.size()<<endl;
    // cout<<"capacity: "<<vec.capacity()<<endl;

    vector<int> dp{1,2,3,4,5,6,7,8,9,0,10,11,12,13};

    dp=vec;
    cout<<"dp-size: "<<dp.size()<<endl;
    cout<<"dp-capacity: "<<dp.capacity()<<endl;
    display(dp);
    return 0;
}