#include <iostream>
#include "LinkedList.h"
using namespace std;
int main(void) {
    LinkedList<int> list;
    for (int i = 0; i < 10; i++) {
        list.append(i);
    }

    for (int i = 0; i < 10; i++) {
        cout << list.pop() << endl;
    }

}