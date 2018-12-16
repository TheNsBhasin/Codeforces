/*input
2000 1250 176 130
*/

//
//  main.cpp
//  Contest
//
//  Created by Nirmaljot Singh Bhasin on 15/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	double s1 = max((3.0 * a) / 10.0, a - ((a / 250.0) * c));
	double s2 = max((3.0 * b) / 10.0, b - ((b / 250.0) * d));
	if (s1 > s2) {
		cout << "Misha" << endl;
	} else if (s2 > s1) {
		cout << "Vasya" << endl;
	} else {
		cout << "Tie" << endl;
	}
	return 0;
}
