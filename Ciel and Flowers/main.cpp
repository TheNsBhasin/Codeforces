/*input
3 6 9
*/

//
//  main.cpp
//  Ciel and Flowers
//
//  Created by Nirmaljot Singh Bhasin on 21/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	lli r, g, b;
	cin >> r >> g >> b;
	lli ans = (r / 3 + g / 3 + b / 3);
	if (r > 0 && g > 0 && b > 0) {
		ans = max(ans, ((r - 1) / 3 + (g - 1) / 3 + (b - 1) / 3) + 1);
	}
	if (r > 1 && g > 1 && b > 1) {
		ans = max(ans, ((r - 2) / 3 + (g - 2) / 3 + (b - 2) / 3) + 2);
	}
	cout << ans << endl;
	return 0;
}
