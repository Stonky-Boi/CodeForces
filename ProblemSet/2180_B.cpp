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
        string a[n];
        for (auto &i : a)
            cin >> i;
        string result;
        for (int i = 0; i < n; i++)
            result = min(result + a[i], a[i] + result);
        cout << result << endl;
    }
    return 0;
}