#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> freq(1e6 + 1, 0);
    long long sum = 0;
    for (int &i : a)
    {
        cin >> i;
        sum += i;
        freq[i]++;
    }
    vector<int> j;
    for (int i = 0; i < n; i++)
    {
        long long target = sum - a[i];
        if (target % 2 == 1 || target > 2e6)
            continue;
        target /= 2;
        if (freq[target] > (target == a[i] ? 1 : 0))
            j.push_back(i + 1);
    }
    cout << j.size() << endl;
    for (const int &i : j)
        cout << i << " ";
    cout << endl;
    return 0;
}