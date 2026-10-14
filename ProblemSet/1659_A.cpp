#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r, b;
        cin >> n >> r >> b;
        int quotient = r / (b + 1);
        int remainder = r % (b + 1);
        string s;
        for (int i = 0; i < b; i++)
        {
            s += string(quotient + ((i < remainder ? 1 : 0)), 'R');
            s += "B";
        }
        s += string(quotient, 'R');
        cout << s << endl;
    }
    return 0;
}