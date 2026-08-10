#include <iostream>
#include  "menu.h"
using namespace std;


// ============================================================
//                         MAIN
// ============================================================

int main()
{
    MenuNode mainMenu = createMainMenu();


    runMenu(mainMenu);


    cout << "\n";
    cout << "============================================================\n";
    cout << "  Neural Network Design - Program Finished\n";
    cout << "============================================================\n";


    return 0;
}



