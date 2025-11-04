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


void collectFeedback1(vector<Feedback>& feedbackList) {
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