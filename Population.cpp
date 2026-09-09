#include <iostream>

using namespace std;

int main()
{
    const int CURRENT_POPULATION = 312032486;
    const int SECONDS_IN_YEAR = 365 * 24 * 60 * 60;

    int birthsPerYear = SECONDS_IN_YEAR / 7;
    int deathsPerYear = SECONDS_IN_YEAR / 13;
    int immigrantsPerYear = SECONDS_IN_YEAR / 45;

    int population = CURRENT_POPULATION;

    cout << "Population projection for the next five years:\n";

    for (int year = 1; year <= 5; year++)
    {
        population += birthsPerYear - deathsPerYear + immigrantsPerYear;
        cout << "Year " << year << ": " << population << endl;
    }

    return 0;
}


