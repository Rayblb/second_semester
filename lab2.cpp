#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void initializeVectors(vector<string>& names, vector<int>& grades) {
    // Get initialization choice from user
    int choice;
    cout << "Choose an initialization option:\n";
    cout << "1. Demo analysis on default input values\n";
    cout << "2. Analysis on random input values\n";
    cout << "3. Analysis on input values from the user himself\n";
    cin >> choice;

    // Initialize vectors based on user choice
    switch (choice) {
        case 1: {
            // Initialize with default values
            names = {"issa", "jana", "ali", "julia", "Mike", "abel", "nina", "kristina", "marwan", "Linda"};
            grades = {90, 80, 70, 60, 50, 40, 30, 100, 10, 0};
            break;
        }
        case 2: {
            // Initialize with random values
            int n;
            cout << "Enter sample size: ";
            cin >> n;
            srand(time(NULL));
            for (int i = 0; i < n; i++) {
                string name = "Student" + to_string(i + 1);
                int grade = rand() % 101;
                names.push_back(name);
                grades.push_back(grade);
            }
            break;
        }
        case 3: {
            // Initialize with user-input values
            int n;
            cout << "Enter sample size: ";
            cin >> n;
            cout << "Enter names and grades sequentially:\n";
            for (int i = 0; i < n; i++) {
                string name;
                int grade;
                cin >> name >> grade;
                names.push_back(name);
                grades.push_back(grade);
            }
            break;
        }
        default: {
            // Handle invalid choice
            cout << "Invalid choice!\n";
        }
    }
}

void printVectors(const vector<string>& names, const vector<int>& grades) {
    // Prints the names vector
    cout << "\nNames:\n";
    for (const auto& name : names) {
        cout << name << endl;
    }

    // Prints the grades vector
    cout << "\nGrades:\n";
    for (const auto& grade : grades) {
        cout << grade << endl;
    }
}

void analyzeGrades(const vector<string>& names, const vector<int>& grades) {
    // Calculate the average grade
    int n = names.size();
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += grades[i];
    }
    double average = sum / n;

    // Print the average grade
    cout << "\nAverage grade: " << average << endl;

    // Count the number of students in each grade range
    int countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;
    for (int i = 0; i < n; i++) {
        if (grades[i] >= 90) {
            countA++;
        } else if (grades[i] >= 80) {
            countB++;
        } else if (grades[i] >= 70) {
            countC++;
        } else if (grades[i] >= 60) {
            countD++;
        } else {
            countF++;
        }
    }

    // Print the grade distribution
    cout << "\nGrade distribution:\n";
    cout << "A: " << countA << endl;
    cout << "B: " << countB << endl;
    cout << "C: " << countC << endl;
    cout << "D: " << countD << endl;
    cout << "F: " << countF << endl;
}
int main() {
    // Create a vector of names
    vector<string> names;
    // Create a vector of grades
    vector<int> grades;

    // Initialize the vectors
    initializeVectors(names, grades);

    // Print the vectors
    printVectors(names, grades);

    // Analyze the grades
    analyzeGrades(names, grades);

    return 0;
}
