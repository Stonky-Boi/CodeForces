#include <iostream>
using namespace std;

int main()
{
    long long int n, f_of_n = 0;
    cin >> n;
    if (n % 2 == 0)
        f_of_n = n / 2;
    else
        f_of_n = (n - 1) / 2 - n;
    cout << f_of_n << endl;
    return 0;
}