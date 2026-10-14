#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int zeroes = 0;
        for (const char &c : s)
        {
            if (c == '0')
                zeroes++;
        }
        cout << (zeroes == 1 || zeroes % 2 == 0 ? "BOB" : "ALICE") << endl;
    }
    return 0;
}