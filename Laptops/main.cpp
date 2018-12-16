/*input
2
1 2
2 1
*/

//
//  main.cpp
//  Laptops
//
//  Created by Nirmaljot Singh Bhasin on 19/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	bool flag = false;
	for (int i = 0; i < n; ++i) {
		lli p, q;
		cin >> p >> q;
		if (p != q) {
			flag = true;
		}
	}
	if (flag) {
		cout << "Happy Alex" << endl;
	} else {
		cout << "Poor Alex" << endl;
	}
	return 0;
}
