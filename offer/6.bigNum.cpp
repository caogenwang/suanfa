/*
https://www.cnblogs.com/rmthy/p/8644236.html
*/
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <list>
#include <queue>
using namespace std;

typedef unsigned int uint;
typedef unsigned long long uint64;

#define MAX_VAL 1000000000 // 10亿
#define VAL_LEN 9
#define FORMAT_STR "%09d"

class LargeInt
{
private:
    std::vector<uint>  _data;

    bool checkValStr(const std::string &valStr);
    int compare(const LargeInt &li) const;
    void arrange();

    static uint estimateQuotient(const LargeInt &liA, const LargeInt &liB);
    static uint getMaxCycle(const LargeInt &liA, const LargeInt &liB);

public:
    LargeInt();
    LargeInt(uint val);
    LargeInt(const std::string &valStr);

    // 四则运算符重载
    LargeInt operator+(const LargeInt &li) const;
    LargeInt operator-(const LargeInt &li) const;
    LargeInt operator*(const LargeInt &li) const;
    LargeInt operator/(const LargeInt &li) const;

    // 比较运算符重载
    bool operator==(const LargeInt &li) const;
    bool operator!=(const LargeInt &li) const;
    bool operator<(const LargeInt &li) const;
    bool operator>(const LargeInt &li) const;
    bool operator<=(const LargeInt &li) const;
    bool operator>=(const LargeInt &li) const;

    // 字符串格式化输出
    std::string toString() const;
};
inline bool isDigit(const char ch)
{
    return ch >= '0' && ch <= '9';
}

LargeInt::LargeInt(){}

LargeInt::LargeInt(uint val)
{
    this->_data.push_back(val % MAX_VAL);
    if(val >= MAX_VAL)
        this->_data.push_back(val/MAX_VAL);
}

bool LargeInt::checkValStr(const string &valStr)
{
    for(auto it = valStr.begin();it != valStr.end();++it)
    {
        if(!isDigit(*it))
            return false;
    }
    return true;
}

LargeInt::LargeInt(const string &valStr)
{
    if (checkValStr(valStr))// 检查valStr合法性
    {
        int len = valStr.length();
        // 按长度9截取子串
        while (len >= VAL_LEN)
        {
            string s = valStr.substr(len - VAL_LEN, VAL_LEN);
            this->_data.push_back(stoi(s));
            len -= VAL_LEN;
        }
        // 残留子串
        if (len > 0)
        {
            string s = valStr.substr(0, len);
            this->_data.push_back(stoi(s));
        }
    }
    this->arrange(); // 去零
}
void LargeInt::arrange()
{
    int idx = this->_data.size();
    while (--idx >= 1)
    {
        if(this->_data[idx]>0)
            break;
        this->_data.pop_back();
    }   
}
int LargeInt::compare(const LargeInt &li) const
{
    int len1 = this->_data.size();
    int len2 = li._data.size();

    //step:比较长度
    if(len1 != len2)
        return (len1>len2) ?1:-1;

    for (int idx = len1 -1 ; idx >= 0; --idx)
    {
        if(this->_data[idx] == li._data[idx])
            continue;
        return this->_data[idx] > li._data[idx]?1:-1;
    }
    return 0;
}

bool LargeInt::operator==(const LargeInt &li) const
{
    return compare(li) == 0;
}

bool LargeInt::operator!=(const LargeInt &li) const
{
    return compare(li) != 0;
}

bool LargeInt::operator<(const LargeInt &li) const
{
    return compare(li) < 0;
}

bool LargeInt::operator>(const LargeInt &li) const
{
    return compare(li) > 0;
}

bool LargeInt::operator<=(const LargeInt &li) const
{
    return compare(li) <= 0;
}

bool LargeInt::operator>=(const LargeInt &li) const
{
    return compare(li) >= 0;
}

LargeInt LargeInt::operator+(const LargeInt &li) const
{
    int len1 = this->_data.size();
    int len2 = li._data.size();

    int minLen = min(len1,len2);
    int maxLen = max(len1,len2);
    const LargeInt &extraLi = (len1 > len2) ? (*this) : li;
    
    uint value = 0;
    uint carry = 0;
    LargeInt retVal;

    for (int idx = 0; idx < minLen; idx++)
    {
        value = this->_data[idx] + li._data[idx] + carry;
        if (value >= MAX_VAL)
        {
            retVal._data.push_back(value - MAX_VAL);
            carry = 1;
        }
        else
        {
            retVal._data.push_back(value);
            carry = 0;
        }
    }
    for (int idx = minLen; idx < maxLen; idx++)
    {
        value = extraLi._data[idx] + carry;
        if (value >= MAX_VAL)
        {
            retVal._data.push_back(value - MAX_VAL);
            carry = 1;
        }
        else
        {
            retVal._data.push_back(value);
            carry = 0;
        }        
    }
    if (carry>0)
    {
        retVal._data.push_back(carry);
    }
    return retVal;
}

