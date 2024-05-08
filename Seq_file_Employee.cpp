#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Employee
{
    int employeeID;
    string name;
    string designation;
    double salary;
};
void addEmployee()
{
    ofstream file("employee_data.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.employeeID;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, emp.name);
    cout << "Enter Designation: ";
    getline(cin, emp.designation);
    cout << "Enter Salary: ";
    cin >> emp.salary;

    file << emp.employeeID << " " << emp.name << " " << emp.designation << " " << emp.salary << endl;
    file.close();

    cout << "Employee added successfully." << endl;
}

void displayEmployee()
{
    ifstream file("employee_data.txt");
    if (!file.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    int empID;
    cout << "Enter Employee ID to display: ";
    cin >> empID;

    Employee emp;
    bool found = false;

    while (file >> emp.employeeID >> emp.name >> emp.designation >> emp.salary)
    {
        if (emp.employeeID == empID)
        {
            cout << "Employee ID: " << emp.employeeID << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Designation: " << emp.designation << endl;
            cout << "Salary: " << emp.salary << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Employee not found." << endl;
    }

    file.close();
}
void deleteEmployee()
{
    ifstream inFile("employee_data.txt");
    if (!inFile.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    ofstream outFile("temp.txt");
    if (!outFile.is_open())
    {
        cout << "Error creating temporary file." << endl;
        inFile.close();
        return;
    }

    int empID;
    cout << "Enter Employee ID to delete: ";
    cin >> empID;

    Employee emp;
    bool found = false;

    while (inFile >> emp.employeeID >> emp.name >> emp.designation >> emp.salary)
    {
        if (emp.employeeID == empID)
        {
            found = true;
            cout << "Employee deleted successfully." << endl;
        }
        else
        {
            outFile << emp.employeeID << "" << emp.name << " " << emp.designation << " " << emp.salary << endl;
        }
    }

    inFile.close();
    outFile.close();

    if (!found)
    {
        cout << "Employee not found." << endl;
    }
    else
    {
        remove("employee_data.txt");
        rename("temp.txt", "employee_data.txt");
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Add Employee\n2. Display Employee\n3. Delete Employee\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            displayEmployee();
            break;
        case 3:
            deleteEmployee();
            break;
        case 4:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}