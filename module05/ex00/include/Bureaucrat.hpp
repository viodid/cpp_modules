#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <exception>
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
    private:
        std::string _error;

    public:
        GradeTooHighException(std::string error);
        ~GradeTooHighException() throw();

        const std::string& getError() const;
    };

    class GradeTooLowException : public std::exception {
    private:
        std::string _error;

    public:
        GradeTooLowException(std::string error);
        ~GradeTooLowException() throw();

        const std::string& getError() const;
    };
};
#endif
