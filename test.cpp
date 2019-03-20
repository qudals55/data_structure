#include <iostream>

class Car
{

public:
  Car(int& _r)
  :ref(_r)
  {
    std::cout<<"ha"<<std::endl;
  }

  void dummy()
  {
    ref=100;
  }

private:
  int& ref;

};

int main()
{
  int i;
  Car c(i);
  c.dummy();

  std::cout<<i<<std::endl;
}
