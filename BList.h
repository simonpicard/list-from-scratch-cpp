#ifndef BLIST_H
#define BLIST_H
#include "List.h"

//Simon Picard | 363576 | INFO2 | Info-f-202 | Projet C++ | BList.h

template <typename T>
class BList : public List<T> {
    protected:
        class Elem : public Cont<T>::Elem {
        public:
            Elem() {}
            Elem(Elem* previous, Elem* next, T objet): Cont<T>::Elem(next, objet), mPrevious(previous) {}
            virtual ~Elem() {}
            Elem*& getPrevious() {
                return mPrevious;
            }
            void setPrevious(Elem* previous) {
                mPrevious = previous;
            }
        private:
            Elem *mPrevious;
        };
    public:
        class Place : public List<T>::Place {
        public:
            Place(): List<T>::Place(0), mFromNext(true) {};
            Place(Elem ** elem, bool varFromNext):  List<T>::Place(reinterpret_cast<typename Cont<T>::Elem**>(elem)), mFromNext(varFromNext) {}
            //je suis oblig� d'utiliser un reinterpret_cast car le dynamic ne fonctionne qu'avec les pointeur de classe
            //ici c'est un pointeur de pointeur de classe
            Place(const typename List<T>::Place & p): List<T>::Place(p.getElem()), mFromNext(true) {}
            void fromNext() {
                mFromNext = true;
            }
            void fromPrevious() {
                mFromNext = false;
            }
            bool isFromNext() const {
                return mFromNext;
            }
            Place operator--(int) {
                this->movePrevious();
                return *this;
            }
            Place& operator--() {
                this->movePrevious();
                return *this;
            }
            virtual void movePrevious() {
                try {
                    if(*this->getElem()==0)
                        throw std::out_of_range("place out of min range");
                    else {
                        this->setToPrevious();
                    }
                }
                catch(std::exception const& e) {
                    std::cerr << "Caught: " << e.what( ) << std::endl;
                }
                this->fromPrevious();
            }
            virtual void moveNext() {
                this->List<T>::Place::moveNext();
                this->fromNext();
            }
             Elem& operator*() {
                return  dynamic_cast<Elem &>(this->Cont<T>::Place::operator*());
            }
            void setPrevious(Elem*& elem) {
                this->operator*().setPrevious(elem);
                //permet de modifier l'attribut previous de l'�l�ment point� par place
            }
            void setNext(Elem*& elem) {
                this->operator*().setNext(elem);
                //permet de modifier l'attribut next de l'�l�ment point� par place
            }
        private:
            bool mFromNext;
            void setToPrevious() {
                this->setElem(reinterpret_cast<typename Cont<T>::Elem**>(&this->operator*().getPrevious()));
            }
        };
        BList(): List<T>(), mTail(0) {}
        BList(const BList<T>& blistToCopy): List<T>(), mTail(0) {
            this->copyBList(dynamic_cast<typename BList<T>::Elem *>(blistToCopy.getConstHead()));
            if(blistToCopy.isVerbose())
                this->verboseOn();
        }
        virtual ~BList() {}

        virtual void add(Place & place, T objet) {
            if(this->empty()) {
                //insertion du premi�re �l�ment, je n'ai pas acc�s � Head et � Tail en m�me temps donc je dois faire un cas sp�cial
                if(this->isVerbose())
                    std::cout<<"add "<<objet<<std::endl;
                Elem *elem = new Elem(0, 0, objet);
                this->setHead(elem);
                this->setTail(elem);
                if(!place.isFromNext()){
                    place = this->first();
                }
            }
            else {
                this->adjustPlace(place);
                if(this->isVerbose())
                    std::cout<<"add "<<objet<<std::endl;
                Elem *elem = new Elem(dynamic_cast<Elem *>(*place.getElem()), dynamic_cast<Elem *>(*place.getElem()), objet);
                //cr�ation d'un pointeur vers un �l�ment, avec son next et previous pointant vers l'�l�ment actuellement point� par place
                *place.getElem() = elem;
                //modification de l'attribut next ou previous de l'�l�ment actuellement point� par place, par le nouvel �l�ment cr��
                if(place.isFromNext()) {
                    //modification du previous de l'�l�ment suivant
                    //et du next de l'elem ajout�
                    place++;
                    elem->setPrevious(dynamic_cast<Elem *>((*place.getElem()))->getPrevious());
                    place.setPrevious(elem);
                    place--;
                    //voir sch�ma addblist.bmp
                }
                else {
                    //l'ajout depuis un pointeur venant d'un attribut previous ajoute l'�l�ment apr�s l'�l�ment point�
                    place--;
                    elem->setNext((*place.getElem())->getNext());
                    place.setNext(elem);
                    place++;
                }
            }
        }

