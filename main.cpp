#include <iostream>
#include <fstream>
#include <string>

#include "includes/utils.hpp"
#include "includes/transition_table.hpp"
#include "includes/enums.hpp"

extern int transitionTable[34][128 + 3];

int main()
{
    std::string filePath;
    std::cout << "Enter file path: ";
    std::getline(std::cin, filePath);

    std::ifstream inputFile(filePath, std::ios::in);

    char buffers[2][4096];

    int activeBuffer = 0;
    bool dontIncrement = false;

    int i = -1;
    int j = 0;
    char ch;
    int state = 0;

    inputFile.read(buffers[activeBuffer], 4096);

    while ((ch = buffers[activeBuffer][j]) != EOF && j < inputFile.gcount())
    {
        if (!transitionTable[state][ACCEPTING])
        {
            int nextState = transitionTable[state][ch];

            if (nextState != -1)
            {
                if (state == 0)
                {
                    i = j;
                }

                // 4096 limit in double buffering
                if (calcNumChars(i, j) == 4096 && !transitionTable[nextState][ACCEPTING])
                {
                    nextState = 0;
                    i = -1;
                }

                if (transitionTable[nextState][ACCEPTING])
                {
                    dontIncrement = true;
                }

                state = nextState;
            }
            else
            {
                state = 0;
                i = -1;
            }
        }
        else
        {
            int endIdx = j;
            int activeBufferForLexeme = activeBuffer;

            if (transitionTable[state][RETRACTING])
            {
                dontIncrement = true;
                if (endIdx == 0)
                {
                    endIdx = 4095;
                    activeBufferForLexeme = (activeBuffer == 0) ? 1 : 0;
                }
                else
                {
                    endIdx--;
                }
            }

            if (transitionTable[state][TOKEN] != COMMENT)
            {
                generateToken(buffers, activeBufferForLexeme, i, endIdx, (LEXICAL_UNITS)transitionTable[state][TOKEN]);
            }
            else
            {
                std::cout << "Ignoring comment\n";
            }

            state = 0;
            i = -1;
        }

        if (!dontIncrement)
        {
            j++;
        }
        dontIncrement = false;

        if (j >= 4096)
        {
            activeBuffer = (activeBuffer == 0) ? 1 : 0;
            inputFile.read(buffers[activeBuffer], 4096);
            j = 0;
        }
    }

    return 0;
}