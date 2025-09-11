


//session avec eric pour topological sort
//https://pydefis.callicode.fr/defis/C23_OrdreVisites/txt

#include <iostream>

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

    string input = "";

    set<int> annees;
    vector<pair<int,int>> links;


    while(getline(cin,input)){
        
        vector<string> phrase = tokenize(input);

        // ajoute dans le set pour voir comment de annees crititque tu a besoin
        annees.insert(stoi(phrase[1]));
        annees.insert(stoi(phrase[3]));

        // saver les liens dans une pair
        links.push_back(make_pair(stoi(phrase[1]),stoi(phrase[3])));

    }

    // fait ta liste de adjacent pour voir les liens

    //besoin des convertision pour quelle indice les annees son
    map<int,int> LegendIndice;
    map<int,int> LegendAnnees;

    int nombre = 0;
    //initialize les maps
    for (auto i : annees){
        

        // ********initialize la mappe 
        LegendAnnees[i] = nombre;
        LegendIndice[nombre] = i;

    }

    vector<vector<int>> adj(annees.size(),vector<int>(annees.size(),0)) ;

    // fait le vecteur de adjacence
    for(auto lien : links ){

        adj[LegendAnnees[lien.first]][LegendAnnees[lien.second]] = 1;
        
    }

    for (auto i : adj){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    return 0;
}





