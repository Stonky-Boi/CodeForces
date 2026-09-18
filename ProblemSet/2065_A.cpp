#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string w;
        cin >> w;
        for (int i = 0; i < w.size() - 2; i++)
            cout << w[i];
        cout << "i" << endl;
    }
    return 0;
}