
//link et la salle infernale
//https://pydefis.callicode.fr/defis/C22_LabyLink/txt


//

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> Maze = {
    {'R', 'B', 'J', 'R', 'R', 'R', 'J', 'R', 'R', 'R'},
    {'J', 'B', 'R', 'R', 'J', 'J', 'Z', 'J', 'B', 'B'},
    {'B', 'J', 'J', 'B', 'Z', 'B', 'B', 'J', 'R', 'J'},
    {'J', 'Z', 'Z', 'B', 'J', 'B', 'B', 'R', 'B', 'B'},
    {'R', 'R', 'J', 'J', 'R', 'B', 'J', 'B', 'J', 'R'}
};
//borne maximal
int MaxI = 4;
int MaxJ = 9;


//trouver toute les path qui remplie toute les cass de la salle 
void AllPaths(int i , int j, char move, string CurrentPath, vector<vector<bool>> visitedTiles ,vector<string> &ValidPaths  ){

    // cas de retour
    
    // Si tu a pas de option de bouger return
    if( i < 0 || i > MaxI || j < 0 || j > MaxJ ){
        return;
    }

    if ( visitedTiles[i][j]){
        return;
    }

    // nous somme dans une nouvelle cas valid. update le current path
    CurrentPath.push_back(move);
    visitedTiles[i][j] = 1;


    //Il y a 46 tiles qui peut etre activer. donc si le string est 46 tu a fini
    if (CurrentPath.length() == 46){
        ValidPaths.push_back(CurrentPath);
        cout << CurrentPath <<  endl << endl;
        return;
    }


    //vesion 2 

    //4 direction et le cas de retour va gerer des cas mal

    // appel up
    AllPaths( i -1 , j , 'H', CurrentPath , visitedTiles, ValidPaths);

    // appel down 
    AllPaths( i +1 , j ,'B', CurrentPath , visitedTiles, ValidPaths);

    // appel gauche
    AllPaths( i , j -1 ,'G', CurrentPath , visitedTiles, ValidPaths);

    // appel droite
    AllPaths( i , j +1, 'D' ,CurrentPath , visitedTiles, ValidPaths);

    return;

}



int main(){
    
    

    vector<vector<bool>> Visited (MaxI + 1,vector<bool> (MaxJ+1, 0));

    //fait les espace noir visited
    Visited[3][1] = 1;
    Visited[3][2] = 1;
    Visited[2][4] = 1;
    Visited[1][6] = 1;

    //first cas de link 
    //Visited[2][MaxJ] = 1;

  

    //affice visited
    for (auto i : Visited){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
    //affice colour maze
    for (auto i : Maze){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    //commence toujours avec G
    string Path = "";
    vector<string> ValidPaths;

    AllPaths( 2 , MaxJ , 'G', Path, Visited, ValidPaths);
    
    cout << endl << endl;

    cout << ValidPaths.size() << endl;

    // 5642 cas qui fill qui fait du sens? 
    // nois jai besoin trouver le plus petit difference?

    int MinDifference = 100;
    string MinPath = "";
    for (auto s : ValidPaths){

        int LinkI = 2;
        int LinkJ = MaxJ;
        int changements = 1; // premier step est un changement
        char LastColor = 'J';

        cout << s << endl;
        // trouver commen de difference 
        for (int i = 1 ; i < s.length() ; ++i){

            //Bouger link avec la lettre
            if (s[i] == 'H'){
                LinkI--;
            }
            else if(s[i] == 'B'){
                LinkI++;
            }
            else if(s[i] == 'G'){
                LinkJ--;
            }
            else if (s[i] == 'D'){
                LinkJ++;
            }

            // si est une difference
            if (Maze[LinkI][LinkJ] != LastColor){
                changements++;
            }
            LastColor = Maze[LinkI][LinkJ];


        }

        if (changements < MinDifference){
            MinPath = s;
            MinDifference = changements;
        }

    }   
    
    cout << MinDifference<< endl << MinPath << endl;
    



}
    














