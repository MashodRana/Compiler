#include <bits/stdc++.h>
using namespace std;
//Check validity of a equation
// for consecutive operator equation is invalid
/*
===========================================================================
*                  ___________________________________                    *
*                  *  "Know Yourself"                *                    *
*                  *  Slack Coder (Mashod Rana)      *                    *
*                  *  The University of Asia Pacific *                    *
*                  *_________________________________*                    *
===========================================================================
*/
#define lm 100005

bool t[256];

void initialize(){
    t['+']=t['-']=t['*']=t['/']=t['^']=t['=']=1;
}
int main()
{
    initialize();
    string str;
    cin>>str;
    int len=str.length();
    bool flag=1;
    if( t[ str[0] ] || t[ str[len-1] ]){
        flag=0;
    }
    else{
        for(int i=1;i<len;i++){
            if( t[ str[i] ] ){
                if( t[ str[i-1] ] ){
                    flag=0;
                    break;
                }
            }
        }
    }
    if(flag)
        printf("Valid");
    else
        printf("Invalid");
    return 0;
}

