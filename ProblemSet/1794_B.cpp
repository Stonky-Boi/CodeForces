#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        for (int &i : a)
        {
            if (i == 1)
                i++;
        }
        for (int i = 1; i < n; i++)
        {
            if (a[i] % a[i - 1] == 0)
                a[i]++;
        }
        for (const int &i : a)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}