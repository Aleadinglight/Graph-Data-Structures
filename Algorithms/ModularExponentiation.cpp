#include <bits/stdc++.h>

using namespace std;
string st;
long long ans;

long long mulmod(long long a, long long b, long long c){
    long long x=0, y=a%c;
    while (b>0){
        if (b%2==1){
            x=(x+y)%c;
        }
        y=(y*2)%c;
        b=b/2;
    }
    return x%c;
} 


long long modulo(long long a, long long b, long long c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=mulmod(x, y, c);
        }
        y = mulmod(y, y, c); // squaring the base
        b /= 2;
    }
    return x%c;
}

int main(){
  long long a,b,c;
  cin>>a>>b>>c;
  ans = modulo(a, b, c);
	cout<<ans<<endl;
	return 0;
}
