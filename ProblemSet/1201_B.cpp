#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    int maximum = 0;
    for (int &i : a)
    {
        cin >> i;
        sum += i;
        maximum = max(maximum, i);
    }
    bool possible = (sum % 2 == 0) && (2ll * maximum <= sum);
    cout << (possible ? "YES" : "NO") << endl;
    return 0;
}