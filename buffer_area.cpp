#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// A point in a 2D coordinate system.
struct Point {
    double x;
    double y;
};

// This function calculates the straight-line distance between two points
// using the Euclidean distance formula: sqrt((x2 - x1)^2 + (y2 - y1)^2).
double calculateDistance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    // Program header for user-friendly output.
    cout << "=========================================" << endl;
    cout << "      GIS Buffer Analysis Program       " << endl;
    cout << "=========================================" << endl;

    // Read the center point around which buffer regions will be evaluated.
    Point center;
    cout << "Enter center point coordinate (x y): ";
    cin >> center.x >> center.y;

    // Number of different buffer distances the user wants to test.
    int bufferCount;
    cout << "Enter number of buffer sizes: ";
    cin >> bufferCount;

    // Store each buffer radius in a dynamic array-like vector.
    vector<double> bufferSizes(bufferCount);
    for (int i = 0; i < bufferCount; i++) {
        cout << "Enter buffer size " << i + 1 << " (distance units): ";
        cin >> bufferSizes[i];
    }

    // Read the number of points to test against the buffers.
    int pointCount;
    cout << "Enter number of points to analyze: ";
    cin >> pointCount;

    // Store all points in a vector.
    vector<Point> points(pointCount);
    for (int i = 0; i < pointCount; i++) {
        cout << "Enter point " << i + 1 << " coordinate (x y): ";
        cin >> points[i].x >> points[i].y;
    }

    // Set decimal precision for consistent distance display.
    cout << fixed << setprecision(2);
    cout << "\nBuffer results around center (" << center.x << ", " << center.y << "):\n";

    // Evaluate each buffer size separately.
    for (int i = 0; i < bufferCount; i++) {
        double radius = bufferSizes[i];
        vector<Point> insidePoints;

        // Check which points fall within the current radius.
        for (const Point& p : points) {
            if (calculateDistance(center, p) <= radius) {
                insidePoints.push_back(p);
            }
        }

        // Display the result for this specific buffer.
        cout << "\nBuffer radius " << radius << ":" << endl;
        cout << "Points contained in this buffer region:" << endl;

        if (insidePoints.empty()) {
            cout << "  No points found inside the buffer." << endl;
        } else {
            for (const Point& p : insidePoints) {
                cout << "  (" << p.x << ", " << p.y << ")" << endl;
            }
        }
    }

    cout << "\nProgram finished successfully." << endl;
    return 0;
}
