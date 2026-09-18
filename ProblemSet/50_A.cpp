#include <iostream>
using namespace std;

int main()
{
    int m, n;
    int dominoes;
    cin >> m >> n;
    if (m % 2 == 0 || n % 2 == 0)
        dominoes = n * m / 2;
    else
    {
        n--;
        dominoes = n * m / 2;
        dominoes += m / 2;
    }
    cout << dominoes << endl;
    return 0;
}