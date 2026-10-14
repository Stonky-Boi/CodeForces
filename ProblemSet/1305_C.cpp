#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    if (n > m)
    {
        cout << 0 << endl;
        return 0;
    }
    long long product = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long diff = abs(a[i] - a[j]) % m;
            product = (product * diff) % m;
        }
    }
    cout << product << endl;
    return 0;
}