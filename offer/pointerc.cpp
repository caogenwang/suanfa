#include <iostream>
#include <string>
#include <memory>
using namespace std;

// int main()
// {
// 	string *s1 = new string("s1");

// 	shared_ptr<string> ps1(s1);
// 	shared_ptr<string> ps2;
// 	ps2 = ps1;

// 	cout << ps1.use_count()<<endl;	//2
// 	cout<<ps2.use_count()<<endl;	//2
// 	cout << ps1.unique()<<endl;	//0

// 	string *s3 = new string("s3");
// 	shared_ptr<string> ps3(s3);

// 	cout << (ps1.get()) << endl;	//033AEB48
// 	cout << ps3.get() << endl;	//033B2C50
// 	swap(ps1, ps3);	//交换所拥有的对象
// 	cout << (ps1.get())<<endl;	//033B2C50
// 	cout << ps3.get() << endl;	//033AEB48

// 	cout << ps1.use_count()<<endl;	//1
// 	cout << ps2.use_count() << endl;	//2
// 	ps2 = ps1;
// 	cout << ps1.use_count()<<endl;	//2
// 	cout << ps2.use_count() << endl;	//2
// 	ps1.reset();	//放弃ps1的拥有权，引用计数的减少
// 	cout << ps1.use_count()<<endl;	//0
// 	cout << ps2.use_count()<<endl;	//1
// }

/*
可以看到fun函数中pa ，pb之间互相引用，两个资源的引用计数为2，
当要跳出函数时，智能指针pa，pb析构时两个资源引用计数会减1，
但是两者引用计数还是为1，导致跳出函数时资源没有被释放（A、B的析构函数没有被调用）
运行结果没有输出析构函数的内容，造成内存泄露。如果把其中一个改为weak_ptr就可以了，
我们把类A里面的shared_ptr pb_，改为weak_ptr pb_ 
*/
// class B;	//声明
// class A
// {
// public:
// 	weak_ptr<B> pb_;
// 	~A()
// 	{
// 		cout << "A delete\n";
// 	}
// };

// class B
// {
// public:
// 	shared_ptr<A> pa_;
// 	~B()
// 	{
// 		cout << "B delete\n";
// 	}
// };

// void fun()
// {
// 	shared_ptr<B> pb(new B());
// 	shared_ptr<A> pa(new A());
// 	cout << pb.use_count() << endl;	//1
// 	cout << pa.use_count() << endl;	//1
// 	pb->pa_ = pa;
// 	pa->pb_ = pb;
// 	cout << pb.use_count() << endl;	//2
// 	cout << pa.use_count() << endl;	//2
// }

// int main()
// {
// 	fun();
// 	return 0;
// }

class D;	//声明
class C
{
public:
	shared_ptr<D> pd_;
	~C()
	{
		cout << "C delete\n";
	}
};

class D
{
public:
	shared_ptr<C> pc_;
	~D()
	{
		cout << "D delete\n";
	}
};

void test()
{
	shared_ptr<D> pd(new D());
	shared_ptr<C> pc(new C());
	cout << pd.use_count() << endl;	//1
	cout << pc.use_count() << endl;	//1
	pd->pc_ = pc;
	pc->pd_ = pd;
	cout << pd.use_count() << endl;	//2
	cout << pc.use_count() << endl;	//2
}

int main()
{
	test();
	return 0;
}