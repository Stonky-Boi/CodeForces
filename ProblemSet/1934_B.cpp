#include <iostream>
using namespace std;

int minimum_coins(int n)
{
    int coins = 0;
    coins += n / 15;
    n %= 15;
    coins += n / 6;
    n %= 6;
    coins += n / 3;
    n %= 3;
    coins += n;
    return coins;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n < 10)
            cout << minimum_coins(n) << endl;
        else if (n < 20)
            cout << min(minimum_coins(n), minimum_coins(n - 10) + 1) << endl;
        else
            cout << min({minimum_coins(n), minimum_coins(n - 10) + 1, minimum_coins(n - 20) + 2}) << endl;
    }
    return 0;
}