#include <iostream>
#include <ncurses.h>
#include <queue>
#include <random>
#include <string>
#include <thread>
#include <unistd.h>
#include <vector>

//!!!!!!!PROBLEMS SWIPE LEFT/RIGHT TO TRUES!!!!!!!!!!!!!!!!!!

enum class Color
{
    kWhite,
    kGreen,
    kBlue,
    kRed,
};

struct State
{
    bool is_element;
    Color color;
};

const uint32_t kBoardWidth = 10;
const uint32_t kBoardHeight = 24;

class Tetris
{
public:
    using Figure = std::vector<std::vector<bool>>;

    Tetris()
    {
        board.resize(kBoardHeight, {kBoardWidth, {false, Color::kWhite}});
        InitFigures();
        std::mt19937 mersenne(rd());
        //Иннициализация терминала:
        initscr(); // init screen
        savetty(); //сохраням текущие настройки, затем их можно востановить с помощью resetty()
        nonl(); // no new line, при нажатии на ентер не переходит на новую строку
        cbreak(); // по умалчанию консоль буферезирует построчно (строка + ентер), с этой
                  //функцией
                  //все будет выполняться посимвольно
        noecho(); // когда что-то печатем, то в консоле это не отображается
        timeout(0); // при 0 функции ввода символов работает асинхронно(не блокирующие чтение);
                    //при
                    //<0 (блокирующие считывание), пока пользователь не нажмет какую-то клавишу,
                    //функция считывающая символ не заканчивается; >0 сколько нужно ждать, если
                    //ничего небыло нажато, то работает как при нуле
        leaveok(stdscr, true); // управляет позицией каретки
        curs_set(0);
    }
    ~Tetris()
    {
        //деиннициализация(восстанавливаем обратно значения терминала):
        curs_set(1); // восстанавливаем коретку
        clear();     //отчистка
        refresh(); //обнавляем отчистку, которая была подгружена в память
        resetty(); //восстанавливаем найстроки, которые были сохранины функцией savetty()
        endwin();  // освобаждаем выделенную память
        exit(0);   //выход(из stdlib)
    }

    bool SearchFullLines(std::vector<uint32_t> &result)
    {
        result.clear();
        for (uint32_t i = 4; i < board.size(); i++)
        {
            bool t = true;
            for (uint32_t j = 0; j < board[0].size(); j++)
            {
                if (board[i][j].is_element == 0)
                {
                    t = false;
                    break;
                }
            }
            if (t)
            {
                result.push_back(i);
            }
        }
        return result.size() > 0 ? true : false;
    }

    bool CheckActiveOnBoard(uint32_t x, uint32_t y)
    {
        for (auto t : active_element)
        {
            if (t.second == x && t.first == y)
            {
                return true;
            }
        }
        return false;
    }

    void StartGame()
    {
        while (!GameOverConditional())
        {
            active_element.clear();
            SetFigureOnBoard();
            clear();
            Print();
            while (!MoveStopConditional())
            {
                Control();
                sleep(1);
                MoveActive();
                clear();
                Print();
            }
            sleep(1);
            std::vector<uint32_t> FullLines;
            while (SearchFullLines(FullLines))
            {
                for (uint32_t i = 0; i < FullLines.size(); i++)
                {
                    for (uint32_t j = 0; j < kBoardWidth; j++)
                    {
                        board[FullLines[i]][j] = {false, Color::kWhite};
                    }
                }
                sleep(1);
                for (uint32_t i = 0; i < FullLines.size(); i++)
                {
                    for (uint32_t j = FullLines[i]; j > 3; j--)
                    {
                        for (uint32_t d = 0; d < kBoardWidth; d++)
                        {
                            if (!CheckActiveOnBoard(d, j))
                            {
                                board[j][d] = board[j - 1][d];
                            }
                        }
                    }
                }
            }
        }
    }

    //////////////////////////
    ////Aditional function////
    //////////////////////////
    bool LeftMoveConditional()
    {
        for (uint32_t i = 0; i < active_element.size(); ++i)
        {
            int a = active_element[i].first - 1; ///////////////////
            if (0 > a)
            {
                return false;
            }
        }
        return true;
    }

    bool RightMoveConditional()
    {
        for (auto i : active_element)
        {
            if (i.first + 1 > kBoardWidth - 1)
            {
                return false;
            }
        }
        return true;
    }

    void Control()
    {
        int keypress = wgetch(stdscr);
        State temp;
        switch (keypress)
        {
        case 'a':
            if (LeftMoveConditional())
            {
                temp = board[active_element[0].second][active_element[0].first];
                for (auto &t : active_element)
                {
                    board[t.second][t.first] = {false, Color::kWhite};
                    --t.first;
                }
                for (auto &t : active_element)
                {
                    board[t.second][t.first] = temp;
                }
            }
            break;
        case 'd':
            if (RightMoveConditional())
            {
                temp = board[active_element[0].second][active_element[0].first];
                for (auto &t : active_element)
                {
                    board[t.second][t.first] = {false, Color::kWhite};
                    ++t.first;
                }
                for (auto &t : active_element)
                {
                    board[t.second][t.first] = temp;
                }
            }
            break;
        default:
            return;
            break;
        }
    }

