#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int residenceStatus;
    double taxableIncome;

    cout << "(0-Resident, 1-Non-resident)" << endl;
    cout << "Enter the residence status: ";
    cin >> residenceStatus;

    cout << "Enter the taxable income: ";
    cin >> taxableIncome;

    double tax = 0.0;

    if (residenceStatus == 0)
    {
        if (taxableIncome <= 2820000)
        {
            tax = 0;
        }
        else if (taxableIncome <= 4020000)
        {
            tax = (taxableIncome - 2820000) * 0.10;
        }
        else if (taxableIncome <= 4920000)
        {
            tax = (taxableIncome - 4020000) * 0.20 + 120000;
        }
        else if (taxableIncome <= 120000000)
        {
            tax = (taxableIncome - 4920000) * 0.30 + 300000;
        }
        else
        {
            tax = (taxableIncome - 4920000) * 0.30 + 300000
                + (taxableIncome - 120000000) * 0.10;
        }
    }
    else if (residenceStatus == 1)
    {
        if (taxableIncome <= 2820000)
        {
            tax = taxableIncome * 0.10;
        }
        else if (taxableIncome <= 4020000)
        {
            tax = taxableIncome * 0.10;
        }
        else if (taxableIncome <= 4920000)
        {
            tax = (taxableIncome - 4020000) * 0.20 + 402000;
        }
        else if (taxableIncome <= 120000000)
        {
            tax = (taxableIncome - 4920000) * 0.30 + 582000;
        }
        else
        {
            tax = (taxableIncome - 4920000) * 0.30 + 582000
                + (taxableIncome - 120000000) * 0.10;
        }
    }
    else
    {
        cout << "Invalid residence status entered." << endl;
        return 1;
    }

    cout << fixed << setprecision(0);
    cout << "Tax is " << tax << endl;

    return 0;
}
