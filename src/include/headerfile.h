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


/* bool isFeasible
* 
* Descripcion: 
*       indica si una solucion es factible
*
* Input:
*       vector<problemParameters> params: parametros ideales y costos de cada avion
*       SIJ sij: matriz de separaciones entre aviones
*       vector<int> sol: vector solucion
*
* Retorna:
*       bool: si una solucion es factible retorna true, de lo contrario false
*/
bool isFeasible(vector<problemParameters> params, SIJ Sij, vector<int> sol);


/* double calculateCost
* 
* Descripcion: 
*       Calcula el costo Z de una solucion
*
* Input:
*       vector<problemParameters> params: parametros ideales y costos de cada avion
*       SIJ sij: matriz de separaciones entre aviones
*       vector<int> sol: vector a asignar solucion aleatoria
*
* Retorna:
*       double z: el costo de la solucion
*/
double calculateCost(vector<problemParameters> params,  SIJ Sij, vector<int> sol);


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


/* void generateneighbour
*
* Descripcion: 
*       Genera un vecino de v. Se genera neighbour
*
* Input:
*       vector<int> v: vector del que se obtiene un vecino
*       int vSize: tamano de v
*       vector<int> neighbour: vecino de v
*       vector<problemParameters> params: parametros ideales y costos de cada avion
*       SIJ sij: matriz de separaciones entre aviones
*       int N_Planes: cantidad total de aviones
*
* Retorna:
*       nada
*/
void generateneighbour(vector<int> v, int vSize, vector<int> &neighbour, vector<problemParameters> params, SIJ sij);


/* void hillClimb_FirstImprovement
*
* Descripcion: 
*       resuelve el problema de alsp usando el algoritmo de hill-climb first improvement con restart
*
* Input:
*       vector<problemParameters> params: parametros ideales y costos de cada avion
*       SIJ sij: matriz de separaciones entre aviones
*       int N_Planes: cantidad total de aviones
*       unsigned int T_MAX: tiempo maximo de ejecucion del algoritmo
*       unsigned int MAX_neighbourS: cantidad maxima de vecinos permitidos en un vecindario
*
* Retorna:
*       unsigned int t: cantidad de vecindarios revisados
*/
unsigned int hillClimb_FirstImprovement(vector<problemParameters> params, SIJ sij, vector<int> &sol, int N_Planes, unsigned int T_MAX, unsigned int MAX_neighbourS);

#endif