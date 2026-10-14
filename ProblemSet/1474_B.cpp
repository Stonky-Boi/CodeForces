#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int MAXN = 30000;
    vector<bool> prime(MAXN + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
                prime[j] = false;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        int p = d + 1;
        while (!prime[p])
            p++;
        int q = p + d;
        while (!prime[q])
            q++;
        cout << 1ll * p * q << endl;
    }
    return 0;
}