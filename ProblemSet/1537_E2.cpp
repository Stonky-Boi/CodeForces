#include <iostream>
using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    int prefix = 1;
    for (int i = 1; i < n; i++)
    {
        char curr = s[i], best = s[i % prefix];
        if (curr < best)
            prefix = i + 1;
        else if (curr > best)
            break;
    }
    for (int i = 0; i < k; i++)
        cout << s[i % prefix];
    cout << endl;
    return 0;
}