    void Print() /////////////////////////////////////////////////
    {
        for (uint32_t i = 4; i < kBoardHeight; i++)
        {
            for (uint32_t j = 0; j < kBoardWidth; j++)
            {
                move(i - 4, j);
                std::string a = std::to_string(board[i][j].is_element);

                addch(a[0]);
            }
        }
        refresh();
    }

    void FullPrint() ///////////////////////////////////////////////
    {
        for (uint32_t i = 0; i < kBoardHeight; i++)
        {
            for (uint32_t j = 0; j < kBoardWidth; j++)
            {
                std::cout << board[i][j].is_element;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl
                  << board.size() << std::endl
                  << board[0].size() << std::endl
                  << std::endl;

        for (uint32_t i = 0; i < kBoardHeight; i++)
        {
            for (uint32_t j = 0; j < kBoardWidth; j++)
            {
                std::cout << static_cast<uint32_t>(board[i][j].color);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl << board.size() << std::endl << board[0].size() << std::endl;
    }

private:
    std::vector<std::vector<State>> board;
    std::vector<Figure> figures;
    std::random_device rd;
    std::vector<std::pair<uint32_t, uint32_t>> active_element;

    bool CheckInActive(uint32_t x, uint32_t y)
    {
        for(auto t : active_element)
        {
            if(t.first == x && t.second == y)
            {
                return true;
            }
        }
        return false;
    }

    bool MoveStopConditional()
    {
        for (auto temp : active_element)
        {
            if (temp.second + 1 > kBoardHeight - 1 ||
                (board[temp.second + 1][temp.first].is_element == 1 && !CheckInActive(temp.first, temp.second + 1)))
            {
                return true;
            }
        }
        return false;
    }

    bool GameOverConditional()
    {
        for (auto i : board[4])
        {
            if (i.is_element == 1)
                return 1;
        }
        return 0;
    }

    void MoveActive()
    {
        State temp = board[active_element[0].second][active_element[0].first];
        for (uint32_t i = 0; i < active_element.size(); ++i)
        {
            board[active_element[i].second][active_element[i].first] = {false, Color::kWhite};
        }
        for (uint32_t i = 0; i < active_element.size(); ++i)
        {
            board[active_element[i].second + 1][active_element[i].first] = temp;
            ++active_element[i].second;
        }
    }

    bool SetFigureOnBoard()
    {
        std::queue<Figure> qu;
        Color color = static_cast<Color>((rd() % 3) + 1);

        if (qu.empty())
        {
            qu.push(GetRendomFigure());
            qu.push(GetRendomFigure());
        }
        else
        {
            qu.push(GetRendomFigure());
        }

        uint32_t spacing_left = qu.front() == figures[0] ? 3 : 4;
        uint32_t spacing_top = qu.front() == figures[0] ? 3 : 2;
        for (uint32_t i = spacing_top; i < spacing_top + 2; ++i)
        {
            for (uint32_t j = spacing_left; j < spacing_left + 4; ++j)
            {
                board[i][j].is_element = qu.front()[i - spacing_top][j - spacing_left];
                if (board[i][j].is_element == true)
                {
                    board[i][j].color = color;
                    active_element.push_back(std::make_pair(j, i));
                }
            }
        }
        qu.pop();

        return true;
    }

    Figure GetRendomFigure()
    {
        return figures[rd() % 7];
    }

    void InitFigures()
    {
        Figure temp;
        std::vector<bool> temp2(4, false);
        temp.resize(2, temp2);

        temp[0][0] = true;
        temp[0][1] = true;
        temp[0][2] = true;
        temp[0][3] = true;
        temp[1][0] = false;
        temp[1][1] = false;
        temp[1][2] = false;
        temp[1][3] = false;
        figures.push_back(temp);

        temp[0][0] = true;
        temp[0][1] = false;
        temp[0][2] = false;
        temp[0][3] = false;
        temp[1][0] = true;
        temp[1][1] = true;
        temp[1][2] = true;
        temp[1][3] = false;
        figures.push_back(temp);

        temp[0][0] = false;
        temp[0][1] = false;
        temp[0][2] = true;
        temp[0][3] = false;
        temp[1][0] = true;
        temp[1][1] = true;
        temp[1][2] = true;
        temp[1][3] = false;
        figures.push_back(temp);

        temp[0][0] = true;
        temp[0][1] = true;
        temp[0][2] = false;
        temp[0][3] = false;
        temp[1][0] = true;
        temp[1][1] = true;
        temp[1][2] = false;
        temp[1][3] = false;
        figures.push_back(temp);

        temp[0][0] = false;
        temp[0][1] = true;
        temp[0][2] = true;
        temp[0][3] = false;
        temp[1][0] = true;
        temp[1][1] = true;
        temp[1][2] = false;
        temp[1][3] = false;
        figures.push_back(temp);

        temp[0][0] = false;
        temp[0][1] = true;
        temp[0][2] = false;
        temp[0][3] = false;
        temp[1][0] = true;
        temp[1][1] = true;
        temp[1][2] = true;
        temp[1][3] = false;
        figures.push_back(temp);

        temp[0][0] = true;
        temp[0][1] = true;
        temp[0][2] = false;
        temp[0][3] = false;
        temp[1][0] = false;
        temp[1][1] = true;
        temp[1][2] = true;
        temp[1][3] = false;
        figures.push_back(temp);
    }
};

int main()
{
    Tetris a;
    a.StartGame();

    return 0;
}
