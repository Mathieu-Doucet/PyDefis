// trouver les dent 
//https://pydefis.callicode.fr/defis/C24_DentToomsEasy/txt
#include <iostream>
using namespace std;

#include <vector>
#include<algorithm>
#include<regex>
#include<string>

vector<string> tokenize(const string &s)
{
	regex expreg("[\\s,-]+");
	sregex_token_iterator it(s.begin(), s.end(), expreg, -1);
	sregex_token_iterator reg_end;
	vector<string> tokens;
	for (; it != reg_end; ++it)
		tokens.push_back(it->str());

	return tokens;

	
} // tokenize()


int main(){

    vector <float> Tooms = {10, 12, 6, 9, 18.5, 22, 7, 4, 9, 10};

    string entree = "";

    vector<int> somme ;
    while(getline(cin,entree)){


        vector<string> fichierString = tokenize(entree);

        vector<float> fichiernombre;

        for(auto i : fichierString){
            fichiernombre.push_back(stof(i));
        }

        float delta = 0;
        bool isTooms = true;
        //profond
        if (fichiernombre[1]>Tooms[0]){
            delta = (fichiernombre[1] -Tooms[0]);
            for(int i = 1 ; i < fichiernombre.size() ; ++i){

                if ((fichiernombre[i] - delta) != Tooms[i-1]){
                    isTooms = false;
                    break;
                }
    
            }
        }
        //pas profond
        else{
            delta = (Tooms[0] - fichiernombre[1]);
            for(int i = 1 ; i < fichiernombre.size() ; ++i){

                if ((fichiernombre[i] +delta) != Tooms[i-1]){
                    isTooms = false;
                    break;
                }
    
            }
        }
        
    
        //cout << fichiernombre[0] << endl;

        if(isTooms){

            somme.push_back(int(fichiernombre[0]));
        }


    }

    int total = 0;
    for(auto i : somme){
        total += i;
        cout << i << endl;
    }

    cout << total << endl;

}
