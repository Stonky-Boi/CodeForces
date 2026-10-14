#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        sort(a.begin(), a.end());
        int curr_block = 1, max_block = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] <= k)
                curr_block++;
            else
            {
                max_block = max(max_block, curr_block);
                curr_block = 1;
            }
        }
        cout << n - max(max_block, curr_block) << endl;
    }
    return 0;
}