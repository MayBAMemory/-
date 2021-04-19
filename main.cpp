#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "Qiju.h"
#include "Qipan.h"
#include "Tic.h"

using namespace std;

int main()
{
    srand((int)time(0));

    Tic::TTTS array[3][3] = {Tic::TTTS_Default};

    int index_x, index_y, indexx, indexy;
    int counter = 0;
    string choice;

    Qipan::Print(array);

    cout << "请选择模式：" << endl
         << "1.人机模式" << endl
         << "2.挑战自己模式" << endl;
    cin >> choice;
LOOP:
    if (choice == "2") //人人模式
    {
        cout << "请输入坐标（行 列）：";
        while (cin >> indexx >> indexy)
        {
            index_x = indexx - 1;
            index_y = indexy - 1;
            if (!((index_x >= 0 && index_x < 3) && (index_y >= 0 && index_y < 3)) || (array[index_x][index_y] != Tic::TTTS_Default))
            {
                cout << "下错了，再输入一次吧" << endl
                     << "请输入坐标（行 列）：";
                continue;
            }

            array[index_x][index_y] = counter % 2 ? Tic::TTTS_O : Tic::TTTS_X;

            Qipan::Print(array);
            cout << "请输入坐标（行 列）：";
            if (Tic::TTTS_O == Qiju::CheckWin(array))
            {
                cout << "游戏结束，O获胜" << endl;
                break;
            }
            else if (Tic::TTTS_X == Qiju::CheckWin(array))
            {
                cout << "游戏结束，X获胜" << endl;
                break;
            }

            counter++;
            if (counter >= 9)
            {
                cout << "游戏结束，平局" << endl;
                break;
            }
        }
    }
    else if (choice == "1") //人机模式
    {
        cout << "请选择难度：" << endl
             << "1.简单模式" << endl
             << "2.难一点点模式" << endl;
    a:
        cin >> choice;
        if (choice == "1") //简单模式
        {
            cout << "请输入坐标（行 列,玩家为O）：";

        HAHA:
            while (cin >> indexx >> indexy)
            {

                index_x = indexx - 1;
                index_y = indexy - 1;

                if (!((index_x >= 0 && index_x < 3) && (index_y >= 0 && index_y < 3)) || (array[index_x][index_y] != Tic::TTTS_Default))
                {
                    cout << "下错了，再输入一次吧";
                    Qipan::Print(array);
                    cout << endl
                         << "请输入坐标（行 列）：";
                    continue;
                }
                else
                    counter += 2;
                array[index_x][index_y] = Tic::TTTS_O;
                if (Tic::TTTS_O == Qiju::CheckWin(array))
                {
                    cout << "游戏结束，O获胜" << endl;
                    Qipan::Print(array);
                    break;
                }
                else if (counter >= 9)
                {
                    cout << "游戏结束，平局" << endl;
                    Qipan::Print(array);
                    break;
                }
                Qipan::Print(array);
                cout << "电脑乱下ing.." << endl;
            wuwu:
                indexx = rand() % 3;
                indexy = rand() % 3;
                if (array[indexx][indexy] == Tic::TTTS_Default)
                    array[indexx][indexy] = Tic::TTTS_X;
                else
                    goto wuwu;

                Qipan::Print(array);
                cout << "请输入坐标（行 列）：";

                if (Tic::TTTS_O == Qiju::CheckWin(array))
                {
                    cout << "游戏结束，O获胜" << endl;
                    break;
                }
                else if (Tic::TTTS_X == Qiju::CheckWin(array))
                {
                    cout << "游戏结束，X获胜" << endl;
                    break;
                }
                goto HAHA;
            }
        }
        else if (choice == "2") //困难模式
        {
            Qipan::Print(array);
            cout << "请输入坐标（行 列,玩家为O）：";
        LALA:
            while (cin >> indexx >> indexy)
            {
                index_x = indexx - 1;
                index_y = indexy - 1;
                if (!((index_x >= 0 && index_x < 3) && (index_y >= 0 && index_y < 3)) || (array[index_x][index_y] != Tic::TTTS_Default))
                {
                    cout << "下错了，再输入一次吧" << endl;
                    Qipan::Print(array);
                    cout << "请输入坐标（行 列）：";
                    continue;
                }
                else
                    counter += 2;
                array[index_x][index_y] = Tic::TTTS_O;
                if (Tic::TTTS_O == Qiju::CheckWin(array)) //判断
                {
                    Qipan::Print(array);
                    cout << "游戏结束，O获胜" << endl;
                    break;
                }
                else if (Tic::TTTS_X == Qiju::CheckWin(array)) //判断
                {
                    Qipan::Print(array);
                    cout << "游戏结束，X获胜" << endl;
                    break;
                }
                else if (counter >= 9) //判断
                {
                    Qipan::Print(array);
                    cout << "游戏结束，平局" << endl;
                    break;
                }
                Qipan::Print(array);
                cout << "电脑乱下ing.." << endl;
                if (!(counter == 2))
                {
                    for (int i = 0; i < 3; i++) //前18种情况
                    {
                        if (array[i][0] == Tic::TTTS_O && array[i][1] == Tic::TTTS_O && array[i][2] == Tic::TTTS_Default)
                        {
                            array[i][2] = Tic::TTTS_X;
                            Qipan::Print(array);
                            break;
                        }
                        else if (array[i][1] == Tic::TTTS_O && array[i][2] == Tic::TTTS_O && array[i][2] == Tic::TTTS_Default)
                        {
                            array[i][0] = Tic::TTTS_X;
                            Qipan::Print(array);
                            break;
                        }
                        else if (array[i][0] == Tic::TTTS_O && array[i][2] == Tic::TTTS_O && array[i][2] == Tic::TTTS_Default)
                        {
                            array[i][2] = Tic::TTTS_X;
                            Qipan::Print(array);
                            break;
                        }
                        else if (array[0][i] == Tic::TTTS_O && array[1][i] == Tic::TTTS_O && array[2][i] == Tic::TTTS_Default)
                        {
                            array[2][i] = Tic::TTTS_X;
                            Qipan::Print(array);
                            break;
                        }
                        else if (array[1][i] == Tic::TTTS_O && array[2][i] == Tic::TTTS_O && array[0][i] == Tic::TTTS_Default)
                        {
                            array[0][i] = Tic::TTTS_X;
                            Qipan::Print(array);
                            break;
                        }
                        else if (array[0][i] == Tic::TTTS_O && array[2][i] == Tic::TTTS_O && array[1][i] == Tic::TTTS_Default)
                        {
                            array[1][i] = Tic::TTTS_X;
                            Qipan::Print(array);
                            break;
                        }
                        if (array[0][0] == Tic::TTTS_O && array[1][1] == Tic::TTTS_O && array[2][2] == Tic::TTTS_Default)
                        {
                            array[2][2] = Tic::TTTS_X;
                            Qipan::Print(array);
                            break;
                        }
                        else if (array[0][0] == Tic::TTTS_O && array[2][2] == Tic::TTTS_O && array[1][1] == Tic::TTTS_Default)
                        {
                            array[2][0] = Tic::TTTS_X;
                            Qipan::Print(array);
                            break;
                        }
                        else if (array[1][1] == Tic::TTTS_O && array[2][2] == Tic::TTTS_O && array[0][0] == Tic::TTTS_Default)
                        {
                            array[0][0] = Tic::TTTS_X;
                            Qipan::Print(array);
                            break;
                        }
                        else if (array[0][2] == Tic::TTTS_O && array[1][1] == Tic::TTTS_O && array[2][0] == Tic::TTTS_Default)
                        {
                            array[2][0] = Tic::TTTS_X;
                            Qipan::Print(array);
                            break;
                        }
                        else if (array[0][2] == Tic::TTTS_O && array[2][0] == Tic::TTTS_O && array[1][1] == Tic::TTTS_Default)
                        {
                            array[2][0] = Tic::TTTS_X;
                            Qipan::Print(array);
                            break;
                        }
                        else if (array[1][1] == Tic::TTTS_O && array[2][0] == Tic::TTTS_O && array[0][2] == Tic::TTTS_Default)
                        {
                            array[0][2] = Tic::TTTS_X;
                            Qipan::Print(array);
                            break;
                        }
                        else
                        {
                        qwe:
                            indexx = rand() % 3;
                            indexy = rand() % 3;
                            if (array[indexx][indexy] == Tic::TTTS_Default)
                            {
                                array[indexx][indexy] = Tic::TTTS_X;
                                Qipan::Print(array);
                                break;
                            }
                            else
                                goto qwe;
                        }
                    }
                    if (Tic::TTTS_X == Qiju::CheckWin(array))
                    {
                        cout << "游戏结束，X获胜" << endl;
                        break;
                    }
                    cout << "请输入坐标（行 列）：";
                }
                else
                {
                ahha:
                    indexx = rand() % 3;
                    indexy = rand() % 3;
                    if (array[indexx][indexy] == Tic::TTTS_Default)
                        array[indexx][indexy] = Tic::TTTS_X;
                    else
                        goto ahha;
                    Qipan::Print(array);
                    if (Tic::TTTS_X == Qiju::CheckWin(array))
                    {
                        cout << "游戏结束，X获胜" << endl;
                        break;
                    }
                    cout << "请输入坐标（行 列）：";
                }
            }
        }
        else
        {
            cout << "输错了，再输一次八：";
            goto a;
        }
    }
    else
    {
        cout << "输错了，再输一次八：";
        cin >> choice;
        goto LOOP;
    }
}
