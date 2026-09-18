#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int mishka_wins = 0, chris_wins = 0;
    while (n--)
    {
        int m, c;
        cin >> m >> c;
        if (m > c)
            mishka_wins++;
        if (m < c)
            chris_wins++;
    }
    if (mishka_wins > chris_wins)
        cout << "Mishka" << endl;
    else if (mishka_wins < chris_wins)
        cout << "Chris" << endl;
    else
        cout << "Friendship is magic!^^" << endl;
    return 0;
}