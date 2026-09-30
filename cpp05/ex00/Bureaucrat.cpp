#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Unnamed Bureaucrat"), grade_(LOWEST_GRADE) {
  std::cout << "[Bureaucrat] Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name_(name) {
  std::cout << "[Bureaucrat] Constructor called." << std::endl;
  if (grade < HIGHEST_GRADE)
    throw GradeTooHighException();
  if (grade > LOWEST_GRADE)
    throw GradeTooLowException();
  grade_ = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
    : name_(other.name_), grade_(other.grade_) {
  std::cout << "[Bureaucrat] Copy constructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
  std::cout << "[Bureaucrat] Copy assignment called." << std::endl;
  if (this != &other)
    grade_ = other.grade_;
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "[Bureaucrat] Destructor called." << std::endl;
}

void Bureaucrat::incrementGrade() {
  if (grade_ <= HIGHEST_GRADE)
    throw GradeTooHighException();
  grade_--;
}

void Bureaucrat::decrementGrade() {
  if (grade_ >= LOWEST_GRADE)
    throw GradeTooLowException();
  grade_++;
}

std::string const &Bureaucrat::getName() const { return name_; }
int Bureaucrat::getGrade() const { return grade_; }

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj) {
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
  return os;
}