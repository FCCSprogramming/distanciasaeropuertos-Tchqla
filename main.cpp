#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
void merge(double arr[], int left, int mid, int right){
    int n1=mid-left+1;
    int n2=right-mid;

    double *L=new double[n1];
    double *R=new double[n2];

    for (int i = 0; i < n1; i++)
    {
        *(L+i)=*(arr+left+i);
    }
    for (int j = 0; j < n2; j++)
    {
        *(R+j)=*(arr+mid+1+j);
    }

    int i=0;
    int j=0;
    int k=left;

    while(i<n1 && j<n2){
        if(*(L+i)<=*(R+j)){
            *(arr+k)=*(L+i);
            i++;
        }
        else{
            *(arr+k)=*(R+j);
            j++;
        }
        k++;
    }

    while(i<n1){
        *(arr+k)=*(L+i);
        i++;
        k++;
    }

    while(j<n2){
        *(arr+k)=*(R+j);
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void merge_sort(double *arr, int left, int right){
    if(left<right){
        int mid=left+(right-left)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void matrix_symme(double **arr, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j){
                *(*(arr+i)+j)=0;
            }
            else{
                double r=(rand()%(1500-100+1)+100)+ (rand()%100)/100.0;//siempre sale entero
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

    cout << "\t";
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
    merge_sort(prom,0,n-1);

    delete[] prom;
    for (int i = 0; i < n; i++){
        delete[] *(aero+i);
    }
    delete[] aero;

    return 0;
}