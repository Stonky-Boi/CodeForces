#include <iostream>
#include <vector>
#include <set>
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
        set<long long> sums;
        sums.insert(0);
        long long sum = 0;
        bool possible = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += i % 2 == 0 ? a[i] : -a[i];
            if (sums.find(sum) != sums.end())
                possible = true;
            sums.insert(sum);
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}