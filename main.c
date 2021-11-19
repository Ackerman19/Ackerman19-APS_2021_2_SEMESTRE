#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define tam 100000

void ordena();
void clear(); 
void numeroRandom(); 
int* vetNum[tam];  // vetor onde os dados são armazenados
char line[tam]; 
clock_t inicio_b, fim_b, inicio_s, fim_s, inicio_i, fim_i, inicio_q, fim_q; // variaveis que guardam os tempo de execução
int main(){ 
	char opc;
	srand(time(NULL)); // defini um valor semente para que os numeros aleatorios não se repitam
	
	setlocale(LC_ALL, "Portuguese"); // função para aceitar acentuação
	while(true){ // laço de repetição do menu
		printf("\n\t\t  ORDENAÇÃO\n\n\n");
		printf("      1 - Internos");
		printf("             2 - Externos");
	
		printf("\n\nDigite a opção que deseja: ");
		scanf("%s", &opc);
		clear(1);
	
		if('1' == opc){ // caso a opção escolhida seja 1, os valores serão internos
			ordena(1);
			break;
		}else if('2' == opc){ // caso a opção escolhida seja 2, os valores serão externos
			ordena(2);
			break;
		}else{
			printf("Opção inválida, tente novamente...\n"); // caso não digite 1 ou 2, da um erro e redireciona novamente ao menu
			clear(1);
		}
	}
	
	return 0;
}
	void ordena(int x){ // nesta função os dados são exibidos antes da ordenação, é feita a ordenação, exibido os dados após a ordenação e exibi os dados para comparação
		int i, j;
		if(x == 1){
			numerosRandom(vetNum, tam);
			
			printBubble();
			
			memset(vetNum, 0, tam);
			
			numerosRandom(vetNum, tam);
			
			printInsertion();
			
			memset(vetNum, 0, tam);
			
			numerosRandom(vetNum, tam);
			
			printSelection();
			
			memset(vetNum, 0, tam);
			
			numerosRandom(vetNum, tam);
			
			printQuick();
			
			printTime(1);
	
			
		}else if(x == 2){
			numerosTxt(vetNum, tam);
			
			printBubble();
			
			memset(vetNum, 0, tam);
			
			numerosTxt(vetNum, tam);
			
			printInsertion();
			
			memset(vetNum, 0, tam);
			
			numerosTxt(vetNum, tam);
			
			printSelection();
			
			memset(vetNum, 0, tam);
			
			numerosTxt(vetNum, tam);
			
			printQuick();
			
			printTime(2);
	}
}
	
	void clear(int x){ // função criada para limpar a tela, passando como parametro um inteiro que será o tempo no qual o programa pausará antes de a tela ser limpada 
		sleep(x);
		system("cls");
	}
	
	int bubbleSort(int* vet, int size){ // algoritmo de ordenação BubbleSort
		
		int aux, i, j,k;
		for(i = 1; i < size; i++){
			for(j = 0; j < size - 1; j++){
				if(vet[j] > vet[j + 1]){
					aux = vet[j];
					vet[j] = vet[j + 1];
					vet[j + 1] = aux;
					
				}
			}
		}
		return 0;
	}
	
	int insertionSort(int* vet, int size){// algoritmo de ordenação InsertionSort
		int i, j, key;
		for(i = 1; i < size; i++){
			key = vet[i];
			j = i - 1;
			
			while(j >=0 && vet[j] > key){
				vet[j + 1] = vet[j];
				j = j - 1;
			}
			vet[j + 1] = key;
		}
		return 0;
	}
	
	int selectionSort(int* vet, int size){// algoritmo de ordenação SelectionSort
		int i, j, min, aux;
		
		for(i = 0; i < size - 1; i++){
			min = i;
			for(j = i + 1; j < size; j++){
				if(vet[j] < vet[min]){
					min = j;
				}
			}
			if(i != min){
				aux = vet[i];
				vet[i] = vet[min];
				vet[min] = aux;
			}
		}
		return 0;
	}
	
	int quickSort(int* vet, int size){// algoritmo de ordenação QuickSort
		int aux;
		if(size <=1){
			return;
		}
		int x = vet[0];
		int a = 1;
		int b = size -1;
		do{
			while (a < size && vet[a] <= x){
				a++;
			}while(vet[b] > x){
				b--;
			}if(a < b){
				aux = vet[a];
				vet[a] = vet[b];
				vet[b] = aux;
				a++;
				b--;
			}
		}while(a <= b);
		vet[0] = vet[b];
		vet[b] = x;
		quickSort(vet, b);
		quickSort(&vet[a], size - a); 
		return 0;
	}
	
	int mostrarVetor(int vet[], int size){// mostra o vetor com os dados
		int i;
		for(i = 0; i<size; i++){
			printf("%d\n", vet[i]);
		}	
		return 0;
	}
	
	int numerosRandom(int* vet, int size){// gera os numeros aleatorios e armazena no vetor
		int i;
		for(i = 0; i<size; i++){
			vet[i] = rand() % 99999 + 99999;
		}
		return 0;
	}
	
	int numerosTxt(int* vet, int size){ // recebe os valores externos e armazena no vetor
		int i;
		FILE *arquivo;
		if(size == 5000){
			arquivo = fopen("palavras5k.txt", "r");
		}else if(size == 10000){
			arquivo = fopen("palavras10k.txt", "r");
		}else if(size == 50000){
			arquivo = fopen("palavras50k.txt", "r");
		}else if(size == 100000){
			arquivo = fopen("palavras100k.txt", "r");
		}

    	if (arquivo == NULL){
        	return EXIT_FAILURE;
        }

    	while(fgets(line, sizeof line, arquivo) != NULL)
    	{
       		vet[i] = strtol(strdup(line), NULL, 10);
        	i++;
    		}
	}
	
	
	void printTime(int y){ // exibe os tempos de execução para comparação 
		if(y == 1){
			printf("\t--DADOS INTERNOS--\n\n");
		}else{
			printf("\t--DADOS EXTERNOS--\n\n");
		}
		char x;
		double time_b = (double)(fim_b - inicio_b) / CLOCKS_PER_SEC;
		double time_i = (double)(fim_i - inicio_i) / CLOCKS_PER_SEC;
		double time_s = (double)(fim_s - inicio_s) / CLOCKS_PER_SEC;
		double time_q = (double)(fim_q - inicio_q) / CLOCKS_PER_SEC;
		
		printf("\tTempo BubbleSort: %.5f", time_b);
		printf("\n\tTempo InsertionSort: %.5f", time_i);
		printf("\n\tTempo SelectionSort: %.5f", time_s);
		printf("\n\tTempo QuickSort: %.5f", time_q);
		
		printf("\n\nDeseja voltar para o menu? (S/N)");
		scanf("%s", &x);
		
		if(x == 'S' || x == 's'){ 
			clear(1);
			main();
		}else{
			printf("\nObrigado, Volte Sempre!!! ");
			exit(1);
		}	
	}
	
	void printBubble(){ // printa os valores desordenados e ordenados pelo método BubbleSort
		printf("\n\n                 Método BubbleSort\n\n\n");
		printf("Valores Desordenados: \n\n");
		sleep(2);
		mostrarVetor(vetNum, tam);
		sleep(5);
		inicio_b = clock();
		bubbleSort(vetNum, tam);
		fim_b = clock();
		printf("\n\nValores Ordenados: \n\n");
		sleep(2);
		mostrarVetor(vetNum, tam);
		clear(2);
	}
	
	void printInsertion(){// printa os valores desordenados e ordenados pelo método InsertionSort
		printf("\n\n                 Método InsertionSort\n\n\n");
		printf("Valores Desordenados: \n\n");
		sleep(2);
		mostrarVetor(vetNum, tam);
		sleep(5);
		inicio_i = clock();
		insertionSort(vetNum, tam);
		fim_i = clock();
		printf("\n\nValores Ordenados: \n\n");
		sleep(2);
		mostrarVetor(vetNum, tam);
		clear(2);
	}
	
	void printSelection(){ // printa os valores desordenados e ordenados pelo método SelectionSort
		printf("\n\n                 Método SelectionSort\n\n\n");
		printf("Valores Desordenados: \n\n");
		sleep(2);
		mostrarVetor(vetNum, tam);
		sleep(5);
		inicio_s = clock();
		selectionSort(vetNum, tam);
		fim_s = clock();
		printf("\n\nValores Ordenados: \n\n");
		sleep(2);
		mostrarVetor(vetNum, tam);
		clear(2);
	}
	
	void printQuick(){ // printa os valores desordenados e ordenados pelo método QuickSort
		printf("\n\n                 Método QuickSort\n\n\n");
		printf("Valores Desordenados: \n\n");
		sleep(2);
		mostrarVetor(vetNum, tam);
		sleep(5);
		inicio_q = clock();
		quickSort(vetNum, tam);
		fim_q = clock();
		printf("\n\nValores Ordenados: \n\n");
		sleep(2);
		mostrarVetor(vetNum, tam);
		clear(2);
	}
