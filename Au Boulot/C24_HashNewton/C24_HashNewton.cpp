
// meli melo d'address
// https://pydefis.callicode.fr/defis/static/cup2024//C24_adresses.txt
#include <iostream>
using namespace std;

#include <bits/stdc++.h>

void println(string const comment, map<string,int> const& map)
{
    std::cout << comment << '{';
    for (const auto& pair : map)
        std::cout << '{' << pair.first << ": " << pair.second << '}' << endl;
    std::cout << "}\n";
}

int main(){

    // prendre les address et les mettre dans une map
    map<string,int> address ;

    string Getline;
    int number = 0;
    while(getline(cin, Getline)){


        string hash;

        //make le string avec le format de newton
        for(char alphabet = 'a' ; alphabet <= 'z' ; ++alphabet){
            int count = 0;
            for(auto character : Getline){
                if (character == alphabet){
                    count++;
                }
            }
            if (count != 0){
                hash += to_string(count);
                hash += alphabet;
            }
            

        }
        address.insert(pair<string,int>(hash,number));
        number++;
    }

    //string AddressNewton = "1a6e1g1i1l1m1n1o2r2s2u1y";

    //print all
    // println("\n" , address);
    cout << "ligne: " << address["1a6e1g1i1l1m1n1o2r2s2u1y"] << endl;

    return 0;
}