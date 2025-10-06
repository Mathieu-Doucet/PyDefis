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
    map<string,pair<int,int>> Coords;
    
    while(getline(cin,Line)){

        vector<string> Token = tokenize(Line);

        Pokemons.push_back(Token[0]);

        Coords[Token[0]] = make_pair(stoi(Token[1]) , stoi(Token[2]));

    }

    string unique;
    for (auto poke : Coords){

        int nombre = count(Pokemons.begin() , Pokemons.end(), poke.first);
        if (nombre == 1){
            unique = poke.first;
        }

    }

    cout <<unique << "  : " <<  Coords[unique].first << ", " <<  Coords[unique].second << endl;


}