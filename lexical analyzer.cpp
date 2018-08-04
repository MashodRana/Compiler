#include<bits/stdc++.h>
using namespace std;
#define pf printf
#define sf scanf
#define pb push_back

map<char,bool>par,punct,A_optr;
map<string,bool>L_optr,keyw;

vector<string>token,logical_opt,con;
vector<int>key,brak,_sin,aop,lop,id;


void initia(){
    par['(']=1; par[')']=1; par['{']=1; par['}']=1; par['[']=1; par[']']=1;

    punct[':']=1; punct[',']=1; punct[';']=1;

    for(int i=42;i<48;i++){
        A_optr[i]=1;
    }
    A_optr['=']=1;

    L_optr[">="]=1; L_optr["<="]=1; L_optr[">"]=1; L_optr["<"]=1; L_optr["=="]=1; L_optr["!="]=1;

    keyw["if"]=1; keyw["else"]=1; keyw["else if"]=1; keyw["for"]=1; keyw["while"]=1; keyw["break"]=1; keyw["continue"]=1;
    keyw["int"]=1; keyw["long"]=1; keyw["double"]=1; keyw["float"]=1;
}


int main()
{

    initia();
    string str;
    getline(cin,str);
    int ln=str.length();

    int a=0;
    while(a<ln){
        if( (str[a]>='A' && str[a]<='Z') || (str[a]>='a' && str[a]<='z') ){
            string s="";
            while(  (str[a]>='A' && str[a]<='Z') || (str[a]>='a' && str[a]<='z') || (str[a]>='0'&&str[a]<='9') ){
                s+=str[a];
                a++;
            }
            token.pb(s);
            a--;
        }
        else if( par[str[a]] ){
            brak.pb(str[a]);
        }
        else if( punct[ str[a] ] ){
            _sin.pb( str[a] );
        }
        else if( A_optr[ str[a] ] ){
            aop.pb( str[a] );
        }
        else if( str[a]=='>' || str[a]=='<' || str[a] =='!' || str[a]=='=' ){
                string s="";
            while( str[a]=='>' || str[a]=='<' || str[a] =='!' || str[a]=='=' ){
                s+=str[a];
                a++;
            }
            if( L_optr[s] ){
                logical_opt.pb(s);
            }
            else{
                aop.pb(2);
            }
            a--;
        }
        else if( str[a]>='0' && str[a]<='9' ){
            string s="";
            while( str[a]>='0' && str[a]<='9' ){
                s+=str[a];
                a++;
            }
            con.pb(s);
            a--;
        }
        a++;
    }

    //vector<string>token,logical_opt,con;
    //vector<int>key,brak,_sin,aop,lop,id;

    for( auto t:token ){
        if( keyw[t] )
            key.pb(1);
        else
            id.pb(1);
    }

    pf("Identifier : %d\n",id.size());
    pf("Constant : %d\n",con.size());
    pf("Parenthesis : %d\n",brak.size());
    pf("Punctuation sign : %d\n",_sin.size());
    pf("Arithmetic operator : %d\n",aop.size());
    pf("Logical operator : %d\n",logical_opt.size());
    pf("Keyword : %d\n",key.size());

    return 0;
}
