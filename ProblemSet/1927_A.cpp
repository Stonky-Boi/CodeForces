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
        string s;
        cin >> s;
        int start = s.find('B');
        int end = s.rfind('B');
        cout << (end - start + 1) << endl;
    }
    return 0;
}