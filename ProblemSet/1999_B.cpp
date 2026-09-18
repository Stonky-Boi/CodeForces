#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a1, a2, b1, b2, games = 0;
        cin >> a1 >> a2 >> b1 >> b2;
        if ((a1 > b1) && (a2 > b2))
            games += 2;
        if ((a1 > b2) && (a2 > b1))
            games += 2;
        if ((a1 > b1) && (a2 == b2))
            games += 2;
        if ((a1 == b1) && (a2 > b2))
            games += 2;
        if ((a1 > b2) && (a2 == b1))
            games += 2;
        if ((a1 == b2) && (a2 > b1))
            games += 2;
        cout << games << endl;
    }
    return 0;
}