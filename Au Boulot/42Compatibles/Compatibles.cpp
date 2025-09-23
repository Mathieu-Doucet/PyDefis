// a pas de zer0
// somme des nombre est divisible par 42
// nombre est divisible par 42

// [178 899 , 999 762]


//https://pydefis.callicode.fr/user/liste_defis

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){



    int counter = 0;

    for (long long nombre = 178898 ; nombre <= 999999 ; ++nombre){

        string NombreString = to_string(nombre);

        bool Zerobool = 0;

        int somme = 0;
        int produit = 1;

        for (auto decimal : NombreString){

            int x = decimal - '0';

            produit = produit * x;
            somme += x;

            //est zero
            if (decimal == '0'){
                Zerobool = 1;
            }


        }

        if(!Zerobool && (somme % 42 ) == 0 && (produit % 42 ) == 0){
            counter++;
        }


    }
    cout << counter << endl;




}




