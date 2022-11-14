#include <iostream>
#include <chrono>
#include "CustomDoublyLinkedList.h"

using namespace std;

const int MAX_RANDOM_NUM = 999999;

void PrintList(CustomDoublyLinkedList<int> customDoublyLinkedList) {
    customDoublyLinkedList.MovePointerToTheBeginning();
    while (!customDoublyLinkedList.IsBorderReached()) {
        cout << customDoublyLinkedList.MoveNext() << endl;
    }
}

void FillListWithRandom(CustomDoublyLinkedList<int> &customDoublyLinkedList, int countOfElements) {
    for (int i = 0; i < countOfElements; i++) {
        customDoublyLinkedList.Add(rand() % MAX_RANDOM_NUM);
    }
}

void DeleteAllElementsInList(CustomDoublyLinkedList<int> &customDoublyLinkedList) {
    customDoublyLinkedList.MovePointerToTheBeginning();
    while (!customDoublyLinkedList.IsBorderReached()) {
        customDoublyLinkedList.RemoveCurrent();
    }
}

void InsertBeforeElementsInLst(CustomDoublyLinkedList<int> &customDoublyLinkedList, int countOfElements) {

    customDoublyLinkedList.MovePointerToTheBeginning();
    for (int i = 0; i < countOfElements; i++) {
        customDoublyLinkedList.InsertBeforeCurrent(rand() % MAX_RANDOM_NUM);
    }
}

void InsertAfterElementsInLst(CustomDoublyLinkedList<int> &customDoublyLinkedList, int countOfElements) {
    customDoublyLinkedList.MovePointerToTheBeginning();
    for (int i = 0; i < countOfElements; i++) {
        customDoublyLinkedList.InsertAfterCurrent(rand() % MAX_RANDOM_NUM);
    }
}

long long MeasureWorkSimulation(CustomDoublyLinkedList<int> &customDoublyLinkedList) {
    int countOfSimulationTests = 1000;
    const int countOfAddCall = 10;
    const int countOfInsertionsCalls = 10;
    const int countOfRemoveCalls = 4;

    chrono::steady_clock::time_point begin, end;

    unsigned int countOfMultiplesTwo = 0;
    unsigned int countOfMultiplesThree = 0;

    begin = chrono::steady_clock::now();
    for (int current_test_num = 0; current_test_num < countOfSimulationTests; current_test_num++) {
        for (int i = 0; i < countOfAddCall; i++) {
            customDoublyLinkedList.Add(rand() % MAX_RANDOM_NUM);
        }
        for (int i = 0; i < countOfInsertionsCalls; i++) {
            customDoublyLinkedList.InsertAfterCurrent(rand() % MAX_RANDOM_NUM);
            customDoublyLinkedList.InsertBeforeCurrent(rand() % MAX_RANDOM_NUM);
        }
        for (int i = 0; i < countOfRemoveCalls; i++) {
            customDoublyLinkedList.RemoveCurrent();
        }

        long long current_sum = 0;
        customDoublyLinkedList.MovePointerToTheBeginning();
        while (!customDoublyLinkedList.IsBorderReached()) {
            if(customDoublyLinkedList.Get() % 2 == 0){
                countOfMultiplesTwo++;
            }
            else if(customDoublyLinkedList.Get() % 2 == 0){
                countOfMultiplesThree++;
            }

            current_sum += customDoublyLinkedList.MoveNext();
        }
    }
    end = chrono::steady_clock::now();
    return chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
}

int main() {
    srand(time(nullptr));
    chrono::steady_clock::time_point begin, end;
    for (int countOfElements = 100; countOfElements <= 10000; countOfElements *= 10) {
        cout << "====== Count of elements : " << countOfElements << endl;
        CustomDoublyLinkedList<int> customSinglyLinkedList = CustomDoublyLinkedList<int>();
        FillListWithRandom(customSinglyLinkedList, countOfElements);
        cout << "Time: " << MeasureWorkSimulation(customSinglyLinkedList) << " ms" << endl << endl;
    }

    return 0;
}
