#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> zeroes(n, 0);
        int digits = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            while (a[i] % 10 == 0)
            {
                zeroes[i]++;
                digits++;
                a[i] /= 10;
            }
            while (a[i] > 0)
            {
                digits++;
                a[i] /= 10;
            }
        }
        sort(zeroes.begin(), zeroes.end(), greater<int>());
        for (int i = 0; i < n; i += 2)
            digits -= zeroes[i];
        cout << (digits > m ? "Sasha" : "Anna") << endl;
    }
    return 0;
}