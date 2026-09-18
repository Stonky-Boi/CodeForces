#include <iostream>
using namespace std;

// // my solution
// int main()
// {
//     int t;
//     cin >> t;
//     vector<int> primes;
//     vector<bool> is_prime(10001, true);
//     is_prime[0] = is_prime[1] = false;
//     for (int i = 2; i * i <= 10000; i++)
//         if (is_prime[i])
//             for (int j = i * i; j <= 10000; j += i)
//                 is_prime[j] = false;
//     for (int i = 2; i <= 10000; i++)
//         if (is_prime[i])
//             primes.push_back(i);
//     while (t--)
//     {
//         long n;
//         long long k;
//         cin >> n >> k;
//         long long a[n];
//         for (int i = 0; i < n; i++)
//             cin >> a[i];
//         long long p = -1;
//         for (auto prime : primes)
//         {
//             if (prime > k + 1)
//                 break;
//             if (k % prime != 0)
//             {
//                 p = prime;
//                 break;
//             }
//         }
//         if (p == -1)
//             p = k + 1;
//         for (int i = 0; i < n; i++)
//             for (int m = 0; m < p; m++)
//                 if ((a[i] + m * k) % p == 0)
//                 {
//                     a[i] += m * k;
//                     break;
//                 }
//         for (int i = 0; i < n; i++)
//             cout << a[i] << " ";
//         cout << endl;
//     }
//     return 0;
// }

// editorial solution
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long n;
        long long k;
        cin >> n >> k;
        long long a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] += (a[i] % (k + 1)) * k;
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}