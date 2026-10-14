#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int value = numeric_limits<int>::max();
        for (int &i : a)
        {
            cin >> i;
            value &= i;
        }
        cout << value << endl;
    }
    return 0;
}