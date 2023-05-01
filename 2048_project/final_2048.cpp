#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
static int score = 0;
static bool wining = false;
void welcome()
{
    cout << "----------------------welcome to 2048----------------------------" << endl;
    return;
}
int function_of_menu()
{
    int menu;
    cout << "----------------------1. start new game--------------------------";
    cout << "\n";
    cout << "----------------------2. continue last game----------------------";
    cout << "\n";
    cout << "----------------------3. about creator---------------------------";
    cout << "\n";
    cout << "----------------------4. score board-----------------------------";
    cout << "\n";
    cout << "----------------------5. theme-----------------------------------";
    cout << "\n";
    cout << "----------------------6. exit------------------------------------";
    cout << "\n";
    cout << "                      Enter option: ";
    cin >> menu;
    return menu;
}
int mode_game()
{
    int mode_of_game;
    cout << "----------------------Choose from the following options:----------------------" << endl;
    cout << "             ----------------------1. 4 x 4----------------------";
    cout << "\n";
    cout << "             ----------------------2. 5 x 5----------------------";
    cout << "\n";
    cout << "             ----------------------3. 6 x 6----------------------";
    cout << "\n";
    cout << "             ----------------------4. 8 x 8----------------------";
    cout << "\n";
    cout << "                                 Enter option: ";
    cin >> mode_of_game;
    return mode_of_game;
}
int choosing_mode(int x)
{
    switch (x)
    {
    case (1):
        x = 16;
        break;
    case (2):
        x = 25;
        break;
    case (3):
        x = 36;
        break;
    case (4):
        x = 64;
    default:
        break;
    }
    return x;
}
bool moving_to_top(int x[8][8], int row)
{
    bool flag = false;
    int d = 1;
    while (d <= 4)
    {

        for (int i = 0; i < row - 1; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if (x[i + 1][j] != 0)
                {
                    if (x[i][j] == 0)
                    {

                        x[i][j] = x[i + 1][j];
                        x[i + 1][j] = 0;
                        flag = true;
                    }
                }
            }
        }
        d++;
    }
    return flag;
}
bool moving_to_buttom(int x[8][8], int row)
{
    bool flag = false;
    int d = 1;
    while (d <= 4)
    {
        for (int i = row - 1; i > 0; i--)
        {
            for (int j = row - 1; j >= 0; j--)
            {
                if (x[i][j] == 0)
                {
                    if (x[i - 1][j] != 0)
                    {
                        x[i][j] = x[i - 1][j];
                        x[i - 1][j] = 0;
                        flag = true;
                    }
                }
            }
        }
        d++;
    }
    return flag;
}
bool moving_to_left(int x[8][8], int row)
{
    bool flag = false;
    int d = 1;
    while (d <= 4)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < row - 1; j++)
            {
                if (x[i][j] == 0)
                {
                    if (x[i][j + 1] != 0)
                    {

                        x[i][j] = x[i][j + 1];
                        x[i][j + 1] = 0;
                        flag = true;
                    }
                }
            }
        }
        d++;
    }
    return flag;
}
bool moving_to_right(int x[8][8], int row)
{
    bool flag = false;
    int d = 1;
    while (d <= 4)
    {
        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = row - 1; j >= 1; j--)
            {
                if (x[i][j] == 0)
                {
                    if (x[i][j - 1] != 0)
                    {

                        x[i][j] = x[i][j - 1];
                        x[i][j - 1] = 0;
                        flag = true;
                    }
                }
            }
        }
        d++;
    }
    return flag;
}
void value(int r, int &raw, int &column, int x[8][8])
{
    do
    {
        raw = rand() % r;
        column = rand() % r;
    } while (x[raw][column] != 0);
}
int order()
{
    int select_order;
    cout << "order:" << endl;
    cout << "1. top" << endl;
    cout << "2. bottom" << endl;
    cout << "3. left" << endl;
    cout << "4. right" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "5. clear" << endl;
    cout << "6. undo" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "7. save and exit" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "please Enter your order: ";
    cin >> select_order;
    return select_order;
}
bool top_func(int x[8][8], int row)
{
    bool flag = false, flag2 = false;
    flag = moving_to_top(x, row); //chasbidan be ham mesal(move to left):  4  0  4  2 ===> 4  4  2  0 step 1
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (x[i][j] == x[i + 1][j])
            {
                if (x[i][j] != 0)
                {
                    x[i][j] = 2 * x[i + 1][j]; //baraye sum mesal(move to left): 4  4  2  0 ===> 8  0  2  0 step 2
                    score += x[i][j];
                    x[i + 1][j] = 0;
                    flag = true;
                }
            }
        }
    }
    flag2 = moving_to_top(x, row); //baraye chasbidan be ham mesal:  8  0  2  0 ===> 8  2  0  0 step 3
    return flag;
}
bool buttom_func(int x[8][8], int row)
{
    bool flag = false, flag2 = false;
    flag = moving_to_buttom(x, row);
    for (int i = row - 1; i > 0; i--)
    {
        for (int j = row - 1; j >= 0; j--)
        {
            if (x[i][j] == x[i - 1][j])
            {
                if (x[i][j] != 0)
                {
                    x[i][j] = 2 * x[i - 1][j];
                    score += x[i][j];
                    x[i - 1][j] = 0;
                    flag = true;
                }
            }
        }
    }
    flag2 = moving_to_buttom(x, row);
    return flag;
}
bool left_func(int x[8][8], int row)
{
    bool flag = false, flag2 = false;
    flag = moving_to_left(x, row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row - 1; j++)
        {
            if (x[i][j] == x[i][j + 1])
            {
                if (x[i][j] != 0)
                {
                    x[i][j] = 2 * x[i][j + 1];
                    score += x[i][j];
                    x[i][j + 1] = 0;
                    flag = true;
                }
            }
        }
    }
    flag2 = moving_to_left(x, row);
    return flag;
}
bool right_func(int x[8][8], int row)
{
    bool flag = false, flag2 = false;
    flag = moving_to_right(x, row);
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = row - 1; j > 0; j--)
        {
            if (x[i][j] == x[i][j - 1])
            {
                if (x[i][j] != 0)
                {
                    x[i][j] = 2 * x[i][j - 1];
                    score += x[i][j];
                    x[i][j - 1] = 0;
                    flag = true;
                }
            }
        }
    }
    flag2 = moving_to_right(x, row);
    return flag;
}
bool is_free(int row, int x[8][8])
{
    bool flag = false;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (x[i][j] != 0)
            {
                flag = false;
            }
            else
            {
                flag = true;
                return flag;
            }
        }
    }
    return flag;
}
void win(int row, int x[8][8])
{
    int y;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if ((x[i][j] == 2048) && (wining = false))
            {
                cout << "congratulations,you won!!!!!" << endl;
                cout << "Continue? " << endl;
                cout << "1.yes" << endl;
                cout << "2.no" << endl;
                cin >> y;
                if (y == 2)
                {
                    cout << "thanks for playing ..." << endl;
                    system("pause");
                    exit(1);
                }
                else
                {
                    wining = true;
                }
            }
        }
    }
}
int about_creator()
{
    int back;
    cout << "----------------------Creator:Mohammad Hossein Rangraz----------------------" << endl;
    cout << "     ----------------------Telegram id:@cryofme----------------------" << endl;
    cout << "           ---------------------1. back----------------------" << endl;
    cout << "                             Enter number: ";
    cin >> back;
    return back;
}
struct str
{
    int score;
    int chand_dar_chand;
    int arr[8][8];
    int undo_numb1;
    int clear_numb1;
};
int main()
{
    system("Color E4");
    int small[8][8];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            small[i][j] = 0;
        }
    }
    int medium[8][8];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            medium[i][j] = 0;
        }
    }
    int large[8][8];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            large[i][j] = 0;
        }
    }
    int very_large[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            very_large[i][j] = 0;
        }
    }
    int temp[8][8];
    int temp2[8][8];
    int One_step_back = 1;
    int undo_numb = 1;
    str game;
    int menu;
    int r_4 = 0;
    int clear_numb = 1;
    FILE *scoring;
    FILE *last_game;
    scoring = fopen("score.txt", "a+");
    if (scoring == NULL)
    {
        cout << "Error!!!" << endl;
        system("pause");
        exit(1);
    }
    int best_score_4_4 = 0, best_score_5_5 = 0, best_score_6_6 = 0, best_score_8_8 = 0;
    fscanf(scoring, "%d", &best_score_4_4);
    fscanf(scoring, "%d", &best_score_5_5);
    fscanf(scoring, "%d", &best_score_6_6);
    fscanf(scoring, "%d", &best_score_8_8);
    fclose(scoring);
    welcome();
