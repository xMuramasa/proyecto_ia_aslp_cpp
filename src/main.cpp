#include <unistd.h>
#include<bits/stdc++.h>
#include "include/headerFile.h"

using namespace std;

//solution
vector<int> solution;

//problem parameters
vector<problemParameters> pP;

// for each plane S_ij
SIJ S_ij;

// varibales necesarias para hill-climbing
unsigned int T_MAX = 1000;
unsigned int MAX_NEIGHBORS = 500;


//timeee
time_t start, stop;


// CTRL-C handler de tutorialspoint.com
// Define the function to be called when ctrl-c (SIGINT) is sent to process
void signal_callback_handler(int signum) {
    cout << endl << "CTRL-C detectado, signum=" << signum << endl;
    cout << endl << "La solucion actual es:" << endl;
    printSol(solution);
    time(&stop);
    cout << "Con un costo de: " << calculateCost(pP, S_ij, solution) << endl << endl;
    cout << "tiempo de ejecucion: " << stop-start << " segundos" << endl << endl;
    // Terminate program
    exit(signum);
}


// tupla de parametros del problema: E_i T_i L_i g h
typedef tuple<int, int, int, double, double> problemParameters;

// matriz de separacion de llegadas de aviones
typedef vector<vector<int>> SIJ;


int main(int argc, char const *argv[])
{

    signal(SIGINT, signal_callback_handler);

    int seed = 123;

    if(argc > 2){
        MAX_NEIGHBORS = atoi(argv[1]);
        T_MAX = atoi(argv[2]);
        seed = atoi(argv[3]);

    }
    cout << endl << "Args de entrada" << endl;
    cout << "SEED: " << seed << endl;
    cout << "T_MAX: " << T_MAX << endl;
    cout << "MAX_NEIGHBORS: " << MAX_NEIGHBORS << endl;


    // variables
    int e,t,l;
    double g,h;
    int tmp;

    // seed for rng
    // seed = 314 lmao
    //srand(314);
    srand(seed);

    // lectura de datos
    // cantidad de aviones
    int N_Planes;
    cin >> N_Planes;

    // info de aviones
    for (int i = 0; i < N_Planes; i++)
    {
        vector<int> S_ij_temp;
        
        cin >> e >> t >> l >> g >> h;
        problemParameters tmpTuple = make_tuple(e,t,l,g,h);

        for (int j = 0; j < N_Planes; j++) {
            cin >> tmp;
            S_ij_temp.push_back(tmp);
        }
        S_ij.push_back(S_ij_temp);
        pP.push_back(tmpTuple);
    }

    time(&start);
    hillClimb_FirstImprovement(pP, S_ij, solution, N_Planes, T_MAX, MAX_NEIGHBORS);
    time(&stop);
    cout << endl << "La solucion actual es:" << endl;
    printSol(solution);
    cout << "Con un costo de: " << calculateCost(pP, S_ij, solution) << endl << endl;
    cout << "tiempo de ejecucion: " << stop-start << " segundos" << endl << endl;

    return 0;
}
