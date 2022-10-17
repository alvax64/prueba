#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int n = 20;
float X=5;

float factimpC(int N);
float powerimpC(int x, int N);
extern float factimpASM(int N);
extern float powerimpASM(int x, int N);


int main() {
	struct timespec ti, tf;
    double elapsed1,elapsed2,elapsed3,elapsed4;

	float *factorialImpC,*factorialImpASM, *npowImpC, *npowImpASM;

	int i,j,k,l;
	float sum1=0,sum2=0,sum3=0,sum4=0;

	float seno,e_M;

	factorialImpC=(float *)malloc(n * sizeof(float));
	factorialImpASM=(float *)malloc(n * sizeof(float));
	npowImpC=(float *)malloc(n * sizeof(float));
	npowImpASM=(float *)malloc(n * sizeof(float));

// OPCION 1: Usando las funciones factimpC y powerimpC
	clock_gettime(CLOCK_REALTIME, &ti);
	for(i=0;i<n+1;i++){
		factorialImpC[i]=factimpC(i);
		npowImpC[i]=powerimpC(X,i);
		sum1+=npowImpC[i]/factorialImpC[i];
	}
	clock_gettime(CLOCK_REALTIME, &tf);
    elapsed1 =  (tf.tv_nsec - ti.tv_nsec);
// OPCION 2: Usando las funciones factimpASM y powerimpC
	clock_gettime(CLOCK_REALTIME, &ti);
	for(j=0;j<n+1;j++){
		factorialImpASM[j]=factimpASM(j);
		npowImpC[j]=powerimpC(X,j);
		sum2+=npowImpC[j]/factorialImpASM[j];
	}
	clock_gettime(CLOCK_REALTIME, &tf);
    elapsed2 =  (tf.tv_nsec - ti.tv_nsec);
// OPCION 3: Usando las funciones factimpC y powerimpASM
	clock_gettime(CLOCK_REALTIME, &ti);
	for(k=0;k<n+1;k++){
		factorialImpC[k]=factimpC(k);
		npowImpASM[k]=powerimpASM(X,k);
		sum3+=npowImpASM[k]/factorialImpC[k];
	}
	clock_gettime(CLOCK_REALTIME, &tf);
    elapsed3 =  (tf.tv_nsec - ti.tv_nsec);
// OPCION 4: Usando las funciones factimpASM y powerimpASM
	clock_gettime(CLOCK_REALTIME, &ti);
	for(l=0;l<n+1;l++){
		factorialImpASM[l]=factimpASM(l);
		npowImpASM[l]=powerimpASM(X,l);
		sum4+=npowImpASM[l]/factorialImpASM[l];
	}
	clock_gettime(CLOCK_REALTIME, &tf);
    elapsed4 =  (tf.tv_nsec - ti.tv_nsec);


	printf("La opción 1 da como resultado %.10f y su tiempo de ejecución fue de %.2f nanosegundos\n",sum1, elapsed1);
	printf("La opción 2 da como resultado %.10f y su tiempo de ejecución fue de %.2f nanosegundos\n",sum2, elapsed2);
	printf("La opción 3 da como resultado %.10f y su tiempo de ejecución fue de %.2f nanosegundos\n",sum3, elapsed3);
	printf("La opción 4 da como resultado %.10f y su tiempo de ejecución fue de %.2f nanosegundos\n",sum4, elapsed4);

	seno=sin(5);
	e_M=100*fabs((seno-sum1)/seno);
	printf("El valor relativo de la opcion 1 es %f\n",e_M);
	e_M=100*fabs((seno-sum2)/seno);
	printf("El valor relativo de la opcion 2 es %f\n",e_M);
	e_M=100*fabs((seno-sum3)/seno);
	printf("El valor relativo de la opcion 3 es %f\n",e_M);
	e_M=100*fabs((seno-sum4)/seno);
	printf("El valor relativo de la opcion 4 es %f\n",e_M);
	return 0;
}

float factimpC(int N)
{
    float fact = 1;
    for(int i=1;i<(2*N)+1;i++){
        fact=fact*(i+1);
    }
    return fact;
};

float powerimpC(int x, int N)
{
    float pot = x;
    for(int i=1;i<(2*N)+1;i++){
		pot=pot*x;
    	}
    if(N%2!=0){
        pot*=-1;
    }
    return pot;
}