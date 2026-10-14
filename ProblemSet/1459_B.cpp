#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int locations = (n % 2 == 0) ? (n + 2) * (n + 2) / 4 : (n + 1) * (n + 3) / 2;
    cout << locations << endl;
    return 0;
}