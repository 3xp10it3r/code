#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        ll x = a1 - a2 + b1 - b2;
        if (x < 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
