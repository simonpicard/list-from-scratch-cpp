#ifndef LIST_H
#define LIST_H
#include "Cont.h"
#include <iostream>

//Simon Picard | 363576 | INFO2 | Info-f-202 | Projet C++ | List.h

template <typename T>
class List : public Cont<T> {
    public:
        class Place : public Cont<T>::Place {
        public:
            Place(typename Cont<T>::Elem ** elem): Cont<T>::Place(elem) {}
            Place(): Cont<T>::Place(0) {}
            Place operator++(int) {
                this->moveNext();
                return *this;
            }
            Place& operator++() {
                this->moveNext();
                return *this;
            }
            virtual void moveNext() {
                try {
                    if(*this->getElem()==0)
                        throw std::out_of_range("place out of max range");
                    else {
                        this->setToNext();
                    }
                }
                catch(std::exception const& e) {
                    std::cerr << "Caught: " << e.what( ) << std::endl;
                }
            }
        private:
            void setToNext() {
                this->setElem(&this->operator*().getNext());
                //modifie la valeur de l'élément pointé dans la place par un pointeur vers l'élément suivant
            }
        };

        List(): Cont<T>(), mHead(0) {}
        List(const List<T> & listToCopy): Cont<T>(), mHead(0) {
            this->copyList(listToCopy.getConstHead());
            if(listToCopy.isVerbose())
                this->verboseOn();
        }
        virtual ~List() {
            this->verboseOff();
            this->clear();
        }
        int size() {
            int res = 0;
            for(Place place = first(); *place.getElem()!=0; place++) {
                res++;
            }
            return res;
        }
        bool empty() const {
            bool res = false;
            if(this->getConstHead() == 0)
                res = true;
            return res;
        }
        void clear() {
            Place place = this->first();
            while(*place.getElem()!=0)
            {
                this->sup(place);
            }
        }
        virtual void add(Place place, T objet) {
            if(this->isVerbose())
                std::cout<<"add "<<objet<<std::endl;
            *place.getElem() = new typename Cont<T>::Elem(*place.getElem(), objet);
            //crée un élement dont next vaut l'élément actuellement pointé
            //modifie le next de l'élément précédant l'élément acutellement pointé, par l'élément créé
        }
        virtual void sup(Place place) {
            if(this->isVerbose())
                std::cout<<"sup "<<place.operator*()<<std::endl;
            typename Cont<T>::Elem *elem = (*place).getNext();
            //création d'un pointeur vers l'Elem suivant de l'élément actuellement pointé
            delete *place.getElem();
            //supprime l'élément actuellement pointé
            *place.getElem() = elem;
            //remplace le next de l'Elem précédent à l'Elem supprimé, par l'Elem suivant de l'Elem supprimé
        }
        Place first() {
            return Place(&this->getHead());
        }
        void setHead(typename Cont<T>::Elem* head) {
            mHead = head;
        }
        typename Cont<T>::Elem*& getHead() {
            return mHead;
        }
        typename Cont<T>::Elem* getConstHead() const {
            return mHead;
        }
        friend std::ostream& operator<<(std::ostream & out, List<T> & t) {
            t.afficher(out);
            return out;
        }
        List& operator=(const List & listToCopy) {
            this->copyList(listToCopy.getConstHead());
            if(listToCopy.isVerbose())
                this->verboseOn();
            return *this;
        }
    private:
        typename Cont<T>::Elem *mHead;
        void copyList(typename Cont<T>::Elem *elem) {
            Place pCopy = Place(&elem);
            Place pCurrent = this->first();
            while(*pCopy.getElem() != 0) {
                this->add(pCurrent, (*pCopy).getObjet());
                pCopy++;
                pCurrent++;
            }
        }
        void afficher(std::ostream& out) {
            char separator[3] = {0,0,'\0'};
            out<<"[";
            for(Place place = this->first(); *place.getElem()!=0; place++) {
                out<<separator<<*place;
                separator[0] = ',';
                separator[1] = ' ';
            }
            out<<"]";
        }

};


#endif // LIST_H
