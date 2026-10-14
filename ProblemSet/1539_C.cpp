#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    long long k, x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    for (long long &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    vector<long long> gaps;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] > x)
            gaps.push_back((a[i] - a[i - 1] - 1) / x);
    }
    sort(gaps.begin(), gaps.end());
    int groups = gaps.size() + 1;
    for (const long long &i : gaps)
    {
        if (k < i)
            break;
        k -= i;
        groups--;
    }
    cout << groups << endl;
    return 0;
}