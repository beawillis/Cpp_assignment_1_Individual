#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// This program computes the area of a triangle using the coordinates
// of its three vertices. It applies Heron's formula after calculating
// the lengths of the three sides.
int main()
{
    // Read the coordinates of the three vertices.
    double x1, y1, x2, y2, x3, y3;

    cout << "Enter three points for a triangle: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Calculate the length of each side using the distance formula.
    double side1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double side2 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double side3 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

    // Compute the semi-perimeter used in Heron's formula.
    double s = (side1 + side2 + side3) / 2;

    // Heron's formula: area = sqrt(s * (s-a) * (s-b) * (s-c)).
    double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

    // Display the answer to one decimal place for readability.
    cout << fixed << setprecision(1);
    cout << "The area of the triangle is " << area << endl;

    return 0;
}
