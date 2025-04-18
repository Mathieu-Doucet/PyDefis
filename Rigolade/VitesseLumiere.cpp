
//https://pydefis.callicode.fr/defis/VitesseLumiere/txt

#include <bits/stdc++.h>
using namespace std;


int main(){


    int x = 997;
    int y = 312;
    int z = 663;

    while ((10 * x ) > y) {
        x = (y * z) % 10000;
        y = (3 * z) % 10000;
        z = (7 * z) % 10000 ;

    }
    
    cout << x << ", " << y << ", " << z << endl;
    
}