//
//  main.cpp
//  SashaAndSticks
//
//  Created by Nirmaljot Singh Bhasin on 24/07/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;
typedef long long int lli;
int main(int argc, const char * argv[]) {
    lli n,k;
    cin>>n>>k;
    lli player2Turns = (n/k)/2;
    lli player1Turns = (n/k) - player2Turns;
    if (player1Turns > player2Turns) {
        if ((n/k)&1) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    } else {
        cout<<"NO"<<endl;
    }
    return 0;
}
