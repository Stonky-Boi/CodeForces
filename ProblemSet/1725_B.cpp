#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> p(n);
    for (int &i : p)
        cin >> i;
    int wins = 0;
    sort(p.begin(), p.end(), greater<int>());
    for (const int &i : p)
    {
        if (i > d)
        {
            wins++;
            n--;
        }
        else if (1ll * i * n > d)
        {
            wins++;
            int used = d / i + 1;
            n -= used;
        }
        else
            break;
    }
    cout << wins << endl;
    return 0;
}