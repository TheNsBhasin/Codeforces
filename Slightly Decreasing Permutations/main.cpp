/*input
3 2
*/

//
//  main.cpp
//  Slightly Decreasing Permutations
//
//  Created by Nirmaljot Singh Bhasin on 08/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int n, k;
	cin >> n >> k;
	lli val = k + 1;
	int i;
	for (i = 0; i <= k; ++i) {
		cout << val << " ";
		--val;
	}
	val = k + 1;
	for (; i < n; ++i) {
		++val;
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
