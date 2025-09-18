


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

map<int,int> LegendIndice;
map<int,int> LegendAnnees;
set<int> annees;

// topological sort

// DFS 
void TopSort ( int TargetAnnees, vector<vector<int>> & adj , stack<int> & file, vector<bool> &visited){

    visited[LegendAnnees[TargetAnnees]] = true;

    vector<int> temp = adj[LegendAnnees[TargetAnnees]];

    for( int it = 0 ; it < annees.size() ; ++it ){
        

        //Si tu trouve un nombre que tu a besoin faire avant fait le 
        if (temp[it] == 1 && !visited[it]){
            TopSort(LegendIndice[it], adj, file,visited);
            
        }
    }
    file.push(TargetAnnees);
    
}


void TopSortGPT(int TargetAnnee, vector<vector<int>> &adj, stack<int> &file, vector<bool> &visited) {
    int idx = LegendAnnees[TargetAnnee];
    visited[idx] = true;

    for (int i = 0; i < adj[idx].size(); ++i) {
        if (adj[idx][i] == 1 && !visited[i]) {
            int nextYear = LegendIndice[i];
            TopSort(nextYear, adj, file, visited);
        }
    }

    file.push(TargetAnnee);
}



int main(){

    string input = "";

    
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


    int iterator = 0;
    //initialize les maps
    for (auto year : annees){

        // ********initialize la mappe 
        LegendAnnees[year] = iterator;
        LegendIndice[iterator] = year;
        iterator++;
    }

    vector<vector<int>> adj(annees.size(),vector<int>(annees.size(),0)) ;

    //debug maps
    cout << "indices" << endl;
    for(auto i : LegendIndice){
        cout << i.first << "  :  " << i.second <<  endl;
    }

    cout << endl << endl;

    cout << "annees" << endl;
    for(auto i : LegendAnnees){
        cout << i.first << "  :  " << i.second <<  endl;
    }
    cout << endl << endl;


    // fait le vecteur de adjacence
    for(auto lien : links ){

        cout << lien.first << " : " << lien.second <<endl; 
        adj[LegendAnnees[lien.first]][LegendAnnees[lien.second]] = 1;
        
    }

    // cout la matrice adj
    for (auto i : adj){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    stack<int> file;
    vector<bool> visited(annees.size(),false);

    // run le topological sort
    for (auto i : annees){
        if (!visited[LegendAnnees[i]]){
            TopSortGPT(i,adj,file, visited );
        }
        
    }
    

    while(!file.empty()){
        cout << file.top() << ", ";
        file.pop();
    }



    return 0;
}





