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
        int zeroes = 0, ones = 0;
        for (const char &c : s)
        {
            if (c == '0')
                zeroes++;
            else
                ones++;
        }
        int moves = min(zeroes, ones);
        cout << (moves % 2 == 0 ? "NET" : "DA") << endl;
    }
    return 0;
}