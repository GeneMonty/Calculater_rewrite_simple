/*
Author: Eugenio Montealegre
Porpuse: Grade Calculator.
Changes: Refactor, cleaned variables, cleaned naming, UI Cleaned,
Note: Kept original functionality, refactored and cleaned variable names, function names as recommended.
Also kept the make_line_dividers function to work better with positive and negative visual space.(avoids cramped lines with this ugly repelit console font, looks prettier in visualstudio (￣ー￣；)
*/

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// Create custom line dividers
void make_line_divider(string style);

// Display Add points or exit program commands
void display_commands();

// Function displays headlines or instructions to user, gets point_limit to display dynamic warning
void display_headline_or_instructions(string title, double points_limit);

// Function display final result summary to user
void display_results(double course_points, double total);

// Function gets course_points from user and checks for incorrect input
double get_course_points(double course_points);

// Function gets the points of assigments (tasks) from user
double get_task_points(string task_name, int task_index, int task_limit, double points, double points_limit, double total);


int main() {

    // Displays program Name
    display_headline_or_instructions("name", {});

    // Displays program Description
    display_headline_or_instructions("description", {});

    char command = 'y';
    while (command != 'x') {

        // Promp user to add points or exit program
        display_commands();
        cout << "|> Command: ";
        cin >> command;
        cout << endl;

        // Declare Variables
        double course_points = 0.0;
        double points = 0.0;
        double total = 0.0;

        if (tolower(command) == 'a') {

            // Promp user to get points for the course
            course_points = get_course_points(course_points);

            // Perform Calculations to get the value for points_limit
            // point_limit, caps the maximum allowed input number for assigments according to course_points.
            double points_limit = (course_points - (course_points * 0.25)) / 15;

            // Promp user to get Assignment points from user, and display warning.
            display_headline_or_instructions("assignment", points_limit);

            // Lab 1-2, promp user to get points for this task
            make_line_divider("short");
            total = get_task_points("Lab Week", 1, 2, points, points_limit, total);

            // Chapter Lab 1-10 ,promp user to get points for this task
            make_line_divider("short");
            total = get_task_points("Chapter Lab", 1, 10, points, points_limit, total);

            // Final Project Phases 1-3 ,promp user to get points for this task
            make_line_divider("short");
            total = get_task_points("Final Project Phase", 1, 3, points, points_limit, total);

            // Display final summary to user
            display_results(course_points, total);

        }
        // Display goodbye to user
        else if (tolower(command) == 'x') {
            display_headline_or_instructions("goodbye", {});
        }
        // Display input error
        else {
            cout << " [!] Invalidad Entry, try Again.\n\n";
        }

    }
}


// Function Definitions

// Create custom line dividers
void make_line_divider(string style) { // Function that makes divider shapes


    if (style == "short") {                // Makes a short line Divider
        cout << endl << "=";
        for (int i = 0; i < 30; i++) {
            cout << "-";
        }
        cout << "=" << endl << endl;

    }
}

// Display Add points or exit program commands
void display_commands() {
    cout << "Press a key to proceed \n\n"
        << "[a] - Add Points\n"
        << "[x] - Exit Program\n\n";
}

// Function displays headlines or instructions to user, gets point_limit to display dynamic warning
void display_headline_or_instructions(string title, double points_limit) {

    // Display Program Title
    if (title == "name") {
        make_line_divider("short"); // calls custom line divider
        cout << "\tGRADE CALCULATOR" << endl;
        make_line_divider("short");
    }
    // Display Program Description
    if (title == "description") {
        cout << "This program will calculate and display:\n\n"
            << "[1] Points earned.\n"
            << "[2] Points needed to achieve desired grade letter.\n" << endl;

    }
    // Display Assignment Instructions
    if (title == "assignment") {
        cout << "|> [ Please Input the Scores for each Assignment ]" << endl
            << "|> [ Scores must be between [0] & [" << points_limit << "] ]" << endl;
    }
    // Display Summary Headline
    if (title == "summary") {
        make_line_divider("short");
        cout << "\tPoints Summary" << endl;
        make_line_divider("short");

    }
    // Display Letter Grades headline
    if (title == "letter grades") {
        make_line_divider("short");
        cout << "\tLetter Grades" << endl;
        make_line_divider("short");

    }
    // Display Goodbye
    if (title == "goodbye") {
        cout << "[!] Goodbye" << endl << endl;

    }


};

// Function display final result summary to user
void display_results(double course_points, double total) {

    // Display headline and print out Course and Earned Points
    display_headline_or_instructions("summary", {});
    cout << "Course Points: " << "[" << course_points << ']' << endl;
    cout << "Earned Points: " << "[" << total << ']' << endl;

    // Display Headline and Print out Letter Grades to user.
    display_headline_or_instructions("letter grades", {}); // Display Letter Grades Headline
    int i = 0;
    for (double g_index = 0.895; g_index > 0.595; g_index += -0.100) {

        // PERFORM CALCULATION
        double grade_letter = (g_index * course_points) - total;

        // ROUNDING UP
        grade_letter = ceil(grade_letter);

        // Array to store string of Letter Grades    
        string letters[4] = {
            "A: ",
            "B: ",
            "C: ",
            "D: "
        };
        // OUTPUT RESULTS
        cout << "Points needed for an " << letters[i] << '[' << grade_letter << ']' << endl;
        i++;
    }
    make_line_divider("short");
}

// Function gets course_points from user and checks for incorrect input
double get_course_points(double course_points) {

    while (true) {
        cout << "How Many Points are Possible for the Course?: ";
        cin >> course_points;
        cout << endl;

        if (course_points <= 0) {
            cout << "\n  [!] Please enter a number greater than [0]" << endl << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // consume wrong input
        }
        else {
            return course_points;
        }
    }

}

// Function gets the points of assigments (tasks) from user
double get_task_points(string task_name, int task_index, int task_limit, double points, double points_limit, double total) {

    while (true) {
        cout << task_name << " [" << task_index << "]: ";
        cin >> points;
        
        // check for incorrect input and prompt user again for correct input
        if (points < 0 || points > points_limit || !cin) {
            cerr << "\n\t |> Please enter a value between [0] & [" << points_limit << "] \n" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // consume wrong input

        }
        // exit out of loop when task limit is reached
        else if (task_index == task_limit) {
            total += points;
            break;
        }
        else {
            total += points;
            task_index += 1;

        }
    }
    //cout << endl;
    return total;
}