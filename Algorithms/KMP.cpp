#include <bits/stdc++.h>

using namespace std;

// W is the string we need to search in S
// These two strings was name after the strings in the description about KMP on wiki
string W, S;

void check(int T[]){
    cout<<"T[]: ";
    for (int i=0; i<W.size(); i++){
        cout<<T[i]<<" ";
    }
    cout<<endl;
}

void KMP_Table(string W, int T[]){
    // pos is the current position we are computing in W
    // cnd is the zero-based index in W of the next character of the candidate prefix
    int pos = 2, cnd = 0;
    // If there is mismatch at the start, there is no possibility of backtracking
    T[0]=-1;
    // at i-1 (index 1-1=0) there is no proper suffix (proper suffix is not equal the original string)
    T[1]=0;
    while (pos < W.size()){
        if (W[pos-1] == W[cnd]){
            T[pos]=cnd+1;
            pos++;
            cnd++;
        }
        else if (cnd>0){
            cnd = T[cnd];
        }
        else {
            pos++;
        }
    }
}

void KMP_Search(string W, string S, int T[]){
    // m denoting the position within S where the prospective match for W begin
    // i denoting the index of the currently consider character in W
    int m=0, i=0, cnt=0;
    //check(T);
    while (m+i<S.size()){
        if (W[i]==S[m+i]){
            i++;
            // Found one match, print out the position
            if (i==W.size()){
                cout<<"Match at position: "<<m<<endl;
                m++;
                i=0;
                cnt++;
            }
        }
        else {
            if (T[i]!=-1){
                i=T[i];
                m=m+i-T[i];
            }
            else{
                m++;
                i=0;
            }
        }
    }

    // If there is no matching
    if (cnt==0)
        cout<<"No matching at all.";
    else 
        cout<<"Found total of "<<cnt<<" matching sequences.";
    cout<<endl;
}

int main(){
    int T[20010];
	// Input W and S
    cout<<"Input S: ";
    getline(cin, S);
    cout<<"Input W: ";
    getline(cin, W);
    // Compute the KMP table, T[i] is the longest proper suffix ends at i-1
    // that is equals to the prefix starts from 0 of string W
    KMP_Table(W, T);
    //check(T);
    KMP_Search(W, S, T);
	return 0;
}