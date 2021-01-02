#include<bits/stdc++.h>
#include "../include/headerFile.h"

using namespace std;


// tupla de parametros del problema: E_i T_i L_i g h
typedef tuple<int, int, int, double, double> problemParameters;

// matriz de separacion de llegadas de aviones
typedef vector<vector<int>> SIJ;


int main(int argc, char const *argv[])
{
    // variables
    int e,t,l;
    double g,h;
    int tmp;

    // seed for rng
    srand(123);

    int N_Planes;
    cin >> N_Planes;
    
    //solution
    vector<int> solution;
    
    //problem parameters
    vector<problemParameters> pP;
    
    // for each plane S_ij
    SIJ S_ij;

    // initial data reading
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

    // initial solution
    generateInitialSolution(solution, pP, N_Planes);
    printSol(solution);

    return 0;
}
