/*
             codecstasy
            SUST  SWE-19
*/
#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
#define fora(i,n) for(int i=0 ; i<n ; i++)
#define ford(i,n) for(int i=n-1 ; i>=0 ; i--)
#define pb push_back
using namespace std;

typedef struct {
    int penalty=0,sol_num=0,sl,atmpt[101];
    bool prb[101],entered=false;
}contestant;

bool comp(contestant a,contestant b) {
    if(a.sol_num==b.sol_num) {
        if(a.penalty==b.penalty) {
            return a.sl<b.sl;
        }
        return a.penalty<b.penalty;
    }
    return a.sol_num>b.sol_num;
}

int main()
{
    ll t;
    stringstream ss;
    string str;
    getline(cin,str);
    ss.clear();
    ss << str;
    ss >> t;
    getline(cin,str);
    while( t-- ) {
        contestant cntst[101];
        for(int i=0 ; i<=100 ; i++) {
            cntst[i].sl=i;
            cntst[i].penalty=0;
            cntst[i].sol_num=0;
            //cntst[i].atmpt=0;
            for(int j=1 ; j<=10 ; j++) {
                cntst[i].prb[j]=false;
                cntst[i].atmpt[j]=0;
            }
        }
        //int jhinku=5;
        while(getline(cin,str)) {
            if(str.empty()) break;
            int a,b,c;
            char d;
            ss.clear();
            ss << str;
            ss >> a >> b >> c >> d;
            //cout << a << b << c << d;
            //cntst[a].sl=a;
            cntst[a].entered=true;
            if(d=='I' || d=='C') {
                if(d=='C' && cntst[a].prb[b]!=true) {
                    cntst[a].penalty+=(c+(cntst[a].atmpt[b])*20);
                    cntst[a].sol_num++;
                    cntst[a].prb[b]=true;
                }
                else if(d=='I' && cntst[a].prb[b]!=true) {
                    cntst[a].atmpt[b]++;
                }
            }
        }
        //vector <contestant> :: iterator it;
        //for(it=cntst.begin() ; it!=cntst.begin() ; it++) //cout << cntst[it].sl << " " << cntst[it].sol_num << " " << cntst[it].penalty << endl;cout << (*it)->sl << " " << (*it)->sol_num << " " << (*it)->penalty << endl;
        sort(cntst,cntst+101,comp);
        for(int i=0 ; i<=100 ; i++) {
            if(cntst[i].entered) {
                cout << cntst[i].sl << " " << cntst[i].sol_num << " " << cntst[i].penalty << endl;
            }
        }
        if(t!=0) cout << endl;
    }
    return 0;

}
