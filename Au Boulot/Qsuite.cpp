//https://pydefis.callicode.fr/defis/QSuite/txt


#include <bits/stdc++.h>
using namespace std;


int main(){
    vector<int> memo(2000);
    // fill le memo
    memo[0] = 1; 
    memo[1] = 1; 
    memo[2] = 1; 

    int a , b;
    cin >> a >> b;

    int somme = 0;
    // fait le tableaux pour [3,j]
    for (int i = 3; i <= b; ++i){
        //Q(n)=Q(n-Q(n-1))+Q(n-Q(n-2))
        memo[i] = memo[ i - memo[i-1]  ] + memo[i-memo[i-2]];

        if (i>= a && i<= b){

            somme += memo[i];
        }
    }
    cout << somme << endl;
}
