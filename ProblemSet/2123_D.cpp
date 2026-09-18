#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n, k, ones = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                ones++;
        if (ones <= k || n < 2 * k)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}