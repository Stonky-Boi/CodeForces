#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<int> diff(n + 1, 0);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        diff[l - 1]++;
        diff[r]--;
    }
    vector<int> freq(n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += diff[i];
        freq[i] = count;
    }
    sort(a.begin(), a.end());
    sort(freq.begin(), freq.end());
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += 1ll * a[i] * freq[i];
    cout << sum << endl;
    return 0;
}