#pragma once

#include <iostream>
#include <vector>
#include <regex>
#include <map>

using namespace std;

class Scribbletune {
    int getPitchFromNote(string note);
    string getNoteFromPitch(int pitch, string accidental);
    map<string,string> getScales();
    string getScaleFromScaleMaps(string scale);
    int computeMidiPitchFromNote(string n);
    string computeNoteFromMidiPitch(int p, string accidental);

    public:
        Scribbletune();
        vector<string> scale(string name);
};
