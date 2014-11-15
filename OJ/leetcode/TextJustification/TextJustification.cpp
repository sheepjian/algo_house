/*
Question:

Given an array of words and a length L, format the text such that each line has exactly L characters 
and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line do not divide evenly between words, 
the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.

Tags: String


Answer:
The time complexity of the is O(N)

*/

#include "Common/Leetcode.h"

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        std::vector<string> res;
        if(words.size()>0) {
            for(int i=0; i<words.size(); i++) {
                int total_characters = 0;
                int j = i ;
                for(; j<words.size(); j++) {
                    if((total_characters+words[j].size())>(L-(j-i)))
                        break;
                    else
                        total_characters += words[j].size();
                }
                int left_space = L - total_characters;
                int total_words = j-i;
                string tmp = "";
                // the last line
                if(j==words.size()) {
                    for(int m=i; m<j; m++) {
                        if(m!=j-1) {
                            tmp += (words[m] + ' ');
                        } else {
                            tmp += (words[m] + string(left_space-total_words+1,' '));
                        }
                    }
                } else {
                    if(total_words==1){
                        tmp = words[i]+string(left_space,' ');
                    } else {
                        int even_space = left_space/(total_words-1);
                        int residue_space = left_space - even_space*(total_words-1);
                        for(int m=i; m<j; m++) {
                            if(m!=j-1) {
                                tmp += (words[m] + string(even_space,' '));
                                if(residue_space>0){
                                    tmp += " ";
                                    residue_space--;
                                }
                            } else {
                                tmp += words[m];
                            }
                        }
                    }
                }
                res.push_back(tmp);
                if(i!=j)
                    i = j-1;
            }
        }
        return res;
    }
};


int main(int argc, char** argv) {
  	Solution sol;
  	vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> words2 = {"What","must","be","shall","be."};

    int L = stoi(argv[1]);
  	vector<string> lines = sol.fullJustify(words,L);
    for(auto s: lines)
        cout<<s<<endl;
  	return 0;
}