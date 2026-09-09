#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x;
    double y;
};

// Calculates Euclidean distance between two points.
double calculateDistance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    cout << "=========================================" << endl;
    cout << "      GIS Buffer Analysis Program       " << endl;
    cout << "=========================================" << endl;

    Point center;
    cout << "Enter center point coordinate (x y): ";
    cin >> center.x >> center.y;

    int bufferCount;
    cout << "Enter number of buffer sizes: ";
    cin >> bufferCount;

    vector<double> bufferSizes(bufferCount);
    for (int i = 0; i < bufferCount; i++) {
        cout << "Enter buffer size " << i + 1 << " (distance units): ";
        cin >> bufferSizes[i];
    }

    int pointCount;
    cout << "Enter number of points to analyze: ";
    cin >> pointCount;

    vector<Point> points(pointCount);
    for (int i = 0; i < pointCount; i++) {
        cout << "Enter point " << i + 1 << " coordinate (x y): ";
        cin >> points[i].x >> points[i].y;
    }

    cout << fixed << setprecision(2);
    cout << "\nBuffer results around center (" << center.x << ", " << center.y << "):\n";

    for (int i = 0; i < bufferCount; i++) {
        double radius = bufferSizes[i];
        vector<Point> insidePoints;

        for (const Point& p : points) {
            if (calculateDistance(center, p) <= radius) {
                insidePoints.push_back(p);
            }
        }

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
