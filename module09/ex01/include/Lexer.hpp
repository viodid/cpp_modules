#ifndef Lexer_HPP
#define Lexer_HPP

#include <string>

typedef enum e_tokenType {
    // OPERANDS
    NUMBER,
    // OPERATORS
    PLUS,
    MINUS,
    SLASH,
    ASTERISK,
    // SPECIAL
    ILEGAL,
    END,
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
    const std::string& _buffer;
    int _position;
    int _readPosition;
    char _ch;

    void _readChar();
    void _eatWhitespace();

public:
    Lexer(const std::string&);
    ~Lexer();

    t_token nextToken();
};
#endif
