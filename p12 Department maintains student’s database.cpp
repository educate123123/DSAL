/* Department maintains student’s database. The file contains roll number, name, division and address.
 Write a program to create a sequential file to store and maintain student data, allow add,  search and
 display data operations*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure to store student data
struct Student 
{
    int roll_no;
    string name;
    string division;
    string address;
};

// Function to add a student record to the file
void addStudent(const string &filename) 
{
    ofstream outfile(filename, ios::app);  // Open the file in append mode
    
    if (!outfile) 
    {
        cout << "Error opening file!" << endl;
        return;
    }

    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.roll_no;
    cin.ignore(); // To ignore the newline character left in the buffer after entering roll_no
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Division: ";
    getline(cin, s.division);
    cout << "Enter Address: ";
    getline(cin, s.address);

    // Write the student data to the file
    outfile << s.roll_no << "\n" << s.name << "\n" << s.division << "\n" << s.address << "\n";

    cout << "Student record added successfully!" << endl;

    outfile.close();
}

// Function to search a student by roll number
void searchStudent(const string &filename, int roll_no) 
{
    ifstream infile(filename);

    if (!infile) 
    {
        cout << "Error opening file!" << endl;
        return;
    }

    Student s;
    bool found = false;
    while (infile >> s.roll_no) 
    {
        infile.ignore(); // To ignore the newline character after reading roll_no
        getline(infile, s.name);
        getline(infile, s.division);
        getline(infile, s.address);

        if (s.roll_no == roll_no) 
        {
            found = true;
            cout << "Student Found!" << endl;
            cout << "Roll Number: " << s.roll_no << endl;
            cout << "Name: " << s.name << endl;
            cout << "Division: " << s.division << endl;
            cout << "Address: " << s.address << endl;
            break;
        }
    }

    if (!found) 
    {
        cout << "Student with Roll Number " << roll_no << " not found!" << endl;
    }

    infile.close();
}

// Function to display all student records
void displayAllStudents(const string &filename) 
{
    ifstream infile(filename);

    if (!infile) 
    {
        cout << "Error opening file!" << endl;
        return;
    }

    Student s;
    cout << "Student Records:" << endl;
    while (infile >> s.roll_no) 
    {
        infile.ignore(); // To ignore the newline character after reading roll_no
        getline(infile, s.name);
        getline(infile, s.division);
        getline(infile, s.address);

        cout << "Roll Number: " << s.roll_no << endl;
        cout << "Name: " << s.name << endl;
        cout << "Division: " << s.division << endl;
        cout << "Address: " << s.address << endl;
        cout << "---------------------------" << endl;
    }

    infile.close();
}

int main() 
{
    string filename = "students.txt";
    int choice;
    int roll_no;

    do 
    {
        cout << "\nStudent Database Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student by Roll Number\n";
        cout << "3. Display All Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                addStudent(filename);
                break;
            case 2:
                cout << "Enter Roll Number to search: ";
                cin >> roll_no;
                searchStudent(filename, roll_no);
                break;
            case 3:
                displayAllStudents(filename);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
