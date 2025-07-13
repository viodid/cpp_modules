#include "../include/Lexer.hpp"

static bool isNumber(char ch);

Lexer::Lexer(const std::string& b)
    : _buffer(b)
    , _position(0)
    , _readPosition(0)
    , _ch(b[0])
{
    _readChar();
}

Lexer::~Lexer() { }

/*
 * Check if the current position is EOF and move the pointer to the next ch
 */
void Lexer::_readChar()
{
    if (_readPosition >= (int)_buffer.length()) {
        _ch = 0;
    } else {
        _ch = _buffer[_readPosition];
    }
    _position = _readPosition;
    _readPosition++;
}

/*
 * Advance to the next char and returns the next token
 */
t_token Lexer::nextToken()
{
    t_token t;
    _eatWhitespace();
    switch (_ch) {
    case '+':
        t.literal = _ch;
        t.type = PLUS;
        break;
    case '-':
        t.literal = _ch;
        t.type = MINUS;
        break;
    case '/':
        t.literal = _ch;
        t.type = SLASH;
        break;
    case '*':
        t.literal = _ch;
        t.type = ASTERISK;
        break;
    case '\0':
        t.literal = "";
        t.type = END;
        break;
    default:
        if (isNumber(_ch))
            t.type = NUMBER;
        else
            t.type = ILEGAL;
        t.literal = _ch;
    }
    _readChar();
    return t;
}

/*
 * advance the nextChar until a valid char is found or '\0'. It mutates state
 */
void Lexer::_eatWhitespace()
{
    while (_ch == ' ' || _ch == '\t' || _ch == '\n') {
        _readChar();
    }
}

static bool isNumber(char ch)
{
    return ch > '0' and ch < '9';
}
