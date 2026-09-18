#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int one = 0, zero = 0;
    for (auto c : s)
        if (c == '0')
            zero++;
        else
            one++;
    cout << abs(one - zero) << endl;
    return 0;
}