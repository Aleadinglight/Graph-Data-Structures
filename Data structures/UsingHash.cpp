// Problem 898C Codeforces
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

map <string, vector<string> > m;
map <string, vector<string> > :: iterator it;

int bang(string st1, string st2){
    if (st1.length()==st2.length() && st1!=st2){
        return -1;
    }
    else{
        if (st1.length()>=st2.length() && st1.substr(st1.length()-st2.length(), st2.length())==st2)
            return 1;
        if(st2.length()>=st1.length() && st2.substr(st2.length()-st1.length(), st1.length())==st1)
            return 1;
        return -1;
    }
}

int main(){
    string st, st1;
    int k,n;
    //
    freopen("input.inp","r",stdin);
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>st;
        cin>>k;
        for (int j=1; j<=k; j++){
            cin>>st1;
            m[st].push_back(st1);
        }
    }
    cout<<m.size()<<endl;
    for (it=m.begin(); it!=m.end(); it++){
        vector<string> v(it->second);
        int f=v.size();
        for (int i=0; i<(int)v.size(); i++){
            for (int j=0; j<(int)v.size(); j++){
                if (bang(v[i], v[j])==1){

                    if (v[i].length()<v[j].length()){
                        v[i]=v[j];
                    }
                    else{
                        v[j]=v[i];
                    }
                }
            }
        }
        sort(v.begin(), v.end());
        int d=v.size();
        for (int i=1; i<(int)v.size(); i++){
            if ( v[i]==v[i-1]){
                d--;
                v[i-1]="";
            }
        }
        cout<<it->first<<" "<<d<<" ";
        for (int j=0; j<(int)v.size(); j++)
            if (v[j]!="")
                cout<<v[j]<<" ";
        cout<<endl;
    }
}
