// https://www.geeksforgeeks.org/maximum-number-of-overlapping-intervals/
// Maximum number of overlap among given ranges
#include <bits/stdc++.h>

using namespace std;



// Vous pouvez par exemple utiliser une table de hachage (<map>) pour conserver les cor-
//respondances entre les nombres de minutes calculés et les formats originaux en entrée
//(jj/mm/yyyy hh:mm)
unordered_map<time_t,string> SecondsACalendrier;

// code donner par mon prof eric hervert pour une enoncer d'un devoir
// Nombre maximal d'overlaps
void overlap(const vector<pair<time_t, time_t>> &v)
{ 
	int ans = 0, count = 0;

	// On crée des associations first <--> 'x' et second <--> 'y'
	vector<pair<time_t, char>> data;

	for(size_t i = 0; i < v.size(); i++)
	{
		data.push_back({v[i].first, 'x'});
		data.push_back({v[i].second, 'y'});
	}

	// On trie (selon les 'x')
	sort(data.begin(), data.end()); // O(n x log(n))

	// variable pour le temps de visiter l'ile
	time_t TempsDeVisiteOptimal = data[0].first;

	/*for(auto &x: data)
		cout << '(' << x.first << ',' << x.second << ") ";
	cout << '\n';*/

	for(size_t i = 0; i < data.size(); i++)
	{
		// Si on rencontre un 'x', on compte un intervalle de plus comme overlap
		if(data[i].second == 'x')
			count++;

		// Si on rencontre un 'y', on compte un intervalle de moins comme overlap
		if(data[i].second == 'y'){
			count--;
			
		}
		
		
		if(ans < count){
			TempsDeVisiteOptimal = data[i].first;
			//cout << endl << ans << endl << TempsDeVisiteOptimal << endl;
			
		}

		ans = max(ans, count);
		// si la reponce est le count premier instance pour count veut dire que le temps pour visiter est optimal maintenant

		
	}

	// trouver la reponce donc affiche les pokemons sur l'ile et le temps optimal
	cout << ans << endl;
	cout << SecondsACalendrier[TempsDeVisiteOptimal * 60] << endl;

	

	//besoin user ctime pour donner un time_t dans calendar

} // overlap()

// tokenizer change le input a le output donner (donner par eric hervert)
//Arceus : 19/12/2040 19:34, 1193671
// vector<sting> =[ , 19/12/2040 , 19:34 , 1193671]

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

int main() 
{ 
	

    string PokemonName;
    string entree;
    vector<string> donneesDeTemps;
    vector<pair<time_t, time_t>> VisitePokemon; // chaque intervalle = paire {first, second}
    string buffertemp = " ";
    int NombreDeVisite = 0;

	//traite tout les temps les pokemon est sur l'ile
    while(cin >> PokemonName){

        
        string test;
        cin >> buffertemp; // enlever le : pour preparer le get line

        getline(cin, test);
        donneesDeTemps = tokenize(test);

		// element du vecteur
		//				1         2       3
        ////Arceus : 19/12/2040 19:34, 1193671
        string datePokemon = donneesDeTemps[1] +" " + donneesDeTemps[2];

	    struct tm temps{};

		//transform le string de la date du pokemon en seconds
        strptime(datePokemon.c_str(), "%d/%m/%Y %H:%M", &temps);


		//nombre de seconds qui a passer depuis le unix time
        time_t unixPokemon= mktime(&temps);

		SecondsACalendrier.insert({unixPokemon,datePokemon});

		//iterateur pour le vecteur des visits
        NombreDeVisite++;
		//resize le vecteur pour la nouvelle visite
        VisitePokemon.resize(NombreDeVisite);

		//ajoute l'arriver du pokemon et la sortie dans des minutes
        VisitePokemon[NombreDeVisite -1 ].first =unixPokemon/60;
        VisitePokemon[NombreDeVisite -1 ].second = (unixPokemon/60)+(stoi(donneesDeTemps[3])) ;
       
	    //cout << unixPokemon << endl; // nombre de secondes depuis le 1er janvier 1970

	
    }
    
 

    //rentrer les donner dans un vector de pair pour le formater dans le overlap function
	vector<pair<time_t, time_t>> v(NombreDeVisite); // chaque intervalle = paire {first, second}
	for(int i = 0; i < NombreDeVisite; i++){
		v[i].first = VisitePokemon[i].first;
		v[i].second = VisitePokemon[i].second;
	}
	
	// trouve la reponce et l'imprime dans la fonction
	overlap(v); 

	return 0;
} // main()
