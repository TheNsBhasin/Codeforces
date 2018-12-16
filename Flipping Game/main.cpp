/*input
1
1
*/

//
//  main.cpp
//  Flipping Game
//
//  Created by Nirmaljot Singh Bhasin on 19/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 102;

lli a[MAXN], b[MAXN];

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	lli ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == 0) {
			b[i] = 1;
		} else {
			b[i] = -1;
			++ans;
		}
	}
	lli curr_sum = 0;
	lli maxi_sum = LONG_MIN;
	for (int i = 0; i < n; ++i) {
		curr_sum += b[i];
		maxi_sum = max(maxi_sum, curr_sum);
		if (curr_sum < 0) {
			curr_sum = 0;
		}
	}
	ans += maxi_sum;
	cout << ans << endl;
	return 0;
}
