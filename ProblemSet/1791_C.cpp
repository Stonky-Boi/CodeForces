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
        int l = 0, r = s.size() - 1;
        while (l < r && (s[l] - '0') + (s[r] - '0') == 1)
        {
            l++;
            r--;
        }
        cout << r - l + 1 << endl;
    }
    return 0;
}