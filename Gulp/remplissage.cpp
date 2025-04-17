//https://pydefis.callicode.fr/defis/Sacados/txt

#include <bits/stdc++.h>
using namespace std;

bool backtrack (vector<int>const &nombres , int somme, set<int> selectionner, vector<int> &reponse){

    // trouver la combination qui donne la somme desirer
    if(somme == 0){
        return true;
    }
    // dans le negative donc est pas bon
    if (somme <0){
        return false;
    }

    // cas general 
    for(auto nombre : nombres){

        if(selectionner.find(nombre) != selectionner.cend()){
            continue;
        }

        // mes le nombre dans selecter 
        selectionner.insert(nombre);

        if (backtrack(nombres , somme - nombre , selectionner, reponse)){
            
            // est tu la premiere fois tu va entrer dans le for loop
            if(reponse.size() == 0){
                //trouver la reponce donc metre la reponce dans la reponce
                for(auto i : selectionner){
                    reponse.push_back(i);
                }

            }
            
            return true;
        }

        // enleve le nombre et essayer un nouveaux (BACKTRACKING)
        selectionner.erase(selectionner.find(nombre));


    }
    // essayer tout les nombres et pas trouver un cas.
    return false;

}
int main(){
    //
    //nombre possible
    vector<int> nombres = {12, 24, 31, 77, 87, 103, 112, 145, 181, 197, 205, 217, 224, 225, 228, 255, 263, 278, 289, 297};
    vector<int> valid;
    set<int> used;
    
    //appel pour le probleme
    backtrack(nombres, 1881, used , valid );

    // metre tout les nombre dans le terminal
    for(auto i : valid){
        cout << i << ", ";
    }
    
    return 0;
}