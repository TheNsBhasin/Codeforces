/*input
2500 2500 8
1 549 1279 1263 2189
1 303 795 1888 2432
1 2227 622 2418 1161
3 771 2492 1335 1433
1 2017 2100 2408 2160
3 48 60 798 729
1 347 708 1868 792
3 1940 2080 377 1546
*/

//
//  main.cpp
//  The Untended Antiquity
//
//  Created by Nirmaljot Singh Bhasin on 27/01/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <climits>
#include <map>
using namespace std;

typedef long long int lli;
const int MAXN = 2501;

map<lli, lli> mp;
lli bit[MAXN][MAXN];

lli getRand() {
	return RAND_MAX * rand() * rand();
}

lli idx(lli r1, lli c1, lli r2, lli c2) {
	return (r1 << 32) | (c1 << 24) | (r2 << 12) | c2;
}

void add(lli x, lli y, lli val) {
	for (lli i = x; i < MAXN; i += (i & -i)) {
		for (lli j = y; j < MAXN; j += (j & -j)) {
			bit[i][j] ^= val;
		}
	}
}

lli get(lli x, lli y) {
	lli ret = 0;
	for (lli i = x; i > 0; i -= (i & -i)) {
		for (lli j = y; j > 0; j -= (j & -j)) {
			ret ^= bit[i][j];
		}
	}
	return ret;
}

int main(int argc, const char * argv[]) {
	lli n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < q; ++i) {
		lli t, r1, c1, r2, c2, rnd;
		cin >> t >> r1 >> c1 >> r2 >> c2;
		if (t == 1) {
			rnd = getRand();
			mp[idx(r1, c1, r2, c2)] = rnd;
		} else if (t == 2) {
			rnd = mp[idx(r1, c1, r2, c2)];
		} else {
			cout << ((get(r1, c1) == get(r2, c2)) ? "Yes" : "No") << endl;;
			continue;
		}
		add(r1, c1, rnd);
		add(r1, c2 + 1, rnd);
		add(r2 + 1, c1, rnd);
		add(r2 + 1, c2 + 1, rnd);
	}
	return 0;
}
