#include <iostream>
using namespace std;

int main()
{
    long int n, k, q;
    cin >> n >> k >> q;
    long int l[n], r[n], a[q], b[q], frequency[200002] = {0};
    long long int prefix[200002] = {0};
    bool allowed[200002] = {false};
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        frequency[l[i]] += 1;
        frequency[r[i] + 1] -= 1;
    }
    for (int i = 1; i < 200002; i++)
    {
        frequency[i] += frequency[i - 1];
        if (frequency[i] >= k)
            allowed[i] = true;
        prefix[i] = prefix[i - 1] + allowed[i];
    }
    for (int i = 0; i < q; i++)
    {
        cin >> a[i] >> b[i];
        cout << prefix[b[i]] - prefix[a[i] - 1] << endl;
    }
    return 0;
}