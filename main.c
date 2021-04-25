#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 33

/* Programa HOW 
   Equipe: 
    - Endesom Silva
   	- Guilherme
   	- Leonardo Peixoto
	- Lucas Gabriel Fagundes Torrá   
	- Pedro Gonçalves
*/
void calculate(int nOption) {
   
  	unsigned int nUserValue;
  	unsigned int nBinary[MAX];
	int i = 0;
	int j;
	unsigned int nDecimal;
	unsigned int nAuxBinary;
    
    switch (nOption)
	{ 
	   /*DEC to BIN*/
	   case 1:
	   	    printf("Informe um valor DECIMAL:");
			scanf("%d", &nUserValue);
      		getchar();
    		
			nDecimal = nUserValue;
	   	    
			while(nDecimal > 0)
			{
				nBinary[i] = nDecimal % 2;
				i++;
				nDecimal = nDecimal / 2;
			}
					
			printf("\nO DECIMAL %d em BINÁRIO é: ",nUserValue);	   
		
			for(j = i - 1; j >= 0; j--){
				printf("%d", nBinary[j]);
				if((j % 4==0))
					printf(" ");
			}
	   break;
	
	   /*BIN to DEC*/
	   case 2:
	   		
			printf("Informe um valor BINÁRIO (SOMENTE 0 OU 1):");
			scanf("%d", &nUserValue);    
				
			nDecimal   = 0;
    		nBinary[1] = nUserValue;
    		nAuxBinary = 1;
    		
			while(nBinary[1] > 0) {
     		   nDecimal   += nBinary[1] % 10 * nAuxBinary;
        	   nBinary[1] = nBinary[1] / 10;
        	   nAuxBinary = nAuxBinary * 2;
		    }
			
			printf("\nO BINARIO %d em DECIMAL é: %d",nUserValue,nDecimal);	   
	   break;

       /*DEC to HEX*/
	   case 3:
 	     	printf("Informe um valor DECIMAL:");
    		scanf("%d", &nUserValue);
      		getchar();
    		printf("\nO DECIMAL %d em HEXA é: %x \n",nUserValue, nUserValue);	     
	   break;
	   
	   /*HEX to DEC*/
	   case 4:
 	     	printf("Informe um valor HEXA:");
    		scanf("%x", &nUserValue);
      		getchar();
    		printf("\nO HEXA %x em DECIMAL é: %d \n",nUserValue, nUserValue);	     
	   break;
	   	
	   default:
	     printf("\n\n Opcao indisponível, por favor escolha uma opcao válida no menu.\n");	     
	}
	
    getch();
    
}

int menu() {
	
	int nOption;
    
			
	printf("CALCULADORA PARA CONVERSÃO DE BASES\n\n");
	printf("Bem vindo! Escolha uma opção abaixo para calcular: \n\n");
	printf("1 - Decimal para binário \n"
	       "2 - Binário para decimal \n"
		   "3 - Decimal para Hexidecimal \n"
		   "4 - Hexadecimal para Decimal \n"
		   "0 - SAIR \n");
	scanf("%d", &nOption);		   
	
	printf("\n\n\n");
	if (nOption != 0)  
		calculate(nOption);
		
	return nOption;
}

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	int bContinue = 1;
	
	while(bContinue != 0){
		system("cls");
		bContinue = menu();	
	}
		
	return 0;
}

