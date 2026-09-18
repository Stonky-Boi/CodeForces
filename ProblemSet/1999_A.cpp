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
        int s = 0;
        for (int i = 0; i < n.size(); i++)
            s += n[i] - '0';
        cout << s << endl;
    }
    return 0;
}