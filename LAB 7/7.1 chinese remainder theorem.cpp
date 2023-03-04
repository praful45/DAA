//7.1 Write a program to implement the Chinese Remainder Theorem to solve any number of equations.

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}


int findMinX(vector<int>& a, vector<int>& m) {
    int M = 1;
    for (int i = 0; i < (int)m.size(); i++) {
        M = M * m[i];
    }

    int x = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        int Mi = M / m[i];
        int Mi_inv = 0;
        for (int j = 1; j < m[i]; j++) {
            if ((Mi * j) % m[i] == 1) {
                Mi_inv = j;
                break;
            }
        }
        x += a[i] * Mi * Mi_inv;
    }

    return x % M;
}



int main() {
    int n; // number of equations
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<int> a(n); // remainder values
    vector<int> m(n); // mod values

    cout << "Enter the remainder and mod values for each equation:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Equation " << i+1 << ": ";
        cin >> a[i] >> m[i];
    }
    
    cout << "\nThe equations are: \n";
    for(int i=0; i < n; i++)
        cout<< " x = " << a[i] <<" ( MOD " << m[i] << ")" << endl;

    int x = findMinX(a, m);

    cout << "\nThe solution is: " << x << endl;



    return 0;
}
