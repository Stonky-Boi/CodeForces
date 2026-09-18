#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;
        int k = 0;
        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] != '0')
                k++;
        }
        cout << k << endl;
        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] != '0')
                cout << (n[i] - '0') * pow(10, n.size() - 1 - i) << " ";
        }
        cout << endl;
    }
    return 0;
}