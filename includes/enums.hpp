#ifndef ENUMS_H
#define ENUMS_H

enum COL
{
    ACCEPTING = 128,
    RETRACTING,
    TOKEN
};

enum State
{
    False = 0,
    True = 1
};

enum LEXICAL_UNITS
{
    NONE = 0,
    KEYWORD,
    IDENTIFIER,
    LITERAL,
    OPERATOR,
    PUNCTUATION,
    COMMENT
};

#endif