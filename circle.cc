#include<iostream>
//题目：设计一个圆类，求元的周长
const double PI=3.14;//创建一个常量PI
class Circle//class 代表设计一个类，类后面紧跟着的就是类的名称Circle
{
  //访问权限
  public:
  //属性：创建一个半径
  int m_r;
  //行为：获取圆的周长
  double calculateZC()
  {
    return 2*PI*m_r;
  }
};
int main()
{
  //通过圆类创建一个具体的圆（对象）
  Circle c1;//c1就是那个具体的圆
  //给圆对象的属性进行赋值
  c1.m_r=10;//"."就可以访问他的属性和行为
  std::cout<<"圆的周长为" <<c1.calculateZC()<<std::endl;
  return 0;
}


