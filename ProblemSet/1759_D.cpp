#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int temp = n;
        int twos = 0, fives = 0;
        while (temp % 2 == 0)
        {
            twos++;
            temp /= 2;
        }
        while (temp % 5 == 0)
        {
            fives++;
            temp /= 5;
        }
        int k = 1;
        while (twos < fives && 1ll * k * 2 <= m)
        {
            k *= 2;
            twos++;
        }
        while (fives < twos && 1ll * k * 5 <= m)
        {
            k *= 5;
            fives++;
        }
        while (1ll * k * 10 <= m)
            k *= 10;
        k *= m / k;
        cout << 1ll * n * k << endl;
    }
    return 0;
}