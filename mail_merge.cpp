#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

// Return the correct date suffix for a day number.
// Examples: 1 -> st, 2 -> nd, 3 -> rd, 21 -> st, 22 -> nd, 23 -> rd.
string daySuffix(int day)
{
    if (day % 100 >= 11 && day % 100 <= 13)
        return "th";

    switch (day % 10)
    {
    case 1:
        return "st";
    case 2:
        return "nd";
    case 3:
        return "rd";
    default:
        return "th";
    }
}

// Convert a numeric month value into its full English name.
string monthName(int month)
{
    string months[] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};
    return months[month - 1];
}

int main()
{
    // These variables store the student's personal admission details.
    string firstName, lastName, studyProgram, academicYear;

    // Capture the student's name and course information.
    cout << "Enter first name: ";
    getline(cin, firstName);

    cout << "Enter last name: ";
    getline(cin, lastName);

    cout << "Enter study program: ";
    getline(cin, studyProgram);

    cout << "Enter academic year: ";
    getline(cin, academicYear);

    // Get the current system date and time.
    time_t now = time(0);
    tm* date = localtime(&now);

    // Extract day, month, and year parts from the current date.
    int day = date->tm_mday;
    int month = date->tm_mon + 1;
    int year = date->tm_year + 1900;

    // Display the formatted date using the day suffix and month name.
    cout << "\nDate: " << day << daySuffix(day) << " " << monthName(month)
         << " " << year << "\n\n";

    // Compose a formal admission letter addressed to the student.
    cout << "To: " << firstName << " " << lastName << ",\n\n";
    cout << "Dear " << firstName << ",\n\n";
    cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere University\n";
    cout << "Admissions Board has approved your application for admission to the\n";
    cout << academicYear << " academic year.\n\n";
    cout << "You have been offered a place for the following course:\n";
    cout << "PROGRAM: " << studyProgram << "\n\n";
    cout << "As a student of Makerere University, you will be part of a historic\n";
    cout << "institution dedicated to academic excellence and innovation. Please ensure\n";
    cout << "that you report to the Academic Registrar's office with your original\n";
    cout << "academic documents for verification during the orientation week.\n\n";
    cout << "We look forward to welcoming you to the Makerere University.\n\n";
    cout << "Yours sincerely,\n\n\n";
    cout << "John Doe\n";
    cout << "Registrar\n";

    return 0;
}