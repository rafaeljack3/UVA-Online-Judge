/* @JUDGE_ID: 706, C++ "LCD Display" */

/* @BEGIN_OF_SOURCE_CODE*/
#include <stdio.h>
#include<iostream>
#include <stdlib.h> /*Character handling functions*/
#include<string.h>
#include <vector>

using namespace std;

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-10;

int DIGIT[100000000];
char LCD[24][140];
int MROW, MCOL;


/*
 |

*/

//int POS_LCD[][] = {{0,1}}

//d -> digito
//pos -> posicao inicial da coluna
void BuildDisplay(int d, int pos, int s, int flag)
{
	int n_row, n_col;
	n_row = 2*s+3;
	n_col = s+2;
	//printf("%d %d %d\n",d,pos,s);

	for(int i=0; i<n_row; i++){
		for(int j=0; j<n_col+flag;j++){
				LCD[i][j+pos] = ' ';
			}
	}
	switch(d){
		case 1:
			for(int i=1; i<=s;i++){
				LCD[i][s+1+pos] = '|';
				LCD[i+s+1][s+1+pos] = '|';
			}
			break;
		case 2:
			for(int i=1; i<=s;i++){
				LCD[0][i+pos] = '-';
				LCD[s+1][i+pos] = '-';
				LCD[2*s+2][i+pos] = '-';

				LCD[i][s+1+pos] = '|';
				LCD[i+s+1][0+pos] = '|';
			}
			break;
		case 3:
			for(int i=1; i<=s;i++){
				LCD[0][i+pos] = '-';
				LCD[s+1][i+pos] = '-';
				LCD[2*s+2][i+pos] = '-';

				LCD[i][s+1+pos] = '|';
				LCD[i+s+1][s+1+pos] = '|';
			}
			break;
		case 4:
			for(int i=1; i<=s;i++){
				LCD[s+1][i+pos] = '-';


				LCD[i][0+pos] = '|';
				LCD[i][s+1+pos] = '|';
				LCD[i+s+1][s+1+pos] = '|';
			}
			break;
		case 5:
			for(int i=1; i<=s;i++){
				LCD[0][i+pos] = '-';
				LCD[s+1][i+pos] = '-';
				LCD[2*s+2][i+pos] = '-';


				LCD[i][0+pos] = '|';
				LCD[i+s+1][s+1+pos] = '|';
			}
			break;
		case 6:
			for(int i=1; i<=s;i++){
				LCD[0][i+pos] = '-';
				LCD[s+1][i+pos] = '-';
				LCD[2*s+2][i+pos] = '-';


				LCD[i][0+pos] = '|';
				LCD[i+s+1][0+pos] = '|';
				LCD[i+s+1][s+1+pos] = '|';
			}
			break;
		case 7:
			for(int i=1; i<=s;i++){
				LCD[0][i+pos] = '-';


				LCD[i][s+1+pos] = '|';
				LCD[i+s+1][s+1+pos] = '|';
			}
			break;
		case 8:
			for(int i=1; i<=s;i++){
				LCD[0][i+pos] = '-';
				LCD[s+1][i+pos] = '-';
				LCD[2*s+2][i+pos] = '-';


				LCD[i][0+pos] = '|';
				LCD[i+s+1][0+pos] = '|';
				LCD[i][s+1+pos] = '|';
				LCD[i+s+1][s+1+pos] = '|';
			}
			break;
		case 9:
			for(int i=1; i<=s;i++){
				LCD[0][i+pos] = '-';
				LCD[s+1][i+pos] = '-';
				LCD[2*s+2][i+pos] = '-';



				LCD[i][0+pos] = '|';
				LCD[i][s+1+pos] = '|';
				LCD[i+s+1][s+1+pos] = '|';
			}
			break;
		case 0:
			for(int i=1; i<=s;i++){
				LCD[0][i+pos] = '-';
				LCD[2*s+2][i+pos] = '-';


				LCD[i][0+pos] = '|';
				LCD[i+s+1][0+pos] = '|';
				LCD[i][s+1+pos] = '|';
				LCD[i+s+1][s+1+pos] = '|';
			}

	}

	return;
}


int main() {
	int n,s,n_digit;
	int pos;
	char sn[12];

	while(1){
		scanf("%d %s",&s, sn);
	
		sscanf(sn,"%d",&n);
		if (s==0 && n==0)
			break;

		//pegar cada digito de sn
		n_digit = 0;
		for (int i = 0; i < 12; ++i)
		{
			if(sn[i]=='\0'){
				break;
			}
			DIGIT[i] = sn[i]-'0';
			n_digit++;
		}

		MROW = 2*s+3;
		MCOL = (s+3)*n_digit;
		
		int flag; //flag para imprimir espaco entre numero
		for (int i = 0; i <n_digit; i++)
		{
			//para cada digito, carrega na matriz
			pos = (s+3)*i;//posicao na matriz
			flag = (i==n_digit-1) ? 0:1;
			BuildDisplay(DIGIT[i],pos,s,flag);
		}

		for(int i=0; i<MROW; i++){
			for (int j = 0; j < MCOL-1; ++j)
			{
				printf("%c",LCD[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		//construir display para cada digito
		//n_row = 2*s+3;
		//n_col = 
		//pos = (s+2)*(n_digit-1);

	}
	return 0;


}

/*@END_OF_SOURCE_CODE*/