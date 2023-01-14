#include "../../sirius/util/lock/spin_lock.hpp"
#include "iostream"
class Test {
public:
  int& getA() {
    return a;
  }
private:
  int a = 10;
};

int main() {
  Test a;
  int &b = a.getA();
  //b = 3;
  std::cout << a.ge << "\n";
  return 0;
}