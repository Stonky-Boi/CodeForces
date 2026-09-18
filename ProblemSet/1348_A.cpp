#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, pile_1 = 0, pile_2 = 0;
        cin >> n;
        for (int i = n / 2; i < n; i++)
            pile_1 += pow(2, i);
        pile_2 = pow(2, n);
        for (int i = 1; i < n / 2; i++)
            pile_2 += pow(2, i);
        cout << abs(pile_1 - pile_2) << endl;
    }
    return 0;
}