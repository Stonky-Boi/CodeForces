#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int first_L = -1;
        for (int i = 0; i < n; i++)
            if (s[i] == 'L')
            {
                first_L = i;
                break;
            }
        cout << first_L + 1 << endl;
    }
    return 0;
}