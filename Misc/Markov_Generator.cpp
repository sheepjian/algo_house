#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <deque>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

enum {
    NPREF = 2, /*number of prefix words*/
    NHASH = 4093, /*size of the state hash table*/
    MAXGEN = 10000 /* maximum words generated*/
};

typedef deque<string> Prefix;
map<Prefix, vector<string> > statetab;

void add(Prefix& prefix, const string& s)
{
    if(prefix.size()==NPREF)
    {
        statetab[prefix].push_back(s);
        prefix.pop_front();
    }
    prefix.push_back(s);
}

void build(Prefix& prefix, istream& in)
{
    string buf;
    while(in>>buf)
        add(prefix, buf);
}


string NONWORD = "\n";

void generate(int nwords)
{
    Prefix prefix;
    int i;

    for(int i=0; i<NPREF; i++)
        add(prefix, NONWORD);

    for(int i=0; i<nwords; i++)
    {
        vector<string>& suf = statetab[prefix];
        const string& w = suf[rand()%suf.size()];
        if(w==NONWORD)
            break;

        cout<<w<<"\n";
        prefix.pop_front();
        prefix.push_back(w);
    }
}

int main(void)
{
    int i, nwords=MAXGEN;
    Prefix prefix;

    for(i=0;i<NPREF;i++)
    {
        add(prefix,NONWORD);
    }

    build(prefix,cin);
    add(prefix,NONWORD);
    for(map<Prefix, vector<string> >::const_iterator it = statetab.begin();
            it!=statetab.end(); it++)
    {
        Prefix prefix = it->first;
        vector<string> svec = it->second;
        cout<<prefix[0]<<"+ "<<prefix[1]<<": ";
        for(vector<string>::const_iterator sit = svec.begin();
                sit!=svec.end(); sit++)
        {
            cout<<*sit<<" ";
        }
        cout<<endl;
    }
    generate(nwords);
    return 0;
}

