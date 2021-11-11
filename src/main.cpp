#include <iostream>
#include <exception>
#include "Test.h"

//Simon Picard | 363576 | INFO2 | Info-f-202 | Projet C++ | main.cpp

using namespace std;

int main()
{
    Test t;
    //t.verboseOn();
    //décommentez t.verboseOn(); si vous voulez plus d'informations sur ce qu'il se passe durant l'execution des tests
    cout<<t.testComplet()<<endl;
    return 0;
}
