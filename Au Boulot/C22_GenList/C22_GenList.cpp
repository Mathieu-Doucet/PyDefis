//syntheiser le pokedex
//https://pydefis.callicode.fr/defis/C22_GenList/txt

#include <iostream>
using namespace std;

#include <vector>
#include<algorithm>
#include<regex>


vector<string> tokenize(const string &s)
{
	regex expreg("[\\s,.]+");
	sregex_token_iterator it(s.begin(), s.end(), expreg, -1);
	sregex_token_iterator reg_end;
	vector<string> tokens;
	for (; it != reg_end; ++it)
		tokens.push_back(it->str());

	return tokens;

	
} // tokenize()


int main() {


    string Donnes = "";
    getline(cin, Donnes);

    vector<string> PokemonNombre = tokenize(Donnes);

    vector<int> PokemonSort;

    for(auto i : PokemonNombre){
        PokemonSort.push_back(stoi(i));
    }

    sort(PokemonSort.begin(), PokemonSort.end());

    string output = to_string(PokemonSort[0]);

    bool IsAStreak= true;
    int streakStart = PokemonSort[0];
    int PrevieuseNombre = streakStart;


    for(int i = 1 ; i < PokemonSort.size() ; ++i){
        
        int nombre = PokemonSort[i];
        //not a streak 
        if ( (nombre - PrevieuseNombre) != 1){

        
            if (IsAStreak){
                string temp = "-" + to_string(PrevieuseNombre) + ",";
                output.append(temp);
            }
            else{
                output.append(",");
            }
            
            IsAStreak = false;

            output.append(to_string(nombre));

            streakStart = nombre;
            PrevieuseNombre = nombre;
            
            continue;

        }

        IsAStreak = true;
        PrevieuseNombre = nombre;
        

        

    }

    if (IsAStreak){
        string temp = "-" + to_string(PrevieuseNombre) + ",";
        output.append(temp);
    }
    else{
        output.append(",");
    }
    
    cout << output << endl;


    return 0;
}