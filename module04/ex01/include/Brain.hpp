#ifndef BRAIN_H
#define BRAIN_H
#include <iostream>
#include <string>

class Brain {
public:
    Brain();
    Brain(const Brain&);
    ~Brain();
    Brain& operator=(const Brain&);

    const std::string* getIdeas() const;

private:
    std::string _ideas[100];
};

#endif
