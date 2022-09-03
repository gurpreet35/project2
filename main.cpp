#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;
int main()
{

    int i, j, choice, flag2 = 0, flag3 = 0, flag = 0, flag1 = 0;
    char count = '0', x[3][3], num;
    cout<<"                           *******************************************************\n";
    cout<<"                           ************************WELCOME************************\n";
    cout<<"                           *******************************************************\n";
    cout<<"                           Press enter key to continue>";
    getchar();

    system("cls");
    cout << "********TIC TAC TOE********\n";
    cout << "Enter your choice\n1. Want to play with smart computer\n";
    cout << "2. Want to play with evil computer\n3. Want to play with player\n4. Exit\n";
    cout<<"RULES:>>>>>>>>>\nif u can try to overwrite the \'x\' or \'o\'\n";
    cout<<"your turn will be dismissed!";
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            int r, a[10], p;
            char c, tic;
            p = 0;
            getchar();
            system("cls");
            //Displaying the format of matrix of tic toe
            for (i = 0; i <= 2; i++)
            {
                for (j = 0; j <= 2; j++)
                {
                    count++;
                    x[i][j] = count;
                    cout << x[i][j] << " | ";
                }
                printf("\n");
            }
            cout << "Player 1:O\n";
            cout << "Player 2:X (Smart Computer)\n";

            for (int k = 0; k < 9; k++)
            {
                if (k % 2 == 0)
                {
                    //player turn >>>>>>>>>>>>>>>>>
                    cout << "Player 1's turn:";
                    cin >> num;
                    for (i = 0; i <= 2; i++)
                    {
                        for (j = 0; j <= 2; j++)
                        {
                            if (x[i][j] == num)
                            {
                                x[i][j] = 'O';
                                cout << x[i][j] << " | ";
                            }
                            else
                                cout << x[i][j] << " | ";
                        }

                        cout << endl;
                    }
                }
                else
                {
                    cout << "Computer's Turn:\n";
                    int r, temp, flag2 = 0, flag3 = 0, i, j, min = 0;
                    srand(time(NULL));                                       //every sec our random sequence become change
                    for (int i = 0; i < 9; i++)
                    {
                        temp = rand() % 9 + min;                             //random function is used to get random different moves from pc
                        for (j = 0; j <= i - 1; j++)
                        {
                            if (temp == a[j])                                //checking for duplicacy in random numbers
                            {
                                break;
                            }
                        }
                        if (i == j)
                        {
                            a[i] = temp;
                        }
                        else
                            i--;
                    }
                                        //Condtion for effective moves of Computer
                                        //row wise
                    for (i = 0; i <= 2; i++)
                    {
                        if (x[i][0] == 'O' && x[i][1] == 'O' && x[i][2] != 'X')
                        {
                            c = x[i][2];
                            flag2 = 1;
                            break;
                        }
                        else if (x[i][0] == 'O' && x[i][2] == 'O' && x[i][1] != 'X' && x[i][1]!='O')
                        {
                            c = x[i][1];
                            flag2 = 1;
                            break;
                        }
                        else if (x[i][1] == 'O' && x[i][2] == 'O' && x[i][0] != 'X')
                        {
                            c = x[i][1];
                            flag2 = 1;
                            break;
                        }
                    }
                                             //column wise
                    for (j = 0; j <= 2; j++)
                    {
                        if (x[0][j] == 'O' && x[1][j] == 'O' && x[2][j] != 'X')
                        {
                            c = x[2][j];
                            flag2 = 1;

                            break;
                        }
                        else if (x[0][j] == 'O' && x[2][j] == 'O' && x[1][j] != 'X')
                        {
                            c = x[1][j];
                            flag2 = 1;
                            break;
                        }
                        else if (x[1][j] == 'O' && x[2][j] == 'O' && x[0][j] != 'X')
                        {
                            c = x[0][j];
                            flag2 = 1;
                            break;
                        }

                                                //Diagonal conditions  
                        if (x[0][0] == 'O' && x[1][1] == 'O' && x[2][2] != 'X')
                        {
                            c = x[2][2];
                            flag2 = 1;
                        }
                        if (x[2][2] == 'O' && x[1][1] == 'O' && x[0][0] != 'X')
                        {
                            c = x[0][0];
                            flag2 = 1;
                        }
                        if (x[0][0] == 'O' && x[2][2] == 'O' && x[1][1] != 'X')
                        {
                            c = x[1][1];
                            flag2 = 1;
                        }
                        if (x[0][2] == 'O' && x[1][1] == 'O' && x[2][0] != 'X')
                        {
                            c = x[2][0];
                            flag2 = 1;
                        }
                        if (x[1][1] == 'O' && x[2][0] == 'O' && x[0][2] != 'X')
                        {
                            c = x[0][2];
                            flag2 = 1;
                        }
                        if (x[0][2] == 'O' && x[2][0] == 'O' && x[1][1] != 'X')
                        {
                            c = x[1][1];
                            flag2 = 1;
                        }
                    }
                                               //conditions for computer winning
                    for (i = 0; i < 3; i++)
                    {

                        if ((x[i][0] == 'X' && x[i][1] == 'X' && x[i][2] != 'O'))
                        {
                            c = x[i][2];
                            flag2 = 1;
                            break;
                        }
                        else if ((x[i][0] == 'X' && x[i][2] == 'X' && x[i][1] != 'O'))
                        {
                            c = x[i][1];
                            flag2 = 1;
                            break;
                        }
                        else if ((x[i][1] == 'X' && x[i][2] == 'X' && x[i][0] != 'O'))
                        {
                            c = x[i][0];
                            flag2 = 1;
                            break;
                        }
                    }

                    for (j = 0; j < 3; j++)
                    {
                        if ((x[0][j] == 'X' && x[1][j] == 'X' && x[2][j] != 'O'))
                        {
                            c = x[2][j];
                            flag2 = 1;
                            break;
                        }
                        else if ((x[0][j] == 'X' && x[2][j] == 'X' && x[1][j] != 'O'))
                        {
                            c = x[1][j];
                            flag2 = 1;
                            break;
                        }
                        else if ((x[1][j] == 'X' && x[2][j] == 'X' && x[0][j] != 'O'))
                        {
                            c = x[0][j];
                            flag2 = 1;
                            break;
                        }
                    }
                    if (flag2 != 1)
                    {                      // priority to other conditions.then the rand() works

                        if (c == 'X' || c == 'O' || c==num || c==':')
                        {

                            k = k - 3;  
                            break;                      //recovering invalid moves
                        }
                        if ((c != 'X' || c != 'O') && c <= '9' && c >= '1')
                        {

                            c = '1' + a[p];
                        
                        }
                        else
                        {
                            p++;
                            c = '1' + a[p];
                        
                        }
                    }
                    cout << c;
                    cout << "\nPress Enter to continue>";
                    p++;
                    tic = 'X';
                }

                getchar();
                system("cls");
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 3; j++)
                    {
                        if (c == x[i][j])
                        {
                            x[i][j] = tic;
                            cout << x[i][j] << " | ";
                        }
                        else
                            cout << x[i][j] << " | ";
                    }
                    cout << endl;
                }
                flag = 0;
                flag1 = 0;
                for (i = 0; i < 3; i++)
                {
                    if (x[i][0] == 'X' && x[i][1] == 'X' && x[i][2] == 'X')
                    {
                        cout << "*************Computer is Winner ***********";
                        exit(0);
                        // break;
                    }
                    else if (x[i][0] == 'O' && x[i][1] == 'O' && x[i][2] == 'O')
                    {
                        cout << "*************Player is Winner**************";
                        exit(0);
                        // break;
                    }
                }
                for (j = 0; j < 3; j++)
                {
                    if (x[0][j] == 'X' && x[1][j] == 'X' && x[2][j] == 'X')
                    {
                        cout << "*************Computer is Winner ***********";
                        break;
                    
                    }
                    else if (x[0][j] == 'O' && x[1][j] == 'O' && x[2][j] == 'O')
                    {
                        cout << "*************Player is Winner**************";
                        break;
                        
                    }
                }
                if (x[0][0] == 'X' && x[1][1] == 'X' && x[2][2] == 'X')
                {
                    cout << "*************Computer is Winner ***********";
                    break;
                }
                else if (x[0][0] == 'O' && x[1][1] == 'O' && x[2][2] == 'O')
                {
                    cout << "*************Player is Winner**************";
                    break;
                }
                else if (x[0][2] == 'X' && x[1][1] == 'X' && x[2][0] == 'X')
                {
                    cout << "*************Computer is Winner ***********";
                    break;
                }
                else if (x[0][2] == 'O' && x[1][1] == 'O' && x[2][0] == 'O')
                {
                    cout << "*************Player is Winner**************";
                    break;
                }
                
            }
            cout << "*************GAME OVER**************";
            break;
        case 2:
            int b[10], q;
            char d, tic1;
            q = 0;
            getchar();
            system("cls");
                             //dispaling modules of tictoe
            for (i = 0; i <= 2; i++)
            {
                for (j = 0; j <= 2; j++)
                {
                    count++;
                    x[i][j] = count;
                    cout << x[i][j] << " | ";
                }
                printf("\n");
            }
            cout << "Player 1:O\n";
            cout << "Player 2:X (Evil Computer)\n";

            for (int k = 0; k < 9; k++)
            {
                if (k % 2 == 0)
                {                //player turn >>>>>>>2
                    cout << "Player 1's turn:";
                    cin >> num;
                    for (i = 0; i <= 2; i++)
                    {
                        for (j = 0; j <= 2; j++)
                        {
                            if (x[i][j] == num)
                            {
                                x[i][j] = 'O';
                                cout << x[i][j] << " | ";
                            }
                            else
                                cout << x[i][j] << " | ";
                        }

                        cout << endl;
                    }
                }
                else
                {
                    cout << "Computer's Turn:";
                    int temp, flag2 = 0, flag3 = 0, i, j, min = 0;
                    int tag1 = 0, tag2 = 0, tag3 = 0, tag4 = 0, tag5 = 0, temp1, temp2, temp3, temp4, temp5;
                    srand(time(NULL));
                    for (int i = 0; i < 9; i++)
                    {
                        temp = rand() % 9 + min;
                        for (j = 0; j <= i - 1; j++)
                        {
                            if (temp == b[j])
                            {
                                break;
                            }
                        }
                        if (i == j)
                        {
                            b[i] = temp;
                        }
                        else
                            i--;
                    }
                           if(d!='X'&&d!='O'){
                    for (i = 0; i <= 2; i++)
                    {
                        if (x[i][0] == 'O' && x[i][1] == 'O' && x[i][2] != 'X')
                        {
                            d = x[i][2];
                            temp1 = x[i][2];
                            flag2 = 1;
                            tag1 = 1;
                            break;
                        }
                        else if (x[i][0] == 'O' && x[i][2] == 'O' && x[i][1] != 'X')
                        {
                            d = x[i][1];
                            temp1 = x[i][1];
                            flag2 = 1;
                            tag1 = 1;
                            break;
                        }
                        else if (x[i][1] == 'O' && x[i][2] == 'O' && x[i][0] != 'X')
                        {
                            d = x[i][0];
                            temp1 = x[i][0];
                            flag2 = 1;
                            tag1 = 1;
                            break;
                        }
                    }
                    for (j = 0; j <= 2; j++)
                    {
                        if (x[0][j] == 'O' && x[1][j] == 'O' && x[2][j] != 'X')
                        {
                            d = x[2][j];
                            temp2 = x[2][j];
                            flag2 = 1;
                            tag2 = 1;
                            break;
                        }
                        else if (x[0][j] == 'O' && x[2][j] == 'O' && x[1][j] != 'X')
                        {
                            d = x[1][j];
                            temp2 = x[1][j];
                            flag2 = 1;
                            tag2 = 1;
                            break;
                        }
                        else if (x[1][j] == 'O' && x[2][j] == 'O' && x[0][j] != 'X')
                        {
                            d = x[0][j];
                            temp2 = x[0][j];
                            flag2 = 1;
                            tag2 = 1;
                            break;
                        }
                        if (x[0][0] == 'O' && x[1][1] == 'O' && x[2][2] != 'X')
                        {
                            d = x[2][2];
                            temp3 = x[2][2];
                            flag2 = 1;
                            tag3 = 1;
                        }
                        if (x[2][2] == 'O' && x[1][1] == 'O' && x[0][0] != 'X')
                        {
                            d = x[0][0];
                            temp3 = x[0][0];
                            flag2 = 1;
                            tag3 = 1;
                        }
                        if (x[0][0] == 'O' && x[2][2] == 'O' && x[1][1] != 'X')
                        {
                            d = x[1][1];
                            temp3 = x[1][1];
                            flag2 = 1;
                            tag3 = 1;
                        }
                        if (x[0][2] == 'O' && x[1][1] == 'O' && x[2][0] != 'X')
                        {
                            d = x[2][0];
                            temp4 = x[2][0];
                            flag2 = 1;
                            tag4 = 1;
                        }
                        if (x[1][1] == 'O' && x[2][0] == 'O' && x[0][2] != 'X')
                        {
                            d = x[0][2];
                            temp4 = x[0][2];
                            flag2 = 1;
                            tag4 = 1;
                        }
                        if (x[0][2] == 'O' && x[2][0] == 'O' && x[1][1] != 'X')
                        {
                            d = x[1][1];
                            temp4 = x[1][1];
                            flag2 = 1;
                            tag4 = 1;
                        }
                    }

                    for (i = 0; i < 3; i++)
                    {

                        if ((x[i][0] == 'X' && x[i][1] == 'X' && x[i][2] != 'O'))
                        {
                            d = x[i][2];
                            flag2 = 1;
                            tag4 = 1;
                            break;
                        }
                        else if ((x[i][0] == 'X' && x[i][2] == 'X' && x[i][1] != 'O'))
                        {
                            d = x[i][1];
                            flag2 = 1;
                            tag4 = 1;
                            break;
                        }
                        else if ((x[i][1] == 'X' && x[i][2] == 'X' && x[i][0] != 'O'))
                        {
                            d = x[i][0];
                            flag2 = 1;
                            tag4 = 1;
                            break;
                        }
                    }

                    for (j = 0; j < 3; j++)
                    {
                        if ((x[0][j] == 'X' && x[1][j] == 'X' && x[2][j] != 'O'))
                        {
                            d = x[2][j];
                            flag2 = 1;
                            tag5 = 1;
                            break;
                        }
                        else if ((x[0][j] == 'X' && x[2][j] == 'X' && x[1][j] != 'O'))
                        {
                            d = x[1][j];
                            flag2 = 1;
                            tag5 = 1;
                            break;
                        }
                        else if ((x[1][j] == 'X' && x[2][j] == 'X' && x[0][j] != 'O'))
                        {
                            d = x[0][j];
                            flag2 = 1;
                            tag5 = 1;
                            break;
                        }
                    }

                    if (flag2 != 1)
                    { // priority to other conditions.then the rand() works
                       if (d == 'X' || d == 'O' || d==num )
                        {
                            k = k - 3;
                            break;
                        }
                        if ((d != 'X' || d != 'O') && d <= '9' && d >= '1')
                        {

                            d = '1' + b[q];
                        
                        }
                        else
                        {
                            q++;
                            d = '1' + b[q];
                        
                        }
                    }
                           }
                    cout << d;
                    q++;
                    tic1 = 'X';
                    if (tag1 == 1 && tag2 == 1)
                    {
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 3; j++)
                            {
                                if (x[i][j] == temp1)
                                {
                                    x[i][j] = tic1;
                                }
                                if (x[i][j] == temp2)
                                {
                                    x[i][j] = tic1;
                                }
                            }
                        }
                    }
                    else if (tag1 == 1 && tag3 == 1)
                    {
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 3; j++)
                            {
                                if (x[i][j] == temp1)
                                {
                                    x[i][j] = tic1;
                                }
                                if (x[i][j] == temp3)
                                {
                                    x[i][j] = tic1;
                                }
                            }
                        }
                    }
                    else if (tag1 == 1 && tag4 == 1)
                    {
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 3; j++)
                            {
                                if (x[i][j] == temp1)
                                {
                                    x[i][j] = tic1;
                                }
                                if (x[i][j] == temp4)
                                {
                                    x[i][j] = tic1;
                                }
                            }
                        }
                    }
                    else if (tag2 == 1 && tag3 == 1)
                    {
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 3; j++)
                            {
                                if (x[i][j] == temp2)
                                {
                                    x[i][j] = tic1;
                                }
                                if (x[i][j] == temp3)
                                {
                                    x[i][j] = tic1;
                                }
                            }
                        }
                    }
                    else if (tag2 == 1 && tag4 == 1)
                    {
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 3; j++)
                            {
                                if (x[i][j] == temp2)
                                {
                                    x[i][j] = tic1;
                                }
                                if (x[i][j] == temp4)
                                {
                                    x[i][j] = tic1;
                                }
                            }
                        }
                    }
                    else if (tag3 == 1 && tag4 == 1)
                    {
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 3; j++)
                            {
                                if (x[i][j] == temp3)
                                {
                                    x[i][j] = tic1;
                                }
                                if (x[i][j] == temp4)
                                {
                                    x[i][j] = tic1;
                                }
                            }
                        }
                    }
                }

                getchar();
                system("cls");
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 3; j++)
                    {
                        if (d == x[i][j])
                        {
                            x[i][j] = tic1;
                            cout << x[i][j] << " | ";
                        }
                        else
                            cout << x[i][j] << " | ";
                    }
                    cout << endl;
                }
                flag = 0;
                flag1 = 0;
                for (i = 0; i < 3; i++)
                {
                    if (x[i][0] == 'X' && x[i][1] == 'X' && x[i][2] == 'X')
                    {
                        cout << "*************Computer is Winner ***********";
                        break;
                    }
                }
                for (j = 0; j < 3; j++)
                {
                    if (x[0][j] == 'X' && x[1][j] == 'X' && x[2][j] == 'X')
                    {
                        cout << "*************Computer is Winner ***********";
                        break;
                    }
                }
                if (x[0][0] == 'X' && x[1][1] == 'X' && x[2][2] == 'X')
                {
                    cout << "*************Computer is Winner ***********";
                    break;
                }
                if (x[0][2] == 'X' && x[1][1] == 'X' && x[2][0] == 'X')
                {
                    cout << "*************Computer is Winner ***********";
                    break;
                }
            }
            cout << "*************GAME OVER**************";
            break;
        case 3:
            getchar();
            system("cls");
            for (i = 0; i <= 2; i++)
            {
                for (j = 0; j <= 2; j++)
                {
                    count++;
                    x[i][j] = count;
                    cout << x[i][j] << " | ";
                }
                printf("\n");
            }
            cout << "Player 1:O\n";
            cout << "Player 2:X\n";
            for (int k = 0; k < 9; k++)
            {
                if (k % 2 == 0)
                {
                    cout << "Player 1's turn:";
                }
                else
                    cout << "Player 2's turn:";
                cin >> num;
                for (i = 0; i <= 2; i++)
                {
                    if (x[i][0] == 'O' && x[i][1] == 'O' && x[i][2] == 'O')
                    {
                        cout << "Player 1 is winner" << endl;
                        exit(0);
                    }
                    else if (x[0][i] == 'O' && x[1][i] == 'O' && x[2][i] == 'O')
                    {
                        cout << "Player 1 is winner" << endl;
                        exit(0);
                    }
                    else if (x[0][0] == 'O' && x[1][1] == 'O' && x[2][2] == 'O')
                    {
                        cout << "Player 1 is winner" << endl;
                        exit(0);
                    }
                    else if (x[2][0] == 'O' && x[1][1] == 'O' && x[0][2] == 'O')
                    {
                        cout << "Player 1 is winner" << endl;
                        exit(0);
                    }
                }
                for (i = 0; i <= 2; i++)
                {
                    if (x[i][0] == 'X' && x[i][1] == 'X' && x[i][2] == 'X')
                    {
                        cout << "Player 2 is winner" << endl;
                        exit(0);
                    }
                    else if (x[0][i] == 'X' && x[1][i] == 'X' && x[2][i] == 'X')
                    {
                        cout << "Player 2 is winner" << endl;
                        exit(0);
                    }
                    else if (x[0][0] == 'X' && x[1][1] == 'X' && x[2][2] == 'X')
                    {
                        cout << "Player 2 is winner" << endl;
                        exit(0);
                    }
                    else if (x[2][0] == 'X' && x[1][1] == 'X' && x[0][2] == 'X')
                    {
                        cout << "Player 2 is winner" << endl;
                        exit(0);
                    }
                }
                getchar();
                system("cls");
                for (i = 0; i <= 2; i++)
                {
                    for (j = 0; j <= 2; j++)
                    {
                        if (x[i][j] == num)
                        {
                            if (k % 2 == 0)
                            {
                                x[i][j] = 'O';
                            }
                            else
                            {
                                x[i][j] = 'X';
                            }
                            cout << x[i][j] << " | ";
                        }
                        else
                            cout << x[i][j] << " | ";
                    }

                    cout << endl;
                }
            }
             cout << "*************GAME OVER**************";
            break;
        case 4:
    
            exit(0);
        }
    } while (choice != 4);
    
    return 0;
}