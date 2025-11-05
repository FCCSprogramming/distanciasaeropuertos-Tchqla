#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void matrix_symme(double **arr, int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j){
                *(*(arr+i)+j)=0;
            }
            else{
                double r=(rand()%(1500-100+1)+100)+ (rand()%100)/100.0;
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

void liberarmatriz(double **arr, int n){
    for (int i = 0; i < n; i++)
    {
        delete[] *(arr+i);
    }
    delete[] arr;
}