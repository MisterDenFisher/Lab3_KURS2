#include "Header.h"

int main()
{
    srand(time(0));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Добро пожаловать в библиотеку!\n";
    
    Library* library = CreateLibrary();

    int answer;
    while (true) {
        printMenu();

        answer = InputInt();
        if (answer == 1)
            Operation(library, answer);
        else if (answer == 2)
            Operation(library, answer);
        else if (answer == 3)
            Operation(library, answer);
        else if (answer == 4)
            library[0].InfoLibrary(library);
        else if (answer == 5)
            break;
        else
            cout << "Такой команды нет!\n";
    }
    cout << "Спасибо за внимание!!!\n";
    
    return 0;

}