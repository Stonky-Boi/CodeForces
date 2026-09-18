#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int a, b, c, elevator_1, elevator_2;
        cin >> a >> b >> c;
        elevator_1 = a - 1;
        elevator_2 = max(b, c) - min(b, c) + c - 1;
        if (elevator_1 < elevator_2)
            cout << "1" << endl;
        else if (elevator_1 > elevator_2)
            cout << "2" << endl;
        else
            cout << "3" << endl;
    }
    return 0;
}