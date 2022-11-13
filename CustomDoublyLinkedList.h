#ifndef USATU_OOP_LW_3_CUSTOMDOUBLYLINKEDLIST_H
#define USATU_OOP_LW_3_CUSTOMDOUBLYLINKEDLIST_H

template<typename T>
class CustomDoublyLinkedList {
private:
    class DoublyLinkedElement {
    public:
        T Object;
        bool IsBorder;
        DoublyLinkedElement *Next;
        DoublyLinkedElement *Previous;

        DoublyLinkedElement() {
            IsBorder = true;
        }

        DoublyLinkedElement(T object, DoublyLinkedElement *previous) {
            IsBorder = false;
            Object = object;
            Previous = previous;
            Next = new DoublyLinkedElement();
        }

        DoublyLinkedElement(T object, DoublyLinkedElement &next, DoublyLinkedElement *previous) {
            IsBorder = false;
            Object = object;
            Next = next;
            Previous = previous;
        }
    };

    int countOfElements;
    DoublyLinkedElement *firstElement;
    DoublyLinkedElement *currentElement;
    DoublyLinkedElement *lastElement;

public:

    CustomDoublyLinkedList() {
        countOfElements = 0;
        firstElement = new DoublyLinkedElement();
        currentElement = firstElement;
        lastElement = firstElement;
    }

    ~CustomDoublyLinkedList() {
        for (; !firstElement->IsBorder;) {
            currentElement = firstElement;
            firstElement = firstElement->Next;
            delete currentElement;
        }
    }

    void Add(T object) {
        if (countOfElements == 0) {
            currentElement = new DoublyLinkedElement(object, firstElement);
            firstElement->Next = currentElement;
            firstElement = currentElement;
            lastElement = currentElement;
        } else {
            lastElement->Next = new DoublyLinkedElement(object, lastElement);
            lastElement = lastElement->Next;
        }
        countOfElements++;
    }

    T Get() {
        return currentElement->Object;
    }

    T GetNext() {
        return currentElement->Next.Object;
    }

    T GetPrevious() {
        return currentElement->Previous->Object;
    }

    T GetFirst() {
        return firstElement->Next.Object;
    }

    T GetLast() {
        return lastElement->Next.Object;
    }

    void MovePointerToTheBeginning(){
        currentElement = firstElement;
    }

    void MovePointerToTheEnd(){
        currentElement = lastElement;
    }

    T MoveNext() {
        T tmp = currentElement->Object;
        currentElement = currentElement->Next;
        return tmp;
    }

    T MovePrevious() {
        T tmp = currentElement->Object;
        currentElement = currentElement->Previous;
        return tmp;
    }

    void RemoveCurrent() {
        currentElement->Previous->Next = currentElement->Next;
        currentElement->Next->Previous = currentElement->Previous;
        if(currentElement->Next->IsBorder && !currentElement->Previous->IsBorder){
            currentElement = currentElement->Previous;
            lastElement = currentElement;
        }
        else if(!currentElement->Next->IsBorder && currentElement->Previous->IsBorder){
            currentElement = currentElement->Next;
            firstElement = currentElement;
        }
        else{
            delete currentElement->Next;
            currentElement = currentElement->Previous;
            firstElement = currentElement;
            lastElement = currentElement;
        }
        delete currentElement;
        countOfElements--;
    }

    bool IsBorderReached() {
        return currentElement->IsBorder;
    }

    int GetCount() {
        return countOfElements;
    }

};

#endif //USATU_OOP_LW_3_CUSTOMDOUBLYLINKEDLIST_H
