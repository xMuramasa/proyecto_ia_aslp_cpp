#include <bits/stdc++.h>
#include "include/headerFile.h"

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


bool isFeasible(vector<problemParameters> params, SIJ Sij, vector<int> sol){

    int count = sol.size();
    int desf = 0;
    int diff = 0;

    if (count == 0) return false;

    for (int i = 0; i < count; i++){
        // fuera del dominio
        if( (sol[i] < get<1>(params[i])) || (get<2>(params[i]) < sol[i]) ) return false; 

        for (int j = 0; j < count; j++)
        {
            if ( i != j) {

                desf = sol[i] + Sij[i][j];
                diff = abs(sol[i] - sol[j]);

                // fuera del dominio
                if( (desf < get<1>(params[i])) || (get<2>(params[i]) < desf) ) return false; 

                // no cumple restriccion de matriz
                if ( diff < Sij[i][j]) return false;
                
            }
        }
    }

    return true;
}


double calculateCost(vector<problemParameters> params, SIJ Sij, vector<int> sol){
    
    long double z = 9999999;
    
    int T_i, x_i;
    int alpha_i, beta_i;
    double g_i, h_i;

    bool flag = isFeasible(params, Sij, sol);

    if (flag){
        z = 0;
        for (int i = 0; i < sol.size(); i++)
        {
            T_i = get<1>(params[i]);
            x_i = sol[i];

            g_i = get<3>(params[i]);
            h_i = get<4>(params[i]);

            alpha_i = max({0, x_i - T_i});
            beta_i = max({0, T_i - x_i});

            z = z + alpha_i * g_i + beta_i * h_i;
        }
    }
    return z;
}


void generateInitialSolution(vector<int> &sol, vector<problemParameters> params, int N_Planes){
    
    int diff, rng;

    if(sol.size() != 0){
        sol.clear();
    }
    
    for (int i = 0; i < N_Planes; i++)
    {
        diff = get<2>(params[i]) - get<0>(params[i]);

        rng = rand() % diff + get<0>(params[i]);
        sol.push_back(rng);
    }
}


void generateNeighbor(vector<int> v, int vSize, vector<int> &neighbor, vector<problemParameters> params, SIJ sij){

    int randPos = rand() % vSize;
    int variation = 0;
    int diff = 0;
    int i = 0;

    if(neighbor.size() != 0){
        neighbor.clear();
    }

    for ( i = 0; i < vSize; i++){   
        if(randPos != i){
            neighbor.push_back(v[i]);

        }else{
            diff = get<2>(params[i]) - get<0>(params[i]);
            variation = rand() % diff + get<0>(params[i]);

            neighbor.push_back(variation);
        }
    }
}


unsigned int hillClimb_FirstImprovement(vector<problemParameters> params, SIJ sij, vector<int> &sol, int N_Planes, unsigned int T_MAX, unsigned int MAX_NEIGHBORS){

    unsigned int t = 0;

    bool local;
    
    //s_best -> solution
    vector<int> sc;
    vector<int> sn_prime;

    do
    {
        local = false;
        generateInitialSolution(sc, params, N_Planes);

        unsigned int neighbor = 0;

        do
        {
            generateNeighbor(sc, N_Planes, sn_prime, params, sij);
            neighbor++;
            
            if(calculateCost(params, sij, sn_prime) < calculateCost(params, sij, sc)){
                sc = sn_prime;
                neighbor = 0;

            }if(neighbor == MAX_NEIGHBORS){
                local =  true;
            }
            
        } while (!local);
        
        t++;

        if(calculateCost(params, sij, sc) < calculateCost(params, sij, sol)){
            sol = sc;
        }

    } while (t != T_MAX);    

    return t;
}
