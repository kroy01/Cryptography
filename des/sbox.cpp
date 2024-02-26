#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SBOX[][4][16] = {{{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
                            {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
                            {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
                            {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}},

                           {{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
                            {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
                            {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
                            {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}},

                           {{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
                            {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
                            {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
                            {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}},

                           {{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
                            {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
                            {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
                            {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}},

                           {{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
                            {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
                            {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
                            {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}},

                           {{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
                            {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
                            {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
                            {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}},

                           {{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
                            {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
                            {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
                            {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}},

                           {{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
                            {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
                            {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
                            {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}}};

//




//FOR DETERMINING THE i AND j INDEX OF THE S-BOX
int sbox_ijValues(std::string str,int a)
{
	 int x;
	 if(a == 2)
	 {
		 if(str == "00") {x = 0;}
		 else if(str == "01") {x = 1;}
		 else if(str == "10") {x = 2;}
		 else if(str == "11") {x = 3;}
		 else { x=-1;}
	 }
	 else if(a == 4)
	 {
		 if(str == "0000") {x = 0;}
		 else if(str == "0001") {x = 1;}
		 else if(str == "0010") {x = 2;}
		 else if(str == "0011") {x = 3;}
		 else if(str == "0100") {x = 4;}
		 else if(str == "0101") {x = 5;}
		 else if(str == "0110") {x = 6;}
		 else if(str == "0111") {x = 7;}
		 else if(str == "1000") {x = 8;}
		 else if(str == "1001") {x = 9;}
		 else if(str == "1010") {x = 10;}
		 else if(str == "1011") {x = 11;}
		 else if(str == "1100") {x = 12;}
		 else if(str == "1101") {x = 13;}
		 else if(str == "1110") {x = 14;}
		 else if(str == "1111") {x = 15;}
		 else { x=-1;}
	 }
	 return x;
}


//FOR CONVERTING THE VALUE CHOSEN FROM S-BOX TO 4 BIT BINARY STRING
std::string sboxOutput(int x)
{
	std::string sbo = "";
	switch(x)
	{
		case 0 : sbo += "0000"; break;
		case 1 : sbo += "0001"; break;
		case 2 : sbo += "0010"; break;
		case 3 : sbo += "0011"; break;
		case 4 : sbo += "0100"; break;
		case 5 : sbo += "0101"; break;
		case 6 : sbo += "0110"; break;
		case 7 : sbo += "0111"; break;
		case 8 : sbo += "1000"; break;
		case 9 : sbo += "1001"; break;
		case 10 : sbo += "1010"; break;
		case 11 : sbo += "1011"; break;
		case 12 : sbo += "1100"; break;
		case 13 : sbo += "1101"; break;
		case 14 : sbo += "1110"; break;
		case 15 : sbo += "1111"; break;
		default : sbo += ""; break;
	}
	return sbo;
}


string sbox_output(string str6, int boxnum){
    int x = boxnum, i=0, j=0;
    string s = "", i_string = "", j_string = "";

    i_string += str6[0];
    i_string += str6[5];

    j_string += str6[1];
    j_string += str6[2];
    j_string += str6[3];
    j_string += str6[4];

    i = sbox_ijValues(i_string, 2);
    j = sbox_ijValues(j_string, 4);


    s += sboxOutput(SBOX[x][i][j]);

    return s;
}

int main(){

    cout<<sbox_output("111111", 6)<<endl;



    return 0;
}