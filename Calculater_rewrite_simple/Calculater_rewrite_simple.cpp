// Calculater_rewrite_simple.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


/*
Author: Eugenio Montealegre
Porpuse: Grade Calculator, simplified version, no functions, no error check.
*/

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// Create custom line dividers
void make_line_divider(string style) { // Function that makes divider shapes

    
    if (style == "short") {                // Makes a short line Divider
        for (int i = 0; i < 10; i++) {
            cout << "~==";
        }
        cout << "~" << endl;

    }
    else if (style == "long") {            // Makes a Long line Divider
        for (int i = 0; i < 17; i++) {
            cout << "~==";
        }
        cout << "~" << endl;

    }
    else if (style == "empty") {            // Makes Empty line Divider
        cout << endl;
    }
}

// Function displays headlines or instructions to user
void display_headline_or_instructions(string title, double points_limit) {
    
    if (title == "name") {
        make_line_divider("short");
        cout << "GRADE CALCULATOR" << endl;
        make_line_divider("short");
    }

    if (title == "instructions") {
        cout << "\n[ Please provide course grading and Assignment Details ]\n\n"
            << "This program will calculate and display:\n\n"
            << "[?] The 'Course Points' earned.\n"
            << "[?] Points needed to achieve desired Grade Letter.\n" << endl;

    }
    
    if (title == "assignment") {
        cout << "|> [ Please Input the Scores for each Assignment ]" << endl
             << "|> [ Scores must be between [0] & [" << points_limit << "] ] \n" << endl;
    }

    if (title == "summary") {
        make_line_divider("short");
        cout << "Points Summary" << endl;
        make_line_divider("short");

    }
    
    if (title == "letter grades") {
        make_line_divider("short");
        cout << "Letter Grades" << endl;
        make_line_divider("short");

    }
    if (title == "goodbye") {
        cout << endl << "Goodbye" << endl << endl;

    }
    

};

// Function gets course_points from user
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

// Function display final results to user
void display_results(double course_points, double total) {
    
    display_headline_or_instructions("summary", {});
    cout << "Course Points: " << "[" << course_points << ']' << endl;
    cout << "Earned Points: " << "[" << total << ']' << endl << endl;
    
    display_headline_or_instructions("letter grades", {});
    int i = 0;
    for (double g_index = 0.895; g_index > 0.595; g_index += -0.100) {

        // PERFORM CALCULATION
        double grade_letter = (g_index * course_points) - total;

        // ROUNDING UP
        grade_letter = ceil(grade_letter);

        // OUTPUT RESULTS    
        string letters[4] = {
            "A: ",
            "B: ",
            "C: ",
            "D: "
        };

        cout << "Points needed for an " << letters[i] << '[' << grade_letter << ']' << endl;
        i++;
    }
    make_line_divider("short");
}

// Function gets the points of assigments from user
double get_task_points(string task_name, int task_index, int task_limit, double points, double points_limit, double total) {

    while (true) {
        cout << task_name << " [" << task_index << "]: ";
        cin >> points;

        if (!cin || points < 0 || points > points_limit) {
            cerr << "\n\t |> Please enter a value between [0] & [" << points_limit << "] \n" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // consume wrong input

        }
        else if (task_index == task_limit) {
            total += points;
            break;
        }
        else {
            total += points;
            task_index += 1;

        }
    }
    cout << endl;
    return total;
}



int main() {

    // Declare Variables
    double course_points = 0.0;
    double points = 0.0;
    double total = 0.0;

    // Displays program Name
    display_headline_or_instructions("name", {});

    // Displays initial Instructions
    display_headline_or_instructions("instructions", {});

    // Promp user to get points for the course
    course_points = get_course_points(course_points);

    // Perform Calculations to get the value for points_limit
    // point_limit, caps the maximum allowed input number for assigments according to course_points.
    double points_limit = (course_points - (course_points*0.25)) / 15; 

    // Promp user to get Assignment points from user, and display warning.
    display_headline_or_instructions("assignment",points_limit);

    // Lab 1-2, promp user to get points for this task
    total = get_task_points("Lab Week", 1, 2, points, points_limit, total);
    
    // Chapter Lab 1-10 ,promp user to get points for this task
    total = get_task_points("Chapter Lab", 1, 10, points, points_limit, total);
    
    // Final Project Phases 1-3 ,promp user to get points for this task
    total = get_task_points("Final Project Phase", 1, 3, points, points_limit, total);

    // Display final summary to user
    display_results(course_points,total);

    // calls function to display goodbye
    display_headline_or_instructions("goodbye",{});

}














