#include <iostream>
#include <string>
using namespace std;

class MyString
{
    public:

        MyString(const char* str) : text(str)
        { 
            std::cout << "构造函数" << std::endl; 
        }
        
        MyString(const MyString& myString) 
        {
            std::cout << "复制构造函数" << std::endl;
            (*this).text = myString.text;
        }

        ~MyString() 
        { 
            std::cout << "析构函数" << std::endl; 
        }

        bool operator==(MyString rhs) const      // pass by value 按值传递,const 函数，不要修改类的对象
        {
            std::cout << "operator==(MyString rhs) pass by value" << std::endl;
            return (*this).text == rhs.text;
        }

        bool operator==(const MyString& rhs)
        {
            std::cout << "operator==(const MyString& rhs)  \
                pass by referenc-to-const" << std::endl;
            return (*this).text == rhs.text;
        }

        const char& operator[](std::size_t position) const  // 一如既往，需要传回const的变量
        { 
            //因为有const,不能修改类对象的值
            
            // ...    // 边界检查
            // ...    // 日志记录
            // ...    // 校验数据完整性
            return text[position]; 
        }

        //     char& operator[](std::size_t position)
        // { 
        //     ...    // 边界检查
        //     ...    // 日志记录
        //     ...    // 校验数据完整性
        //     return text[position]; 
        // }

        //static_cast<const MyString&>(*this)[position]，
        //表示将 MyString& 转换成 const MyString&，可让其调用 const operator[] 兄弟；
        //const_cast<char&>( ... )，表示将 const char & 转换为 char &，
        //让其是 non-const operator[] 的返回类型。
        
        char& operator[](std::size_t position)
        { 
            return const_cast<char&>(
                    static_cast<const MyString&>(*this)[position]
                    ); 
        }
    private:
        std::string text;
};
//改善C++ 程序效率的一个根本的方法是以 pass by referenc-to-const（const T& a） 方式传递对象
const int  func(const int &i)
{
    cout<<i<<endl;
    return i;
}

int main()
{
    std::cout << "main()" << std::endl;
    MyString ms1("小林coding");
    MyString ms2("小林coding");

    std::cout << ( ms1 == ms2) << std::endl;//采用按值传递，会出现一个临时变量
    std::cout << "end!" << std::endl;

    int a = 0;
    a = func(a);

    return 0;
}