#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        for (int i = 0; i < tokens.size(); i++)
        {
            if (contain_symbol(tokens[i]))//取前连个压栈的进行运算,运算完成在压栈
            {
                int top2 = s_polish.top();
                s_polish.pop();
                int top1 = s_polish.top();
                s_polish.pop();
                if(tokens[i] == "+")
                {
                    int result = top1 + top2;
                    s_polish.push(result);
                }
                else if(tokens[i] == "-")
                {
                    int result = top1 - top2;
                    s_polish.push(result);
                }
                else if(tokens[i] == "*")
                {
                    int result = top1 * top2;
                    s_polish.push(result);
                }
                else
                {
                    int result = top1 / top2;
                    s_polish.push(result);   
                }
            }
            else
            {
                s_polish.push(atoi(tokens[i].c_str()));
            }
        }
        return s_polish.top();
    }

    bool contain_symbol(string s)
    {
          
        if (s == "+")
        {
            return true;
        }
        else if(s == "-")
        {
            return true;
        }
        else if(s == "*")
        {
            return true;
        }
        else if(s == "/")
        {
            return true;
        }
        return false;
    }  

public:
    stack<int> s_polish;
};
int main(int argc,char**argv)
{
    const char* init[]=
    {
        "4", "13", "5", "/", "+"
    };
    vector<string> _vs(init,init+5);
    vector<string> &vs = _vs;

    // for (int i = 0; i < vs.size(); i++)
    // {
    //     cout<<vs[i]<<endl;
    // }
    
    Solution *s = new Solution();
    s->evalRPN(vs);
    int result = s->s_polish.top();
    cout<<result<<endl;
    delete s;
    return 0;
}