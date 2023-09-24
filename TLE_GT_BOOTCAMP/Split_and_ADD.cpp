#include <iostream>

const int MOD = 1e9 + 7;

long long power(long long base, long long exp)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

long long sumInRange(int N, int L, int R)
{
    if (L == 1 && R == N)
    {
        return power(2, N - 1);
    }
    int M = (L + R) / 2;
    long long left_sum = sumInRange(N / 2, L, M);
    long long right_sum = sumInRange(N / 2, M + 1, R);
    return (left_sum + right_sum) % MOD;
}

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        int N, L, R;
        std::cin >> N >> L >> R;
        long long result = sumInRange(N, L, R);
        std::cout << result << std::endl;
    }

    return 0;
}
