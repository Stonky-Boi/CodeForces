#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int side_length;
        if (2 * min(a, b) >= max(a, b))
            side_length = 2 * min(a, b);
        else
            side_length = max(a, b);
        cout << side_length * side_length << endl;
    }
    return 0;
}