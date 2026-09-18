#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long int maximum_consecutive_ones = 0, ones_in_row = 0;
        bool zero_found = false;
        for (long long int i = 0; i < 2 * s.size(); i++)
        {
            if (s[i % s.size()] == '1')
                ones_in_row++;
            else
            {
                zero_found = true;
                ones_in_row = 0;
            }
            maximum_consecutive_ones = (maximum_consecutive_ones > ones_in_row) ? maximum_consecutive_ones : ones_in_row;
        }
        long long int area = zero_found ? ((maximum_consecutive_ones + 1) / 2) * ((maximum_consecutive_ones + 2) / 2) : (s.size() * s.size());
        cout << area << endl;
    }
    return 0;
}