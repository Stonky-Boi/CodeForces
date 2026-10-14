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
        int sum = 0, max_value = 0;
        for (int &i : a)
        {
            cin >> i;
            sum += i;
            max_value = max(max_value, i);
        }
        cout << (max_value > sum / 2 || sum % 2 == 1 ? "T" : "HL") << endl;
    }
    return 0;
}