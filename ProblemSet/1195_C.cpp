#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h1(n), h2(n);
    for (int &i : h1)
        cin >> i;
    for (int &i : h2)
        cin >> i;
    vector<long long> dp1(n + 1, 0), dp2(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        dp1[i] = max(dp1[i - 1], dp2[i - 1] + h1[i - 1]);
        dp2[i] = max(dp2[i - 1], dp1[i - 1] + h2[i - 1]);
    }
    cout << max(dp1[n], dp2[n]) << endl;
    return 0;
}