#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
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

int main1() {
    vector<Order> orderSummary;  // To store all orders for summary
    return 0;
}
void generateOrderSummary1( vector<Order>& orderSummary) {
    cout << "\n\n================ Order Summary =================" << endl;
    cout << " Total Orders Processed: " << orderSummary.size() << endl;
    cout << "------------------------------------------------" << endl;

    for (const auto& order : orderSummary) {
        cout << "Member ID: " << (order.memberID.empty() ? "Non-Member" : order.memberID) << endl;
        cout << "Paper Size: " << order.paperSize << endl;
        cout << "Color Type: " << order.colorType << endl;
        cout << "Binding Type: " << order.bindingType << endl;
        cout << "Lamination: " << (order.lamination ? "Yes" : "No") << endl;
        cout << "Stapling: " << (order.stapling ? "Yes" : "No") << endl;
        cout << "Quantity: " << order.quantity << endl;
        cout << "Total Cost: RM " << fixed << setprecision(2) << order.totalCost << endl;
        cout << "Receipt Number: R" << order.receiptNumber << endl;
        cout << "------------------------------------------------" << endl;
    }
}

