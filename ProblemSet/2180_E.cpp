#include <iostream>
using namespace std;

long long least_set_bit(long long value)
{
    return value & -value;
}

bool is_power_of_two(long long value)
{
    return value == least_set_bit(value);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long left, right;
        cin >> left >> right;
        long long highest_bit = 1LL << 60;
        while (highest_bit > 0 && ((left & highest_bit) == (right & highest_bit)))
        {
            if (left & highest_bit)
            {
                left -= highest_bit;
                right -= highest_bit;
            }
            highest_bit >>= 1;
        }
        long long valid_values;
        if (left > 0 && is_power_of_two(left + right + 1))
            valid_values = 2 * min(least_set_bit(left), least_set_bit(right + 1)) - 1;
        else if (left > 0)
            valid_values = min(least_set_bit(left), least_set_bit(right + 1)) - 1;
        else
            valid_values = least_set_bit(right + 1) - 1;
        cout << valid_values << endl;
    }
    return 0;
}