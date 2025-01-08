#include <iostream>

class Fruit{
  public:
  std::string m_name, m_color;
  Fruit(std::string name, std::string color): m_name(name), m_color(color){};
};

class Apple : public Fruit{
  double m_fiber;  
  public:
  Apple(std::string name, std::string color, double fiber) : Fruit(name, color), m_fiber(fiber){};
  friend std::ostream& operator<<(std::ostream&, const Apple&);
};

std::ostream& operator<<(std::ostream& out, const Apple& obj){
  out << "Apple(" << obj.m_name << ", " << obj.m_color << ", " << obj.m_fiber << ");";
  return out;
}

class Banana : public Fruit{
  public:
  Banana(std::string name, std::string color) : Fruit(name, color){}; 
  friend std::ostream& operator<<(std::ostream&, const Banana&);
};

std::ostream& operator<<(std::ostream& out, const Banana& obj){
  out << "Banana(" << obj.m_name << ", " << obj.m_color << ");";
  return out;
}

int main()
{
  const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';
  return 0;
}