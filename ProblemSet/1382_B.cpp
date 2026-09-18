#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, ones_count = 0;
        cin >> n;
        bool all_one = true;
        for (int i = 0, a; i < n; i++)
        {
            cin >> a;
            if (all_one && a == 1 && i < n - 1)
                ones_count++;
            if (a != 1)
                all_one = false;
        }
        if (ones_count % 2 == 0)
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
    return 0;
}