/* @JUDGE_ID: 10196 C++ "Check the Check"  */

/* @BEGIN_OF_SOURCE_CODE*/
#include <stdio.h>
#include<iostream>
#include <stdlib.h> /*Character handling functions*/
#include<string.h>


using namespace std;

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-10;

#define BOARD_LEN 8
#define WHITE 1
#define BLACK 0
char BOARD[BOARD_LEN][BOARD_LEN];
char MARK_BOARD[BOARD_LEN][BOARD_LEN];
char PIECES[2][6] = {{'p','n','b','r','q','k'},{'P','N','B','R','Q','K'}};

typedef struct
{
	int x;
	int y;
} Point;

void cleanBoard(char board[][BOARD_LEN]){
	for (int i = 0; i < BOARD_LEN; ++i)
	{
		for (int j = 0; j < BOARD_LEN; ++j)
		{
			board[i][j] = '.';
		}
	}

}

int isBoardEmpty(){
	for (int i = 0; i < BOARD_LEN; ++i)
	{
		for (int j = 0; j < BOARD_LEN; ++j)
		{
			if (BOARD[i][j] != '.')
				return 0;
		}
	}

	return 1;
}

void saveLine(char* s, int index){
	for (int j = 0; j < BOARD_LEN; ++j)
	{
		BOARD[index][j] = s[j];
	}
}

void printBoard(char board[][BOARD_LEN]){
	for (int i = 0; i < BOARD_LEN; ++i)
	{
		for (int j = 0; j < BOARD_LEN; ++j)
		{
			printf("%c",board[i][j]);
		}
		printf("\n");
	}

}

int isBlackWhite(char p, int black_white){
	for (int i = 0; i < 6; ++i)
	{
		if (PIECES[black_white][i]==p)
		{
			return 1;
		}
	}
	return 0;
}

void checkRoot(int idx, int jdx, int black_white){
	char p, king;
	int color_king;
	color_king = black_white ? BLACK: WHITE;
	king = PIECES[color_king][5];

	//UP
	for (int i = idx-1; i >= 0; --i){
		p =  BOARD[i][jdx];
		if ( p=='.' || p==king) 
			MARK_BOARD[i][jdx] = '*'; //VERIFICAR ISSO
		else
			break;
	}

	//DOWN
	for (int i = idx+1; i < BOARD_LEN; ++i){
		p =  BOARD[i][jdx];
		if ( p=='.' || p==king) 
			MARK_BOARD[i][jdx] = '*'; //VERIFICAR ISSO
		else
			break;
	}

	//LEFT
	for (int j = jdx-1; j >=0; --j){
		p =  BOARD[idx][j];
		if ( p=='.' || p==king) 
			MARK_BOARD[idx][j] = '*'; //VERIFICAR ISSO
		else
			break;
	}

	//RIGHT
	for (int j = jdx+1; j < BOARD_LEN; ++j){
		p =  BOARD[idx][j];
		if ( p=='.' || p==king) 
			MARK_BOARD[idx][j] = '*'; //VERIFICAR ISSO
		else
			break;
	}
}

void checkBishop(int idx, int jdx, int black_white){
	int i,j,dif;
	char p, king;
	int color_king;
	color_king = black_white ? BLACK: WHITE;
	king = PIECES[color_king][5];

	//up right
	dif = 1;
	while(1){
		i = idx-dif;
		j = jdx+dif;
		if (i>=0  && j< BOARD_LEN){
			p = BOARD[i][j];
			if ( p=='.' || p==king)
				MARK_BOARD[i][j] = '*';
			else
				break;
		}else
			break;
		dif++;
	}

	//up left
	dif = 1;
	while(1){
		i = idx-dif;
		j = jdx-dif;
		if (i>=0  && j>=0){ 
			p = BOARD[i][j];
			if ( p=='.' || p==king)
				MARK_BOARD[i][j] = '*';
			else
				break;
		}else
			break;
		dif++;
	}

	//down left
	dif = 1;
	while(1){
		i = idx+dif;
		j = jdx-dif;
		if (i< BOARD_LEN  && j>=0){
			p = BOARD[i][j];
			if ( p=='.' || p==king)
				MARK_BOARD[i][j] = '*';
			else
				break;
		}else
			break;
		dif++;
	}

	//down right
	dif = 1;
	while(1){
		i = idx+dif;
		j = jdx+dif;
		if (i< BOARD_LEN  && j< BOARD_LEN){ 
			p = BOARD[i][j];
			if ( p=='.' || p==king)
				MARK_BOARD[i][j] = '*';
			else
				break;
		}else
			break;
		dif++;
	}

}

