#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Struct to store feedback details
struct Feedback {
    string comments;
    int rating; // Rating out of 5
};
void viewFeedback1(const vector<Feedback>& feedbackList) {
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
