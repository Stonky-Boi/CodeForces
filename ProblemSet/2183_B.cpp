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
        vector<int> frequency(n + 2, 0);
        for (auto &i : a)
        {
            cin >> i;
            if (i < n + 2)
                frequency[i]++;
        }
        int global_mex = 0;
        while (frequency[global_mex] > 0)
            global_mex++;
        int result = min(global_mex, k - 1);
        cout << result << endl;
    }
    return 0;
}