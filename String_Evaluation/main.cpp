#include <iostream>
#include <string>

using namespace std;
int atoi(string s);
bool isNum(string s);
float eval(string s);

int main()
{
    float res = eval("2*3/16+4");
    cout<<res;
    return 0;
}
float eval(string s){
    if(isNum(s)){
        return atoi(s);
    }else{
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='/'){
                return eval(s.substr(0,i)) * eval(s.substr(i+1,s.length()-1)) ;
            }
        }
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='*'){
                return eval(s.substr(i+1,s.length()-1)) * eval(s.substr(0,i));
            }
        }
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='+'){
                return eval(s.substr(i+1,s.length()-1)) + eval(s.substr(0,i));
            }
        }
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='-'){
                return eval(s.substr(0,i)) - eval(s.substr(i+1,s.length()-1)) ;
            }
        }
    }
}

int atoi(string s){
    int res=0;
    for(int i=0;i<s.length();i++){
        res = res*10+s[i]-'0';
    }
    return res;
}
bool isNum(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
            return false;
        }
    }
    return true;
}
