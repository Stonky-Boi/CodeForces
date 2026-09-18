#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int police_strength = 0, untreated_crimes = 0;
    while (n--)
    {
        int event;
        cin >> event;
        if (event == -1 && police_strength > 0)
            police_strength--;
        else if (event == -1)
            untreated_crimes++;
        else
            police_strength += event;
    }
    cout << untreated_crimes << endl;
    return 0;
}