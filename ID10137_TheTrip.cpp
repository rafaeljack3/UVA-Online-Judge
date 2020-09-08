/* @JUDGE_ID: 10137, C++ "The Trip" */

/* @BEGIN_OF_SOURCE_CODE*/
#include <stdio.h>
#include<iostream>
#include <stdlib.h> /*Character handling functions*/
#include<string.h>


using namespace std;

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-10;
double MONEY_SPENT[1024];



int main() {
	long np;
	double v,transf_pos, transf_neg,avg;
	while(1){
		cin>>np;
		if (np==0)
			break;
		avg=0;
		for (int i = 0; i < np; ++i){
			cin>>MONEY_SPENT[i];
			avg+=MONEY_SPENT[i];
		}

		//multiplica por 100
		avg = avg/np;

		transf_pos = 0;
		transf_neg = 0;
		for (int i = 0; i < np; ++i){
			v = (double) ((long) ((MONEY_SPENT[i]-avg)*100.00))/100.0;
			if (v >0)
				transf_pos+=v;
			else
				transf_neg+=v;
		}
		transf_neg=-transf_neg;

		printf("$%.2f\n",transf_neg > transf_pos ?transf_neg:transf_pos);

	}

}

/*@END_OF_SOURCE_CODE*/