#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool hard = false;
    while (n--)
    {
        int opinion;
        cin >> opinion;
        if (opinion == 1)
        {
            hard = true;
            break;
        }
    }
    if (hard)
        cout << "HARD" << endl;
    else
        cout << "EASY" << endl;
    return 0;
}