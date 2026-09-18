#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x = 0;
    while (n--)
    {
        string statement;
        cin >> statement;
        if (statement[1] == '+')
            x += 1;
        if (statement[1] == '-')
            x -= 1;
    }
    cout << x << endl;
    return 0;
}