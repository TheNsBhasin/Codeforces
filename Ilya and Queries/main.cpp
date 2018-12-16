/*input
#..###
5
1 3
5 6
1 5
3 6
3 4
*/

//
//  main.cpp
//  Ilya and Queries
//
//  Created by Nirmaljot Singh Bhasin on 20/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli pre[MAXN];

int main(int argc, const char * argv[]) {
	string s;
	cin >> s;
	for (int i = 1; i < s.length(); ++i) {
		pre[i] = pre[i - 1] + (s[i - 1] == s[i]);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		lli l, r;
		cin >> l >> r;
		cout << pre[r - 1] - pre[l - 1] << endl;
	}
	return 0;
}
