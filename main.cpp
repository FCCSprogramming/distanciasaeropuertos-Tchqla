#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j){
                *(*(aero+i)+j)=0;
            }
            else{
                double r=rand()%(1500-100+1)+100;
                *(*(aero+i)+j)=r;
                *(*(aero+j)+i)=r;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << *(*(aero+i)+j) << "\t";
        }
        cout << endl;
    }

    return 0;
}

//readme: debo crear el repositorio local y luego subirlo a github


// Repository URL:
//https://github.com/FCCSprogramming/distanciasaeropuertos-Tchqla.git