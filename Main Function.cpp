#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

// Numerical Constants
const double COST_A4_COLOUR = 0.50;
const double COST_A4_BW = 0.20;
const double COST_A3_COLOUR = 1.00;
const double COST_A3_BW = 0.80;
const double BINDING_COST_COIL = 3.50;
const double BINDING_COST_COMB = 3.00;
const double BINDING_COST_RING = 5.00;
const double LAMINATION_COST = 1.00;
const double DISCOUNT_MEMBER = 0.10;

// Static variable to maintain the sequence of receipt numbers
static int currentReceiptNumber = 1000;

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

// Struct to store feedback details
struct Feedback {
    string comments;
    int rating; // Rating out of 5
};

// Function prototypes
bool checkMembership(string& userType, string& memberID, bool& loggedIn);
void OrderMenu(int& qty, string& paperSize, string& colorType, string& bindingType, bool& lamination, bool& stapling);
double calculateCost(bool isMember, int quantity, string paperSize, string colorType, string bindingType, bool lamination, bool stapling);
void Payment(double total, string serviceDetails, string userType, const Order& order);
void Receipt(const Order& order);
void SelectServices(vector<Order>& orderSummary, vector<Feedback>& feedbackList);
void generateOrderSummary(const vector<Order>& orderSummary);
int generateReceiptNumber();
void collectFeedback(vector<Feedback>& feedbackList);
void viewFeedback(const vector<Feedback>& feedbackList);

int main() {
    vector<Order> orderSummary;  // To store all orders for summary
    vector<Feedback> feedbackList;  // To store all feedbacks
    SelectServices(orderSummary,feedbackList);
    return 0;
}

void SelectServices(vector<Order>& orderSummary, vector<Feedback>& feedbackList) {
    int serviceNum;
    string userType = "Non-Member", memberID;
    int qty;
    bool lamination = false, stapling = false;  // Defaults
    string paperSize, colorType, bindingType = "None";  // Default binding as "None"
    double totalCost;
    bool loggedIn = false;

    // Enhanced welcome message with a border
    cout << "==========================================================" << endl;
    cout << "  CCCCCCCCC     JJJJJJJJ    JJJJJJJJ       Printing Shop   " << endl;
    cout << " CCC     CCC        JJ          JJ                         " << endl;
    cout << " CC                  JJ          JJ                         " << endl;
    cout << " CC                  JJ          JJ                         " << endl;
    cout << " CC                  JJ          JJ                         " << endl;
    cout << " CCC     CCC     JJ  JJ      JJ  JJ                         " << endl;
    cout << "  CCCCCCCCC       JJJJ        JJJJ       Services for All!  " << endl;
    cout << "==========================================================" << endl;

    cout << "\n\n ------------------------------------------------" << endl;
    cout << " |          Welcome to CJJ Printing Shop         |" << endl;
    cout << " ------------------------------------------------" << endl;

    do {
        cout << "\n-------------------------------------------------" << endl;
        cout << "|                 Main Menu                      |" << endl;
        cout << "-------------------------------------------------" << endl;
        if (!loggedIn) {  // Show the login menu only if the user hasn't logged in yet
            cout << "| 1. Login Membership                            |" << endl;
        }
        cout << "| 2. New Printing / Order Menu                   |" << endl;
        cout << "| 3. View Summary                                |" << endl;
        cout << "| 4. Leave Feedback                              |" << endl;
        cout << "| 5. View Feedback                               |" << endl;
        cout << "| 6. Exit                                        |" << endl;
        cout << "-------------------------------------------------" << endl;

        cout << "\nPlease select the service > ";
        cin >> serviceNum;

        if (!loggedIn && serviceNum == 1) {
            if (checkMembership(userType, memberID, loggedIn)) {
                cout << "\n*** Membership Verified ***\n";
            }
            else {
                cout << "\n*** Invalid Membership or Non-Member ***\n";
            }
        }
        else if (serviceNum == 2) {
            // Order Menu and Calculate Cost
            OrderMenu(qty, paperSize, colorType, bindingType, lamination, stapling);
            totalCost = calculateCost(userType == "Member", qty, paperSize, colorType, bindingType, lamination, stapling);
            Order order = { memberID, userType, paperSize, colorType, bindingType, lamination, stapling, qty, totalCost, generateReceiptNumber() };
            Payment(totalCost, "Printing and Binding", userType, order);

            // Save the order details in the summary list
            orderSummary.push_back(order);
        
        }
        else if (serviceNum == 3) {
            // Generate Order Summary for Management
            generateOrderSummary(orderSummary);
        }
        else if (serviceNum == 4) {
            // Collect feedback
            collectFeedback(feedbackList);
        }
        else if (serviceNum == 5) {
            // View feedback
            viewFeedback(feedbackList);
        }
        else if (serviceNum == 6) {
            cout << "\n*** Thank you for using CJJ Printing Services! ***" << endl;
            break;
        }
        else {
            cout << "\nInvalid option, please select again.\n";
        }
    } while (true);
}


