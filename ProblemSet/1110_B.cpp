#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> b(n);
    for (int &i : b)
        cin >> i;
    vector<int> gaps(n - 1);
    for (int i = 1; i < n; i++)
        gaps[i - 1] = b[i] - b[i - 1] - 1;
    sort(gaps.begin(), gaps.end());
    long long length = n;
    for (int i = 0; i < n - k; i++)
        length += gaps[i];
    cout << length << endl;
    return 0;
}