
//https://pydefis.callicode.fr/defis/Queulorior/txt
#include <bits/stdc++.h>
using namespace std;



int main(){

    // long message qui est 4x100 de 0 et va devenir des 1 pour visualier le message avec les direction
    auto message = vector<vector<char>> (5, (vector<char>(250, ' ')));

    string direction = "";


    getline(cin,direction);




    /*
    dessin remplie possible
    #-#-#
    | | |
    #-#-#
    | | |
    #-#-#  
    
    */
    // commence en bas a gauche
    int i = 4; 
    int j = 0;
    for (auto lettre : direction){

        if (lettre == 'N'){
            
            // rempli la jointure
            message[i][j] =  '#';
            i--;
            // fait la ligne
            message[i][j] =  '|';
            i--;

        }
        if (lettre == 'S'){
            // rempli la jointure
            message[i][j] =  '#';
            i++;
            // fait la ligne
            message[i][j] =  '|';
            i++;
        }
        if (lettre == 'E'){

            // rempli la jointure
            message[i][j] =  '#';
            j++;
            // fait la ligne
            message[i][j] =  '-';
            j++;
        }
        if (lettre == 'O'){
            // rempli la jointure
            message[i][j] =  '#';
            j--;
            // fait la ligne
            message[i][j] =  '-';
            j--;
        }

    }



    // bloc de 4X25 
    for (int offset = 0 ; offset *100 < message[0].size(); ++offset  ){

        for (int i = 0 ; i < message.size() ; ++i){

            for (int j = 0; j < 100 ; ++j){
                
                cout << message[i][j + (offset * 100)];
            }
            //separe la column
            cout <<endl;
    
        }

        // separe le bloc
        cout << endl << endl;


    }

    // avec la sortie jai peut trouver la reponce (fait attention avec le v et y   pi D et O)
    // le context de pokemon a aussi aider

    cout << endl << endl << endl << endl;





}