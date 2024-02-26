#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const vector<vector<string>> roundKey =   { {"B1", "05", "D2", "C6"},
                                            {"29", "41", "10", "42"},
                                            {"3B", "85", "D2", "9B"},
                                            {"33", "92", "32", "69"}};

        
const string sbox[][16];






int sbox_ijValues(char str)
{
	int x;

	if(str == '0') {x = 0;}
	else if(str == '1') {x = 1;}
	else if(str == '2') {x = 2;}
	else if(str == '3') {x = 3;}
	else if(str == '4') {x = 4;}
	else if(str == '5') {x = 5;}
	else if(str == '6') {x = 6;}
	else if(str == '7') {x = 7;}
	else if(str == '8') {x = 8;}
	else if(str == '9') {x = 9;}
	else if(str == 'A') {x = 10;}
	else if(str == 'B') {x = 11;}
	else if(str == 'C') {x = 12;}
	else if(str == 'D') {x = 13;}
	else if(str == 'E') {x = 14;}
	else if(str == 'F') {x = 15;}
	else { x=-1;}

	return x;
}


string sbox_output(string byte){
    string newbyte = "";
    int i = sbox_ijValues(byte[0]);
    int j = sbox_ijValues(byte[1]);

    newbyte = sbox[i][j];

    return newbyte;
}


vector<vector<string>> wordbreakdown(vector<vector<string>> rk){
    vector <vector<string>> v;
    vector<string> vs(4,"");
    string s = "";

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            vs[j] = rk[j][i];
        }
        v.push_back(vs);
    }

    return v;
}

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


string xors(string x1, string x2){
    int n = x1.length();
    string s = "";

    for(int i=0; i<n; i++){
        if(x1[i]==x2[i]){
            s+="0";
        }else{
            s+="1";
        }
    }

    return s;
}

vector<string> xorword(vector<string> w1, vector<string> w2){
    vector<string> v;
    v.push_back(bth(xors(htb(w1[0]), htb(w2[0]))));
    v.push_back(bth(xors(htb(w1[1]), htb(w2[1]))));
    v.push_back(bth(xors(htb(w1[2]), htb(w2[2]))));
    v.push_back(bth(xors(htb(w1[3]), htb(w2[3]))));

    return v;
}


vector<string> gfunction(vector<string> w, string rc){
    //lcs1
    vector<string> w4 = w;
    string temp = w4[0];
    w4[0] = w4[1];
    w4[1] = w4[2];
    w4[2] = w4[3];
    w4[3] = temp;

    //subbyte
    w4[0] = sbox_output(w4[0]);
    w4[1] = sbox_output(w4[1]);
    w4[2] = sbox_output(w4[2]);
    w4[3] = sbox_output(w4[3]);

    //rcxor
    w4[0] = bth(xors(htb(rc), htb(w4[0])));


    return w4;
}

vector<vector<string>> keyGen(vector<vector<string>> w){
    vector<vector<string>> v;

    vector<string> wd = gfunction(w[3], "02");
    vector<string> wn1 = xorword(wd, w[0]);
    vector<string> wn2 = xorword(wn1, w[1]);
    vector<string> wn3 = xorword(wn2, w[2]);
    vector<string> wn4 = xorword(wn3, w[3]);

    v.push_back(wn1);
    v.push_back(wn2);
    v.push_back(wn3);
    v.push_back(wn4);

    return v;
}


int main(){
    vector<vector<string>> w = wordbreakdown(roundKey);
    vector<vector<string>> wnew = keyGen(w); 





    return 0;
}