#include <iostream>
#include <vector>
#include <regex>
#include <map>
#include "Scribbletune.h"

using namespace std;

Scribbletune::Scribbletune() {

};


int Scribbletune::getPitchFromNote(string note) {
    map<string,int> m;
    m["a"] = 21;
    m["b"] = 22;
    m["c"] = 12;
    m["d"] = 14;
    m["e"] = 16;
    m["f"] = 17;
    m["g"] = 19;

    return m[note];
}

string Scribbletune::getNoteFromPitch(int pitch, string accidental) {
    map<int, string> m;
    m[12] = "c";
    m[13] = accidental == "#" ? "c#" : "db";
    m[14] = "d";
    m[15] = accidental == "#" ? "d#" : "eb";
    m[16] = "e";
    m[17] = "f";
    m[18] = accidental == "#" ? "f#" : "gb";
    m[19] = "g";
    m[20] = accidental == "#" ? "g#" : "ab";
    m[21] = "a";
    m[22] = accidental == "#" ? "a#" : "bb";
    m[23] = "b";

    return m[pitch];
}

map<string,string> Scribbletune::getScales() {
    map<string,string> m;
    m["major pentatonic"] = "WWHW";
    m["ionian pentatonic"] = "HHWH";
    m["mixolydian pentatonic"] = "HHWH";
    m["ritusen"] = "WHWW";
    m["egyptian"] = "WHWH";
    m["neopolitan major pentatonic"] = "HHHH";
    m["vietnamese 1"] = "HWWH";
    m["pelog"] = "HWHH";
    m["kumoijoshi"] = "HHWH";
    m["hirajoshi"] = "WHHH";
    m["iwato"] = "HHHH";
    m["in-sen"] = "HHWH";
    m["lydian pentatonic"] = "HWHH";
    m["malkos raga"] = "HWHW";
    m["locrian pentatonic"] = "HWHH";
    m["minor pentatonic"] = "HWWH";
    m["minor six pentatonic"] = "HWWW";
    m["flat three pentatonic"] = "WHHW";
    m["flat six pentatonic"] = "WWHH";
    m["scriabin"] = "HHHW";
    m["whole tone pentatonic"] = "HWWW";
    m["lydian #5P pentatonic"] = "HWWH";
    m["lydian dominant pentatonic"] = "HWHH";
    m["minor #7M pentatonic"] = "HWWH";
    m["super locrian pentatonic"] = "HHWH";
    m["minor hexatonic"] = "WHWWH";
    m["augmented"] = "HHHHH";
    m["major blues"] = "WHHHW";
    m["piongio"] = "WHWWH";
    m["prometheus neopolitan"] = "HHWHH";
    m["prometheus"] = "WWWHH";
    m["mystery #1"] = "HHWWW";
    m["six tone symmetric"] = "HHHHH";
    m["whole tone"] = "WWWWW";
    m["messiaen's mode #5"] = "HHHHH";
    m["minor blues"] = "HWHHH";
    m["locrian major"] = "WWHHWW";
    m["double harmonic lydian"] = "HHWHHH";
    m["harmonic minor"] = "WHWWHH";
    m["altered"] = "HWHWWW";
    m["locrian #2"] = "WHWHWW";
    m["mixolydian b6"] = "WWHWHW";
    m["lydian dominant"] = "WWWHWH";
    m["lydian"] = "WWWHWW";
    m["lydian augmented"] = "WWWWHW";
    m["dorian b2"] = "HWWWWH";
    m["melodic minor"] = "WHWWWW";
    m["locrian"] = "HWWHWW";
    m["ultralocrian"] = "HWHWWH";
    m["locrian 6"] = "HWWHHH";
    m["augmented heptatonic"] = "HHHWHH";
    m["romanian minor"] = "WHHHWH";
    m["dorian #4"] = "WHHHWH";
    m["lydian diminished"] = "WHHHWW";
    m["phrygian"] = "HWWWHW";
    m["leading whole tone"] = "WWWWWH";
    m["lydian minor"] = "WWWHHW";
    m["phrygian dominant"] = "HHHWHW";
    m["balinese"] = "HWWWHH";
    m["neopolitan major"] = "HWWWWW";
    m["aeolian"] = "WHWWHW";
    m["harmonic major"] = "WWHWHH";
    m["double harmonic major"] = "HHHWHH";
    m["dorian"] = "WHWWWH";
    m["hungarian minor"] = "WHHHHH";
    m["hungarian major"] = "HHWHWH";
    m["oriental"] = "HHHHHH";
    m["flamenco"] = "HWHWHH";
    m["todi raga"] = "HWHHHH";
    m["mixolydian"] = "WWHWWH";
    m["persian"] = "HHHHWH";
    m["major"] = "WWHWWW";
    m["enigmatic"] = "HHWWWH";
    m["major augmented"] = "WWHHHW";
    m["lydian #9"] = "HHWHWW";
    m["messiaen's mode #4"] = "HHHHHHH";
    m["purvi raga"] = "HHHHHHH";
    m["spanish heptatonic"] = "HWHHWHW";
    m["bebop"] = "WWHWWHH";
    m["bebop minor"] = "WHHHWWH";
    m["bebop major"] = "WWHWHHW";
    m["bebop locrian"] = "HWWHHHW";
    m["minor bebop"] = "WHWWHWH";
    m["diminished"] = "WHWHWHW";
    m["ichikosucho"] = "WWHHHWW";
    m["minor six diminished"] = "WHWWHHW";
    m["half-whole diminished"] = "HWHWHWH";
    m["kafi raga"] = "HHHWWHH";
    m["messiaen's mode #6"] = "WWHHWWH";
    m["composite blues"] = "WHHHHHWH";
    m["messiaen's mode #3"] = "WHHWHHWH";
    m["messiaen's mode #7"] = "HHHWHHHHW";
    m["chromatic"] = "HHHHHHHHHHH";
    return m;
}

