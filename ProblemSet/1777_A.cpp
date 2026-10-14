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
        int operations = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] % 2 == a[i] % 2)
                operations++;
        }
        cout << operations << endl;
    }
    return 0;
}