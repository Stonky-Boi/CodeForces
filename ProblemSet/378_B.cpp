#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    string s1 = "", s2 = "";
    for (int i = 0; i < n / 2; i++)
    {
        s1 += '1';
        s2 += '1';
    }
    for (int i = n / 2; i < n; i++)
    {
        s1 += '0';
        s2 += '0';
    }
    int i = 0, j = 0;
    for (int k = 0; k < n; k++)
    {
        if (a[i] < b[j])
        {
            s1[i] = '1';
            i++;
        }
        else
        {
            s2[j] = '1';
            j++;
        }
    }
    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}