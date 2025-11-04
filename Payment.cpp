#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Struct to store order details for summary
struct Order {
    string memberID;
    string userType;
    string paperSize;
    string colorType;
    string bindingType;
    bool lamination;
    bool stapling;
    int quantity;
    double totalCost;
    int receiptNumber; // Added to store receipt number
};

void Payment1(double total, string serviceDetails, string userType, Order& order) {
    int payOption;
    bool validPayment = false;

    while (!validPayment) {
        cout << "\n================= Payment ==================" << endl;
        cout << "Total cost: RM " << fixed << setprecision(2) << total << endl;
        cout << endl;
        cout << "Select payment method:" << endl;
        cout << "1. TouchNGo" << endl;
        cout << "2. Cash" << endl;
        cout << "3. Credit Card" << endl;
        cout << "Choice: ";
        cin >> payOption;

        if (payOption == 1 || payOption == 2 || payOption == 3) {
            validPayment = true;  // Valid payment option selected
        }
        else {
            cout << "Invalid choice. Please select 1, 2, or 3." << endl;
        }
    }

    switch (payOption) {
    case 1:
        cout << "\nPayment Successful via TouchNGo!" << endl;
        break;
    case 2:
        cout << "\nPayment Successful via Cash!" << endl;
        break;
    case 3:
        cout << "\nPayment Successful via Credit Card!" << endl;
        break;
    default:
        cout << "\nInvalid payment option selected." << endl;
    }

}

