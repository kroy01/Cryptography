#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int p;
int q;

int e;
int d;
int n;
int phi;


int setKeys(){
    n = p*q;
    phi = (p-1)*(q-1);


    e=2;
    while(true){
        if((__gcd(e,phi)==1)&&(e<phi)){
            break;
        }else{
            e++;
        }
    }

    d=2;
    while(true){
        if((__gcd(d*e,phi)==1)&&(d!=e)){
            break;
        }else{
            d++;
        }
    }
}

long long int encrypt(int num){
    int pbk = e;
    long long int ct = 1;
    while(pbk--){
        ct *= num;
        ct %= n;
    }
    return ct;
}

long long int decrypt(int num){
    int pvk = d;
    long long int dt = 1;
    while(pvk--){
        dt *= num;
        dt %= n;
    }
    return dt;
}


int main(){
    p=11;
    q=3;
    setKeys();

    cout<<e<<" : "<<d<<endl<<endl;

    string text = "secret";
    vector<int> t, et, dt;

    for(int i = 0; i<text.length(); i++){
        t.push_back((int)(text[i]-'a'));
    }

    for(int i=0; i<t.size(); i++){
        cout<<t[i]<<" ";
    }
    cout<<endl;

    for(int i=0; i<t.size(); i++){
        et.push_back(encrypt(t[i]));
    }
    for(int i=0; i<t.size(); i++){
        cout<<et[i]<<" ";
    }
    cout<<endl;

    for(int i=0; i<t.size(); i++){
        dt.push_back(decrypt(et[i]));
    }
    cout<<endl;
    for(int i=0; i<t.size(); i++){
        cout<<char(dt[i] + 97)<<" ";
    }
    cout<<endl;

    
    return 0;

}