#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int IP_INV[] = {40, 8, 48, 16, 56, 24, 64, 32,
            39, 7, 47, 15, 55, 23, 63, 31,
            38, 6, 46, 14, 54, 22, 62, 30,
            37, 5, 45, 13, 53, 21, 61, 29,
            36, 4, 44, 12, 52, 20, 60, 28,
            35, 3, 43, 11, 51, 19, 59, 27,
            34, 2, 42, 10, 50, 18, 58, 26,
            33, 1, 41, 9, 49, 17, 57, 25};

string hexTobin(char ch){
    string str;
    switch(ch){
        case '0' : str="0000" ; break;
        case '1' : str="0001" ; break;
        case '2' : str="0010" ; break;
        case '3' : str="0011" ; break;
        case '4' : str="0100" ; break;
        case '5' : str="0101" ; break;
        case '6' : str="0110" ; break;
        case '7' : str="0111" ; break;
        case '8' : str="1000" ; break;
        case '9' : str="1001" ; break;
        case 'A' : str="1010" ; break;
        case 'B' : str="1011" ; break;
        case 'C' : str="1100" ; break;
        case 'D' : str="1101" ; break;
        case 'E' : str="1110" ; break;
        case 'F' : str="1111" ; break;
    }

    return str;
}

string binTohex(string bin){
    string str;

    if      (bin == "0000"){
        str = "0";
    }else if(bin == "0001"){
        str = "1";
    }else if(bin == "0010"){
        str = "2";
    }else if(bin == "0011"){
        str = "3";
    }else if(bin == "0100"){
        str = "4";
    }else if(bin == "0101"){
        str = "5";
    }else if(bin == "0110"){
        str = "6";
    }else if(bin == "0111"){
        str = "7";
    }else if(bin == "1000"){
        str = "8";
    }else if(bin == "1001"){
        str = "9";
    }else if(bin == "1010"){
        str = "A";
    }else if(bin == "1011"){
        str = "B";
    }else if(bin == "1100"){
        str = "C";
    }else if(bin == "1101"){
        str = "D";
    }else if(bin == "1110"){
        str = "E";
    }else if(bin == "1111"){
        str = "F";
    }


    return str;
}

string bth(string str){
    vector<string> v;
    string s = "";

    for(int i=0; i<str.length(); i+=4){
        s+=str[i];
        s+=str[i+1];
        s+=str[i+2];
        s+=str[i+3];
        v.push_back(s);
        s = "";
    }

    s = "";
    for(int i=0; i<v.size(); i++){
        s += binTohex(v[i]);
    }

    return s;
}

string htb(string str){
    string s = "";

    for(int i=0; i<str.length(); i++){
        s += hexTobin(str[i]);
    }

    return s;
}




string permute(string str){
    string s = htb(str);

    string ns = "";

    for(int i=0; i<64; i++){
        ns += s[IP_INV[i]-1];
    }

    string fp = bth(ns);

    return fp;
}


int main(){

    string str = "AAAABBBBCCCCDDDD";

    string fp = permute(str);


    cout<<fp<<endl;



    return 0;
}