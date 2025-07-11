#include "../include/Lexer.hpp"

Lexer::Lexer(const std::string& b)
    : _buffer(b)
    , _position(0)
    , _readPosition(0)
    , _ch(b[0])
{
}

Lexer::~Lexer() { }

/*
 * Check if the current position is EOF and move the pointer to the next ch
 */
void Lexer::_readChar()
{
    if (_readPosition == len(_buffer))
    // TODO
}
