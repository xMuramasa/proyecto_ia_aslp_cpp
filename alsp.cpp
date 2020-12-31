#include<bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int, double, double> problemParameters;
typedef vector<vector<int>> SIJ;

/* void printSIJ
* Print de los parametros S_ij
*/
void printSIJ(SIJ x){
    for(auto i: x){
        for(auto ij: i)
            cout << ij << ' ';
        cout << endl;
    }
    cout << endl;
}


/* void printPP
* Print de los parametros e/t/l/g/h
*/
void printPP(vector<problemParameters> x){
    for(auto i: x){
        cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << ' ' << get<3>(i) << ' ' << get<4>(i) << endl;
    }
}


/* double calculateCost
* Calcula el costo Z de una solucion
*/
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


/* void readData
* lee input desde stdin
*/
void readData(int N_Planes, SIJ S_ij, vector<problemParameters> pP){
    int e,t,l;
    double g,h;
    int tmp;

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
}


/* void generateInitialSolution
* Genera una solucion inicial
*/
void generateInitialSolution(vector<int> solution, int size, vector<problemParameters> params){

}


int main(int argc, char const *argv[])
{
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

    // data reading
    readData(N_Planes, S_ij, pP);

    // initial solution
    generateInitialSolution(solution, N_Planes, pP);
    
    
    printSIJ(S_ij);
    printPP(pP);

    printf("%ld\n", solution.size());

    return 0;
}
