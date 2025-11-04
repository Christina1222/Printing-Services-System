#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <chrono>
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

void Receipt1( Order& order) {
    // Get current time as system time
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm localTime;
    localtime_s(&localTime, &currentTime);

    // Print header
    cout << "\n------------------------ CJJ Printing Shop ------------------------" << endl;
    cout << "Date                : " << put_time(&localTime, "%d/%m/%Y") << endl;
    cout << "Time                : " << put_time(&localTime, "%H:%M") << endl;
    cout << "Receipt Number      : R" << setw(4) << order.receiptNumber << endl;
    cout << "Customer Type       : " << order.userType << endl;
    cout << "--------------------------------------------------------------------" << endl;

    // Print order details in a table format
    cout << left << setw(20) << "Description" << " : " << setw(20) << left << "Details" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Paper Size" << " : " << setw(20) << left << order.paperSize << endl;
    cout << left << setw(20) << "Colour Option" << " : " << setw(20) << left << order.colorType << endl;
    cout << left << setw(20) << "Binding Service" << " : " << setw(20) << left << order.bindingType << endl;
    cout << left << setw(20) << "Quantity" << " : " << setw(20) << left << order.quantity << endl;
    cout << left << setw(20) << "Lamination" << " : " << setw(20) << left << (order.lamination ? "Yes" : "No") << endl;
    cout << left << setw(20) << "Stapling" << " : " << setw(20) << left << (order.stapling ? "Yes" : "No") << endl;

    // Print total amount
    cout << "\n--------------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Total Amount" << " : RM " << fixed << setprecision(2) << setw(20) << left << order.totalCost << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << setw(40) << right << "Thank you for your purchase!" << endl;
}