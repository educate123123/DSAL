#include <iostream>
#include <string>
using namespace std;

struct Student 
{
    int rollNo;
    string name;
    float SGPA;
};

int binarySearch(Student students[], int n, string targetName) 
{
    int left = 0, right = n-1;
    
    while (left<=right) 
    {
        int mid=left+(right-left)/2;
        
        // If the name matches at the mid position
        if (students[mid].name==targetName) 
        {
            return mid;  // Return the index of the student found
        }
        // If the target name is smaller, ignore the right half
        else if (students[mid].name>targetName) 
        {
            right = mid-1;
        }
        // If the target name is larger, ignore the left half
        else 
        {
            left=mid+1;
        }
    }
    return -1;  // Name not found
}

int main() 
{
    // Updated list of students (sorted by name)
    Student students[] = 
    {
        {1, "Deva", 7.8},
        {2, "Pratik", 6.5},
        {3, "Shrinath", 6.8},
        {4, "Suraj", 7.2}
    };
    
    int n = sizeof(students)/sizeof(students[0]);
    string targetName="Suraj";
    
    int result=binarySearch(students, n, targetName);
    
    if (result!=-1) 
    {
        cout<<"Student found: "<< students[result].name <<", Roll No: " <<students[result].rollNo<<", SGPA: "<< students[result].SGPA<<endl;
    }
    else 
    {
        cout<<"Student not found!"<<endl;
    }
    
    return 0;
}
