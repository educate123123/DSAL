#include <iostream>
#include <string> // Include string header
using namespace std;

// Define structure for Student
struct Student 
{
    int rollNo;
    string name;
    float sgpa;
};

// Bubble Sort to arrange students by Roll No
void bubbleSort(Student students[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (students[j].rollNo > students[j + 1].rollNo) 
            {
                // Swap the students
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Function to display the student list
void display(Student students[], int n) 
{
    cout << "Roll No\tName\tSGPA\n";
    for (int i = 0; i < n; i++) 
    {
        cout << students[i].rollNo << "\t" << students[i].name << "\t" << students[i].sgpa << endl;
    }
}

int main() 
{
    // Array of Students
    Student students[] = {
        {16, "Deva", 8.0}, // Corrected sgpa value
        {56, "Shrinath", 9.1},
        {74, "Vaibhav", 9.0},
        {58, "Suraj", 7.5}
    };
    int n = 4; // Updated number of students

    cout << "Before Sorting:\n";
    display(students, n);

    // Sort the students by Roll No
    bubbleSort(students, n);

    cout << "\nAfter Sorting:\n";
    display(students, n);

    return 0;
}
