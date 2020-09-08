#include <stdio.h>
#include<iostream>
#include <stdlib.h> /*Character handling functions*/


using namespace std;

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-10;

int CACHE[1000000] = {-1};

int Ncycle(int n){
	int x,nc = 1;
	x = n;

	if(CACHE[n]>0)
		return CACHE[n];

	while(x!=1){
		x = x % 2 ==0 ? x/2: 3*x+1;
		nc++;
	}
	CACHE[n] = nc;
	return nc;
}

int maxCycle(int x0, int xn){
	int i,nc;
	int maxc =1;
	if(x0>xn){
		swap(x0,xn);
	}

	for(i=x0;i<=xn;i++){
		nc = Ncycle(i);
		if (nc > maxc) maxc =  nc;
		
	}
	return maxc;
}

int main() {
	int x0,xn;
	int maxc;

	while (cin>>x0>>xn){
		maxc = maxCycle(x0,xn);
		
		cout<<x0<<" "<<xn<< " "<<maxc<<endl;
	}
 
  return 0;
}