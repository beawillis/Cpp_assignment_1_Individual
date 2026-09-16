#include <iostream>
#include <iomanip>

using namespace std;

// This program calculates tax based on an individual's residence status
// and taxable income. It applies different tax rate brackets depending
// on whether the user is a resident or a non-resident.
int main()
{
    // Residence status: 0 for resident, 1 for non-resident.
    int residenceStatus;

    // The income amount from which tax is calculated.
    double taxableIncome;

    // Ask the user to state their residence status.
    cout << "(0-Resident, 1-Non-resident)" << endl;
    cout << "Enter the residence status: ";
    cin >> residenceStatus;

    // Ask for the taxable income value.
    cout << "Enter the taxable income: ";
    cin >> taxableIncome;

    // This variable will hold the computed tax amount.
    double tax = 0.0;

    // Tax policy for residents.
    if (residenceStatus == 0)
    {
        // Tax-free income threshold for residents.
        if (taxableIncome <= 2820000)
        {
            tax = 0;
        }
        // Lower taxed interval for residents.
        else if (taxableIncome <= 4020000)
        {
            tax = (taxableIncome - 2820000) * 0.10;
        }
        // Middle tax bracket for residents.
        else if (taxableIncome <= 4920000)
        {
            tax = (taxableIncome - 4020000) * 0.20 + 120000;
        }
        // Higher tax bracket for residents.
        else if (taxableIncome <= 120000000)
        {
            tax = (taxableIncome - 4920000) * 0.30 + 300000;
        }
        // Very high income bracket for residents.
        else
        {
            tax = (taxableIncome - 4920000) * 0.30 + 300000
                + (taxableIncome - 120000000) * 0.10;
        }
    }
    // Tax policy for non-residents.
    else if (residenceStatus == 1)
    {
        // Lower income for non-residents is taxed at 10%.
        if (taxableIncome <= 2820000)
        {
            tax = taxableIncome * 0.10;
        }
        else if (taxableIncome <= 4020000)
        {
            tax = taxableIncome * 0.10;
        }
        // Middle bracket for non-residents.
        else if (taxableIncome <= 4920000)
        {
            tax = (taxableIncome - 4020000) * 0.20 + 402000;
        }
        // Higher bracket for non-residents.
        else if (taxableIncome <= 120000000)
        {
            tax = (taxableIncome - 4920000) * 0.30 + 582000;
        }
        // Very high income bracket for non-residents.
        else
        {
            tax = (taxableIncome - 4920000) * 0.30 + 582000
                + (taxableIncome - 120000000) * 0.10;
        }
    }
    else
    {
        // Reject invalid residence codes.
        cout << "Invalid residence status entered." << endl;
        return 1;
    }

    // Output the final tax amount without decimals.
    cout << fixed << setprecision(0);
    cout << "Tax is " << tax << endl;

    return 0;
}
