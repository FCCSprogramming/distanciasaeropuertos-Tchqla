#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void matrix_symme(double **arr, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j){
                *(*(arr+i)+j)=0;
            }
            else{
                double r=rand()%(1500-100+1)+100;//siempre sale entero
                *(*(arr+i)+j)=r;
                *(*(arr+j)+i)=r;
            }
        }
    }
}

void show_matrix(double **arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "aero " << i+1 << "\t";
        for (int j = 0; j < n; j++)
        {
            cout << *(*(arr+i)+j) << "\t";
        }
        cout << endl;
    }
}

double prom_dist(double **arr, int n, int c){
    double sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=*(*(arr+c)+i);
    }
    return sum/(n-1);
}

int main(){
    srand(time(NULL));
    int n;
    cout << "indique la cantidad de aeropuertos: ";
    cin >> n;
    double **aero=new double*[n];
    for (int i = 0; i < n; i++)
    {
        *(aero+i)=new double[n];
    }

    matrix_symme(aero,n);

    for (int i = 0; i < n; i++)
    {
        cout << "aero " << i+1 << "\t";
    }
    cout << endl;

    show_matrix(aero,n);

    double *prom= new double[n];
    for (int i = 0; i < n; i++){
        *(prom+i)=prom_dist(aero,n,i);
        cout << "promedio de distancias del aeropuerto " << i+1 << ": " << *(prom+i)<< endl; //talvez lo deje
    }

    delete[] prom;
    for (int i = 0; i < n; i++){
        delete[] *(aero+i);
    }
    delete[] aero;

    return 0;
}