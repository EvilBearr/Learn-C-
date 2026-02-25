#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int compare(const pair<int,int>&a,const pair<int,int>&b){
    if(a.second>b.second) return 1;
    else if(a.second==b.second){
        if(a.first<=b.first)return 1;
        else return 0;
    }
    else return 0;
}
int *func(){
    int a=15;
    int *p=new int(a);//在堆区开辟一块内存,new 返回该数据类型的指针
    int *q=new int[10];//堆区开辟一块内存存数组
    return q;
}
int main(){
    //函数返回值是引用,可以让函数调用作为左值,不能返回局部变量的引用
    int a=10;
    int &b=a;//给a取别名为b,操作b相当于操作a.注意:引用必须初始化,且引用后不可以改变(引用相当于指针常量,指向不能改变)
    int *z=func();
    cout<<z[5]<<endl;
    delete []z;//释放数组内存前面加[]后面是指针名字
    //函数形参写成const int&a,防止使用函数时把原来的实参改变
    //函数有默认值,可以少传参数;但是有默认值再传参数,按传入的参数计算
    /*1.函数有多个参数,某个参数有默认值,从这个参数开始到最后都必须有默认值
    eg:int func(int a=10;int b);这是不对的,b也需要有参数
    2.函数声明和实现部分只能有一个地方传入默认值,不能都传,可以都不传
    */
   /*函数的占位参数:只写数据类型,占位后必须传值,但是占位参数也可以有默认值void func(int a,int=10),之后就不用传了*/
   /*函数重载(函数名字相同但是能多次定义)
   条件:1.函数名称相同2.函数返回值相同3.函数作用域相同4.函数参数不同或数量不同或顺序不同
   */
    cout<<"test"<<endl;
   return 0; 
}


