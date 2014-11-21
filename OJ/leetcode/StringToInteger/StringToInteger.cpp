/*
File Name : StringToInteger.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-21 23:28:40

Question:

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, 
please do not see below and ask yourself what are the possible input cases.


Requirements for atoi:
The function first discards as many whitespace characters as necessary 
until the first non-whitespace character is found. 
Then, starting from this character, 
takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, 
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, 
or if no such sequence exists because either str is empty or it contains only whitespace characters, 
no conversion is performed.

If no valid conversion could be performed, a zero value is returned. 
If the correct value is out of the range of representable values, 
INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.


Tags: 


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	int atoi(const char *str) {
    	if (!str){return 0;}
        int i=0;
        bool pos=true;
        int res=0;
        while (str[i]==' '){ i++;}
        if (str[i]=='+'){ pos=true;i++;}
        else if (str[i]=='-'){ pos = false;i++;}
        if (!isdigit(str[i])){return 0;}
        
        while(str[i]){
            while (isdigit(str[i])){
               if (pos && res>INT_MAX/10){return INT_MAX;}
               if (pos && res==INT_MAX/10 && int(str[i]-'0')>=7){return INT_MAX;}
               if (!pos && -res<INT_MIN/10){return INT_MIN;}
               if (!pos && -res==INT_MIN/10 && int(str[i]-'0')>=8){return INT_MIN;}
               res = res*10 + int(str[i]-'0');
               i++;
            }
            if(str[i]==' ')
                i++;
            else if(str[i]=='\0')
                break;
            else
                return 0;;
        }
             
        if (pos){return res;}
        else{return -res;}       
    }

};


int main(int argc, char** argv) {
	Solution sol;

	const char* s = argv[1];
	cout<<sol.atoi(s)<<endl;

	return 0;
}
