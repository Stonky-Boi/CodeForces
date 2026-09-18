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
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i].first;
            nums[i].second = i + 1;
        }
        sort(nums.begin(), nums.end());
        int minimum = INT_MAX;
        int curr = 0;
        for (int i = 0; i < n - 1; i++)
            if ((nums[i].first ^ nums[i + 1].first) < minimum)
            {
                minimum = (nums[i].first ^ nums[i + 1].first);
                curr = i;
            }
        cout << nums[curr].second << " " << nums[curr + 1].second << " ";
        cout << (nums[curr].first ^ ((1 << k) - 1)) << endl;
    }
    return 0;
}