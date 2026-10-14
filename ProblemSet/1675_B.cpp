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
        for (int i = n - 2; i >= 0; i--)
        {
            while (a[i] >= a[i + 1] && a[i] > 0)
            {
                a[i] /= 2;
                operations++;
            }
            if (a[i] == 0 && a[i + 1] == 0)
            {
                operations = -1;
                break;
            }
        }
        cout << operations << endl;
    }
    return 0;
}