void checkBoard(int black_white){
	char p;

	///
	for (int i = 0; i < BOARD_LEN; ++i)
	{
		for (int j = 0; j < BOARD_LEN; ++j)
		{
			p = BOARD[i][j];
			if (!isBlackWhite(p, black_white))
				continue;

			if( p== PIECES[black_white][0]){ //'p' - 'P'
				if (black_white == WHITE){
						if ( i-1>= 0 && j-1 >= 0 ) MARK_BOARD[i-1][j-1] = '*';
						if ( i-1>= 0 && j+1 < BOARD_LEN ) MARK_BOARD[i-1][j+1] = '*';
				}else{//BLACK
						if ( i+1< BOARD_LEN && j-1 >= 0 ) MARK_BOARD[i+1][j-1] = '*';
						if ( i+1 < BOARD_LEN && j+1 < BOARD_LEN ) MARK_BOARD[i+1][j+1] = '*';
				}
				continue;
			}

			if(p == PIECES[black_white][1]){ //'n' - 'N'
				if ( i-1>= 0 && j-2 >= 0 ) MARK_BOARD[i-1][j-2] = '*';
				if ( i+1 < BOARD_LEN && j-2 >= 0 ) MARK_BOARD[i+1][j-2] = '*';

				if ( i-2>= 0 && j-1 >= 0 ) MARK_BOARD[i-2][j-1] = '*';
				if ( i+2 < BOARD_LEN && j-1 >= 0 ) MARK_BOARD[i+2][j-1] = '*';

				if ( i-2>= 0 && j+1 < BOARD_LEN ) MARK_BOARD[i-2][j+1] = '*';
				if ( i+2 < BOARD_LEN && j+1 < BOARD_LEN ) MARK_BOARD[i+2][j+1] = '*';

				if ( i-1>= 0 && j+2 < BOARD_LEN ) MARK_BOARD[i-1][j+2] = '*';
				if ( i+1 < BOARD_LEN && j+2 < BOARD_LEN ) MARK_BOARD[i+1][j+2] = '*';

				continue;
			}


			if (p==PIECES[black_white][2]){ //'b' -'B'
				checkBishop(i,j,black_white);
				continue;
			}

			if(p==PIECES[black_white][3]){ //'r' -'R'
				checkRoot(i,j,black_white);
				continue;
			}

			if(p==PIECES[black_white][4]){// 'q' - 'Q'
				checkBishop(i,j,black_white);
				checkRoot(i,j,black_white);
				continue;
			}
			if(p==PIECES[black_white][5]){ // 'K' - 'k'
					if ( i-1>= 0 && j-1 >= 0 ) MARK_BOARD[i-1][j-1] = '*';
					if ( i-1>= 0 ) MARK_BOARD[i-1][j] = '*';
					if ( i-1>= 0 && j+1 < BOARD_LEN ) MARK_BOARD[i-1][j+1] = '*';

					if (j-1 >= 0 ) MARK_BOARD[i][j-1] = '*';
					if (j+1 < BOARD_LEN ) MARK_BOARD[i][j+1] = '*';

					if ( i+1<BOARD_LEN  && j-1 >= 0 ) MARK_BOARD[i+1][j-1] = '*';
					if ( i+1<BOARD_LEN ) MARK_BOARD[i+1][j] = '*';
					if ( i+1<BOARD_LEN  && j+1 < BOARD_LEN ) MARK_BOARD[i+1][j+1] = '*';
			}
			
			
		}
	}

}

void getPosition(char p, int* idx, int* jdx){
	for (int i = 0; i < BOARD_LEN; ++i)
	{
		for (int j = 0; j < BOARD_LEN; ++j)
		{
			if (BOARD[i][j] == p){
				*idx = i;
				*jdx = j;
				return;
			}
		}
	}
}

int main() {
	char s[10], cc;
	int idx, jdx;
	int count = 1;
	while(1){
		//ler a entrada:
		for (int i = 0; i < BOARD_LEN; ++i)
		{
			scanf("%s",s);
			//printf("%s\n",s);
			saveLine(s,i);
		}

		if(isBoardEmpty())
			break;

		//verificar ataque preto
		cleanBoard(MARK_BOARD);
		checkBoard(BLACK);
		getPosition('K',&idx,&jdx);
		//cout<<idx<<"  "<<jdx<<endl;
		cc = MARK_BOARD[idx][jdx];

		if (cc=='*'){
			printf("Game #%d: white king is in check.\n", count);
		}else{
			//verifica ataque branco
			cleanBoard(MARK_BOARD);
			checkBoard(WHITE);
			getPosition('k',&idx,&jdx);
			cc = MARK_BOARD[idx][jdx];
			if (cc=='*')
				printf("Game #%d: black king is in check.\n", count);
			else
				printf("Game #%d: no king is in check.\n", count);

		}


		
		count++;

	}

	return 0;
}

/*@END_OF_SOURCE_CODE*/