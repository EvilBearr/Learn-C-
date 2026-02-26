#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<ctype.h>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
//struct与class的区别:struct默认权限是公共权限,class默认是私有

/*
控制读写权限:类内private写所有属性,类内public写函数
只写显示函数->可读不可写,只写设置函数->可写不可读
*/

/*
构造函数与析构函数 当不写时编译器默认写,但里面时空语句
构造函数分类:有参函数,无参函数,拷贝构造函数
*/

/*
拷贝构造函数的调用时机1.通过一个已经创建的对象来初始化一个新对象  person p1(p2);
2.通过值传递方式给函数参数传值  person p1;void test(person p1){ ;}
3.值方式返回局部对象     person test01(){
        person p1;
        return p1;
    };
    void funn(){
    person p2=test01();
    }
    调用funn函数时可能调用拷贝构造函数
*/

/*构造函数的调用规则:
c++编译器默认提供:无参构造函数,拷贝构造函数,析构函数
提供有参构造函数,编译器不提供无参构造函数,但是提供拷贝构造函数
提供拷贝构造函数,编译器无参有参构造函数都不提供
*/

/*
浅拷贝:编译器默认提供,如果类内在堆区开辟了内存,析构函数要释放内存,会导致同一块内存被重复释放,所以要深拷贝
*/

/*
B类中的成员可以是A类的对象,该成员称为对象成员
class A{};
class B{
public:
A a;
};
构造顺序,先构造A,再构造B,析构顺序则相反
*/
class animal{
    public:
    static int size;//静态成员变量,所有对象共享,类内定义,类外初始化
    int age;
    //访问方式 1. a.size  2. animal::size
    static void funny(){
        size=50;//只能访问静态成员变量,因为静态成员变量是共享的
        //age=0;报错!!!不能访问非静态成员变量
        cout<<"静态成员函数的调用"<<endl;
    }
    //静态对象函数可以通过类名访问  eg:animal::funny(); 也可以通过对象访问
};
int animal::size=100;//初始化
void statictest(){
    animal a1,a2;
    a2.size=200;
    cout<<a1.size<<endl;//输出也是200;
}
class person{
    public: string name;
    int age;
    int money;
    int *height;
    person(){
        cout<<"无参构造函数的调用"<<endl;
    }
    person(int a,int h){
        age=a;
        height=new int(h);
        cout<<"有参构造函数的调用"<<endl;
    }
    // person(const person &p){
    //     age=p.age;
    //     name=p.name;
    //     money=p.money;
    //     car=p.car;
    //     password=p.password;
    //     height=p.height;//编译器默认提供,直接让指针指向相同,是浅拷贝
    //     cout<<"拷贝构造函数的调用"<<endl;
    // }
    person(const person&p){
        age=p.age;
        name=p.name;
        money=p.money;
        car=p.car;
        password=p.password;
        height=new int(*p.height);
        cout<<"深拷贝构造函数的调用"<<endl;
    }
    ~person(){
        if(height!=NULL){
            delete height;
            height=NULL;//防止野指针
        }
        cout<<"析构函数的调用"<<endl;
    }
    void func(){
        cout<<"姓名:"<<name<<endl;
    }
    protected: string car;//保护权限:类内可访问,类外不可以
    private: string password;//私有权限:类内可访问,类外不可以
};
//设置一个圆类
class circle{
    //访问权限
    public:
    //属性:也叫做成员属性
    int r;
    //行为,获取圆的周长与面积:行为也叫做成员函数
    double c(){
        return 2*3.14*r;
    }
    double s(){
        return 3.14*r*r;
    }
    void setr(int a){
        r=a;
    }
};
int main(){
    // circle c1;//通过圆类创建一个圆对象(实例化:通过类创建对象的过程)
    // c1.r=10;
    // c1.setr(20);//使用函数给圆的半径赋值
    // cout<<"周长:"<<c1.c()<<" 面积:"<<c1.s()<<endl;
    // person s1;//默认调用无参构造函数,注意不要加括号
    // s1.name="张三";//s1.car="奔驰"不可访问
    // person s2(s1);//调用拷贝构造函数
    // person p3(10);//调用有参构造函数
    // statictest();
    return 0;
}