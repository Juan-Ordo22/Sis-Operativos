/**************************************
*Autor:Juan Ordoñez
* Fecha:6 de agosto 
* materia: sistemas operativos
* Tema: Evaluaciòn de rendimiento
****************************************/

#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define DATA_RESERVA (1024*1024*64*3)

static double MEM_CHUNK[DATA_RESERVA];

void MULT_MatrizA(int sz, double *m,double *n,double *c){

  int i,j,k;
  for(i=0;i<sz;i++){
     for(j=0;j<sz;j++){
       double *pA, *pB,Sumat;
       Sumat=0.0;
       pA= m+(i*sz); 
       pB =n+j;
       for(k=sz;k>0;k--, pA++,pB+=sz)
         Sumat+=(*pA)*(*pB);
         c[i*sz+j]=Sumat;
         
       
     } 
  }  
}


void Init_MatrizA(int sz, double *m,double *n,double *c){

  int i,j,k;
  for(k=0;k<sz;k++){
     for(j=0;j<sz;j++){
       m[j+k*sz]=2.3*(j+k);
        n[j+k*sz]=3.2*(j-k);
        c[j+k*sz]=1.3;
     } 
  }  
}

void imprimi_Mat(int sz, double *a){
  
  int j,K;
  for(K=0;K<sz;K++){
    for(j=0;j<sz;j++){
      printf("%f ",a[j+K*sz]);
      
     }
    printf("\n");
    }
  printf("---------------------------------------\n");
}
int main(int argc, char *argv[]){
  
  double *A,*B,*C;
   if(argc < 2){
     printf("./matMult MatrizSize Num Hilos....\n\n");
     return -1;
   }
   int N=((int) atof(argv[1]));
   int h=((int) atof(argv[2]));
  A=MEM_CHUNK;
  B=A+N*N;
  C=B+N*N;
   printf("valores ingresados\n");
   printf("Matriz size(NXM):%dX%d \n",N,N );
    printf("numero de Hilos (h): %d \n",h);
   Init_MatrizA(N, A, B, C);
   MULT_MatrizA(N,A, B,C);
   imprimi_Mat(N,A);
   imprimi_Mat(N,B);
   imprimi_Mat(N,C);
  return 0;
  
}