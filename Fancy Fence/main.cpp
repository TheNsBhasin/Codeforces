/*input
3
30
60
90
*/

//
//  main.cpp
//  Fancy Fence
//
//  Created by Nirmaljot Singh Bhasin on 15/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		lli a;
		cin >> a;
		if (360 % (180 - a) == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
    return 0;
}
