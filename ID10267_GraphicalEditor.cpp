/* @JUDGE_ID: 10267 C++ ""Graphical Editor"" */

/* @BEGIN_OF_SOURCE_CODE*/
#include <stdio.h>
#include<iostream>
#include <stdlib.h> /*Character handling functions*/
#include<string.h>


using namespace std;

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-10;

#define MAX 252
char IMG[MAX][MAX];
int M,N;

void cleanIMG(){
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			IMG[i][j] = 'O';
			IMG[N+1][j] = '0';
		}
		IMG[i][M+1] = '0';
	}
}

void printIMG(){
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cout<<IMG[i][j];
		}
		cout<<endl;
	}	
}

void fillRegionR(int x,int y,char c){
	char oldcolor;
	oldcolor = IMG[y][x];

	if (oldcolor == c)
		return;

	IMG[y][x] = c;
	if (x>=1 and IMG[y][x-1]==oldcolor) fillRegionR(x-1,y,c);
	if (x<=M and IMG[y][x+1]==oldcolor) fillRegionR(x+1,y,c);
	if (y>=1 and IMG[y-1][x]==oldcolor) fillRegionR(x,y-1,c);
	if (y<=N and IMG[y+1][x]==oldcolor) fillRegionR(x,y+1,c);

	return;
}

int main() {
	char cmd, c;
	int x,y,x1,x2,y1,y2,tmp;
	char name[128];

	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			IMG[i][j] = '0';
		}
	}

	while (true){
		//ler comando entrada
		cin>>cmd;

		switch(cmd){
			case 'I':
				cin>>M>>N;
				//cout<<cmd<<" "<<x<<" "<<y<<endl;
				cleanIMG();
				break;
			case 'C':
				//cout<<cmd<<endl;
				cleanIMG();
				break;
			case 'L':
				cin>>x>>y>>c;
				//cout<<cmd<<" "<<x1<<" "<<y1<<" "<<c<<endl;
				IMG[y][x] = c;
				break;
			case 'V':
				cin>>x>>y1>>y2>>c;
				if( y1> y2){
					tmp = y1;
					y1 = y2;
					y2 = tmp;
				}
				for (int i = y1; i <= y2; ++i)
				{
					IMG[i][x] = c;
				}
				//cout<<cmd<<" "<<x1<<" "<<x2<<" "<<y1<<" "<<c<<endl;

				break;

			case 'H':
				cin>>x1>>x2>>y>>c;
				if (x1 > x2){
					tmp = x1;
					x1 = x2;
					x2 = tmp;
				}
				for (int j = x1; j <= x2; ++j)
				{
					IMG[y][j] = c;
				}
				//cout<<cmd<<" "<<x1<<" "<<x2<<" "<<y1<<" "<<c<<endl;

				break;
			case 'K':
				cin>>x1>>y1>>x2>>y2>>c;
				if (x1 > x2){
					tmp = x1;
					x1 = x2;
					x2 = tmp;
				}
				if( y1> y2){
					tmp = y1;
					y1 = y2;
					y2 = tmp;
				}
				//cout<<cmd<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<c<<endl;
				for (int i = y1; i <= y2; ++i)
				{
					for (int j = x1; j <= x2; ++j)
					{
						IMG[i][j] = c;
					}
				}
				break;
			case 'F':
				cin>>x>>y>>c;
				fillRegionR(x,y,c);
				//cout<<cmd<<" "<<x1<<" "<<y1<<" "<<c<<endl;
				break;
			case 'S':
				cin>>name;
				cout<<name<<endl;
				printIMG();
				//cout<<cmd<<" "<<name<<endl;
				break;
			case 'X':
				goto stop;
				break;
			default:
				continue;
		}
		
	}
 	stop:
  return 0;
}

/*@END_OF_SOURCE_CODE*/