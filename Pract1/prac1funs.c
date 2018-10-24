#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int resTsup(int n, double **A, double *b, double *x, double tol){
int i,z;
double sum;

for(i=n-1; i>=0; i--){
    if((fabs(A[i][i]))<tol){
            return 1;
        }
    z=i+1;
    sum=0;
    while(z<n){

        sum=sum+(A[i][z]*x[z]);
        z=z+1;
    }
    x[i]=(b[i]-sum)/(A[i][i]);

    }
return 0;
}

void prodMatVec(int n, double **A, double *x, double *y){
    int i,j;
 
 
    for(i=0; i<n;i++){
        y[i]=0;
        for(j=0;j<n;j++){
            y[i]+=A[i][j]*x[j];
            

        }
        
    }
    }
    

double norma2(int n, double *z){
    int i;
    double suma,resul;
    suma=0;
    for(i=0; i<n; i++){
        
        suma=suma+z[i];
    }
    resul=abs(suma);
    resul=sqrt(resul);
    return resul;
}


int gauss(int n, double **A, double *v, double tol){
    int i,k,j;
    double x, y;

    for(k=0;k<n-1;k++){
        if((fabs(A[k][k]))<tol){
            return 1;
        }
        x=A[k][k];
        for(i=k+1;i<n;i++){
            y=A[i][k];
            v[i]=((v[i])-((y/x)*v[k]));
            for(j=0;j<n;j++){
                A[i][j]=((A[i][j])-((y/x)*A[k][j]));
            }
        }
    }
    return 0;
}

int gausspivot(int n, double **A, double *v, double tol){
    int i,k,j,z,fila,temp;
    double x,y;
    fila=0;
    temp=0;
    x=0;

    for(k=0; k<n-1; k++){
        for(z=0; z<n-1; z++){
            if(A[z][k]>x){
                x=A[z][k];
                fila=z;
        }
        }
        if(x!=A[k][0]){
            for(i=0;i<n;i++){
                temp=A[i][k];
                A[i][k]=A[fila][i];
                A[fila][i]=temp;
            }
        }
            
    
    }

    return 0;

}




        

    


