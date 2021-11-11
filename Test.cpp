#include "Test.h"

//Simon Picard | 363576 | INFO2 | Info-f-202 | Projet C++ | Test.cpp

using namespace std;

Test::Test()
{}

bool Test::testComplet()
{
    bool test = true;
    cout<<"Test de List"<<endl;
    test &= testList();
    cout<<"Test de BList"<<endl;
    test &= testBList();
    cout<<"Test mixe de BList"<<endl;
    test &= testMixeBList();
    return test;
}

bool Test::testList()
{
    bool test = true;
    List<int> t;
    List<char> t2;
    if(this->isVerbose()){
        t.verboseOn();
        t2.verboseOn();
    }

    test &= creationList(t);
    test &= creationList(t2);
    test &= insertionMilieuList(t);
    test &= insertionMilieuList(t2);
    test &= insertionTeteList(t);
    test &= insertionQueueList(t);
    test &= suppressionMilieuList(t);
    test &= suppressionMilieuList(t2);
    test &= suppressionTeteList(t);
    test &= suppressionQueueList(t);
    test &= inversionList(t);
    test &= inversionList(t2);
    test &= tailleList(t);
    test &= viderList(t);
    test &= estVideList(t);
    return test;
}

bool Test::testBList()
{
    bool test = true;
    BList<int> bl;
    BList<char> bl2;
    if(this->isVerbose()){
        bl.verboseOn();
        bl2.verboseOn();
    }

    test &= creationBList(bl);
    test &= creationBList(bl2);
    test &= insertionMilieuNextBList(bl);
    test &= insertionMilieuNextBList(bl2);
    test &= insertionMilieuPreviousBList(bl);
    test &= insertionTeteBList(bl);
    test &= insertionQueueBList(bl);
    test &= suppressionMilieuNextBList(bl);
    test &= suppressionMilieuNextBList(bl2);
    test &= suppressionMilieuPreviousBList(bl);
    test &= suppressionTeteBList(bl);
    test &= suppressionQueueBList(bl);
    test &= inversionBList(bl);
    test &= inversionBList(bl2);
    return test;
}

Test::~Test()
{
    //dtor
}

