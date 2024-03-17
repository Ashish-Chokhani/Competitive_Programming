#include<bits/stdc++.h>
using namespace std;

string reverse_string(int i,string &s){
    if(i<0)
    return "";

    string reversed_string=reverse_string(i-1,s); //Reversed string
    string cur_string = s[i]+reversed_string;
    return cur_string;    
}

int main(){
    string s;
    cin>>s; //Taking input
    int len=s.length();
    string ans="";
    string reversed_string=reverse_string(len-1,s);
    cout<<reversed_string<<"\n";
    return 0;
}