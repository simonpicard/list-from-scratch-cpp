#ifndef TEST_H
#define TEST_H
#include "BList.h"

//Simon Picard | 363576 | INFO2 | Info-f-202 | Projet C++ | Test.h


class Test
{
    public:
        Test();
        virtual ~Test();
        bool creationList(List<int> & t);
        bool creationList(List<char> & t);
        bool insertionMilieuList(List<int> t);
        bool insertionMilieuList(List<char> t);
        bool insertionTeteList(List<int> t);
        bool insertionQueueList(List<int> t);
        bool suppressionMilieuList(List<int> t);
        bool suppressionMilieuList(List<char> t);
        bool suppressionTeteList(List<int> t);
        bool suppressionQueueList(List<int> t);
        bool inversionList(List<int> t);
        bool inversionList(List<char> t);
        bool tailleList(List<int> t);
        bool viderList(List<int> t);
        bool estVideList(List<int> t);

        bool creationBList(BList<int> & t);
        bool creationBList(BList<char> & t);
        bool insertionMilieuNextBList(BList<int> t);
        bool insertionMilieuNextBList(BList<char> t);
        bool insertionMilieuPreviousBList(BList<int> t);
        bool insertionTeteBList(BList<int> t);
        bool insertionQueueBList(BList<int> t);
        bool suppressionMilieuNextBList(BList<int> t);
        bool suppressionMilieuNextBList(BList<char> t);
        bool suppressionMilieuPreviousBList(BList<int> t);
        bool suppressionTeteBList(BList<int> t);
        bool suppressionQueueBList(BList<int> t);
        bool inversionBList(BList<int> t);
        bool inversionBList(BList<char> t);

        bool testMixeBList();

        bool testBList();
        bool testList();
        bool testComplet();

        void verboseOn(){
            this->verbose = true;
        }
        void verboseOff(){
            this->verbose = false;
        }
        bool isVerbose() const {
            return this->verbose;
        }

    private:
        bool verbose = false;
        template <typename T>
        void reverseL(List<T> & t);
        template <typename T>
        void reverseBL(BList<T> & t);
        template <typename T>
        bool verificationLien(BList<T> & t);
};

#endif // TEST_H
