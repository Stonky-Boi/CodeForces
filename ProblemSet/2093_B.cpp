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
        bool non_zero = false;
        int zero_count = 0;
        for (int i = n.size() - 1; i >= 0; i--)
        {
            if (n[i] != '0')
                non_zero = true;
            else if (non_zero)
                zero_count++;
        }
        cout << n.size() - zero_count - 1 << endl;
    }
    return 0;
}