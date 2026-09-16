#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// This program calculates a person's Body Mass Index (BMI)
// using their weight in pounds and height in inches.
// It then classifies the BMI into a health category.
int main()
{
    // Store the user's weight and height as input values.
    double weightInPounds;
    double heightInInches;

    // Prompt the user for input.
    cout << "Enter weight in pounds: ";
    cin >> weightInPounds;

    cout << "Enter height in inches: ";
    cin >> heightInInches;

    // These constants convert imperial units to metric units.
    // BMI uses kilograms and meters, so the conversion is essential.
    const double KILOGRAMS_PER_POUND = 0.45359237;
    const double METERS_PER_INCH = 0.0254;

    // Convert the entered values into the metric system.
    double weightInKilograms = weightInPounds * KILOGRAMS_PER_POUND;
    double heightInMeters = heightInInches * METERS_PER_INCH;

    // BMI formula: weight in kilograms divided by height in meters squared.
    double bmi = weightInKilograms / (heightInMeters * heightInMeters);

    // Format the output to two decimal places for a cleaner display.
    cout << fixed << setprecision(2);
    cout << "BMI is " << bmi << endl;

    // Classify the BMI according to standard health ranges.
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