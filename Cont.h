#ifndef CONT_H
#define CONT_H
#include <stdexcept>
#include <stdlib.h>
#include <iostream>

//Simon Picard | 363576 | INFO2 | Info-f-202 | Projet C++ | Cont.h

template <typename T>
class Cont {
    public:
        Cont() {}
        virtual ~Cont() {}
        virtual int size() = 0;
        virtual bool empty() const = 0;
        virtual void clear() = 0;
        void verboseOn(){
            this->verbose = true;
        }
        void verboseOff(){
            this->verbose = false;
        }
        bool isVerbose() const {
            return this->verbose;
        }
    protected:
        class Elem{
        public:
            Elem() {}
            Elem(Elem* next, T objet): mNext(next), mObjet(objet) {}
            virtual ~Elem() {}
            Elem*& getNext() {
                return mNext;
            }
            T getObjet() const {
                return mObjet;
            }
            void setNext(Elem* next) {
                mNext = next;
            }
            void setObjet(T objet) {
                mObjet = objet;
            }
            friend std::ostream& operator<<(std::ostream& out, const Elem elem) {
                elem.afficher(out);
                return out;
            }
        private:
            Elem *mNext;
            T mObjet;
            void afficher(std::ostream& out) const {
                out << this->getObjet();
            }
        };
    public:
        class Place {
        public:
            Place(): mElem(0) {}
            Place(Elem** elem): mElem(elem) {}
            Place(const Place & placeToCopy): mElem(placeToCopy.getElem()) { }
            virtual ~Place() {}
            Elem** getElem() const {
                return mElem;
            }
            Elem& operator*() {
                try {
                    if (*this->getElem()==0)
                        throw std::out_of_range("The place is pointing to a non valid element");
                    else
                        return *(*this->getElem());
                }
                catch(std::exception const& e) {
                    std::cerr << "Caught: " << e.what() << std::endl;
                    exit (EXIT_FAILURE);
                }
            }
        protected:
            void setElem(Elem ** elem) {
                mElem = elem;
            }
        private:
            Elem **mElem;
        };
    private:
        bool verbose = false;
};

#endif // CONT_H
