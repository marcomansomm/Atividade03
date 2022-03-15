#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>


int tam;


int maximo, minimo;
float media;

void *max(int numeros[])
{
	int max = numeros[0];


	for(int i = 0; i < tam; i++){
		if(numeros[i] > max){
			max = numeros[i];
		}
	}
	
	maximo = max;

}

void *min(int numeros[])
{
	int min = numeros[0];


	for(int i = 0; i < tam; i++){
		if(numeros[i] < min){
			min = numeros[i];
		}
	}	

	minimo = min;

}

void *average(int numeros[])
{
	int sum = 0;

	for(int i = 0; i < tam; i++){
		sum += numeros[i];
	}

	media = sum / tam;	
}


int main(void){
	
	int size, i;
	pthread_t t1, t2, t3;

	printf("Digite a quantidade de entradas: ");
	scanf("%d", &size);
	int numeros[size];

	for(i = 0; i < size; i++){
		scanf("%d", &numeros[i]);
	}

	tam = i;

	pthread_create(&t1, NULL, max, &numeros);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, min, &numeros);
	pthread_join(t2, NULL);
	pthread_create(&t3, NULL, average, &numeros);
	pthread_join(t3, NULL);
	

	printf("The average value is: %.2f\n", media);
	printf("The minimum value is: %d\n", minimo);
	printf("The maximum value is: %d\n", maximo);

	return 0;

}
