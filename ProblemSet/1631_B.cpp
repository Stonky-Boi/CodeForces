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
        int count = 1;
        while (count < n)
        {
            if (a[n - count - 1] == a[n - 1])
                count++;
            else
            {
                operations++;
                count *= 2;
            }
        }
        cout << operations << endl;
    }
    return 0;
}