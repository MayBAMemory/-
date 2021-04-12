#include <iostream>
#include <stdlib.h>
using namespace std;
class Tic
{
public:
    enum TTTS
    {
        TTTS_Default = 0,
        TTTS_O = 1,
        TTTS_X = 2
    };
};

class Qipan
{
public:
    static void Print(Tic::TTTS array[][3])
    {
        for (int i = 0; i < 3; i++)
        {
            cout << " -----   -----   -----" << endl;
            for (int j = 0; j < 3; j++)
            {
                if (array[i][j] == Tic::Tic::TTTS_Default)
                    cout << "|     | ";
                else if (array[i][j] == Tic::Tic::TTTS_O)
                    cout << "|  O  | ";
                else
                    cout << "|  X  | ";
            }
            cout << endl;
            cout << " -----   -----   -----" << endl;
        }
    }
};

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
    if (choice == "2")
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
    else if (choice == "1")
    {
        cout << "请选择难度：" << endl
             << "1.简单模式" << endl
             << "2.没那么简单模式" << endl;
    a:
        cin >> choice;
        if (choice == "1")
        {
            cout << "请输入坐标（行 列,玩家为O）：";
        
            HAHA:while (cin >> indexx >> indexy)
            {
                
                index_x = indexx - 1;
                index_y = indexy - 1;

                if (!((index_x >= 0 && index_x < 3) && (index_y >= 0 && index_y < 3)) || (array[index_x][index_y] != Tic::TTTS_Default))
                {
                    cout << "下错了，再输入一次吧" << endl
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
        else if (choice == "2")
        {

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
