#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int stones = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            stones++;
    }
    cout << stones << endl;
    return 0;
}