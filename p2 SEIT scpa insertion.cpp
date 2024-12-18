#include <iostream>
using namespace std;

struct Student 
{
    int rollNo;
    string name;
    float sgpa;
};

void insertionSort(Student students[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].name > key.name) 
        {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

void display(Student students[], int n) 
{
    cout << "Roll No\tName\t\tSGPA\n";
    for (int i = 0; i < n; i++)
        cout << students[i].rollNo << "\t" << students[i].name << "\t\t" << students[i].sgpa << endl;
}

int main() 
{
    Student students[] = 
    {
        {103, "Deva", 7.8}, 
        {101, "Pratik", 6.5}, 
        {102, "Suraj", 7.2}, 
        {104, "Shrinath", 6.8}
    };
    int n = 4;

    cout << "Before Sorting:\n";
    display(students, n);

    insertionSort(students, n);

    cout << "\nAfter Sorting:\n";
    display(students, n);

    return 0;
}