back_to_menu:
    menu = function_of_menu();
    system("cls");
    if (menu == 1)
    {
        int mode_of_game;
        mode_of_game = mode_game();
        while ((mode_of_game > 4) || (mode_of_game < 1))
        {
            cout << "-----------------------------------------" << endl;
            cout << "Error The selected value is unacceptable!" << endl;
            cout << "plz try again" << endl;
            mode_of_game = mode_game();
        }
        int choosed_mode;
        choosed_mode = choosing_mode(mode_of_game);
        system("cls");
        switch (choosed_mode)
        {
        case (16): //game 4 * 4
        {
            int column_4_4;
            int raw_4_4;
            value(4, raw_4_4, column_4_4, small);
            small[raw_4_4][column_4_4] = 2;
            value(4, raw_4_4, column_4_4, small);
            small[raw_4_4][column_4_4] = 2;
        continue_4_4:
            while (true)
            {
                cout << "YOUR SCORE: " << score << endl;
                cout << "-----------------------" << endl
                     << endl;
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        cout << small[i][j] << "    ";
                    }
                    cout << endl;
                    cout << endl;
                }
                int select_order;
                cout << "-----------------------" << endl;
            back_to_order_4_4:
                select_order = order();
                bool flag;
                bool flag3 = false;
                if (One_step_back % 2 == 0)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            temp[i][j] = small[i][j];
                        }
                    }
                    One_step_back++;
                }
                else
                {
                    for (int i = 0; i < 4; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            temp2[i][j] = small[i][j];
                        }
                    }
                    One_step_back++;
                }
                switch (select_order)
                {
                case (1):
                    flag = top_func(small, 4);
                    //  top;
                    break;
                case (2):
                    flag = buttom_func(small, 4);
                    //   bottom;
                    break;
                case (3):
                    flag = left_func(small, 4);
                    // left;
                    break;
                case (4):
                    flag = right_func(small, 4);
                    // right;
                    break;
                case (5):
                    if (clear_numb <= 3)
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            for (int j = 0; j < 4; j++)
                            {
                                if (small[i][j] == 2)
                                {
                                    small[i][j] = 0;
                                }
                            }
                        }
                        clear_numb++;
                    }
                    else
                    {
                        cout << "-----------------------" << endl;
                        cout << "you dont have enough point to clear your game" << endl;
                        cout << "-----------------------" << endl;
                        system("pause");
                    }

                    flag3 = true;
                    break;
                case (6):
                    if (undo_numb <= 2)
                    {
                        if (One_step_back % 2 == 0)
                        {
                            for (int i = 0; i < 4; i++)
                            {
                                for (int j = 0; j < 4; j++)
                                {
                                    small[i][j] = temp[i][j];
                                }
                            }
                            flag3 = true;
                        }
                        else
                        {
                            for (int i = 0; i < 4; i++)
                            {
                                for (int j = 0; j < 4; j++)
                                {
                                    small[i][j] = temp2[i][j];
                                }
                            }
                            flag3 = true;
                        }

                        undo_numb++;
                    }
                    else
                    {
                        cout << "-----------------------" << endl;
                        cout << "you dont have enough point to undo your game" << endl;
                        cout << "-----------------------" << endl;
                        system("pause");
                    }

                    break;
                case (7):
                    system("cls");
                    game.chand_dar_chand = 4;
                    game.score = score;
                    game.clear_numb1 = clear_numb;
                    game.undo_numb1 = undo_numb;
                    for (int i = 0; i < 4; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            game.arr[i][j] = small[i][j];
                        }
                    }
                    last_game = fopen("lgame.bin", "w+b");
                    if (last_game == NULL)
                    {
                        cout << "Error!!!" << endl;
                        system("pause");
                        exit(1);
                    }
                    fwrite(&game, sizeof(str), 1, last_game);
                    fclose(last_game);
                    if (best_score_4_4 < score)
                    {
                        scoring = fopen("score.txt", "w");
                        if (scoring == NULL)
                        {
                            cout << "Error!!!" << endl;
                            system("pause");
                            exit(1);
                        }
                        fprintf(scoring, "%d\n%d\n%d\n%d\n", score, best_score_5_5, best_score_6_6, best_score_8_8);
                        fclose(scoring);
                    }
                    cout << "thanks for playing..." << endl;
                    system("pause");
                    exit(1);
                    break;
                default:
                    cout << "incorrect value, please try again" << endl;
                    goto back_to_order_4_4;
                    break;
                }
                win(4, small);
                system("cls");
                bool flag2;
                flag2 = is_free(4, small);
                if (flag2 == false)
                {
                    if (flag == false)
                    {
                        if (best_score_4_4 < score)
                        {
                            scoring = fopen("score.txt", "w");
                            if (scoring == NULL)
                            {
                                cout << "Error!!!" << endl;
                                system("pause");
                                exit(1);
                            }
                            fprintf(scoring, "%d\n%d\n%d\n%d\n", score, best_score_5_5, best_score_6_6, best_score_8_8);
                            fclose(scoring);
                        }
                        cout << "Game Over" << endl;
                        cout << "your score :" << score << endl;
                        cout << "THANKS FOR PLAYING ..." << endl;
                        system("pause");
                        exit(1);
                    }
                }
                else if (flag2 == true)
                {
                    if (flag == true)
                    {
                        if (flag3 == false)
                        {
                            if (r_4 == 5)
                            {
                                value(4, raw_4_4, column_4_4, small);
                                small[raw_4_4][column_4_4] = 4;
                                r_4 = 0;
                            }
                            else
                            {
                                value(4, raw_4_4, column_4_4, small);
                                small[raw_4_4][column_4_4] = 2;
                                r_4++;
                            }
                        }
                    }
                    else
                    {
                        cout << "Change the path" << endl;
                        cout << "-----------------------" << endl;
                    }
                }
            }
            break;
        case (25): //game 5*5
        {
            int column_5_5;
            int raw_5_5;
            value(5, raw_5_5, column_5_5, medium);
            medium[raw_5_5][column_5_5] = 2;
            value(5, raw_5_5, column_5_5, medium);
            medium[raw_5_5][column_5_5] = 2;
        continue_5_5:
            while (true)
            {
                cout << "YOUR SCORE: " << score << endl;
                cout << "-----------------------" << endl
                     << endl;
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        cout << medium[i][j] << "    ";
                    }
                    cout << endl;
                    cout << endl;
                }
                int select_order;
                cout << "-----------------------" << endl;
            back_to_order_5_5:
                select_order = order();
                bool flag;
                bool flag3 = false;
                if (One_step_back % 2 == 0)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        for (int j = 0; j < 5; j++)
                        {
                            temp[i][j] = medium[i][j];
                        }
                    }
                    One_step_back++;
                }
                else
                {
                    for (int i = 0; i < 5; i++)
                    {
                        for (int j = 0; j < 5; j++)
                        {
                            temp2[i][j] = medium[i][j];
                        }
                    }
                    One_step_back++;
                }
                switch (select_order)
                {
                case (1):
                    flag = top_func(medium, 5);
                    //  top;
                    break;
                case (2):
                    flag = buttom_func(medium, 5);
                    //   bottom;
                    break;
                case (3):
                    flag = left_func(medium, 5);
                    // left;
                    break;
                case (4):
                    flag = right_func(medium, 5);
                    // right;
                    break;
                case (5):
                    if (clear_numb <= 3)
                    {
                        for (int i = 0; i < 5; i++)
                        {
                            for (int j = 0; j < 5; j++)
                            {
                                if (medium[i][j] == 2)
                                {
                                    medium[i][j] = 0;
                                }
                            }
                        }
                        clear_numb++;
                    }
                    else
                    {
                        cout << "-----------------------" << endl;
                        cout << "you dont have enough point to clear your game" << endl;
                        cout << "-----------------------" << endl;
                        system("pause");
                    }
                    flag3 = true;
                    break;
                case (6):
                    if (undo_numb <= 2)
                    {
                        if (One_step_back % 2 == 0)
                        {
                            for (int i = 0; i < 5; i++)
                            {
                                for (int j = 0; j < 5; j++)
                                {
                                    medium[i][j] = temp[i][j];
                                }
                            }
                            flag3 = true;
                        }
                        else
                        {
                            for (int i = 0; i < 5; i++)
                            {
                                for (int j = 0; j < 5; j++)
                                {
                                    medium[i][j] = temp2[i][j];
                                }
                            }
                            flag3 = true;
                        }

                        undo_numb++;
                    }
                    else
                    {
                        cout << "-----------------------" << endl;
                        cout << "you dont have enough point to undo your game" << endl;
                        cout << "-----------------------" << endl;
                        system("pause");
                    }

                    break;
                case (7):
                    system("cls");
                    game.chand_dar_chand = 5;
                    game.score = score;
                    game.clear_numb1 = clear_numb;
                    game.undo_numb1 = undo_numb;
                    for (int i = 0; i < 5; i++)
                    {
                        for (int j = 0; j < 5; j++)
                        {
                            game.arr[i][j] = medium[i][j];
                        }
                    }
                    last_game = fopen("lgame.bin", "w+b");
                    if (last_game == NULL)
                    {
                        cout << "Error!!!" << endl;
                        system("pause");
                        exit(1);
                    }
                    fwrite(&game, sizeof(str), 1, last_game);
                    fclose(last_game);
                    if (best_score_5_5 < score) //best score
                    {
                        scoring = fopen("score.txt", "w");
                        if (scoring == NULL)
                        {
                            cout << "\n\n\nError!!! File connot be opened" << endl;
                            system("pause");
                            exit(1);
                        }
                        fprintf(scoring, "%d\n%d\n%d\n%d\n", best_score_4_4, score, best_score_6_6, best_score_8_8);
                        fclose(scoring);
                    }
                    cout << "thanks for playing..." << endl;
                    system("pause");
                    exit(1);
                    break;
                default:
                    cout << "incorrect value, please try again" << endl;
                    goto back_to_order_5_5;
                    break;
                }
                win(5, medium);
                system("cls");
                bool flag2;
                flag2 = is_free(5, medium);
                if (flag2 == false)
                {
                    if (flag == false)
                    {
                        if (best_score_5_5 < score) //best score
                        {
                            scoring = fopen("score.txt", "w");
                            if (scoring == NULL)
                            {
                                cout << "\n\n\nError!!! File connot be opened" << endl;
                                system("pause");
                                exit(1);
                            }
                            fprintf(scoring, "%d\n%d\n%d\n%d\n", best_score_4_4, score, best_score_6_6, best_score_8_8);
                            fclose(scoring);
                        }
                        cout << "Game Over" << endl;
                        cout << "your score :" << score << endl;
                        cout << "THANKS FOR PLAYING ..." << endl;
                        system("pause");
                        exit(1);
                    }
                }
                else if (flag2 == true)
                {
                    if (flag == true)
                    {
                        if (flag3 == false)
                        {
                            if (r_4 == 5)
                            {
                                value(5, raw_5_5, column_5_5, medium);
                                medium[raw_5_5][column_5_5] = 4;
                                r_4 = 0;
                            }
                            else
                            {
                                value(5, raw_5_5, column_5_5, medium);
                                medium[raw_5_5][column_5_5] = 2;
                                r_4++;
                            }
                        }
                    }
                    else
                    {
                        cout << "Change the path" << endl;
                    }
                }
            }
        }
        break;
        case (36):
        {
            int column_6_6;
            int raw_6_6;
            value(6, raw_6_6, column_6_6, large);
            large[raw_6_6][column_6_6] = 2;
            value(6, raw_6_6, column_6_6, large);
            large[raw_6_6][column_6_6] = 2;
        continue_6_6:
            while (true)
            {
                cout << "YOUR SCORE: " << score << endl;
                cout << "-----------------------" << endl
                     << endl;
                for (int i = 0; i < 6; i++)
                {
                    for (int j = 0; j < 6; j++)
                    {
                        cout << large[i][j] << "    ";
                    }
                    cout << endl;
                    cout << endl;
                }
                int select_order;
                cout << "-----------------------" << endl;
            back_to_order_6_6:
                select_order = order();
                bool flag;
                bool flag3 = false;
                if (One_step_back % 2 == 0)
                {
                    for (int i = 0; i < 6; i++)
                    {
                        for (int j = 0; j < 6; j++)
                        {
                            temp[i][j] = large[i][j];
                        }
                    }
                    One_step_back++;
                }
                else
                {
                    for (int i = 0; i < 6; i++)
                    {
                        for (int j = 0; j < 6; j++)
                        {
                            temp2[i][j] = large[i][j];
                        }
                    }
                    One_step_back++;
                }
                switch (select_order)
                {
                case (1):
                    flag = top_func(large, 6);
                    //  top;
                    break;
                case (2):
                    flag = buttom_func(large, 6);
                    //   bottom;
                    break;
                case (3):
                    flag = left_func(large, 6);
                    // left;
                    break;
                case (4):
                    flag = right_func(large, 6);
                    // right;
                    break;
                case (5):
                    if (clear_numb <= 3)
                    {
                        for (int i = 0; i < 6; i++)
                        {
                            for (int j = 0; j < 6; j++)
                            {
                                if (large[i][j] == 2)
                                {
                                    large[i][j] = 0;
                                }
                            }
                        }
                        clear_numb++;
                    }
                    else
                    {
                        cout << "-----------------------" << endl;
                        cout << "you dont have enough point to clear your game" << endl;
                        cout << "-----------------------" << endl;
                        system("pause");
                    }
                    flag3 = true;
                    break;
                case (6):
                    if (undo_numb <= 2)
                    {
                        if (One_step_back % 2 == 0)
                        {
                            for (int i = 0; i < 6; i++)
                            {
                                for (int j = 0; j < 6; j++)
                                {
                                    large[i][j] = temp[i][j];
                                }
                            }
                            flag3 = true;
                        }
                        else
                        {
                            for (int i = 0; i < 6; i++)
                            {
                                for (int j = 0; j < 6; j++)
                                {
                                    large[i][j] = temp2[i][j];
                                }
                            }
                            flag3 = true;
                        }

                        undo_numb++;
                    }
                    else
                    {
                        cout << "-----------------------" << endl;
                        cout << "you dont have enough point to undo your game" << endl;
                        cout << "-----------------------" << endl;
                        system("pause");
                    }

                    break;
                case (7):
                    system("cls");
                    game.chand_dar_chand = 6;
                    game.score = score;
                    game.clear_numb1 = clear_numb;
                    game.undo_numb1 = undo_numb;
                    for (int i = 0; i < 6; i++)
                    {
                        for (int j = 0; j < 6; j++)
                        {
                            game.arr[i][j] = large[i][j];
                        }
                    }
                    last_game = fopen("lgame.bin", "w+b");
                    if (last_game == NULL)
                    {
                        cout << "Error!!!" << endl;
                        system("pause");
                        exit(1);
                    }
                    fwrite(&game, sizeof(str), 1, last_game);
                    fclose(last_game);
                    if (best_score_6_6 < score) //best score
                    {
                        scoring = fopen("score.txt", "w");
                        if (scoring == NULL)
                        {
                            cout << "\n\n\nError!!!" << endl;
                            system("pause");
                            exit(1);
                        }
                        fprintf(scoring, "%d\n%d\n%d\n%d\n", best_score_4_4, best_score_5_5, score, best_score_8_8);
                        fclose(scoring);
                    }
                    cout << "thanks for playing..." << endl;
                    system("pause");
                    exit(1);
                    break;
                default:
                    cout << "incorrect value, please try again" << endl;
                    goto back_to_order_6_6;
                    break;
                }
                win(6, large);
                system("cls");
                bool flag2;
                flag2 = is_free(6, large);
                if (flag2 == false)
                {
                    if (flag == false)
                    {
                        if (best_score_6_6 < score) //best score
                        {
                            scoring = fopen("score.txt", "w");
                            if (scoring == NULL)
                            {
                                cout << "\n\n\nError!!!" << endl;
                                system("pause");
                                exit(1);
                            }
                            fprintf(scoring, "%d\n%d\n%d\n%d\n", best_score_4_4, best_score_5_5, score, best_score_8_8);
                            fclose(scoring);
                        }
                        cout << "Game Over" << endl;
                        cout << "your score :" << score << endl;
                        cout << "THANKS FOR PLAYING ..." << endl;
                        system("pause");
                        exit(1);
                    }
                }
                else if (flag2 == true)
                {
                    if (flag == true)
                    {
                        if (flag3 == false)
                        {
                            if (r_4 == 5)
                            {
                                value(6, raw_6_6, column_6_6, large);
                                large[raw_6_6][column_6_6] = 4;
                                r_4 = 0;
                            }
                            else
                            {
                                value(6, raw_6_6, column_6_6, large);
                                large[raw_6_6][column_6_6] = 2;
                                r_4++;
                            }
                        }
                    }
                    else
                    {
                        cout << "Change the path" << endl;
                    }
                }
            }
        }
        break;
        case (64):
        {
            int column_8_8;
            int raw_8_8;
            value(8, raw_8_8, column_8_8, very_large);
            very_large[raw_8_8][column_8_8] = 2;
            value(8, raw_8_8, column_8_8, very_large);
            very_large[raw_8_8][column_8_8] = 2;
        continue_8_8:
            while (true)
            {
                cout << "YOUR SCORE: " << score << endl;
                cout << "-----------------------" << endl
                     << endl;
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        cout << very_large[i][j] << "    ";
                    }
                    cout << endl;
                    cout << endl;
                }
                int select_order;
                cout << "-----------------------" << endl;
            back_to_order_8_8:
                select_order = order();
                bool flag;
                bool flag3 = false;
                if (One_step_back % 2 == 0)
                {
                    for (int i = 0; i < 8; i++)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            temp[i][j] = very_large[i][j];
                        }
                    }
                    One_step_back++;
                }
                else
                {
                    for (int i = 0; i < 8; i++)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            temp2[i][j] = very_large[i][j];
                        }
                    }
                    One_step_back++;
                }
                switch (select_order)
                {
                case (1):
                    flag = top_func(very_large, 8);
                    //  top;
                    break;
                case (2):
                    flag = buttom_func(very_large, 8);
                    //   bottom;
                    break;
                case (3):
                    flag = left_func(very_large, 8);
                    // left;
                    break;
                case (4):
                    flag = right_func(very_large, 8);
                    // right;
                    break;
                case (5):
                    if (clear_numb <= 3)
                    {
                        for (int i = 0; i < 8; i++)
                        {
                            for (int j = 0; j < 8; j++)
                            {
                                if (very_large[i][j] == 2)
                                {
                                    very_large[i][j] = 0;
                                }
                            }
                        }
                        clear_numb++;
                    }
                    else
                    {
                        cout << "-----------------------" << endl;
                        cout << "you dont have enough point to clear your game" << endl;
                        cout << "-----------------------" << endl;
                        system("pause");
                    }
                    flag3 = true;
                    break;
                case (6):
                    if (undo_numb <= 2)
                    {
                        if (One_step_back % 2 == 0)
                        {
                            for (int i = 0; i < 8; i++)
                            {
                                for (int j = 0; j < 8; j++)
                                {
                                    very_large[i][j] = temp[i][j];
                                }
                            }
                            flag3 = true;
                        }
                        else
                        {
                            for (int i = 0; i < 8; i++)
                            {
                                for (int j = 0; j < 8; j++)
                                {
                                    very_large[i][j] = temp2[i][j];
                                }
                            }
                            flag3 = true;
                        }

                        undo_numb++;
                    }
                    else
                    {
                        cout << "-----------------------" << endl;
                        cout << "you dont have enough point to undo your game" << endl;
                        cout << "-----------------------" << endl;
                        system("pause");
                    }

                    break;
                case (7):
                    system("cls");
                    game.chand_dar_chand = 8;
                    game.score = score;
                    game.clear_numb1 = clear_numb;
                    game.undo_numb1 = undo_numb;
                    for (int i = 0; i < 8; i++)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            game.arr[i][j] = very_large[i][j];
                        }
                    }
                    last_game = fopen("lgame.bin", "w+b");
                    if (last_game == NULL)
                    {
                        cout << "Error!!!" << endl;
                        system("pause");
                        exit(1);
                    }
                    fwrite(&game, sizeof(str), 1, last_game);
                    fclose(last_game);
                    if (best_score_8_8 < score) //best score
                    {
                        scoring = fopen("score.txt", "w");
                        if (scoring == NULL)
                        {
                            cout << "\n\n\nError!!! File connot be opened" << endl;
                            system("pause");
                            exit(1);
                        }
                        fprintf(scoring, "%d\n%d\n%d\n%d\n", best_score_4_4, best_score_5_5, best_score_6_6, score);
                        fclose(scoring);
                    }
                    cout << "thanks for playing..." << endl;
                    system("pause");
                    exit(1);
                    break;
                default:
                    cout << "incorrect value, please try again" << endl;
                    goto back_to_order_8_8;
                    break;
                }
                win(8, very_large);
                system("cls");
                bool flag2;
                flag2 = is_free(8, very_large);
                if (flag2 == false)
                {
                    if (flag == false)
                    {
                        if (best_score_8_8 < score) //best score
                        {
                            scoring = fopen("score.txt", "w");
                            if (scoring == NULL)
                            {
                                cout << "\n\n\nError!!! File connot be opened" << endl;
                                system("pause");
                                exit(1);
                            }
                            fprintf(scoring, "%d\n%d\n%d\n%d\n", best_score_4_4, best_score_5_5, best_score_6_6, score);
                            fclose(scoring);
                        }
                        cout << "Game Over" << endl;
                        cout << "your score :" << score << endl;
                        cout << "THANKS FOR PLAYING ..." << endl;
                        system("pause");
                        exit(1);
                    }
                }
                else if (flag2 == true)
                {
                    if (flag == true)
                    {
                        if (flag3 == false)
                        {
                            if (r_4 == 5)
                            {
                                value(8, raw_8_8, column_8_8, very_large);
                                very_large[raw_8_8][column_8_8] = 4;
                                r_4 = 0;
                            }
                            else
                            {
                                value(8, raw_8_8, column_8_8, very_large);
                                very_large[raw_8_8][column_8_8] = 2;
                                r_4++;
                            }
                        }
                    }
                    else
                    {
                        cout << "Change the path" << endl;
                    }
                }
            }
        }
        break;
        default:
            break;
        }
        }
    }
    else if (menu == 2) // continue last game
    {
        last_game = fopen("lgame.bin", "a+b");
        fread(&game, sizeof(str), 1, last_game);
        fclose(last_game);
        switch (game.chand_dar_chand)
        {
        case (4):
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    small[i][j] = game.arr[i][j];
                }
            }
            clear_numb = game.clear_numb1;
            undo_numb = game.undo_numb1;
            score = game.score;
            goto continue_4_4;
            break;
        case (5):
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    medium[i][j] = game.arr[i][j];
                }
            }
            clear_numb = game.clear_numb1;
            undo_numb = game.undo_numb1;
            score = game.score;
            goto continue_5_5;
            break;
        case (6):
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    medium[i][j] = game.arr[i][j];
                }
            }
            clear_numb = game.clear_numb1;
            undo_numb = game.undo_numb1;
            score = game.score;
            goto continue_6_6;
            break;
        case (8):
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    medium[i][j] = game.arr[i][j];
                }
            }
            clear_numb = game.clear_numb1;
            undo_numb = game.undo_numb1;
            score = game.score;
            goto continue_8_8;
            break;
        default:
            break;
        }
    }
    else if (menu == 3) // about creator
    {
        int back = 0;
        while (back != 1)
        {
            back = about_creator();
            system("cls");
        }
        goto back_to_menu;
    }
    else if (menu == 4) //score board
    {
        int back = 0;
        while (back != 1)
        {
            cout << "----------------------" << endl;
            cout << "best score:" << endl;
            cout << "4 x 4: " << best_score_4_4 << endl;
            cout << "5 x 5: " << best_score_5_5 << endl;
            cout << "6 x 6: " << best_score_6_6 << endl;
            cout << "8 x 8: " << best_score_8_8 << endl;
            cout << "----------------------" << endl;
            cout << "1.back" << endl;
            cin >> back;
            system("cls");
            if (back == 1)
            {
                goto back_to_menu;
            }
        }
    }
    else if (menu == 5)
    {
        while (true)
        {
            int theme;
            cout << "1.green theme" << endl;
            cout << "2.yellow and red theme" << endl;
            cout << "3.dark purple theme" << endl;
            cout << "4.default" << endl;
            cout << "5.back" << endl;
            cout << "choose:" << endl;
            cin >> theme;
            if (theme == 1)
            {
                system("Color 0A");
            }
            else if (theme == 2)
            {
                system("Color DE");
            }
            else if (theme == 3)
            {
                system("Color 5");
            }
            else if (theme == 4)
            {

                system("Color  E4");
            }
            else if (theme == 5)
            {
                system("cls");
                goto back_to_menu;
            }
            system("cls");
        }
    }
    else if (menu == 6) //exit
    {
        cout << "-----------------------THANKS FOR PLAYING...-----------------------"
             << "\n\n";
        system("pause");
        exit(1);
    }
    else
    {
        goto back_to_menu;
    }
    return 0;
}