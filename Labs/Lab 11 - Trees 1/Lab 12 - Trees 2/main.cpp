#include <cstdlib>
#include <stdlib.h> //for rand()!
#include "Heap.h"
using namespace std;

int main(int argc, char** argv) {
    //variables
    int N = 0;
    int randomNum = 0;
    
    cout << "Now inserting..." << endl;
    cout << "N = ";
    cin >> N;
    
    Heap* heap = new Heap(N);
    
    for (int i = 0; i < N; i++) {
        //get random number
        randomNum = rand() % N;
        cout << "randomNum = " << randomNum << endl;
        //insert it
        heap->insert(randomNum);
    }
    
    cout << endl << "Now removing..." << endl;  
    
    while (!heap->isEmpty()) {
        heap->remove(N);
        cout << "removed " << N << endl;
        heap->print();
    }
    
    return 0;
}

