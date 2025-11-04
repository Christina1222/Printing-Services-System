#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void OrderMenu1(int& qty, string& paperSize, string& colorType, string& bindingType, bool& lamination, bool& stapling) {
    int sizeChoice, colorChoice, bindingChoice;
    char lamChoice, stapleChoice;

    cout << "\n\n================= Order Menu ==================" << endl;
    cout << "| Select paper size:                            |" << endl;
    cout << "| 1. A4                                         |" << endl;
    cout << "| 2. A3                                         |" << endl;
    cout << "================================================" << endl;
    cout << "Choice: ";
    cin >> sizeChoice;
    while (sizeChoice != 1 && sizeChoice != 2) {
        cout << "Invalid choice. Please select again: ";
        cin >> sizeChoice;
    }
    paperSize = (sizeChoice == 1) ? "A4" : "A3";

    cout << "\n\n================= Color Options =================" << endl;
    cout << "| 1. Colour                                      |" << endl;
    cout << "| 2. Black and White                             |" << endl;
    cout << "=================================================" << endl;
    cout << "Choice: ";
    cin >> colorChoice;
    while (colorChoice != 1 && colorChoice != 2) {
        cout << "Invalid choice. Please select again: ";
        cin >> colorChoice;
    }
    colorType = (colorChoice == 1) ? "Colour" : "Black and White";

    cout << "\n\n================= Binding Options ===============" << endl;
    cout << "| 1. Coil                                        |" << endl;
    cout << "| 2. Comb                                        |" << endl;
    cout << "| 3. 3-ring                                      |" << endl;
    cout << "| 4. None                                        |" << endl;
    cout << "=================================================" << endl;
    cout << "Choice: ";
    cin >> bindingChoice;
    while (bindingChoice < 1 || bindingChoice > 4) {
        cout << "Invalid choice. Please select again: ";
        cin >> bindingChoice;
    }
    bindingType = (bindingChoice == 1) ? "Coil" : (bindingChoice == 2) ? "Comb" : (bindingChoice == 3) ? "3-ring" : "None";

    cout << "\n\n================= Lamination ====================" << endl;
    cout << "Lamination (Y/N)? ";
    cin >> lamChoice;
    while (lamChoice != 'Y' && lamChoice != 'N' && lamChoice != 'y' && lamChoice != 'n') {
        cout << "Invalid choice. Please select Y or N: ";
        cin >> lamChoice;
    }
    lamination = (lamChoice == 'Y' || lamChoice == 'y');

    cout << "\n\n================= Stapling ======================" << endl;
    cout << "Stapling (Y/N)? ";
    cin >> stapleChoice;
    while (stapleChoice != 'Y' && stapleChoice != 'N' && stapleChoice != 'y' && stapleChoice != 'n') {
        cout << "Invalid choice. Please select Y or N: ";
        cin >> stapleChoice;
    }
    stapling = (stapleChoice == 'Y' || stapleChoice == 'y');

    cout << "\n\n================= Quantity ======================" << endl;
    cout << "Enter quantity: ";
    cin >> qty;
    while (qty <= 0) {
        cout << "Quantity must be positive. Enter again: ";
        cin >> qty;
    }
}
