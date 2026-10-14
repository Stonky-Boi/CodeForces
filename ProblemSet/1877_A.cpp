#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n - 1);
        int efficiency = 0;
        for (int &i : a)
        {
            cin >> i;
            efficiency -= i;
        }
        cout << efficiency << endl;
    }
    return 0;
}