#include <iostream>
using namespace std;

int main()
{
    int Y, W;
    cin >> Y >> W;
    int favourable_choices = 6 - max(Y, W) + 1;
    switch (favourable_choices)
    {
    case 0:
        cout << "0/1" << endl;
        break;
    case 1:
        cout << "1/6" << endl;
        break;
    case 2:
        cout << "1/3" << endl;
        break;
    case 3:
        cout << "1/2" << endl;
        break;
    case 4:
        cout << "2/3" << endl;
        break;
    case 5:
        cout << "5/6" << endl;
        break;
    case 6:
        cout << "1/1" << endl;
        break;
    default:
        break;
    }
    return 0;
}