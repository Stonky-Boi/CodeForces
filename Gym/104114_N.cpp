#include <iostream>
using namespace std;

int main()
{
    long long int n, m;
    cin >> n >> m;
    long long int s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 1; i < n; i++)
    {
        if (s[i] < s[i - 1] - m)
            s[i] = s[i - 1] - m;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] < s[i + 1] - m)
            s[i] = s[i + 1] - m;
    }
    for (int i = 0; i < n; i++)
        cout << s[i] << " ";
    cout << endl;
    return 0;
}