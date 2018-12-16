/*input
4 3
10 20 30 40
1 4
1 2
2 3
*/

//
//  main.cpp
//  The Child and Toy
//
//  Created by Nirmaljot Singh Bhasin on 19/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;
const int MAXN = 1003;

lli v[MAXN];
vector< pair<lli, lli> > edge;

int main(int argc, const char * argv[]) {
	lli n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	for (int i = 0; i < m; ++i) {
		lli x, y;
		cin >> x >> y;
		edge.push_back({x, y});
	}
	lli res = 0;
	for (int i = 0; i < edge.size(); ++i) {
		res += min(v[edge[i].first], v[edge[i].second]);
	}
	cout << res << endl;
	return 0;
}
