#include "LibrarySystem.h"

int main() {
    LibrarySystem system;
    try {
        system.start();
    }
    catch (const LibraryException& e) {
        cout << "An error occurred: " << e.what() << endl;
    }
    return 0;
}