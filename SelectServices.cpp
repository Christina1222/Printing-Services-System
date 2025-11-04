#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void SelectServices1 () {

    int serviceNum;
    string serviceType;
    char choice;

    cout << "  CCCCCCC     JJJJJJJJ    JJJJJJJJ  " << endl;
    cout << " CCC    CC        JJ          JJ    " << endl;
    cout << " CC               JJ          JJ    " << endl;
    cout << " CC               JJ          JJ    " << endl;
    cout << " CC               JJ          JJ    " << endl;
    cout << " CCC    CC    JJ  JJ      JJ  JJ    " << endl;
    cout << "  CCCCCCC      JJJJ        JJJJ   " << endl;

    cout << "\n\n -------------------------------" << endl;
    cout << " |Welcome to CJJ printing shop |" << endl;
    cout << " -------------------------------" << endl;

    do {
        cout << "\n1.Login Membership" << endl;
        cout << "2.New Printing" << endl;
        cout << "3.Order Menu" << endl;
        cout << "4.Summary" << endl;
        cout << "5.Exit" << endl;

        cout << "\nPlease select the number of service you want? (1-5) > ";
        cin >> serviceNum;

        switch (serviceNum) {
        case 1:
            serviceType = "Login Membership";
            break;
        case 2:
            serviceType = "Normal Printing service";
            break;
        case 3:
            serviceType = "Order Menu";
            break;
        case 4:
            serviceType = "Summary";
            break;
        case 5:
            cout << "Thanks for your support :)" << endl;
            break;
            exit(0);
        default:
            cout << "Sorry we don't have this type of service" << endl;
            cout << "Do you want to select again (Y/N) > ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                continue;
            }

        }
    } while (choice == 'Y' || choice == 'y');

}