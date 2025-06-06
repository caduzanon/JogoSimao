#pragma once
#include <Lists/Element.hpp>
#include <iostream>
namespace Game{
    namespace Lists{
        using namespace std;
        template<class TL>
        class List{
            private:
                Element<TL>* pFirst;
                Element<TL>* pLast;
                unsigned int size;
            public:
                List();
                ~List();
                void addElement(TL* element);                                            //overloaded 
                void addElement(TL* element, int position);                              //overloaded
                void removeElement(TL* element, const bool deletion);                    //overloaded
                void removeElement(int position, const bool deletion);                   //overloaded
                int getSize();
                TL* operator[](int position);
                void clearList();
        };

        template<class TL>
        List<TL>::List() : pFirst(nullptr), pLast(nullptr), size(0){ //initializes list
            //hello
        }

        template<class TL>
        List<TL>::~List(){ //destroys list
            //baibai
            clearList();
        }

        template<class TL>
        void List<TL>::addElement(TL* element){ //inserts element at the end of list
            if (element == nullptr){ //check for null
                cout << "Error when adding element: Null pointer received" << endl;
                exit(1);
            }
            //if it made it here, it's not null, so we create element
            Element<TL>* newElement = new Element<TL>();
            if (newElement == nullptr){ //check if it has been created
                cout << "Error when creating ElementTL in ListTL" << endl;
                exit(1);
            }
            //if it exists:
            newElement->setElement(element); //sets the content of the list element to the one received in the function
            //'progression' adjustments: list is linked, gotta keep it linked
            if (pFirst == nullptr){ //in this case, we just made a list! life is good and there is only one element.
                pFirst = newElement;
                pLast = newElement;
            }
            else{ //here, the element created is not the first. we set the order of elements.
                pLast->setNext(newElement); //make the current last element point to our new thing
                pLast = newElement; //now the last item in this list is the new thing
            }
            size++;
            cout << "Successfully added element to List" << endl;
        }



        template<class TL>
        void List<TL>::addElement(TL* element, int position){ //inserts element at a desired position
            if (position > size || position < 0){
                cout << "Error: position is incompatible with the current List size. Please use the other function to add element." << endl;
                exit(1);
            }
            if (element == nullptr){
                cout << "Error when adding element: Null pointer received" << endl;
                exit(1);
            }
            //if it made it here, it's not null, so we create element
            Element<TL>* newElement = new Element<TL>();
            if (newElement == nullptr){ //check if it has been created
                cout << "Error when creating ElementTL in ListTL" << endl;
                exit(1);
            }
            //if it exists:
            newElement->setElement(element); //sets the content of the list element to the one received in the function
            //'progression' adjustments: list is linked, gotta keep it linked
            if (pFirst == nullptr){ //in this case, we just made a list! life is good and there is only one element.
                pFirst = newElement;
                pLast = newElement;
            }
            else{ //here, the element created is not the first. we insert the element in the desired spot.
                Element<TL>* aux1 = pFirst;
                Element<TL>* aux2 = nullptr;
                //iterate through the list
                for (int i=0; i<position; i++){
                    aux2 = aux1;
                    aux1 = aux1->getNext();
                }
                //at the time we arrive to the desired position:
                // aux1 holds the next element in the list (it's at the position spot) (and can be null)
                // aux2 holds the position of the previous element (position-1)
                if (aux2 == nullptr){ //initial building case
                    newElement->setNext(aux1);
                    pFirst = newElement;
                }
                else{ //here we insert element at [position] by setting it as the next of position - 1 and the original position element as its next
                    aux2->setNext(newElement);
                    newElement->setNext(aux1);
                }
            }
            size++;
            cout << "Successfully added element to List at the specified position." << endl;
        }



        template<class TL>
        void List<TL>::removeElement(TL* element, const bool deletion){ //removes element by element content
            if(element == nullptr){
                cout << "Error when removing element: Null pointer received" << endl;
                exit(1);
            }
            Element<TL>* aux1 = pFirst;
            Element<TL>* aux2 = nullptr;

            while (aux1 != nullptr && aux1->getElement() != element){ //iterate through the list until we find what we want. aux1 will store the position of the desired element, aux2 the previous.
                aux2 = aux1;
                aux1 = aux1->getNext();
            }
            if (aux1->getElement() == element){ //go ahead!
                if (aux1 ==pFirst){
                    pFirst = aux1->getNext();
                }else if (aux1 = pLast){
                    pLast = aux2;
                }else{
                    aux2->setNext(aux1->getNext());
                }
                if (deletion){
                    delete(aux1);
                    aux1 = nullptr;
                    aux2 = nullptr;
                }
                size--;
            }
        }

        template<class TL>
        void List<TL>::removeElement(int position, const bool deletion){ //removes element by its position
            TL* element = operator[](position);
            return removeElement(element, deletion); //why not use the other one
        }

        template<class TL>
        int List<TL>::getSize(){ //returns the size of the list
            return (int)size;
        }

        template<class TL>
        TL* List<TL>::operator[](int position){ //returns the element at the desired position
            if(position >= size || position < 0){
                cout << "Error when searching for element in List: Position out of bounds." << endl;
                exit(1);
            }

            Element<TL>* aux1 = pFirst;
            for (int i = 0; i<position; i++){
                aux1 = aux1->getNext();
            }
            if (aux1 != nullptr){
                return aux1->getElement();
            }
            cout << "Error when returning element: iterator sent to null!" << endl;
            return nullptr;
        }

        template<class TL>
        void List<TL>::clearList(){ //clears the list
            if(pFirst != nullptr){
                Element<TL>* aux1 = pFirst;
                Element<TL>* aux2 = nullptr;
                int i = 0;
                while (aux1 != nullptr && i < size){
                    TL* element = aux1->getElement();
                    if (element != nullptr){
                        delete(element);
                        element = nullptr;
                    }
                    aux2 = aux1 ->getNext();
                    delete(aux1);
                    aux1 = nullptr;
                    aux1 = aux2;
                    i++;
                }
            }
            pFirst = nullptr;
            pLast = nullptr;
            size = 0;
        }

    } //end-Lists
} //end-Game