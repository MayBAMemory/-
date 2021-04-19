#ifndef QIPAN_H
#define QIPAN_H
#include"Tic.h"
#include<iostream>
class Qipan
{
public:
    static void Print(Tic::TTTS array[][3])
    {
        for (int i = 0; i < 3; i++)
        {
            std::cout << " -----   -----   -----" << std::endl;
            for (int j = 0; j < 3; j++)
            {
                if (array[i][j] == Tic::Tic::TTTS_Default)
                    std::cout << "|     | ";
                else if (array[i][j] == Tic::Tic::TTTS_O)
                    std::cout << "|  O  | ";
                else
                    std::cout << "|  X  | ";
            }
            std::cout << std::endl;
            std::cout << " -----   -----   -----" << std::endl;
        }
    }
};
#endif