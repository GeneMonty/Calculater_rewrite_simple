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

void make_line_divider(string style) { // Function that makes divider shapes

    if (style == "short") {                // Small Divider
        for (int i = 0; i < 10; i++) {
            cout << "~==";
        }
        cout << "~" << endl;

    }
    else if (style == "long") {            // Long Divider
        for (int i = 0; i < 17; i++) {
            cout << "~==";
        }
        cout << "~" << endl;

    }
    else if (style == "empty") {            // Empty divider
        cout << endl;
    }
}

void display_headline_or_instructions(string title, double points_limit) {
    
    if (title == "name") {
        cout << "--------------------------" << endl;
        cout << "GRADE CALCULATOR" << endl;
        cout << "--------------------------" << endl;
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
        cout << "--------------------------" << endl;
        cout << "Points Summary" << endl;
        cout << "--------------------------" << endl;

    }
    
    if (title == "letter grades") {
        cout << "--------------------------" << endl;
        cout << "Letter Grades" << endl;
        cout << "--------------------------" << endl;

    }
    if (title == "goodbye") {
        cout << endl << "Goodbye" << endl << endl;

    }
    

};
double get_task_points(string task_name, int task_index, int task_limit, double points, double points_limit, double total);
double get_course_points(double course_points) {

    while (true) {
        cout << "How Many Points are Possible for the Course?: ";
        cin >> course_points;

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
    cout << endl << "--------------------------" << endl;
}






int main() {

    // Declare Variables
    double course_points = 0.0;
    double points = 0.0;
    double total = 0.0;

    // Display Title and Instructions
    display_headline_or_instructions("name", {});
    display_headline_or_instructions("instructions", {});

    // Get the total Course Points from user.
    course_points = get_course_points(course_points);

    // Perform Calculations to get the value of exam and the points_limit
    double exam_points = 0.25 * course_points;
    double points_limit = (course_points - exam_points) / 15; // used for dynamic input check in get_task_points()

    // Get Assignment points from user.
    display_headline_or_instructions("assignment",{});


    // Lab 1-2
    total = get_task_points("Lab Week", 1, 2, points, points_limit, total);
    
    // Chapter Lab 1-10
    //total = get_task_points("Chapter Lab", 1, 10, points, points_limit, total);
    
    // Final Project Phases 1-3
    //total = get_task_points("Final Project Phase", 1, 3, points, points_limit, total);
   

    // Calculae and Display Results
    display_results(course_points,total);
    display_headline_or_instructions("goodbye",{});

}







double get_task_points(string task_name,int task_index,int task_limit,double points,double points_limit,double total) {
    
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






// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
