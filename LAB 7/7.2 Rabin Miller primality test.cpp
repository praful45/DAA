#include <bits/stdc++.h>
using namespace std;

// Modular exponentiation
long long modpow(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Miller-Rabin primality test
bool isPrime(long long n, int k) {
    // Corner cases
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    // Find d such that d*(2^r) = n-1
    long long d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }

    // Repeat the test k times
    for (int i = 0; i < k; i++) {
        // Choose a random witness number a in the range [2, n-2]
        long long a = rand() % (n - 3) + 2;

        // Compute x = a^d mod n
        long long x = modpow(a, d, n);

        // If x == 1 or x == n-1, n is likely to be prime
        if (x == 1 || x == n - 1) {
            continue;
        }

        // Repeat n-1 times
        for (int j = 1; j <= n - 1; j++) {
            x = (x * x) % n;
            if (x == n - 1) {
                break;
            }
            if (x == 1) {
                return false;
            }
        }

        if (x != n - 1) {
            return false;
        }
    }

    // If n passes all the tests, it is likely to be prime
    return true;
}

int main() {
    srand(time(NULL));

    long long n;
    int k;
    cout << "Enter a number to test for primality: ";
    cin >> n;
    cout << "Enter the number of iterations (k): ";
    cin >> k;

    if (isPrime(n, k)) {
        cout << n << " is likely to be prime." << endl;
    } else {
        cout << n << " is composite." << endl;
    }

    return 0;
}


