#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

// x eggs and n floors
int minTesting(int x, int n){
    if (n ==1 || n==0)
        return n;
    if(x==1)
    	return n;

    int eggFloor[x+1][n+1];
    for (int i = 1; i <= x; i++)
    {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }

    for (int j = 1; j <= n; j++)
        eggFloor[1][j] = j;

	for (int i = 2; i <= x; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            eggFloor[i][j] = INT_MAX;
            for (int k = 1; k <= j; k++)
            {
                int res = 1 + max(eggFloor[i-1][k-1], eggFloor[i][j-k]);
                if (res < eggFloor[i][j])
                    eggFloor[i][j] = res;
            }
        }
    }
    return eggFloor[x][n];
}

int main(int argc, char** argv){
	int eggs = atoi(argv[1]);
	int floors = atoi(argv[2]);
	cout<<"the minimum testing times for a "<<floors
		<<"-storey building is "<<minTesting(eggs, floors)
		<<" if you have "<<eggs<<" eggs "<<endl;

	return 0;
}