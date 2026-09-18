#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &i : a)
        cin >> i;
    vector<int> bit_count(21, 0);
    for (int i = 0; i < n; i++)
        for (int b = 0; b <= 20; b++)
            bit_count[b] += (a[i] >> b) & 1;
    vector<long long> final_array(n, 0);
    for (int b = 0; b <= 20; b++)
        for (int i = n - bit_count[b]; i < n; i++)
            final_array[i] |= (1LL << b);
    long long square_sum = 0;
    for (auto i : final_array)
        square_sum += i * i;
    cout << square_sum << endl;
    return 0;
}