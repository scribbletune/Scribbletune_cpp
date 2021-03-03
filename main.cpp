#include <iostream>
#include <vector>
#include "Scribbletune.h"

int main() {
    Scribbletune scribble;
    vector<string> scaleNotes;
    scaleNotes = scribble.scale("c2 minor pentatonic");
    
    for (int i = 0; i < scaleNotes.size(); i++)
        std::cout << scaleNotes.at(i) << std::endl;

    return 0;
};