        virtual void sup(typename List<T>::Place place) {
            Place placeDeBL = place;
            this->sup(placeDeBL);
        }

        virtual void sup(Place & place) {
            if(this->empty())
                return;
            if((*place).getNext()==0 && place.isFromNext())
                place = this->last();
            else if((*place).getPrevious()==0 && !place.isFromNext())
                place = this->first();
            if(this->isVerbose())
                std::cout<<"sup "<<place.operator*().getObjet()<<std::endl;
            Elem *next = dynamic_cast<Elem*>((*place).getNext());
            Elem *previous = (*place).getPrevious();
            //on sauvegarde les pointeur next et previous de l'�l�ment qu'on va supprimer
            delete *place.getElem();
            if(place.isFromNext()) {
                *place.getElem() = next;
                if(*place.getElem()!=0)
                    place.setPrevious(previous);
                else
                    this->setTail(0);
                //on met � jour les pointeur next et previous de l'�l�ment suivant et pr�c�dant
                //voir sch�ma supblist.bmp
            }
            else {
                *place.getElem() = previous;

                if(*place.getElem()!=0) {
                    place.setNext(next);
                    place++;
                    //comme on pointait d'un previous, on a supprim� un �l�ment avant place, place est d�scendu d'un etage, il faut la remont� d'un
                }
                else
                    this->setHead(0);
            }
        }
        Place last() {
            return Place(&this->getTail(), false);
        }
        Elem*& getTail() {
            return mTail;
        }
        void setTail(Elem* elem) {
            mTail = elem;
        }
        BList& operator=(const BList & blistToCopy) {
            this->copyBList(dynamic_cast<typename BList<T>::Elem *>(blistToCopy.getConstHead()));
            if(blistToCopy.isVerbose())
                this->verboseOn();
            return *this;
        }
        private:
        Elem *mTail;
            void copyBList(typename Cont<T>::Elem *elem) {
                Place pCopy = Place(&elem);
                Place pCurrent = this->first();
                while(*pCopy.getElem() != 0) {
                    this->add(pCurrent, (*pCopy).getObjet());
                    pCopy++;
                    pCurrent++;
                }
            }
            void adjustPlace(Place & place) {
                if(!place.isFromNext()) {
                    if(*place.getElem()==0) {
                        //si la place pointe vers 0 et viens d'un previous, on veut pointer sur le premi�re element
                        //donc on prend Head comme pointeur vers ce premi�re element
                        place = this->first();
                    }
                    else if(*place.getElem() != this->getTail()) {
                        //on a vu que l'algorithme pour ins�rer un �l�ment depuis un pointeur previous
                        //l'aap�s avant l'�l�ment point� il faut donc remont� d'une case
                        place--;
                        if(*place.getElem()==0) {
                            place = this->first();
                        }
                    }
                }
                else{
                    if(*place.getElem()==0) {
                        //si la place pointe vers 0 et viens d'un next, on veut pointer sur le derni�re element
                        //donc on prend Tail comme pointeur vers ce derni�re element
                        place = this->last();
                    }
                }
            }
};

#endif // BLIST_H