void collectFeedback(vector<Feedback>& feedbackList) {
    Feedback fb;
    int rating;
    cout << "\nPlease provide feedback on your experience." << endl;
    cout << "Rate your experience (1-5): ";
    cin >> rating;
    while (rating < 1 || rating > 5) {
        cout << "Invalid rating. Please provide a rating between 1 and 5: ";
        cin >> rating;
    }
    fb.rating = rating;

    cin.ignore(); // Ignore the newline character from the previous input
    cout << "Any additional comments? (Press Enter if none): ";
    getline(cin, fb.comments);

    // Add feedback to the list
    feedbackList.push_back(fb);
    cout << "Thank you for your feedback!" << endl;
}

void viewFeedback(const vector<Feedback>& feedbackList) {
    if (feedbackList.empty()) {
        cout << "\nNo feedback has been submitted yet." << endl;
        return;
    }

    cout << "\n=========== Customer Feedback ============" << endl;
    for (const auto& fb : feedbackList) {
        cout << "Rating: " << fb.rating << "/5" << endl;
        cout << "Comments: " << (fb.comments.empty() ? "No comments" : fb.comments) << endl;
        cout << "-------------------------------------------" << endl;
    }
}

bool checkMembership(string& userType, string& memberID, bool& loggedIn) {
    char membershipChoice;
    cout << "Are you a member? (Y/N): ";
    cin >> membershipChoice;

    if (membershipChoice == 'Y' || membershipChoice == 'y') {
        cout << "Please enter your MemberID: ";
        cin >> memberID;
        if (memberID.substr(0, 2) == "24") { // prefix must be 24 
            userType = "Member";
            loggedIn = true; // User has logged in successfully 
            return true;
        }
        else {
            cout << "Invalid MemberID. It must start with '24'.\n";
            loggedIn = true; // Still mark as logged in, to prevent re-login
            return false;
        }
    }
    else {
        userType = "Non-Member";
        loggedIn = true; //Mark as logged in prevents the program from prompting them again to log in
        return false;
    }
}

void OrderMenu(int& qty, string& paperSize, string& colorType, string& bindingType, bool& lamination, bool& stapling) {
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

double calculateCost(bool isMember, int quantity, string paperSize, string colorType, string bindingType, bool lamination, bool stapling) {
    double cost = 0;
    double discount = isMember ? DISCOUNT_MEMBER : 0.00;

    if (paperSize == "A4") {
        cost += (colorType == "Colour") ? COST_A4_COLOUR : COST_A4_BW;
    }
    else if (paperSize == "A3") {
        cost += (colorType == "Colour") ? COST_A3_COLOUR : COST_A3_BW;
    }

    cost *= quantity;

    if (bindingType == "Coil") cost += BINDING_COST_COIL;
    else if (bindingType == "Comb") cost += BINDING_COST_COMB;
    else if (bindingType == "3-ring") cost += BINDING_COST_RING;

    if (lamination) cost += LAMINATION_COST;
    // Stapling cost is zero, but included for completeness
    if (stapling) cost += 0.00;

    cost -= cost * discount;
    return cost;
}

void Receipt(const Order& order) {
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

void Payment(double total, string serviceDetails, string userType, const Order& order) {
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

    Receipt(order);
}

void generateOrderSummary(const vector<Order>& orderSummary) {
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

// Function to generate and return a new receipt number
int generateReceiptNumber() {
    return ++currentReceiptNumber;
}

