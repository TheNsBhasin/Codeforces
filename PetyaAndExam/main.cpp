//
//  main.cpp
//  PetyaAndExam
//
//  Created by Nirmaljot Singh Bhasin on 24/07/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string good, str, query;
bool isGood[26];
int main(int argc, const char * argv[]) {
    int n;
    cin>>good;
    for(int i=0;good[i];i++)
        isGood[good[i]-'a'] = true;
    cin>>str;
    cin>>n;
    while(n--) {
        bool flag = true;
        cin>>query;
        int j = 0;
        if(query.length() + 1 < str.length()) {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i = 0; i < str.length(); ++i) {
            if(str[i] == '?') {
                if(!isGood[query[j]-'a']) {
                    flag = false;
                    break;
                }
                ++j;
            } else if(str[i] == '*') {
                int skip = (int)(query.length()-str.length())+1;
                for(int k = 0; k < skip; ++k) {
                    if(isGood[query[j]-'a']) {
                        flag = false;
                    }
                    ++j;
                }
                if(!flag)
                    break;
            } else {
                if(str[i] != query[j]) {
                    flag = false;
                    break;
                }
                ++j;
            }
            if(!flag)
                break;
        }
        if(j < query.length()) {
            flag = false;
        }
        if(flag){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
