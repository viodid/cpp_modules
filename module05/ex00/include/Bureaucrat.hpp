#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& copy);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& copy);

    const std::string& getName() const;
    int getGrade() const;
    void incremetGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
