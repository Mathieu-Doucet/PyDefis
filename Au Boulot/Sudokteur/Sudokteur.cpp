//equilibre le sudokteur
// https://pydefis.callicode.fr/defis/C23_Sudokteur/txt
#include <iostream>
using namespace std;

#include <vector>
#include<algorithm>


int main() {


    string Donnes = "";

    // 0 - 9 et .
    vector<int> array(11,0);

    while(getline(cin, Donnes)){

        for(auto nombre : Donnes){

            if (nombre == '.'){
                array[10]++;
                continue;
            }

            //prend le nombre et stoker
            nombre = nombre - '0';
            array[nombre]++;
        }


        
    }
    
    int trou = array[11];
    auto max = max_element(array.begin() , array.end()) ;
    

    int ajout[10] = {0};
    string output = "";

    //equilibre toute a le max
    for (int i = 0 ; i < 10 ; ++i){
        
        int delta = *max - array[i];
        cout << delta << endl;

        if (delta != 0 ){

            for (int j = 0 ; j < delta ; ++j){
                output.append(to_string(i));
            }
        }
    }
    // reponce
    cout <<endl << output << endl;;



    //debuging
    for (auto nombrearray : array){
        cout << nombrearray << endl;
    }

    cout << endl << endl << *max << endl << trou << endl << endl;
    return 0;
}