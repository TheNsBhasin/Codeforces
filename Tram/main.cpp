/*input
4
0 3
2 5
4 2
4 0
*/

//
//  main.cpp
//  Tram
//
//  Created by Nirmaljot Singh Bhasin on 08/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	lli seats = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		lli a, b;
		cin >> a >> b;
		seats -= a;
		seats += b;
		ans = max(ans, seats);
	}
	cout << ans << endl;
	return 0;
}
