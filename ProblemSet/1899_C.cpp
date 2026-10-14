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
        int max_sum = a[0], curr_sum = a[0];
        for (int i = 1; i < n; i++)
        {
            if ((a[i] & 1) == (a[i - 1] & 1))
                curr_sum = a[i];
            else
                curr_sum = max(0, curr_sum) + a[i];
            max_sum = max(max_sum, curr_sum);
        }
        cout << max_sum << endl;
    }
    return 0;
}