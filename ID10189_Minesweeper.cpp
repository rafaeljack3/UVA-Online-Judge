/* @JUDGE_ID: 10189 C++ "Minesweeper" */

/* @BEGIN_OF_SOURCE_CODE*/
#include <stdio.h>
#include<iostream>
#include <stdlib.h> /*Character handling functions*/
#include<string.h>


using namespace std;

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-10;

#define MAX 102
char FIELD[MAX][MAX];
char FIELDN[MAX][MAX];

int M,N;

int checkField(int row, int col){
	int i;
	int nmina = 0;
	int index[8][2];

	index[0][0] = row-1;
	index[1][0] = row-1;
	index[2][0] = row-1;
	index[3][0] = row;
	index[4][0] = row;
	index[5][0] = row+1;
	index[6][0] = row+1;
	index[7][0] = row+1;

	index[0][1] = col-1;
	index[1][1] = col;
	index[2][1] = col+1;
	index[3][1] = col-1;
	index[4][1] = col+1;
	index[5][1] = col-1;
	index[6][1] = col;
	index[7][1] = col+1;

	for(i=0; i<8;i++){
		if (index[i][0]>=0 && index[i][0]< M )
			if (index[i][1]>=0 && index[i][1]< N )
				if (FIELD[index[i][0]][index[i][1]]=='*')
					nmina++;
	}

	return nmina;
}

int Minesweeper(){
	int i,j;

	for(i=0;i<M;i++){
		FIELDN[i][N] = '\0';
		for(j=0;j<N;j++){
			if(FIELD[i][j] == '*'){//tem mina
				FIELDN[i][j] = '*';

			}else{//
				FIELDN[i][j] =  checkField(i,j)+ '0';

			}
		}

	}

	return 0;
}


int main() {
	int i,nn,status;
	string line;

	nn=1;
	status = 0;
	while (true){
		cin>>M>>N;
		if (M==0 && N==0)
			break;

		for(i=0;i<M;i++)
			scanf("%s\n",FIELD[i]);
			//cin>>line;
			//strcpy(FIELD[i],line.c_str());
		
		Minesweeper();
		if (status)
				printf("\n");
		else
			status = 1;
		printf("Field #%d:\n",nn);
		for(i=0;i<M;i++)
			printf("%s\n",FIELDN[i]);

		nn++;
		
	}
 
  return 0;
}

/*@END_OF_SOURCE_CODE*/