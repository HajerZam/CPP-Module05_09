#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat b1("John", 0);
    std::cout << b1 << std::endl;
  } catch (std::exception const &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat b2("Jane", 151);
    std::cout << b2 << std::endl;
  } catch (std::exception const &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat b3("Alice", 75);
    std::cout << b3 << std::endl;
    b3.incrementGrade();
    std::cout << "After increment: " << b3 << std::endl;
    b3.decrementGrade();
    std::cout << "After decrement: " << b3 << std::endl;
  } catch (std::exception const &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat top("Boss", 1);
    top.incrementGrade(); // should throw
  } catch (std::exception const &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat low("Intern", 150);
    low.decrementGrade(); // should throw
  } catch (std::exception const &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}