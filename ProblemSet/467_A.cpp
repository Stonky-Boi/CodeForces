#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int rooms = 0;
    while (n--)
    {
        int p, q;
        cin >> p >> q;
        if (q - p >= 2)
            rooms++;
    }
    cout << rooms << endl;
    return 0;
}