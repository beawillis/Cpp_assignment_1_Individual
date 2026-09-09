#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    double weightInPounds;
    double heightInInches;

    cout << "Enter weight in pounds: ";
    cin >> weightInPounds;

    cout << "Enter height in inches: ";
    cin >> heightInInches;

    const double KILOGRAMS_PER_POUND = 0.45359237;
    const double METERS_PER_INCH = 0.0254;

    double weightInKilograms = weightInPounds * KILOGRAMS_PER_POUND;
    double heightInMeters = heightInInches * METERS_PER_INCH;

    double bmi = weightInKilograms / (heightInMeters * heightInMeters);

    cout << fixed << setprecision(2);
    cout << "BMI is " << bmi << endl;

    if (bmi < 18.5)
        cout << "Underweight" << endl;
    else if (bmi < 24.9)
        cout << "Normal" << endl;
    else if (bmi < 29.9)
        cout << "Overweight" << endl;
    else
        cout << "Obese" << endl;

    return 0;
}