#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int positive = 0, negative = 0;
        for (int &i : a)
        {
            cin >> i;
            if (i == 1)
                positive++;
            else
                negative++;
        }
        int operations = 0;
        if (positive < negative)
        {
            operations += (negative - positive + 1) / 2;
            negative -= operations;
        }
        if (negative % 2 == 1)
            operations++;
        cout << operations << endl;
    }
    return 0;
}