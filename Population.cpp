#include <iostream>

using namespace std;

// This program projects the population over the next five years.
// It assumes a constant annual increase based on average birth,
// death, and immigration rates per second.
int main()
{
    // The starting population used for the forecast.
    const int CURRENT_POPULATION = 312032486;

    // Number of seconds in one year, used to estimate yearly changes.
    const int SECONDS_IN_YEAR = 365 * 24 * 60 * 60;

    // Estimated yearly net change values based on average rates.
    // Each value represents the number of people added or removed per year.
    int birthsPerYear = SECONDS_IN_YEAR / 7;
    int deathsPerYear = SECONDS_IN_YEAR / 13;
    int immigrantsPerYear = SECONDS_IN_YEAR / 45;

    // The working population value that changes each year.
    int population = CURRENT_POPULATION;

    // Display a heading for the forecast.
    cout << "Population projection for the next five years:\n";

    // Repeat the update process for five years.
    for (int year = 1; year <= 5; year++)
    {
        // Each year, the population increases by births and immigrants,
        // then decreases by deaths.
        population += birthsPerYear - deathsPerYear + immigrantsPerYear;

        // Print the updated population for the current year.
        cout << "Year " << year << ": " << population << endl;
    }

    return 0;
}


