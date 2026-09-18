#include <iostream>
using namespace std;

int main()
{
    int n, p;
    cin >> n;
    double orange = 0, water = 0;
    while (n--)
    {
        cin >> p;
        orange += p;
        water += 100;
    }
    cout << orange * 100 / water << endl;
    return 0;
}