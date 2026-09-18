#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long k;
        cin >> k;
        long long current = 9, length = 1;
        while (k - current * length > 0)
        {
            k -= current * length;
            current *= 10;
            length++;
        }
        string s = to_string(current / 9 + (k - 1) / length);
        long long sum = 0;
        for (int i = 0; i < (k - 1) % length + 1; i++)
            sum += s[i] - '0';
        long long prefix_sum = 0;
        for (int i = 0; i < (int)s.length(); i++)
        {
            int current_digit = s[i] - '0';
            if (current_digit)
            {
                sum += current_digit * (length - 1) * current / 2;
                sum += current_digit * (2 * prefix_sum + current_digit - 1) / 2 * current / 9;
            }
            current /= 10;
            length--;
            prefix_sum += current_digit;
        }
        cout << sum << endl;
    }
    return 0;
}