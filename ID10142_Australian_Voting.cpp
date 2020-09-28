/* @JUDGE_ID: 10142 C++ "Australian Voting"  */

/* @BEGIN_OF_SOURCE_CODE*/
//C++
#include<iostream>
#include<string>


//C style
#include <stdio.h>
#include <stdlib.h> /*Character handling functions*/



using namespace std;

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-10;


int getMaxPos(int rank[], int nc){
	int max = -1;
	int pos = 0;
	for (int i = 1; i < nc+1; ++i)
	{
		if (rank[i] > max){
			max = rank[i];
			pos = i;
		}
	}

	return pos;
}


int main() {
	string s, token;
	size_t pos=0;
	string cand[20];//nome dos candidatos
	int elim_cand[20];
	string ballots[1000];//votos
	int rank[22];//somatoria notas

	int N,nc,nb, x, win,min,max, r;
	float rate;

	cin>>N;
	while(N--){
		cin>>nc;//numero de candidatos
		x = 0;
		getline(cin,s);//ler restante da linha
		while(x<nc) getline(cin,cand[x++]);

		nb = 0;//numerro de ballots(cedulas)
		while(true){
			getline(cin,s);	
			if (s.size()==0) break;
			ballots[nb++] = s;
		}

		//controla candidatos eliminados
		for (int i = 0; i < 20; ++i)
		{
			elim_cand[i] = 1;
		}
		
		int nn=0;
		while(nn<nc){
			//zera o rank
			for (int i = 0; i < nc+1; ++i) 
				rank[i] = 0;
			//contar numero de votos
			for (int i = 0; i < nb; ++i){
				s = ballots[i];
				pos = s.find(' ');
				token = s.substr(0,pos);
				rank[atoi(token.c_str())]++;//incrementa na posicao do candidato
			}
			//posicao do candidato com maior nota
			win = getMaxPos(rank, nc);
			max = rank[win];
			rate = (float) rank[win]/nb;
			if( rate > 0.5){
				cout<<cand[win-1]<<endl;
				break; //ha um ganhador
			}
			
			//pegar menor nota
			min = 1000;
			for (int i = 1; i < nc+1; ++i)
			{
				if (elim_cand[i-1] && rank[i]< min){
					min = rank[i];
				}	
			}

			//se min = max, ha um empate
			if (min == max ){
				for (int i = 0; i < nc; ++i)
				{
					if(elim_cand[i])
						cout<<cand[i]<<endl;
				}				
				break; //empate
			}

			//elimina candidatos com menor nota
			for (int i = 1; i < nc+1; ++i)
			{
				x = rank[i];
				if (elim_cand[i-1] && x==min){//elimina candidatos com nota minima
					elim_cand[i-1] = 0;//controla cand eliminados
					//deleta nota nas cedulas
					for (int j = 0; j < nb; ++j){
						pos = ballots[j].find(' ');
						token = ballots[j].substr(0,pos);
						r = atoi(token.c_str());
						if ( r== i){//elimina e verifica se os proximos jah foram eliminados
							ballots[j].erase(0, pos+1);
							while(1){
								pos = ballots[j].find(' ');
								token = ballots[j].substr(0,pos);
								r = atoi(token.c_str());
								if (!elim_cand[r-1]){
									ballots[j].erase(0, pos+1);
								}else
									break;
							}
						}
					}

				}
			}
		
			nn++;//continua nova contagem se não teve ganhador
		}

		if(N> 0)
			cout<<endl;
	}

	return 0;
}

/*@END_OF_SOURCE_CODE*/