#ifndef QIJU_H
#define QIJU_H
#include"Tic.h"
class Qiju
{
public:
    static Tic::TTTS CheckWin(Tic::TTTS array[][3])
    {
        for (int i = 0; i < 3; i++)
            if (array[i][0] == array[i][1] && array[i][0] == array[i][2] && array[i][0] != Tic::TTTS_Default)
                return array[i][0];
        for (int j = 0; j < 3; j++)
            if (array[0][j] == array[1][j] && array[0][j] == array[2][j] && array[0][j] != Tic::TTTS_Default)
                return array[0][j];

        if (array[0][0] == array[1][1] && array[0][0] == array[2][2] && array[0][0] != Tic::TTTS_Default)
            return array[0][0];
        if (array[0][2] == array[1][1] && array[0][2] == array[2][0] && array[0][2] != Tic::TTTS_Default)
            return array[0][2];

        return Tic::TTTS_Default;
    }
};
#endif