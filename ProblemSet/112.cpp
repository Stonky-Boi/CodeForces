#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << pow(a, b) - pow(b, a) << endl;
    return 0;
}