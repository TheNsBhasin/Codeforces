/*input
6 2 9
*/

//
//  main.cpp
//  The Intriguing Obsession
//
//  Created by Nirmaljot Singh Bhasin on 26/01/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MOD = 998244353;
const int MAXN = 5001;

lli fact[MAXN], inv_fact[MAXN];

lli power(lli a, lli n) {
	lli ret = 1;
	while (n > 0) {
		if (n & 1) {
			ret = (ret * a) % MOD;
		}
		a = (a * a) % MOD;
		n >>= 1;
	}
	return ret;
}

void preprocess() {
	fact[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
}

lli C(lli n, lli r) {
	lli ret = (fact[n] * (power((fact[n - r] * fact[r]) % MOD, MOD - 2)) % MOD) % MOD;
	return ret % MOD;
}

lli solve(lli n, lli m) {
	lli sum = 0;
	for (int k = 0; k <= min(n, m); ++k) {
		sum += (((C(n , k) * C(m, k)) % MOD) * fact[k]) % MOD;
		sum %= MOD;
	}
	return sum % MOD;
}

int main(int argc, const char * argv[]) {
	preprocess();
	lli a, b, c;
	cin >> a >> b >> c;
	lli ans = solve(a, b);
	ans = (ans * solve(b, c)) % MOD;
	ans = (ans * solve(c, a)) % MOD;
	cout << ans << endl;
	return 0;
}
