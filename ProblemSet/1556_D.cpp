#include <iostream>
#include <vector>
using namespace std;

int ask(string s, int a, int b)
{
    cout << s << ' ' << a << ' ' << b << endl;
    int res;
    cin >> res;
    return res;
}

int sum(int a, int b)
{
    int and_result = ask("and", ++a, ++b);
    int or_result = ask("or", a, b);
    int xor_result = ~and_result & or_result;
    return 2 * and_result + xor_result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a_plus_b = sum(0, 1);
    int a_plus_c = sum(0, 2);
    int b_plus_c = sum(1, 2);
    vector<int> sequence;
    sequence.push_back((a_plus_b + a_plus_c - b_plus_c) / 2);
    sequence.push_back(a_plus_b - sequence[0]);
    sequence.push_back(a_plus_c - sequence[0]);
    for (int i = 3; i < n; i++)
        sequence.push_back(sum(i - 1, i) - sequence.back());
    sort(sequence.begin(), sequence.end());
    cout << "finish " << sequence[k - 1] << endl;
}