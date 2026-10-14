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
        vector<int> a(n);
        int base_xor = 0;
        for (int &i : a)
        {
            cin >> i;
            base_xor ^= i;
        }
        cout << ((n % 2 == 0 && base_xor != 0) ? -1 : base_xor) << endl;
    }
    return 0;
}