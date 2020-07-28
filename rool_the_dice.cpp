#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <ctype.h>
using namespace std;

void draw_line(int n, char ch);
void rules();
int doBet(string player, int balance)
{
    int bet = 0;
    std::cout << "\n\n" << player << " enter money to bet :"<< " ";
    std::cin.clear();
    std::cin.ignore(256,'\n');
    std::cin >> bet;
    //debug
    cout <<"\n bet "<<bet;
    cout <<"\n balance " <<balance;
    return bet;
}
int main(void)
{
    int balance, bet, lucky_number, dice;
    char player[80], ch;
    system("CLS");
    draw_line(60, '=');
    std::cout << "\n\n\n\n\t\t  DICE GAME  \n\n\n\n";
    draw_line(60, '=');
    do
    {
        std::cout << "\n\n\n Enter Your Name: "<< " ";
        std::cin >> player;
    } while (std::cin.fail());


    balance = 0;
    std::cin.clear();
    string balance_str;
    std::cout << "\n\n\n Enter your deposit amount : "<< " ";
    std::cin >> balance;
     while(balance < 1) 
     {
        system("CLS");
        rules();
        balance = 0;
        
        std::cout << " \n\n\n Error.\n\n\n You must enter a number to represent the deposit amount. \n\n";
        std::cout << "\n\n\n Enter your deposit amount again. Please remember to input  numbers only! : "<< " ";
        std::system("PAUSE");
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> balance;
        
    }
       

    do
    {
        
       std::cout << "\n\nYour current balance is  $ "<< "  " << balance; // debug
        bet = 0;
        bet = doBet(player , balance);
        while (bet > balance || bet <= 0)
        {
            system("CLS");
            rules();
             std::cout << "\n\nYour current balance is  $ "<< "  " << balance;
           // 
            bet = 0;
            bet = doBet(player , balance);
            
            if (bet > balance || bet <0)
            {
                std::cout << "\nYour betting amount is more than your current balance\n\nRe-enter data\n ";
                std::system("PAUSE");
               
            }else
            {
                
                break;
            }
        }
        lucky_number = 0;
        std::cout << "\n lucky_number:" << lucky_number; 

        do
        {
            
            std::cout << "\n lucky_number:" << lucky_number; 
            std::cout << "\n Enter your lucky number to bet between 1 to 12 : "
                      << " ";
            std::cin.clear();
            std::cin.ignore(256,'\n');          
            
            std::cout << "\n your lucky number is:" << lucky_number; 
            // system("PAUSE");
            if (lucky_number <=0 || lucky_number > 12)
                std::cout << "\n Please check the number!! should be between 1 to 12\n\nRe-enter data\n "
                          << "  ";
            else if(lucky_number > 0 && lucky_number < 13)
            {
                std::cout << "\n Good luck !!!\n ";
                system("PAUSE");
                break;
            }
        }while (lucky_number <= 0 || lucky_number > 12); 
        
        dice = rand() % 12 + 1;
        if (dice == lucky_number)
        {
            std::cout << "\n\nGood Luck indeed!! You won   $ \t ."   << "   " << bet * 10;
            balance = balance + bet * 10;
        }
        else
        {
            std::cout << "\n Bad Luck this time !! You lose  $ "  << "   "
                      << "  " << bet;
            balance = balance - bet;
        }
        std::cout << "\n\n  The winning number was : "
                  << "  " << dice;

        std::cout << "\n\n"
                  << "  " << player << " You have  $  "    << "   " << balance << endl;
        std::cout << "\n\n-->Do you want to play (y/n)? ";
        std::cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    system("CLS");
    std::cout << "\n\n\n";
    draw_line(70, '+');
    std::cout << "\n\n\t  YOUR BALANCE AMOUNT IS $ "  << "  " << balance << "\n\n Go have a beer \n\n";
    draw_line(70, '+');
    std::cout << "\n\n Game programmed by Bruno Maia Serralheiro \n" << "\
     Thank you for playing.\n Enjoy your life! \nPress any key to exit... \n\n\n ";
    draw_line(70, '+');
    getch();
    return 0;
}

void draw_line(int n, char ch)
{
    for (int i = 0; i < n; i++)
        std::cout << ch;
}

void rules()
{
    system("CLS");
    std::cout << "\n\n";
    draw_line(60, '-');
    std::cout << "\n\t\tRULES OF THE GAME\n";
    draw_line(60, '-');
    std::cout << "\n\t1. Choose any number between 1 to 12\n\t2. If you win you will get 10 times of money you bet\n\t3. If you bet on wrong number you will lose your betting amount\n\n";
    draw_line(60, '-');
    std::cout << endl;
}
