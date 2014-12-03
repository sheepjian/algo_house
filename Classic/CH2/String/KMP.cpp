#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> getNext(string p) {
	int len = p.size();

    vector<int> next(len);

    next[0] = 0;

    for (int i = 1, j = 0; i < p.length(); i ++) {
    	while(j > 0 && p[i]!= p[j])
    		j = next[j - 1];

    	if (p[i] == p[j])
    		j++;

    	next[i] = j;
    }
    return next;
}

bool kmp(string S, string T){
	vector<int> next = getNext(T);
	for (int i = 0, j = 0; i < S.length(); i++) {
		while (j > 0 && S[i] != T[j])
			j = next[j - 1];

		if (S[i] == T[j])
			j++;

		if (j == T.length())
			return true;
	}
	return false;
}



int main(int argc, char** argv){
	string S(argv[1]);
	string T(argv[2]);

	if(kmp(S,T))
		cout<<"find the pattern\n";
	else
		cout<<"no matched pattern\n";


	return 0;
}