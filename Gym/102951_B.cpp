#include <iostream>
using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    int a[N];
    for (auto &x : a)
        cin >> x;
    sort(a, a + N);
    int count = 0, time = 0;
    for (auto x : a)
    {
        if (time + x > X)
            break;
        else
        {
            count++;
            time += x;
        }
    }
    cout << count << endl;
    return 0;
}