LargeInt LargeInt::operator-(const LargeInt &li) const
{
    if(*this <= li)
    {
        return LargeInt(0);
    }
    int         len1 = this->_data.size();
    int         len2 = li._data.size();

    uint        value = 0;  // 差
    uint        carry = 0;  // 借位
    LargeInt    retVal;

     for(int idx = 0;idx < len2;idx++)
     {
         if (this->_data[idx] < li._data[idx] + carry) // 注意细节，carry放在右侧，避免出现差值为负数的情况
        {
            value = this->_data[idx] + MAX_VAL - carry - li._data[idx];//减去以前借出去的位
            carry = 1;
        }
        else
        {
            value = this->_data[idx] - carry - li._data[idx];
            carry = 0;
        }
        retVal._data.push_back(value);
     }
    for (int idx = len2; idx < len1; ++idx)
    {
        if (this->_data[idx] < carry)
        {
            value = this->_data[idx] + MAX_VAL - carry;
            carry = 1;
        }
        else
        {
            value = this->_data[idx] - carry;
            carry = 0;
        }
        retVal._data.push_back(value);
    }

    retVal.arrange();
    return retVal;
}

LargeInt LargeInt::operator*(const LargeInt &li) const
{
    int len1 = this->_data.size();
    int len2 = li._data.size();

    if (len1 < len2) return li.operator*(*this); // 优化，保证被乘数位数大于乘数

    uint64 value;      // 积
    uint64 carry = 0;  // 进位
    LargeInt retVal(0);

    for (int idx2 = 0; idx2 < len2; ++idx2)
    {
        LargeInt mulTemp;
        carry = 0;

        // 补零
        for (int tmpIdx = 0; tmpIdx < idx2; ++tmpIdx)
            mulTemp._data.push_back(0);
        
        for (int idx1 = 0; idx1 < len1; ++idx1)
        {
            value = (uint64)(li._data[idx2]) * (uint64)(this->_data[idx1]) + carry;

            mulTemp._data.push_back((uint)(value % MAX_VAL));
            carry = value / MAX_VAL;
        }

        if (carry)
            mulTemp._data.push_back((uint)carry);

        retVal = retVal + mulTemp;
    }
    return retVal;
}

LargeInt LargeInt::operator/(const LargeInt &li) const
{
    if (li._data.empty() || li == 0) 
        return LargeInt("");
    if (*this < li) 
        return LargeInt(0);
    
    int len1 = this->_data.size();
    int len2 = li._data.size();

    uint value;
    LargeInt retVal;
    LargeInt divTemp;

    for (int idx = len1 - len2 + 1; idx < len1; ++idx)
    {
        divTemp._data.push_back(this->_data[idx]);
    }

     // len1 >= len2
    for (int idx = len1 - len2; idx >= 0; --idx)
    {
        value = 0;
        divTemp._data.insert(divTemp._data.begin(), this->_data[idx]);
        divTemp.arrange();

        value = getMaxCycle(divTemp, li); // 商

        divTemp = divTemp - li * value;   // 余数  

        retVal._data.insert(retVal._data.begin(), value); // 除法是由高位向低位进行，所以插入位置在begin
    }
    retVal.arrange();
    return retVal;
}
// 计算商值
uint LargeInt::getMaxCycle(const LargeInt &liA, const LargeInt &liB)
{
    LargeInt        tempA = liA;
    const LargeInt& tempB = liB;
    uint            tempC;
    uint            res = 0;
    uint            counter = 0; // 调试用
    bool            flag = true;


    while (tempA >= tempB)
    {
        counter++;
        
        tempC = estimateQuotient(tempA, tempB);
        tempA = tempB * tempC - tempA;
       
        res = flag ? (res + tempC) : (res - tempC);
        flag = !flag;
    }

    // 微调 
    while (res > 0 && liB * res > liA) res--;

    return res;
}

// 估值
uint LargeInt::estimateQuotient(const LargeInt &liA, const LargeInt &liB)
{
    int         lenA = liA._data.size();
    int         lenB = liB._data.size();
    uint64      valA, valB;

    if (lenA == lenB)
    {
        if (lenA > 1)
        {
            valA = (uint64)liA._data[lenA - 1] * MAX_VAL + liA._data[lenA - 2];
            valB = (uint64)liB._data[lenB - 1] * MAX_VAL + liB._data[lenB - 2];
        }
        else
        {
            valA = (uint64)liA._data[lenA - 1];
            valB = (uint64)liB._data[lenB - 1];
        }
    }
    else
    {
        valA = (uint64)liA._data[lenA - 1] * MAX_VAL + liA._data[lenA - 2];
        valB = (uint64)liB._data[lenB - 1];
    }

    return (uint)(valA / valB);
}
string LargeInt::toString() const
{
    int len = this->_data.size();
    int shift = 0;
    char *buff = new char[len * VAL_LEN + 1];

    if (len > 0)
        shift += sprintf(buff + shift, "%d", this->_data[len - 1]);

    for (int idx = len - 2; idx >= 0; --idx)
    {
        shift += sprintf(buff + shift, FORMAT_STR,  this->_data[idx]);
    }
    buff[shift] = '\0';

    string retStr(buff);
    delete[] buff;

    return retStr;
}
void division(char *a, int b)
{
	int q, r, len;

	len = strlen(a);
	for (int i = 0; i < len; i++)a[i] -= '0';
	if (len == 1)
	{
		r = a[0] % b;
		printf("%d %d", a[0] / b, r);
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			if(i!=len-1)
				if (a[i] / b != 0)
				{
					a[i + 1] += 10 * (a[i] % b);
					a[i] /= b;
				}
				else
				{
					a[i + 1] += 10 * a[i];
					a[i] = 0;
				}
			else if (i == len - 1)
			{
				r = a[i] % b;
				a[i] /= b;
			}
		}
		for (int i = 0; i < len; i++)
			if (i == 0 && a[i] != 0)printf("%d", a[i]);
			else if (i != 0)printf("%d", a[i]);
		printf(" %d", r);
	}

	return ;
}