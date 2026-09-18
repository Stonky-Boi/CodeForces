#include <iostream>
using namespace std;

void do_swap(int x)
{
    cout << "swap " << x + 1 << endl;
}

int throw_ball(int x)
{
    cout << "throw " << x + 1 << endl;
    int number_of_jumps;
    cin >> number_of_jumps;
    return number_of_jumps;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n] = {0};
        int jumps[n + 2] = {0};
        for (int i = n - 1; i >= 0; i--)
        {
            if (jumps[i + 1] == jumps[i + 2])
                jumps[i] = jumps[i + 1] + 1;
            else
            {
                jumps[i] = throw_ball(i);
                if (jumps[i] == jumps[i + 1] + 1)
                    a[i] = 1;
                else
                    a[i] = 2;
            }
        }
        for (int i = 0; i + 1 < n; i++)
        {
            if (a[i] == 0)
            {
                do_swap(i);
                int jumps_i = throw_ball(i + 1);
                if (jumps_i == jumps[i + 2] + 1)
                    a[i] = 1;
                else
                    a[i] = 2;
            }
        }
        do_swap(n - 2);
        int jumps_last = throw_ball(n - 2);
        if (jumps_last == 2)
            a[n - 1] = 1;
        else
            a[n - 1] = 2;
        cout << "!";
        for (int i = 0; i < n; i++)
            cout << " " << a[i];
        cout << endl;
    }
    return 0;
}