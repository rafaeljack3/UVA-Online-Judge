/* @JUDGE_ID: 10033 C++ "Interpreter" */

/* @BEGIN_OF_SOURCE_CODE*/
#include <stdio.h>
#include<iostream>
#include <stdlib.h> /*Character handling functions*/
#include<string.h>


using namespace std;

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-10;

#define MAX_RAM 1000
unsigned int RAM[1000];
unsigned int REG[10];

void cleanRAM(){
	for (int i = 0; i < 1000; ++i)
	{
		RAM[i] = 0;

	}
}

void cleanREG(){
	for (int i = 0; i < 10; ++i)
	{
		REG[i] = 0;
	}
}

void printREG(){
	for (int i = 0; i < 10; ++i)
	{
		printf("R %d: %03d|",i, REG[i]);
	}
	printf("\n\n");
}


int main() {
	unsigned int n_cases,n_inst, exec_inst,code,d,n, n_exec, pointer;
	char inst[8];

	scanf("%d\n",&n_cases);

	for (unsigned int i = 0; i < n_cases; ++i)
	{
		//LER INSTRUCOES E ARMAZENA NA MEMORIA RAM
		n_inst = 0;
		cleanRAM();
		while(true){//ler ateh o proximo linha em branco
			//ler instrucoes
			if(fgets(inst, sizeof(inst), stdin)==NULL)
            	break;

			if (inst[0]=='\n'){//sai do while se ler uma linha em branco
				break;
			}

			RAM[n_inst++]= (inst[0]-'0')*100+ 10*(inst[1]-'0') + (inst[2]-'0');
		}

		pointer = 0;
		n_exec = 0;
		cleanREG();
		while(true){
			exec_inst = RAM[pointer];
			code = exec_inst/100;//pega o digito das centenas
			d =  (10*exec_inst % 1000)/100;//digito das dezenas
			n = exec_inst % 10;//digito


			switch(code){
				case 1:
					//printf("E 1 %d %d\n",d,n );
					n_exec++;
					goto NEXT;
				case 2: //2dn set register d to n
					//printf("E 2 %d %d\n",d,n );
					REG[d] = n;
					//printREG();
					n_exec++;
					pointer++;
					break;
				case 3:
					//printf("E 3 %d %d\n",d,n );
					REG[d] = (n + REG[d]) % 1000;
					pointer++;
					n_exec++;
					//printREG();
					break;
				case 4:
					//printf("E 4 %d %d\n",d,n );
					REG[d] = (REG[d]*n) % 1000;
					//printREG();
					pointer++;
					n_exec++;
					break;
				case 5:
					//printf("E 5 %d %d\n",d,n );
					REG[d] = REG[n];
					//printREG();
					pointer++;
					n_exec++;
					break;
				case 6://6d
					//printf("E 6 %d %d\n",d,n );
					REG[d] = (REG[d] +REG[n]) %1000;
					//printREG();
					pointer++;
					n_exec++;
					break;				
				case 7:
					//printf("E 7 %d %d\n",d,n );
					REG[d] = (REG[d]* REG[n]) % 1000;
					//printREG();
					pointer++;
					n_exec++;
					break;					
				case 8:
					//printf("E 8 %d %d\n",d,n );
					REG[d] = RAM[REG[n]]% 1000;
					//printREG();
					pointer++;
					n_exec++;
					break;						
				case 9:
					//printf("E 9 %d %d\n",d,n );
					RAM[REG[n]] = REG[d]% 1000;
					pointer++;
					n_exec++;
					break;
				case 0:
					//printf("E 0 %d %d\n",d,n );
					n_exec++;
					if (REG[n] != 0)
						pointer = REG[d]% 1000;
					else
						pointer++;
					break;

			}
		}
		NEXT:
		cout<<n_exec<<endl;
		if (i<n_cases-1)
			cout<<endl;

	}

}


/*@END_OF_SOURCE_CODE*/