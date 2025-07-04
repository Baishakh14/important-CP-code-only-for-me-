/*
Allaih is Almighty
Bismillahhi Rahmanir Rahim
Baishakh
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            // i is a prime factor
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1) {
        // n itself is a prime > sqrt(original n)
        result -= result / n;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << phi(n) << '\n';
    }

    return 0;
}
