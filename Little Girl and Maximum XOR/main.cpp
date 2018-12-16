//
//  main.cpp
//  Little Girl and Maximum XOR
//
//  Created by Nirmaljot Singh Bhasin on 13/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 61;

int main(int argc, const char *argv[]) {
    lli l, r;
    cin >> l >> r;
    lli bits = MAXN;
    while (bits >= 0 && !(((l >> bits) & 1) ^ ((r >> bits) & 1))) {
        --bits;
    }   
    lli res = (1ll << (bits + 1)) - 1; 
    cout << res << endl;
    return 0;
}