bool Test::creationList(List<int> & t)
{
    int res[10] = {0,1,2,3,4,5,6,7,8,9};
    bool test = true;
    List<int>::Place p = t.first();
    for(int i = 0; i<10; i++)
    {
        t.add(p, i);
        p++;
    }
    p = t.first();
    for(int i = 0; i<10; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }

    cout<<"Le resultat du test de creation de list est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::creationList(List<char> & t)
{
    char res[10] = {'a','b','c','d','e','f','g','h','i','j'};
    bool test = true;
    List<char>::Place p = t.first();
    char c = 'a';
    for(int i = 0; i<10; i++)
    {
        t.add(p, c);
        p++;
        c++;
    }
    p = t.first();
    for(int i = 0; i<10; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }

    cout<<"Le resultat du test de creation de list de char est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::insertionMilieuList(List<int> t)
{
    int res[11] = {0,1,2,3,4,45,5,6,7,8,9};
    bool test = true;
    List<int>::Place p = t.first();
    for(int i = 0; i<5; i++)
    {
        p++;
    }
    t.add(p, 45);
    p = t.first();
    for(int i = 0; i<11; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }

    cout<<"Le resultat du test d'insertion en milieu de list est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::insertionMilieuList(List<char> t)
{
    char res[11] = {'a','b','c','d','e','z','f','g','h','i','j'};
    bool test = true;
    List<char>::Place p = t.first();
    for(int i = 0; i<5; i++)
    {
        p++;
    }
    t.add(p, 'z');
    p = t.first();
    for(int i = 0; i<11; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }

    cout<<"Le resultat du test d'insertion en milieu de list de char est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::insertionTeteList(List<int> t)
{
    int res[11] = {-1,0,1,2,3,4,5,6,7,8,9};
    bool test = true;
    List<int>::Place p = t.first();
    t.add(p, -1);
    p = t.first();
    for(int i = 0; i<11; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }

    cout<<"Le resultat du test d'insertion en tete de list est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::insertionQueueList(List<int> t)
{
    int res[11] = {0,1,2,3,4,5,6,7,8,9,10};
    bool test = true;
    List<int>::Place p = t.first();
    for(int i = 0; i<10; i++)
    {
        p++;
    }
    t.add(p, 10);
    p = t.first();
    for(int i = 0; i<11; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }

    cout<<"Le resultat du test d'insertion en queue de list est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::suppressionMilieuList(List<int> t)
{
    int res[9] = {0,1,2,3,5,6,7,8,9};
    bool test = true;
    List<int>::Place p = t.first();
    for(int i = 0; i<4; i++)
    {
        p++;
    }
    t.sup(p);
    p = t.first();
    for(int i = 0; i<9; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }

    cout<<"Le resultat du test de suppression en milieu de list est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::suppressionMilieuList(List<char> t)
{
    char res[9] = {'a','b','c','d','f','g','h','i','j'};
    bool test = true;
    List<char>::Place p = t.first();
    for(int i = 0; i<4; i++)
    {
        p++;
    }
    t.sup(p);
    p = t.first();
    for(int i = 0; i<9; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }

    cout<<"Le resultat du test de suppression en milieu de list de char est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::suppressionTeteList(List<int> t)
{
    int res[9] = {1,2,3,4,5,6,7,8,9};
    bool test = true;
    List<int>::Place p = t.first();
    t.sup(p);
    p = t.first();
    for(int i = 0; i<9; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }

    cout<<"Le resultat du test de suppression en tete de list est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}


bool Test::suppressionQueueList(List<int> t)
{
    int res[9] = {0,1,2,3,4,5,6,7,8};
    bool test = true;
    List<int>::Place p = t.first();
    for(int i = 0; i<9; i++)
    {
        p++;
    }
    t.sup(p);
    p = t.first();
    for(int i = 0; i<9; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }

    cout<<"Le resultat du test de suppression en queue de list est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

template <typename T>
void Test::reverseL(List<T> & t)
{
    typename List<T>::Place f = t.first();
    typename List<T>::Place p = t.first();
    T temp;
    int listSize = t.size();
    for(int i = 0; i<listSize; i++)
    {
        temp = (*f).getObjet();
        f++;
        t.add(t.first(), temp);
        if(i==0){
            p = t.first();
            p++;
        }
    }
    for(int i = 0; i<listSize; i++)
    {
        t.sup(p);
    }
}

bool Test::inversionList(List<int>  t)
{
    int res[10] = {9,8,7,6,5,4,3,2,1,0};
    bool test = true;
    reverseL(t);
    List<int>::Place p = t.first();
    for(int i = 0; i<9; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }

    cout<<"Le resultat du test d'inversion de list est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::inversionList(List<char>  t)
{
    char res[10] = {'j','i','h','g','f','e','d','c','b','a'};
    bool test = true;
    List<char>::Place p = t.first();
    reverseL(t);
    for(int i = 0; i<9; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }

    cout<<"Le resultat du test d'inversion de list de char est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::tailleList(List<int>  t)
{
    int res = 10;
    bool test = true;
    if(t.size() != res)
        test = false;
    cout<<"Le resultat du test de la taille d'une list est "<<test<<"\n"<<endl;
    return test;
}

bool Test::viderList(List<int>  t)
{
    int res = 0;
    bool test = true;
    t.clear();
    if(t.size() != res)
        test = false;

    cout<<"Le resultat du test de vider une list est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::estVideList(List<int>  t)
{
    bool test = true;
    if(t.empty())
        test = false;
    t.clear();
    if(!t.empty())
        test = false;
    cout<<"Le resultat du test pour savoir si une list est vide est "<<test<<"\n"<<endl;
    return test;

}

bool Test::creationBList(BList<int> & t)
{
    int res[10] = {0,1,2,3,4,5,6,7,8,9};
    bool test = true;
    BList<int>::Place p = t.first();
    for(int i = 0; i<10; i++)
    {
        t.add(p, i);
        p++;
    }
    p = t.first();
    for(int i = 0; i<10; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }
    test &= this->verificationLien(t);

    cout<<"Le resultat du test de creation de blist est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::creationBList(BList<char> & t)
{
    char res[10] = {'a','b','c','d','e','f','g','h','i','j'};
    bool test = true;
    BList<char>::Place p = t.first();
    char c = 'a';
    for(int i = 0; i<10; i++)
    {
        t.add(p, c);
        c++;
        p++;
    }
    p = t.first();
    for(int i = 0; i<10; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }
    test &= this->verificationLien(t);

    cout<<"Le resultat du test de creation de blist de char est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::insertionMilieuNextBList(BList<int> t)
{
    int res[11] = {0,1,2,3,4,45,5,6,7,8,9};
    bool test = true;
    BList<int>::Place p = t.first();
    for(int i = 0; i<5; i++)
    {
        p++;
    }
    t.add(p, 45);
    p = t.first();
    for(int i = 0; i<11; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }
    test &= this->verificationLien(t);

    cout<<"Le resultat du test d'insertion en milieu de blist depuis un next est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::insertionMilieuNextBList(BList<char> t)
{
    char res[11] = {'a','b','c','d','e','z','f','g','h','i','j'};
    bool test = true;
    BList<char>::Place p = t.first();
    for(int i = 0; i<5; i++)
    {
        p++;
    }
    t.add(p, 'z');
    p = t.first();
    for(int i = 0; i<11; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }
    test &= this->verificationLien(t);

    cout<<"Le resultat du test d'insertion en milieu de blist de char depuis un next est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::insertionMilieuPreviousBList(BList<int> t)
{
    int res[11] = {0,1,2,3,4,45,5,6,7,8,9};
    bool test = true;
    BList<int>::Place p = t.last();
    for(int i = 0; i<4; i++)
    {
        p--;
    }
    t.add(p, 45);
    p = t.first();
    for(int i = 0; i<11; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }
    test &= this->verificationLien(t);

    cout<<"Le resultat du test d'insertion en milieu de blist depuis un previous est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::insertionTeteBList(BList<int> t)
{
    int res[11] = {-1,0,1,2,3,4,5,6,7,8,9};
    bool test = true;
    BList<int>::Place p = t.first();
    t.add(p, -1);
    p = t.first();
    for(int i = 0; i<11; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }
    test &= this->verificationLien(t);

    cout<<"Le resultat du test d'insertion en tete de blist est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::insertionQueueBList(BList<int> t)
{
    int res[11] = {0,1,2,3,4,5,6,7,8,9,10};
    bool test = true;
    BList<int>::Place p = t.last();
    t.add(p, 10);
    p = t.first();
    for(int i = 0; i<11; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }
    test &= this->verificationLien(t);

    cout<<"Le resultat du test d'insertion en queue de blist est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::suppressionMilieuNextBList(BList<int> t)
{
    int res[9] = {0,1,2,3,5,6,7,8,9};
    bool test = true;
    BList<int>::Place p = t.first();
    for(int i = 0; i<4; i++)
    {
        p++;
    }
    t.sup(p);
    p = t.first();
    for(int i = 0; i<9; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }
    test &= this->verificationLien(t);

    cout<<"Le resultat du test de suppression en milieu de blist depuis un next est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::suppressionMilieuNextBList(BList<char> t)
{
    char res[9] = {'a','b','c','d','f','g','h','i','j'};
    bool test = true;
    BList<char>::Place p = t.first();
    for(int i = 0; i<4; i++)
    {
        p++;
    }
    t.sup(p);
    p = t.first();
    for(int i = 0; i<9; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }
    test &= this->verificationLien(t);

    cout<<"Le resultat du test de suppression en milieu de blist de char depuis un next est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::suppressionMilieuPreviousBList(BList<int> t)
{
    int res[9] = {0,1,2,3,5,6,7,8,9};
    bool test = true;
    BList<int>::Place p = t.last();
    for(int i = 0; i<5; i++)
    {
        p--;
    }
    t.sup(p);
    p = t.first();
    for(int i = 0; i<9; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }
    test &= this->verificationLien(t);

    cout<<"Le resultat du test de suppression en milieu de blist depuis un previous est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::suppressionTeteBList(BList<int> t)
{
    int res[9] = {1,2,3,4,5,6,7,8,9};
    bool test = true;
    BList<int>::Place p = t.first();
    t.sup(p);
    p = t.first();
    for(int i = 0; i<9; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }
    test &= this->verificationLien(t);

    cout<<"Le resultat du test de suppression en tete de blist est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::suppressionQueueBList(BList<int> t)
{
    int res[9] = {0,1,2,3,4,5,6,7,8};
    bool test = true;
    BList<int>::Place p = t.last();
    t.sup(p);
    p = t.first();
    for(int i = 0; i<9; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }
    test &= this->verificationLien(t);

    cout<<"Le resultat du test de suppression en queue de blist est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::inversionBList(BList<int>  t)
{
    int res[10] = {9,8,7,6,5,4,3,2,1,0};
    bool test = true;
    this->reverseBL(t);
    BList<int>::Place p = t.first();
    for(int i = 0; i<10; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }
    test &= this->verificationLien(t);

    cout<<"Le resultat du test d'inversion de blist est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

bool Test::inversionBList(BList<char>  t)
{
    char res[10] = {'j','i','h','g','f','e','d','c','b','a'};
    bool test = true;
    this->reverseBL(t);
    BList<char>::Place p = t.first();
    for(int i = 0; i<10; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }
    test &= this->verificationLien(t);

    cout<<"Le resultat du test d'inversion de blist de char est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}

template <typename T>
void Test::reverseBL(BList<T> & t)
{
    typename BList<T>::Place f = t.first();
    typename BList<T>::Place l = t.last();
    T temp1, temp2;
    int BLsize = t.size();
    for(int i = 0; i<BLsize/2; i++)
    {
        temp1 = (*f).getObjet();
        temp2 = (*l).getObjet();
        t.sup(f);
        t.sup(l);
        t.add(l, temp1);
        t.add(f, temp2);
        ++f;
        --l;
    }
}

template <typename T>
bool Test::verificationLien(BList<T> & t)
{
    T head = t.getHead()->getObjet();
    T tail = t.getTail()->getObjet();
    int BLsize = t.size();
    bool test = true;
    typename BList<T>::Place p = t.first();
    for(int i = 0; i<BLsize-1; i++){
        p++;
    }
    if ((*p).getObjet() != tail)
        test = false;
    p = t.last();
    for(int i = 0; i<BLsize-1; i++){
        p--;
    }
    if ((*p).getObjet() != head)
        test = false;
    return test;
}

bool Test::testMixeBList()
{
    int res[13] = {-1,0,1,2,3,4,5,6,7,8,9,10,11};
    bool test = true;

    BList<int> t;
    BList<int>::Place p = t.last();
    if(this->isVerbose())
        t.verboseOn();

    t.add(p,9);
    t.add(p,8);
    t.add(p,7);
    t.sup(p);
    t.add(p,7);
    t.add(p,6);
    t.add(p,5);
    t.add(p,4);
    t.add(p,3);
    t.add(p,2);
    t.add(p,1);
    t.sup(p);
    t.add(p,1);
    t.add(p,0);
    t.sup(p);
    t.add(p,0);
    p = t.last();
	p--;
    p--;
    p--;
    p++;
    t.sup(p);
    t.sup(p);
    t.sup(p);
    t.add(p,9);
    t.add(p,8);
    t.add(p,7);
    p++;
    p++;
    p++;
    t.add(p,10);
    p = t.last();
    t.sup(p);
    t.add(p, 10);
    p--;
    p--;
    p--;
    p--;
    p--;
    t.sup(p);
    t.sup(p);
    t.sup(p);
    t.add(p, 7);
    t.add(p, 6);
    t.add(p, 5);
    p--;
    p--;
    t.sup(p);
    t.add(p, 3);
    p--;
    p--;
    p--;
    t.sup(p);
    t.add(p, 0);
    p++;
    p++;
    t.sup(p);
    t.add(p, 2);
    p++;
    p++;
    t.sup(p);
    t.add(p, 4);


    p = t.last();
    p--;
    p--;
    p--;
    t.sup(p);
    t.add(p, 3);
    p--;
    p--;
    t.sup(p);
    t.add(p, 5);
    p--;
    p--;
    p--;
    p--;
    p--;
    t.sup(p);
    t.add(p, 10);
    p++;
    p++;
    t.sup(p);
    t.add(p, 8);
    p++;
    p++;
    t.sup(p);
    t.add(p, 6);

    reverseBL(t);
    p = t.first();
    t.sup(p);
    t.add(p, 10);
    p++;
    ++p;
    p++;
    t.sup(p);
    t.add(p, 7);
    p++;
    p++;
    t.sup(p);
    t.add(p, 5);
    BList<int>::Place p2 = p;
    p2++;
    p2++;
    p2++;
    p2++;
    p2++;
    t.sup(p2);
    t.add(p2, 0);
    --p2;
    p2--;
    t.sup(p2);
    t.add(p2, 2);
    p2--;
    p2--;
    t.sup(p2);
    t.add(p2, 4);
    p = t.last();
    t.add(p, -1);
    p = t.first();
    t.add(p, 11);
    reverseBL(t);

    for(int i = 0; i<13; i++)
    {
        if(res[i] != (*p).getObjet())
            test = false;
        p++;
    }
    test &= this->verificationLien(t);

    cout<<"Le resultat du test mixe de blist est "<<test<<"\n"<<t<<"\n"<<endl;
    return test;
}
