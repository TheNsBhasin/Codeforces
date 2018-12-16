/*input
3
4 5 6
*/

//
//  main.cpp
//  T-primes
//
//  Created by Nirmaljot Singh Bhasin on 19/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

typedef long long int lli;
const int MAXN = 1000006;

lli A[MAXN], sp[MAXN];
bool v[MAXN];

void seive() {
	for (lli i = 2; i < MAXN; i += 2) {
		sp[i] = 2;
	}
	for (lli i = 3; i < MAXN; i += 2) {
		if (!v[i]) {
			sp[i] = i;
			for (lli j = i; (j * i) < MAXN; j += 2) {
				if (!v[j * i])	{
					v[j * i] = true;
					sp[j * i] = i;
				}
			}
		}
	}
}

int main(int argc, const char * argv[]) {
	seive();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
		lli a = sqrt(A[i]);
		if (sp[a] * a == A[i]) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
