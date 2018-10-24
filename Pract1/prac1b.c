#include <stdio.h>
#include <stdlib.h>
#include "prac1funs.c"

int main (void){
    int n,i,j;
    double **a, *b, *x,*y, **copia, tol, *resultResta, resulNorma2;
    printf("Dimensio de la matriu, (n) = \n");
    if(scanf("%d",&n) == 1){
        printf("Correcte");
    }
    else{
        return 0;
    }
    y=(double*)malloc(n*sizeof(double));
    resultResta=(double*)malloc(n*sizeof(double));

    a=(double**)malloc(n*sizeof(double*));
    if(a==NULL){
        printf("No hi ha prou memoria");
        return 1;
    }
    copia=(double**)malloc(n*sizeof(double*));
    if(copia==NULL){
        printf("No hi ha prou memoria");
        return 4;
    }

    for (i=0; i<n; i++){
        a[i]=(double*)malloc(n*sizeof(double));
        if(a[i]==NULL){
            printf("No hi ha prou memoria");
            return 2;
        }
    }
    for (i=0; i<n; i++){
        copia[i]=(double*)malloc(n*sizeof(double));
        if(copia[i]==NULL){
            printf("No hi ha prou memoria");
            return 4;
        }
    }

    b=(double*)malloc(n*sizeof(double));
    if(b==NULL){
        printf("No hi ha prou memoria");
        return 3;
    }
    x=calloc(n, sizeof(double));
    if(x==NULL){
        printf("No hi ha prou memoria");
        return 3;
    }
  
    
    
    printf("Doneu els (%d x %d) elements de la matriu A \n", n, n);
    for(i=0; i<n;i++){
        for(j=0;j<n;j++){
            if (scanf("%le", &a[i][j])==1){
            }
        }
    }
    printf("Doneu els %d elements del vector u \n", n);
    for(i=0; i<n ; i++){
       if (scanf("%le", &b[i])==1){
        }
    }


    printf("Matriu \n");
    for(i=0; i<n;i++){
        for(j=0; j<n;j++){
            copia[i][j]=a[i][j];
            printf(" %16.7e ", copia[i][j]);
        }
        printf("\n");
    }

    
    tol=0.00001;
    if((gauss(n,a,b,tol))==3){
        printf("Matriu dolenta");

    }

    if((resTsup(n,a,b,x,tol)==3)){
        printf("Matriu dolenta");
    }


    
    printf("Matriu final\n");
    for(i=0; i<n;i++){
        for(j=0; j<n;j++){
            printf(" %16.7e ", a[i][j]);
        }
        printf("\n");
    }
    printf("Vector \n");
    for(i=0; i<n; i++){
        printf(" %16.7e \n", b[i]);
    }
    printf("Vector resolució \n");
    for(i=0; i<n; i++){
        printf( "%16.7e \n", x[i]);
    }
    prodMatVec(n, copia, x, y);

    for(i=0; i<n;i++){
        resultResta[i]=0.;
    }
    for(i=0; i<n;i++){
        resultResta[i]=b[i]-y[i];
    }
    printf("Vector RESULTAT \n");
    for(i=0; i<n; i++){
        printf( "%16.7e \n", resultResta[i]);
    }
    resulNorma2=norma2(n,resultResta);
    
    printf("Bondat trobada \n");
    printf("%16.5e",resulNorma2);
    

    for(i=0; i<n; i++){
        free (a[i]);
    }

    free(a);
    free(b);
     
    return 0;
}
    
    
    


 