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
        int s[n];
        for (int i = 0; i < n; i++)
            cin >> s[i];
        sort(s, s + n);
        int minimum = 1000;
        for (int i = 0; i < n - 1; i++)
            minimum = min(minimum, s[i + 1] - s[i]);
        cout << minimum << endl;
    }
    return 0;
}