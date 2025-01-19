#include <stdio.h>
#include <math.h>
#include <time.h>

typedef struct st{
    float  num1;
    float  num2;
    float  result=0, c=1;
    char n;
    int f;
    
};

int main(){
	
	FILE* fp;
	fp = fopen("C:\\Users\\user\\Desktop\\file1.txt","w");
	if( fp == NULL) printf("faili ar aris");
	time_t t;
    struct tm *tm_info;
    char tarigi[80];


    time(&t);  // Hal-hazirki vaxti alir
    tm_info = localtime(&t);  // Istifad?çinin yerli zaman zonasina uygun olaraq vaxti alir

    // Tarixi formatlayiriq 
    strftime(tarigi, sizeof(tarigi), "%Y-%m-%d %H:%M:%S", tm_info);
	st S;
	while (S.c!=0){
	printf("\t\t\t*************CALCULATOR*************\n\n");
	printf("\tsheiyvane pirveli ricxvi: ");
	scanf("%f",&S.num1);
	getchar();
	printf("\tshearchiet operacia (+ - * / % ^ ! r): ");
	scanf("%c",&S.n);
	if(S.num1=='r' || S.num1=='!'){
	printf("\tsheiyvane meore ricxvi: ");
	scanf("%f",&S.num2);
	}

	fprintf(fp, "Tarigi: %s\n", tarigi);
	
switch(S.n){
	case '+': 
		S.result=S.num1+S.num2;
		printf("\n\tpasuxi: %.2f\n",S.result); 
		fprintf(fp,"shedegi:%.2f\n",S.result);
	    break;
	case '-': 
		S.result=S.num1-S.num2;
		printf("\tpasuxi: %.2f\n",S.result); 
		fprintf(fp,"shedegi:%.2f\n",S.result);
	    break;
	case '*': 
		S.result=S.num1 * S.num2;
		printf("\tpasuxi:%.2f\n",S.result); 
		fprintf(fp,"shedegi:%.2f\n",S.result);
		break;
	case '/': 
		S.result=S.num1 / S.num2;
		printf("\tpasuxi: %.2f\n",S.result); 
		fprintf(fp,"shedegi:%.2f\n",S.result);
		break;
	case '%': 
		S.result=int(S.num1 ) % int(S.num2);
		printf("\tpasuxi: %.0f\n",S.result); 
		fprintf(fp,"shedegi:%.2f\n",S.result);
		break;
	case '^': 
		S.num1=pow(S.num1,S.num2);
		printf("\tpasuxi: %.2f\n",S.num1); 
		fprintf(fp,"shedegi:%.2f\n",S.result);
		break;
	
	case '!': {
                S.f = (int)S.num1;  
                if (S.f < 0) {
                    printf("\n\t Faktoriyali negatiuri gancdobit aris!!!\n");
                } else {
                    S.result = 1;
                    for (int i = 1; i <= S.f; i++) {
                        S.result *= i;
                    }
                    printf("\tpasuxi: %.0f\n", S.result);
                    fprintf(fp,"%d!\n",S.f);
                    fprintf(fp, "shedegi: %.0f\n", S.result);
                }
                break;
            }
	case 'r': 
		S.result = sqrt(S.num1);
		printf("\tpasuxi: %.2f\n",S.result); 
		fprintf(fp,"shedegi:%.2f\n",S.result);
		break;
		default : printf("\tarascorad sheiyvanet\n\n");
		
		break; 					 
	} 
	printf("\tshedegi dawerilia failshi\n");
	printf ("   dasrulebistvis sheiyvanet 0 da gagrcelebistvis romelime ricxvi: ");
	scanf ("%d", &S.c); 
	
}
printf ("\twarmatebit dasrulebulia. ");
fclose(fp);

}




