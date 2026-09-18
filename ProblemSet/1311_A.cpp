#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b;
        cin >> a >> b;
        int minimum_moves;
        if (a > b)
        {
            if ((a - b) % 2 == 0)
                minimum_moves = 1;
            else
                minimum_moves = 2;
        }
        else if (a < b)
        {
            if ((b - a) % 2 == 0)
                minimum_moves = 2;
            else
                minimum_moves = 1;
        }
        else
            minimum_moves = 0;
        cout << minimum_moves << endl;
    }
    return 0;
}