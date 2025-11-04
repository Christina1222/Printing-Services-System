#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std; 

bool checkMembership1(string& userType, string& memberID) {
    char membershipChoice;
    cout << "Are you a member? (Y/N): ";
    cin >> membershipChoice;

    switch (membershipChoice) {
    case 'Y':
    case 'y':
        cout << "Please enter your MemberID: ";
        cin >> memberID;
        // Check if MemberID starts with "24"
        if (memberID.substr(0, 2) == "24") {
            userType = "Member";
            return true;
        }
        else {
            cout << "Invalid MemberID. It must start with '24'.\n";
            return false;
        }
    case 'N':
    case 'n':
        userType = "Non-Member";
        cout << "Do you want to join the membership? (Y/N): ";
        cin >> membershipChoice;
        if (membershipChoice == 'Y' || membershipChoice == 'y') {
            cout << "Please enter your MemberID: ";
            cin >> memberID;
            // Check if MemberID starts with "24"
            if (memberID.substr(0, 2) == "24") {
                userType = "Member";
                return true;
            }
            else {
                cout << "Invalid MemberID. It must start with '24'.\n";
                return false;
            }
        }
        break;
    default:
        cout << "Invalid choice.\n";
        break;
    }
    return false;
}