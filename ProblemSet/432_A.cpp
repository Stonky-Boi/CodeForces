#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int eligible_participants = 0;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        if (5 - y >= k)
            eligible_participants++;
    }
    if (eligible_participants < 3)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << eligible_participants / 3 << endl;
    return 0;
}