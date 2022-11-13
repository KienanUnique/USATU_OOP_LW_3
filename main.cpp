#include <iostream>
#include "CustomDoublyLinkedList.h"

using namespace std;

// TODO: class Square: CalculatePerimeter
// TODO: Get...Time

void PrintList(CustomDoublyLinkedList<string> customDoublyLinkedList) {
    customDoublyLinkedList.MovePointerToTheBeginning();
    for (; !customDoublyLinkedList.IsBorderReached(); customDoublyLinkedList.MoveNext()) {
        cout << customDoublyLinkedList.Get().append(" appended info") << endl;
    }
}

CustomDoublyLinkedList<string> GetListFilledWithRandomElements(int countOfElements) {
    const int MAX_RANDOM_NUM = 999999;

    CustomDoublyLinkedList<string> customSinglyLinkedList = CustomDoublyLinkedList<string>();
    for (int i = 0; i < countOfElements; i++) {
        customSinglyLinkedList.Add("random number: " + to_string(rand() % MAX_RANDOM_NUM));
    }
    return customSinglyLinkedList;
}

int main() {
    srand(time(nullptr));
    CustomDoublyLinkedList<string> customDoublyLinkedList = GetListFilledWithRandomElements(10);
    PrintList(customDoublyLinkedList);

    return 0;
}
