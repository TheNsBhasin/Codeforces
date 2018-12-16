/*input
2
2
-1
*/

//
//  main.cpp
//  Party
//
//  Created by Nirmaljot Singh Bhasin on 20/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 2003;

lli p[MAXN], h[MAXN];

lli height(lli i) {
	if (h[i] != -1) {
		return h[i];
	}
	h[i] = height(p[i]) + 1;
	return h[i];
}

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		if (p[i] == -1) {
			p[i] = 0;
		}
	}
	fill(h + 1, h + n + 1, -1);
	lli maxi = 0;
	for (int i = 1; i <= n; ++i) {
		maxi = max(maxi, height(i));
	}
	cout << maxi << endl;
	return 0;
}
