/*
File Name : ValidNumber.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-13 13:59:48

Question:

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Tags: Math; String

Answer:
1. number's RegExp [\+\-]?[0-9.]?
2. Build FSM

More:
RegExp -> NFA

*/

#include "Common/Leetcode.h"

class Solution {
public:
	bool isDigit(const char s){
		return (s>='0'&&s<='9');
	}
	bool isNumber(const char *s) {
		int i = 0;
		int current_state = 0;

		while(s[i]) {
			switch (current_state){
				case 0:
					if(s[i]=='-'||s[i]=='+') current_state = 1;
					else if(s[i]=='.') current_state = 2;
					else if(isDigit(s[i])) current_state = 3;
					else if(s[i]!=' ') return false;          //otherwise keep in state 0
					break;
				case 1:
					if(s[i]=='.') current_state = 2;
					else if(isDigit(s[i])) current_state =3;
					else return false;
					break;
				case 2:
					if(isDigit(s[i])) current_state = 8;
					else return false;
					break;
				case 3:
					if(s[i]=='e'||s[i]=='E') current_state = 4;
					else if(s[i]==' ') current_state = 6;
					else if(s[i]=='.') current_state = 7;
					else if(!isDigit(s[i])) return false; //otherwise keep in state 3
					break;
				case 4:
					if(s[i]=='-'||s[i]=='+') current_state = 9;
					else if(isDigit(s[i])) current_state = 5;
					else return false;
					break;
				case 5:
					if(s[i]==' ') current_state = 6;
					else if(!isDigit(s[i])) return false; //otherwise keep in state 5
					break;
				case 6:
					if(s[i]!=' ') return false;
					break;
				case 7:
					if(s[i]=='e'||s[i]=='E') current_state=4;
					else if(s[i]==' ') current_state=6;
					else if(!isDigit(s[i])) return false;
					break;
				case 8:
					if(s[i]=='e'||s[i]=='E') current_state=4;
					else if(s[i]==' ') current_state=6;
					else if(!isDigit(s[i])) return false;
					break;
				case 9:
					if(isDigit(s[i])) current_state = 5;
					else return false;
					break;
			}
			i++;
		}
		return (current_state==3||(current_state>=5&&current_state<=8));
	}
};


int main(int argc, char** argv) {
	Solution sol;
	while(true){
		double e = +.6E+2;
		char s[100];
		char flag[10];
		cout<<"input number: ";
		cin.getline(s,100);
		if(sol.isNumber(s))
			cout<<"it is a number "<<endl;
		else
			cout<<"it is not a valid number"<<endl;

		cout<<"end now?(Y/y)\n";
		cin.getline(flag,10);
		char Y[] = "Y";
		char y[] = "y";
		if(strcmp(flag,Y)== 0 || strcmp(flag,y)==0)
			break;

	}
	return 0;
}
