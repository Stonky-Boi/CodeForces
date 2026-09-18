#include <iostream>
#include <vector>
using namespace std;

int add(int a, int b, int mod)
{
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

using matrix = vector<vector<int>>;

matrix multiply_matrix(const matrix &A, const matrix &B, int state_size, int mod)
{
    matrix result(state_size, vector<int>(state_size, 0));
    matrix B_transpose(state_size, vector<int>(state_size));
    for (int i = 0; i < state_size; i++)
        for (int j = 0; j < state_size; j++)
            B_transpose[i][j] = B[j][i];
    for (int i = 0; i < state_size; i++)
        for (int j = 0; j < state_size; j++)
        {
            unsigned long long sum = 0;
            for (int k = 0; k < state_size; k++)
            {
                sum += (unsigned long long)A[i][k] * B_transpose[j][k];
                if ((k & 15) == 15)
                    sum %= mod;
            }
            result[i][j] = sum % mod;
        }
    return result;
}

matrix matrix_power(matrix base, int exponent, int state_size, int mod)
{
    matrix result(state_size, vector<int>(state_size, 0));
    for (int i = 0; i < state_size; i++)
        result[i][i] = 1;
    while (exponent > 0)
    {
        if (exponent & 1)
            result = multiply_matrix(result, base, state_size, mod);
        base = multiply_matrix(base, base, state_size, mod);
        exponent >>= 1;
    }
    return result;
}

int main()
{
    int n, m, mod;
    cin >> n >> m >> mod;
    int state_size = 2 * m + 1;
    matrix transition(state_size, vector<int>(state_size, 0));
    transition[state_size - 1][state_size - 1] = 1;
    for (int i = 0; i < m; i++)
        for (int flag = 0; flag < 2; flag++)
        {
            int state_index = i * 2 + flag;
            for (int left = (flag ? 0 : i); left <= i; left++)
                for (int right = i; right < m; right++)
                {
                    transition[state_index][state_size - 1] = add(transition[state_index][state_size - 1], 1, mod);
                    for (int j = left; j <= right; j++)
                    {
                        int next_flag = (j == left) ? 1 : 0;
                        int next_state = j * 2 + next_flag;
                        transition[state_index][next_state] = add(transition[state_index][next_state], 1, mod);
                    }
                }
        }
    matrix result = matrix_power(transition, n, state_size, mod);
    cout << result[1][state_size - 1] << endl;
    return 0;
}