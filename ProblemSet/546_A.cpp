#include <iostream>
using namespace std;

int main()
{
    int k, w;
    long long int n;
    cin >> k >> n >> w;
    long long int money_borrowed = 0;
    for (int i = 1; i < w + 1; i++)
        money_borrowed += i * k;
    if (money_borrowed > n)
        cout << money_borrowed - n << endl;
    else
        cout << "0" << endl;
    return 0;
}