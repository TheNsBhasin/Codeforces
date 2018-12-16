/*input
1 3 3
*/

//
//  main.cpp
//  Beautiful Numbers
//
//  Created by Nirmaljot Singh Bhasin on 23/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

const int MAXN = 1000006;
const int MOD = 1000000007;

lli fact[MAXN];

void preprocess() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

lli power(lli a, lli n, lli mod) {
    lli res = 1;
    a = a % mod;
    while (n > 0) {
        if (n & 1) {
            res = (res * a) % mod;
        }

        n = n >> 1;
        a = (a * a) % mod;
    }

    return res;
}

lli C(lli n, lli i) {
    lli res = fact[n] % MOD;
    lli div = (fact[n - i] * fact[i]) % MOD;
    lli inv = power(div, MOD - 2, MOD);

    return (res * inv) % MOD;
}

bool check(lli num, lli a, lli b) {
    while (num > 0) {
        lli digit = num % 10;
        if (digit != a && digit != b) {
            return false;
        }
        num /= 10;
    }

    return true;
}

lli solve(lli a, lli b, lli n) {
    lli res = 0;

    for (int i = 0; i <= n; ++i) {
        lli sum = (a * i) + ((n - i) * b);
        if (check(sum, a, b)) {
            res = (res + C(n, i)) % MOD;
        }
    }

    return res % MOD;
}

int main(int argc, const char *argv[]) {
    preprocess();
    int a, b, n;
    cin >> a >> b >> n;
    cout << solve(a, b, n) << endl;
    return 0;
}