string Scribbletune::getScaleFromScaleMaps(string scale) {
    map<string,string> m = getScales();
    return m[scale];
}

int Scribbletune::computeMidiPitchFromNote(string n) {
    smatch match;
    regex exp;

    // n is something like G#4
    // use a regular expression to get the note, accidental and octave
    exp = "([a-gA-G])([b#])?([0-9])";

    regex_match(n, match, exp);
    
    string note; // G 
    string accidental; // # or b
    int octave; // 4

    note = match[1];
    accidental = match[2];
    octave = stoi(match[3]);

    int accidentalFactor;
    accidentalFactor = (accidental == "#") ? 1 : -1;

    return (12 * octave) + this->getPitchFromNote(note) + (accidentalFactor * accidental.size());
}

string Scribbletune::computeNoteFromMidiPitch(int p, string accidental) {
    int octave;
    int noteNum;
    string noteName;

    if (p > 23) {
        // noteNum is on octave 1 or more
        octave = p / 12 - 1;
        // subtract number of octaves from noteNum
        noteNum = p - octave * 12;
    }

    noteName = this->getNoteFromPitch(noteNum, accidental);
    return noteName + to_string(octave);
}

vector<string> Scribbletune::scale(string name) {
    smatch match;
    regex exp;

    exp = "([a-gA-G][b#]?[0-9]) (.+)";

    regex_match(name, match, exp);

    string note; 
    string scale;

    note = match[1]; // C4
    scale = match[2]; // major

    vector<string> v;
    v.push_back(note);

    // update the regular expression to get the accidental from the note
    exp = "([a-gA-G])([b#])?([0-9])";
    regex_match(note, match, exp);
    string accidental = match[2]; // # or b

    int pitch = this->computeMidiPitchFromNote(note);
    string scaleMap = this->getScaleFromScaleMaps(scale);
    for (int i = 0; i < scaleMap.length(); i++) {
        if (scaleMap.at(i) == 'W') {
            pitch += 2;
        } else {
            pitch += 1;
        }
        v.push_back(this->computeNoteFromMidiPitch(pitch, accidental));
    }
    return v;
}

