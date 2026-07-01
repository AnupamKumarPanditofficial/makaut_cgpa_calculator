#include <iostream>
#include <iomanip>
using namespace std;

// Function to get valid CGPA input
double getValidCGPA(int semester)
{
    double cgpa;

    while (true)
    {
        cout << "Enter CGPA of Semester " << semester << " (0 - 10): ";
        cin >> cgpa;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a numeric value.\n";
        }
        else if (cgpa < 0 || cgpa > 10)
        {
            cout << "CGPA must be between 0 and 10.\n";
        }
        else
        {
            return cgpa;
        }
    }
}

int main()
{
    char choice;

    cout << "=========================================\n";
    cout << "   MAKAUT CGPA & Percentage Calculator\n";
    cout << "=========================================\n";

    do
    {
        int totalSemesters;

        // Input validation for total semesters
        while (true)
        {
            cout << "\nEnter Total Number of Semesters: ";
            cin >> totalSemesters;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Please enter a valid number.\n";
            }
            else if (totalSemesters <= 0)
            {
                cout << "Number of semesters must be greater than 0.\n";
            }
            else
            {
                break;
            }
        }

        double totalCGPA = 0;

        // Input semester CGPAs
        for (int i = 1; i <= totalSemesters; i++)
        {
            totalCGPA += getValidCGPA(i);
        }

        // Calculate Average CGPA
        double averageCGPA = totalCGPA / totalSemesters;

        // Calculate Percentage
        double percentage = (averageCGPA - 0.5) * 10;

        // Display Result
        cout << "\n========== RESULT ==========\n";
        cout << fixed << setprecision(2);
        cout << "Average CGPA : " << averageCGPA << endl;
        cout << "Percentage   : " << percentage << "%" << endl;
        cout << "============================\n";

        cout << "\nDo you want to calculate again? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "\nThank you for using the MAKAUT CGPA Calculator!\n";

    return 0;
}
