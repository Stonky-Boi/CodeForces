#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    bool sorted = true;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] > s[i])
        {
            sorted = false;
            cout << "YES" << endl;
            cout << i << " " << i + 1 << endl;
            break;
        }
    }
    if (sorted)
        cout << "NO" << endl;
    return 0;
}