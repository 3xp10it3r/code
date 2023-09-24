#include <iostream>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

bool canSatisfyConditions(ll N)
{
    if (N <= 2)
        return false;

    ll lcm_result = 1;
    ll sum_result = N * (N + 1) / 2;

    for (ll i = 2; i <= N; i++)
    {
        lcm_result = lcm(lcm_result, i);

        // If the LCM exceeds N, break early to avoid unnecessary calculations.
        if (lcm_result > N)
            break;
    }

    return lcm_result == sum_result;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        ll N;
        cin >> N;

        if (canSatisfyConditions(N))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
