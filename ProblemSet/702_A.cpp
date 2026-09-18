#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int max_length = 1, current_length = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] > a[i])
        {
            current_length++;
            if (current_length > max_length)
                max_length = current_length;
        }
        else
            current_length = 1;
    }
    cout << max_length << endl;
    return 0;
}