#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <exception>
#include <string>

class Bureaucrat {
private:
    const std::string _name;
    uint _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string& name, uint grade);
    Bureaucrat(const Bureaucrat& copy);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& copy);

    const std::string& getName();
    uint getGrade();

    class GradeTooHighException : public std::exception {
    private:
        std::string error;

    public:
        GradeTooHighException(std::string error);
        const std::string& getError() const;
    };

    class GradeTooLowException : public std::exception {
    private:
        std::string error;

    public:
        GradeTooLowException(std::string error);
        const std::string& getError() const;
    };
};

#endif
