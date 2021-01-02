#include<bits/stdc++.h>
using namespace std;


#ifndef HEADER_FILE
#define HEADER_FILE

// tupla de parametros del problema: E_i T_i L_i g h
typedef tuple<int, int, int, double, double> problemParameters;

// matriz de separacion de llegadas de aviones
typedef vector<vector<int>> SIJ;

/* void printSol
* 
* Descripcion: 
*       Print solucion actual
*
* Input:
*       vector<int> x: solucion a mostrar
*
* Retorna:
*       nada
*/
void printSol(vector<int> x);


/* void printSIJ
* 
* Descripcion: 
*       Print de los parametros S_ij
*
* Input:
*       SIJ x: matriz de separaciones entre aviones a mostrar
*
* Retorna:
*       nada
*/
void printSIJ(SIJ x);


/* void printPP
* 
* Descripcion: 
*       Print de los parametros e/t/l/g/h
*
* Input:
*       vector<problemParameters> params: parametros ideales y costos de cada avion
*
* Retorna:
*       nada
*/
void printPP(vector<problemParameters> x);


/* double calculateCost
* 
* Descripcion: 
*       Calcula el costo Z de una solucion
*
* Input:
*       vector<problemParameters> params: parametros ideales y costos de cada avion
*       vector<int> sol: vector a asignar solucion aleatoria
*
* Retorna:
*       double z: el costo de la solucion
*/
double calculateCost(vector<problemParameters> params, vector<int> sol);


/* void generateInitialSolution
* 
* Descripcion: 
*       Genera una solucion inicial aleatoria
*
* Input:
*       vector<int> sol: vector a asignar solucion aleatoria
*       vector<problemParameters> params: parametros ideales y costos de cada avion
*       int N_Planes: cantidad total de aviones
*
* Retorna:
*       nada
*/
void generateInitialSolution(vector<int> &sol, vector<problemParameters> params, int N_Planes);


/* vector<int> hillClimb_FirstImprovement
*
* Descripcion: 
*       resuelve el problema de alsp usando el algoritmo de hill-climb first improvement con restart
*
* Input:
*       vector<problemParameters> params: parametros ideales y costos de cada avion
*       SIJ sij: matriz de separaciones entre aviones
*       int N_Planes: cantidad total de aviones
*       unsigned int T_MAX: tiempo maximo de ejecucion del algoritmo
*       unsigned int MAX_NEIGHBORS: cantidad maxima de vecinos permitidos en un vecindario
*
* Retorna:
*       nada
*/
void hillClimb_FirstImprovement(vector<problemParameters> params, SIJ sij, vector<int> solution, int N_Planes, unsigned int T_MAX, unsigned int MAX_NEIGHBORS);

#endif