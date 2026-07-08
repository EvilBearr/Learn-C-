#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class building;
class gay{
    public:
    building* b;
    int age;
    int money;
    void visit(building &a);
    void visit2(building &a);
    // gay(){
    //     b=new building;
    // }这样不对,因为building定义还不完整,必须在building的实现后面定义gay的构造函数
    gay();//先声明,在之后实现
};
class building{
friend void gay::visit(building &a);//成员函数作为友元,visit可以访问私有成员,而visit2不可以
friend void look(building b);//全局函数(类外的函数)做友元,在类外也可以访问私有成员,需要在对应类内声明,加上friend关键字
public:
// friend class gay;//gay这个类是building类的好朋友,gay类中所以函数或者指针都可以访问building中的私有成员
building(){//构造函数
    this->sittingroom="客厅";
    this->bedroom="卧室(building中的私有成员)";
}
string sittingroom;
private:
string bedroom;
};

//类内声明的函数实现
gay::gay(){
    b=new building;
}
void gay::visit(building &a){
    cout<<"访问私有内容: "<<a.bedroom<<endl;
}
void gay::visit2(building &a){
    cout<<a.sittingroom<<endl;
    // cout<<a.bedroom<<endl;会报错,因为这个成员函数不是友元
}

//一个全局函数
void look(building b){//全局函数(类外的函数)做友元,在类外也可以访问私有成员,需要在对应类内声明,加上friend关键字
    cout<<"访问私有成员: "<<b.bedroom<<endl;
}

//测试函数
void test01(){
    gay a;
    cout<<"访问: "<<a.b->sittingroom<<endl;
}
void test02(){
    gay a;
    a.visit(*(a.b));
}


int main(){
    // building a;
    // look(a);
    // test01();
    test02();
    return 0;
}
