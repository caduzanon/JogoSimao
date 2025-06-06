#pragma once

namespace Game{
    namespace Lists{
        template<class TE>
        class Element{
            private:
                Element<TE>* next;
                TE* element;
            public:
                Element();
                ~Element();
                void setElement(TE* pElement);
                void setNext(Element<TE>* pNext);
                Element<TE>* getNext();
                TE* getElement();
        };

        template<class TE>
        Element<TE>::Element() : next(nullptr), element(nullptr){
            //hello    
        }

        template<class TE>
        Element<TE>::~Element(){
            //bai bai
        }

        template<class TE>
        void Element<TE>::setNext(Element<TE>* pNext){
            if(pNext != nullptr){
                this->next = pNext;
            }
        }

        template<class TE>
        void Element<TE>::setElement(TE* pElement){
            this->element = pElement;
        }
        
        template<class TE>
        Element<TE>* Element<TE>::getNext(){
            return next;
        }

        template<class TE>
        TE* Element<TE>::getElement(){
            return element;
        }
    }
}