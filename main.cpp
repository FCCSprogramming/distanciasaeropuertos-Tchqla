#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "funciones.h"
using namespace std;

int main(){
    int n;
    cout << "indique la cantidad de aeropuertos: ";
    cin >> n;
    double **aero=new double*[n];
    for (int i = 0; i < n; i++)
    {
        *(aero+i)=new double[n];
    }

    matrix_symme(aero,n);

    cout << "\t";
    for (int i = 0; i < n; i++)
    {
        cout << "aero " << i+1 << "\t";
    }
    cout << endl;

    show_matrix(aero,n);

    double *prom= new double[n];
    int *p= new int[n];
    for (int i = 0; i < n; i++){
        *(prom+i)=prom_dist(aero,n,i);
        cout << "promedio de distancias del aeropuerto " << i+1 << ": " << *(prom+i)<< endl; //talvez lo deje
    }

    double min_dist = prom[0];
    int min_airport = 1;
    for(int i = 1; i < n; i++) {
        if(prom[i] < min_dist) {
            min_dist = prom[i];
            min_airport = i + 1;
        }
    }
    cout << "\nel aeropuerto con menor distancia promedio es el aeropuerto " << min_airport << " con una distancia promedio de " << min_dist << endl;

    delete[] prom;
    
    liberarmatriz(aero,n);

    return 0;
}