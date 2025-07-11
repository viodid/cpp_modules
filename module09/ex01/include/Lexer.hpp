#ifndef Lexer_HPP
#define Lexer_HPP

#include <string>

typedef enum e_tokenType {
    OPERATOR,
    OPERAND,
} tokenType;

typedef struct s_token {
    tokenType type;
    std::string literal;
} t_token;

typedef struct s_list {
    void* content;
    s_list* next;
} t_list;

class Lexer {

private:
    int position;
    int readPosition;
    char ch;

    void _readChar();

public:
    Lexer();
    ~Lexer();

    t_token nextToken();
};
#endif
