/*input
rrlll
*/

//
//  main.cpp
//  Escape from Stones
//
//  Created by Nirmaljot Singh Bhasin on 19/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 1000006;

lli ans[MAXN];

int main(int argc, const char * argv[]) {
	string s;
	cin >> s;
	lli n = s.length();
	lli low = 1, high = n;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'l') {
			ans[high--] = (i + 1);
		} else {
			ans[low++] = (i + 1);
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
