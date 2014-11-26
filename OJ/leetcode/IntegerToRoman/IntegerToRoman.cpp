/*
File Name : IntegerToRoman.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-26 20:26:17

Question:

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

Tags:  Math; String

Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
    string intToRoman(int num) {
    	string str;  
        string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};  
        int value[]=    {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1}; 
        for(int i=0;num!=0;++i)
        {
            while(num>=value[i])
            {
                num-=value[i];
                str+=symbol[i];
            }
        }
        return str;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	int number =  atoi(argv[1]);
	cout<<"the roman numeral for "<<number<<" is "<<sol.intToRoman(number)<<endl;
	return 0;
}
