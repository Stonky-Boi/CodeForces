#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int prev_positive = 0, prev_negative = 0;
    long long positive = 0, negative = 0;
    for (int &i : a)
    {
        cin >> i;
        int curr_positive, curr_negative;
        if (i > 0)
        {
            curr_positive = prev_positive + 1;
            curr_negative = prev_negative;
        }
        else
        {
            curr_positive = prev_negative;
            curr_negative = prev_positive + 1;
        }
        positive += curr_positive;
        negative += curr_negative;
        prev_positive = curr_positive;
        prev_negative = curr_negative;
    }
    cout << negative << " " << positive << endl;
    return 0;
}