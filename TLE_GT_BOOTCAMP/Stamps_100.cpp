#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        bool f = true;
        ll id = -1;
        for (ll i = 0; i < n - 2; i++)
        {
            if (s[i] == '0')
                continue;
            if (s[i] == '1' && f)
            {
                id = i;
                f = false;
            }
        }
        if (id != -1)
        {
            for (ll k = id + 1; k < n; k++)
            {
                s[k] = '0';
            }
        }
        cout << s << endl;
    }
    return 0;
}
