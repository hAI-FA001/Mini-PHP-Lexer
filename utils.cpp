#include "includes/utils.hpp"

void generateToken(char buffers[2][4096], int activeBuffer, int i, int j, LEXICAL_UNITS lexicalUnit)
{
    std::cout << "TOKEN: <";
    if (i <= j)
    {
        for (int idx = i; idx <= j; idx++)
        {
            std::cout << buffers[activeBuffer][idx];
        }
    }
    else
    {
        int otherBuffer = (activeBuffer == 0) ? 1 : 0;

        for (int idx = i; idx < 4096; idx++)
        {
            std::cout << buffers[otherBuffer][idx];
        }

        for (int idx = 0; idx <= j; idx++)
        {

            std::cout << buffers[activeBuffer][idx];
        }
    }

    std::cout << ", ";

    switch (lexicalUnit)
    {
    case KEYWORD:
        std::cout << "KEYWORD";
        break;
    case IDENTIFIER:
        std::cout << "IDENTIFIER";
        break;
    case LITERAL:
        std::cout << "LITERAL";
        break;
    case OPERATOR:
        std::cout << "OPERATOR";
        break;
    case PUNCTUATION:
        std::cout << "PUNCTUATION";
        break;
    case COMMENT:
        std::cout << "COMMENT";
        break;
    }

    std::cout << ">\n";
}

int calcNumChars(int i, int j)
{
    int numChars = 0;
    if (i <= j) // 1 buffer used
    {
        numChars = j - i + 1;
    }
    else // both buffer used
    {
        numChars = (4095 - i + 1) + (j - 0 + 1);
    }

    return numChars;
}