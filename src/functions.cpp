#include <bits/stdc++.h>
#include "../include/headerFile.h"

using namespace std;


// tupla de parametros del problema: E_i T_i L_i g h
typedef tuple<int, int, int, double, double> problemParameters;

// matriz de separacion de llegadas de aviones
typedef vector<vector<int>> SIJ;


void printSol(vector<int> x){
    for(auto i: x){
        cout << i << ' ';
    }
    cout << endl;
}


void printSIJ(SIJ x){
    for(auto i: x){
        for(auto ij: i)
            cout << ij << ' ';
        cout << endl;
    }
    cout << endl;
}


void printPP(vector<problemParameters> x){
    for(auto i: x){
        cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << ' ' << get<3>(i) << ' ' << get<4>(i) << endl;
    }
    cout << endl;
}


double calculateCost(vector<problemParameters> params, vector<int> sol){
    double z;
    int alpha_i, beta_i;
    int T_i, x_i;

    for (int i = 0; i < sol.size(); i++)
    {

        T_i = get<1>(params[i]);
        x_i = sol[i];

        alpha_i = max({0, x_i - T_i});
        beta_i = max({0, T_i - x_i});

        z = z + alpha_i + beta_i;
    }

    return z;
}


void generateInitialSolution(vector<int> &sol, vector<problemParameters> params, int N_Planes){
    
    int diff, rng;
    
    for (int i = 0; i < N_Planes; i++)
    {
        diff = get<2>(params[i]) - get<0>(params[i]);

        rng = rand() % diff + get<0>(params[i]);
        sol.push_back(rng);
    }
}


void hillClimb_FirstImprovement(vector<problemParameters> params, SIJ sij, vector<int> solution, int N_Planes, unsigned int T_MAX, unsigned int MAX_NEIGHBORS){

    unsigned int t = 0;

    //s_best = solution
    
    bool local = false;

    vector<int> sc;
    vector<int> sn_prime;

    do
    {
        generateInitialSolution(sc, params, N_Planes);

        unsigned int neighbor = 0;

        do
        {
            //generateNeighbor(sn_prime, sc, sij, params);
            neighbor++;
            
            if(calculateCost(params, sn_prime) <= calculateCost(params, sc)){
                sc = sn_prime;
                neighbor = 0;

            }if(neighbor == MAX_NEIGHBORS){
                local =  true;
            }
        } while (!local);
        
        t++;

        if(calculateCost(params, sc) <= calculateCost(params, solution)){
            solution = sc;
        }

    } while (t != T_MAX);    
}
