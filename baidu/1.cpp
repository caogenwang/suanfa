/*
去除字符串的前后k空格，然后再翻转
"is a example!"   ---->   "example a is"
"is a example!   "   ---->   "example a is"
"   is a    example!"   ---->   "example    a is"
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string rever(string &s){
    int index1 = s.find_first_not_of(" ");
    int index2 = s.find_last_not_of(" ");
    s = s.substr(index1,index2-index1+1);
    ::reverse(s.begin(), s.end());
    string tmp="";
    string res = "";
    bool visited = false;
    int len = s.length();
    for(int i=0;i<len;i++){
        if(s[i] == ' '){
            if(!visited){
                ::reverse(tmp.begin(), tmp.end());
                res += tmp;
                tmp = "";
                visited = true;
            }
            res += " ";
        }
        else{
            tmp += s[i];
            visited = false;
            if(i == len-1){
                ::reverse(tmp.begin(), tmp.end());
                res += tmp;
            }
        }
    }
    return res;
}


int main(){

}
