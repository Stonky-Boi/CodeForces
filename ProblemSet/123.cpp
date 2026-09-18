#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int s = 0;
    if ((k == 1) || (k == 2))
        cout << k << endl;
    else
    {
        int fibonacci[k];
        fibonacci[0] = 1;
        fibonacci[1] = 1;
        for (int i = 2; i < k; i++)
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        for (int i = 0; i < k; i++)
            s += fibonacci[i];
        cout << s << endl;
    }
    return 0;
}