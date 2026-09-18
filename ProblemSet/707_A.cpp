#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    bool color = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char pixel;
            cin >> pixel;
            if (pixel == 'C' || pixel == 'M' || pixel == 'Y')
            {
                color = true;
                break;
            }
        }
    }
    if (color)
        cout << "#Color" << endl;
    else
        cout << "#Black&White" << endl;
    return 0;
}