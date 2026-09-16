#pragma once

# define MAX_GRADE 150
# define MIN_GRADE 1

 class Bureaucrat {
    private:
        std::string const name_;
        unsigned int grade_;
    public:
        Bureaucrat(); // Default constructor
        Bureaucrat(std::string const &name, unsigned int grade); // Parameterized constructor
        Bureaucrat(Bureaucrat const &other); // Copy constructor
        Bureaucrat &operator=(Bureaucrat const &other); // Copy assignment operator
        ~Bureaucrat(); // Destructor
 }