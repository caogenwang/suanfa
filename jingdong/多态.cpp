#include <iostream>
using namespace std;
 
class Father
{
public:
	int m_fMember;
 
	void testFunc(){
		cout<<"Father testFunc "<<m_fMember<<endl;
	}
	virtual void testVFunc(){
		cout<<"Father testVFunc "<<m_fMember<<endl;
	}
	Father(){m_fMember=1;}
};
 
class Child : public Father{
public:
	int m_cMember;
	Child(){m_cMember=2;}
	
	virtual void testVFunc(){cout<<"Child testVFunc "<<m_cMember<<":"<<m_fMember<<endl;}
	void testFunc(){cout<<"Child testFunc "<<m_cMember<<":"<<m_fMember<<endl;}
	void testNFunc(){cout<<"Child testNFunc "<<m_cMember<<":"<<m_fMember<<endl;}
};
 
 
int main()
{
	Father* pRealFather = new Father();
	Child* pFalseChild = (Child*)pRealFather;
	Father* pFalseFather = new Child();
	
	pFalseFather->testFunc();//Father testFunc 1,这个地方是静态的绑定，所以虽然pFalseFather指向子类对象，但是调用的还是基类的函数
	pFalseFather->testVFunc();//Father testFunc 1,这个地方是动态绑定，需要调用子类的函数
 
	pFalseChild->testVFunc();//Father testVFunc 1,动态绑定，执行具体的类型的函数
	/*注意这是静态绑定，所以调用的是子类对象的函数，如果指针为空的话也能调用到，因为是子类
        指向一个强制类型转换的基类，所以并不存在子类的成员数据，但是成员函数已经绑定
    */
    pFalseChild->testFunc();//Child testFunc -1073741824:1
	pFalseChild->testNFunc();//Child testNFunc -1073741824:1
 
	return 0;

}

