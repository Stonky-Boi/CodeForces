#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
    return a;
}

int multiply(int a, int b)
{
    return (long long)a * b % MOD;
}

void add_segment(vector<int> &diff, int left, int right, int value)
{
    diff[left] = add(diff[left], value);
    diff[right] = add(diff[right], -value);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), k(m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : k)
        cin >> i;
    vector<int> left_min(n, -1), right_min(n, n);
    vector<int> stack;
    for (int i = 0; i < n; i++)
    {
        while (!stack.empty() && a[stack.back()] > a[i])
            stack.pop_back();
        if (!stack.empty())
            left_min[i] = stack.back();
        stack.push_back(i);
    }
    stack.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stack.empty() && a[stack.back()] >= a[i])
            stack.pop_back();
        if (!stack.empty())
            right_min[i] = stack.back();
        stack.push_back(i);
    }
    int common_sum = 0;
    vector<int> left_coef(m + 1, 0);
    vector<int> left_const(m + 1, 0);
    vector<int> right_coef(m + 1, 0);
    vector<int> right_const(m + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int count_min = multiply(i - left_min[i], right_min[i] - i);
        int total_subarrays = multiply(i + 1, n - i);
        int not_min = add(total_subarrays, -count_min);
        int ai_inverse = 1, exp = MOD - 2;
        int base = a[i];
        while (exp > 0)
        {
            if (exp & 1)
                ai_inverse = multiply(ai_inverse, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        common_sum = add(common_sum, multiply(not_min, ai_inverse));
        int pos = lower_bound(k.begin(), k.end(), a[i]) - k.begin();
        add_segment(left_coef, 0, pos, multiply(count_min, ai_inverse));
        add_segment(left_const, 0, pos, multiply(count_min, ai_inverse));
        add_segment(right_coef, pos, m, count_min);
        add_segment(right_const, pos, m, multiply(count_min, add(2, -a[i])));
    }
    for (int i = 0; i < m; i++)
    {
        left_coef[i + 1] = add(left_coef[i + 1], left_coef[i]);
        left_const[i + 1] = add(left_const[i + 1], left_const[i]);
        right_coef[i + 1] = add(right_coef[i + 1], right_coef[i]);
        right_const[i + 1] = add(right_const[i + 1], right_const[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int answer = common_sum;
        int total_coef = add(left_coef[i], right_coef[i]);
        int total_const = add(left_const[i], right_const[i]);
        answer = add(answer, multiply(total_coef, k[i]));
        answer = add(answer, total_const);
        cout << answer << endl;
    }
    return 0;
}