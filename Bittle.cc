#include<iostream>
#include<memory>
class geometry
{
  public:
    geometry()=default;
    virtual ~geometry()=default;
    virtual double getS()=0;
};
class cube:public geometry
{
  public:
    cube(double l,double w):m_l(l),m_w(w){}
    virtual double getS() override
    {
      double s=m_l*m_w;
      return s;
    }
    virtual ~cube()
    {
      std::cout<<"...."<<std::endl;
    }
  private:
    double m_l;
    double m_w;
};
class triange:public geometry
{
  public:
    triange(int a,int b):m_a(a),m_b(b){}
    virtual double getS() override
    {
      double s=0.5*m_a*m_b;
      return s;
    }
    virtual ~triange()
    {
      std::cout<<"ooo"<<std::endl;
    }
  private:
    int m_a;
    int m_b;
};
/*bool compare(cube &b,triange &t)
{
  return b.getS()<t.getS();
}*/
bool compare(std::shared_ptr<geometry>& b, std::shared_ptr<geometry>& t) 
{
  return b->getS() < t->getS();
}
int main()
{
 // cube b1(2.5,3.5);
//  triange t1(3,5);
  std::shared_ptr<geometry>B=std::make_shared<cube>(2.5,3.5);
  std::shared_ptr<geometry>C=std::make_shared<triange>(3,5);
  if(compare(B,C))
  {
    std::cout<<"max:C "<<C->getS()<<std::endl;
  }
  else
  {
    std::cout<<"max:B "<<B->getS()<<std::endl;
  }
  return 0;
}



