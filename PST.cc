#include<iostream>
#include<vector>
#include<string>
#include<memory>
class person
{
  public:
    person(std::string name):m_name(name){}
    virtual ~person()=default;
    virtual void print()=0;
    std::string getname()
    {
      return m_name;
    }
  private:
    std::string m_name;
};
class student:public person
{
  public:
    student(std::string name,int age):person(name),m_age(age){}
    ~student()
    {
      std::cout<<"ooo"<<std::endl;
    }
    int getage()
    {
      return m_age;
    }
    virtual void print()override
    {
      std::cout<<"student's name: "<<getname()<<", age: "<<getage()<<std::endl;
    }

  private:
    int m_age;
};
class teacher:public person
{
  public:
    teacher(std::string name,int id):person(name),m_id(id){}
    ~teacher()
    {
      std::cout<<getname()<<"is been dismissed"<<std::endl;
    }
    int getid()
    {
      return m_id;
    }
    virtual void print()override
    {
      std::cout<<"teacher's name: "<<getname()<<", id: "<<getid()<<std::endl;
    }
    void add(std::shared_ptr<student> s)
    {
      T.push_back(s);
    }
    void printstudent()
    {
      std::cout<<getname()<<" 's students"<<std::endl;
      for(auto student:T)
      {
        student->print();
      }
    }
    void transferStudentsTo(std::shared_ptr<teacher> newTeacher) 
    {
      for ( auto student:T) 
      {
        newTeacher->add(student);
      }
      T.clear();
    }
  private:
    int m_id;
    std::vector<std::shared_ptr<student>>T;
};
int main()
{
  std::shared_ptr<student> S1=std::make_shared<student>("kk",20);
  std::shared_ptr<student> S2=std::make_shared<student>("ll",30);
  std::shared_ptr<student> S3=std::make_shared<student>("hh",40);
  std::shared_ptr<teacher> T1=std::make_shared<teacher>("YY",123);
  std::shared_ptr<teacher> T2=std::make_shared<teacher>("TT",456);
  T1->add(S1);
  T1->add(S2);
  T1->add(S3);
  std::cout<<"before"<<std::endl;
  T1->printstudent();
  T2->printstudent();
  T1->transferStudentsTo(T2);
  std::cout<<"after"<<std::endl;
  T1->printstudent();
  T2->printstudent();

  return 0;
}




