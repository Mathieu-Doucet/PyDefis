//https://pydefis.callicode.fr/defis/PokePlusRare/txt

#include <bits/stdc++.h>

using namespace std;

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


int main(){

    string Line;
    vector<string> Pokemons;
    vector<vector<string>> Raw;
    set<string> PokemonName;
    
    while(getline(cin,Line)){

        vector<string> Token = tokenize(Line);

        Pokemons.push_back(Token[0]);

        PokemonName.insert(Token[0]);

        Raw.push_back(Token);

    }


    string pokemonMin;
    int min = 200000;
    for (auto poke : PokemonName){

        int nombre = count(Pokemons.begin() , Pokemons.end(), poke);

        if (nombre <= min){
            pokemonMin = poke;
            min = nombre;
        }

    }

    cout << pokemonMin << "  : " << min << endl;

    
}