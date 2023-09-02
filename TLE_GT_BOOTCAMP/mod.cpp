#include <iostream>

using namespace std;

// Function to calculate the modular inverse of 'a' modulo 'm'
long long modularInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

int main() {
    long long P, Q;
    const long long MOD = 1000000007; // (10^9 + 7)

    // Read the values of P and Q
    cout << "Enter the values of P and Q: ";
    P = 5, Q = 7;

    // Calculate the modular inverse of Q modulo (10^9 + 7)
    long long Q_inv = modularInverse(Q, MOD);

    // Calculate P * Q^-1 modulo (10^9 + 7)
    long long result = (P * Q_inv) % MOD;

    // Output the result
    cout << "Result: " << result << endl;

    return 0;
}
