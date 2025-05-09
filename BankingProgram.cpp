#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>

#define ANIMATION_SLEEP_TIME 250

void animationSleepingTimeAndCleaning(){
    Sleep(ANIMATION_SLEEP_TIME);
    system("cls");
}

void loadingAnimation(){
    system("cls");
    for(int i = 0; i < rand() % 4; i++){
        std::cout << "\nLOADING |";
        animationSleepingTimeAndCleaning();
        std::cout << "\nLOADING /";
        animationSleepingTimeAndCleaning();
        std::cout << "\nLOADING -";
        animationSleepingTimeAndCleaning();
        std::cout << "\nLOADING \\";
        animationSleepingTimeAndCleaning();
    }
}

void showBalance(double balance){
    std::cout << "Your balance is $" << balance;
}

void inputValidationDeposit(double &amountBuffer){ //amount buffer should not accept negative numbers and numbers that exceed $30.000
    while(amountBuffer <= 0 || amountBuffer > 30000){
        std::cout << "\nWARNING! Amount can't be a negative number or exceed $30.000\n";
        std::cout << "Enter again: ";
        std::cin >> amountBuffer;
    }
}

void inputValidationWithdraw(double &amountBuffer, double balance){ //amount buffer should not accept negative numbers and numbers that exceed $30.000
    while(amountBuffer <= 0 || amountBuffer > balance){
        std::cout << "\nWARNING! Amount can't be a negative number exceed your balance\n";
        showBalance(balance);
        std::cout << "\nEnter again: ";
        std::cin >> amountBuffer;
    }
}

int main(){

    srand(time(0));

    char choiceBuffer;
    double balance = 100;
    double amountBuffer;
    while(true){

        loadingAnimation();
        
        std::cout << "******************\n";
        std::cout << "Enter your choice:\n";
        std::cout << "******************\n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";

        choiceBuffer = _getch();

        loadingAnimation();

        std::cout << "\n";

        switch(choiceBuffer){
        case '1':
            showBalance(balance);
            std::cout << "\n\npress any key to go back...";
            _getch();
            break;
        case '2':
            std::cout << "Enter amount to deposit: ";
            std::cin >> amountBuffer;
            inputValidationDeposit(amountBuffer);
            balance = balance + amountBuffer;
            showBalance(balance);
            std::cout << "\n\npress any key to go back...";
            _getch();
            break;
        case '3':
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amountBuffer;
            inputValidationWithdraw(amountBuffer, balance);
            balance -= amountBuffer;
            showBalance(balance);
            std::cout << "\n\npress any key to go back...";
            _getch();
            break;
        case '4':
            std::cout << "Do you want to exit?\n\npress (Y for Yes) (any other key for No)";
            choiceBuffer = _getch();
            if(choiceBuffer == 'y'){
                goto exit;
            } else {
                break;
            }
        }
    }


exit:
    ;
}

