#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string row_1, row_2;
        cin >> row_1;
        cin >> row_2;
        for (int i = 0; i < n; i++)
        {
            if (row_1[i] == 'G')
                row_1[i] = 'B';
            if (row_2[i] == 'G')
                row_2[i] = 'B';
        }
        if (row_1 == row_2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}