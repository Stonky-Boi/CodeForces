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
        cout << (n % 3 == 0 ? "Second" : "First") << endl;
    }
    return 0;
}