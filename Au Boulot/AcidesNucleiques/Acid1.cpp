
// Analyse de séquences 1/2 
//https://pydefis.callicode.fr/defis/C24_AcidesNucleiques_01/txt



#include <iostream>
using namespace std;

#include <vector>
#include<string>
#include<map>
#include <gmp.h>
#include <gmpxx.h>


map<char,mpz_class>ADN = {
    {'A', 1}, {'G', 1}, {'C', 1}, {'U', 1}, 
{'R', 2}, {'Y', 2},{'K', 2}, {'M', 2}, {'S', 2}, {'W', 2}, 
{'B', 3}, {'D', 3},{'H', 3}, {'V', 3},
{'N', 4} };


void CalculeSequence(string sequence){

    mpz_class total = 1; 

    for(auto lettre : sequence){
        total = total * ADN[lettre];
    }   

    cout << total << endl;

    //string output = to_string(total);

    //veut les 5 dernier   0123456789
    //return output.substr( (output.size() - 5) , 5);



}
int main(){

    string entree = "NDNKCNVNUGYWRGCNABGSNCRACGSHWNNCYBCSNVUAAGDCMNKNYNNBNCGUBHUNRANDGDMDRSYMGSNWHNDNCVCMAMCANWKYRKVMWMKC";
    //string entree = "BBBBDDDDHHHH";

    CalculeSequence(entree);

    return 0;
}




