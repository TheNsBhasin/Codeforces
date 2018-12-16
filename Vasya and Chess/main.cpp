/*input
2
*/

//
//  main.cpp
//  Vasya and Chess
//
//  Created by Nirmaljot Singh Bhasin on 12/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

const int MAXN = 1000006;
const int MOD = 1000000007;

int main(int argc, const char *argv[]) {
    int n;
    cin >> n;
    if (n & 1) {
        cout << "black" << endl;
    } else {
        cout << "white" << endl;
        cout << 1 << " " << 2 << endl;
    }
    return 0;
}
