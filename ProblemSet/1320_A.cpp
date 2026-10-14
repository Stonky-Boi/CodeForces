#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> b(n);
    for (int &i : b)
        cin >> i;
    map<int, long long> sum;
    for (int i = 0; i < n; i++)
        sum[i - b[i]] += b[i];
    long long maximum = 0;
    for (const auto &[_, s] : sum)
        maximum = max(maximum, s);
    cout << maximum << endl;
    return 0;
}