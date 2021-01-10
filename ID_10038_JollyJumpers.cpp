/* @JUDGE_ID: 10038 C++ "Jolly Jumpers"  */

/* @BEGIN_OF_SOURCE_CODE*/

/*
 GCC 4.8.0 /bits/stdc++.h source.
 https://gcc.gnu.org/onlinedocs/gcc-4.8.0/libstdc++/api/a01541_source.html
 */
#include <bits/stdc++.h>

/*
Basics C library
*/
#include <stdio.h>
#include <stdlib.h> /*Character handling functions*/
#include<string.h>

using namespace std;

/*
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(y))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
*/


typedef long long      LL;
typedef vector<int>    VI;


const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-10;


int main() {
	int N,x ;
	vector<int> v;
	vector<int> m;


	while(cin>>N){
		m.clear();
		v.clear();
		if (N == 1)
		{
			cout<<"Jolly"<<endl;
			cin >> x;
			continue;
		}
		for (int i = 0; i < N; ++i) m.push_back(0);


		for (int i = 0; i < N; ++i){
			cin>>x;
			v.push_back(x);
		}

		for (int i = 1; i < N; ++i)
		{
			x = abs(v.at(i) - v.at(i-1));
			if( x<N)
				m[x] = 1;
		}
		int status = 1;

		for (int i = 1; i < N; ++i)
				if (m[i] == 0)
					status = 0;

		if (status)
			cout<<"Jolly"<<endl;
		else
			cout<<"Not jolly"<<endl;


	}
	return 0;
}
/*@END_OF_SOURCE_CODE*/
