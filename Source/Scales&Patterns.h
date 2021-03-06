/*
  ==============================================================================

    Scales&Patterns.h
    Created: 13 Dec 2014 6:35:44pm
    Author:  Liam Lacey

  ==============================================================================
*/

#ifndef SCALES_H_INCLUDED
#define SCALES_H_INCLUDED

#define NUM_OF_SCALES /*10*/ 6
#define NUM_OF_CHORD_PROGRESSIONS 24
#define NUM_OF_DRUM_PATTERNS 15
#define NUM_OF_NOTE_AMOUNTS 7
#define DRUM_PATTERN_LENGTH 16
#define CHORD_PROG_LENGTH 4
#define SCALE_LENGTH 7


namespace Scales
{
    //Stores just one octave worth of a scale.
    //First index is scale number, second index is note number.
    //-1 means not a note (this is needed as some scales has less notes in an octave).
    //I've put them in an order from happy to sad (ish).
    //These scales are used to determine notes that can be used in lead, pads, and bass layers.
    const int scale[NUM_OF_SCALES][SCALE_LENGTH] =
    {
        {0,2,4,5,7,9,11}, //major
        {0,2,4,7,9,12,14}, //majorPentatonic
        //{0,3,5,6,7,10,12}, //blues
        //{0,3,4,5,7,9,10}, //rockNRoll
        //{0,2,3,6,7,8,11}, //hungarianGypsy
        //{0,4,5,7,9,10,11}, //ragaMadhuri
        {0,2,3,5,7,8,10}, //minor
        {0,3,5,7,10,12,15}, //minorPentatonic
        {0,2,3,5,7,9,11}, //melodicMinor
        {0,2,3,5,7,8,11} //harmonicMinor
    };
    
    //Stores order of root notes for a chord progression based on selected scale.
    //First index is progression number, second index is note index number.
    //I haven't put these in any type of order - What order could I put them in?
    //These progressions are used to determine the pads and bass note order/pattern.
    const int chordProgression[NUM_OF_CHORD_PROGRESSIONS][CHORD_PROG_LENGTH] =
    {
        {1,4,5,5},
        {1,2,5,5},
        {1,4,2,5},
        {1,4,5,7},
        {1,2,5,7},
        {1,4,2,7},
        
        {5,5,4,1},
        {5,5,2,1},
        {5,2,4,1},
        {7,5,4,1},
        {7,5,2,1},
        {7,2,4,1},
        
        {5,5,1,4},
        {5,5,1,2},
        {5,2,1,4},
        {7,5,1,4},
        {7,5,1,2},
        {7,2,1,4},
        
        {5,1,5,4},
        {5,1,5,2},
        {5,1,2,4},
        {7,1,5,4},
        {7,1,5,2},
        {7,1,2,4},
        
    };
}

namespace DrumPatterns
{
    //Stores a number a different parts for each type of drum.
    //First index is pattern number, second index is hit/rest in pattern.
    //A 1 signifies a hit, and a 0 signifies a rest.
    
    const int kickPattern[NUM_OF_DRUM_PATTERNS][DRUM_PATTERN_LENGTH] =
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
        {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0},
        {1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0},
        {1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0},
        {1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0},
        {1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0},
        {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},
        {1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1},
        {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0},
        {1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };
    
    const int snarePattern[NUM_OF_DRUM_PATTERNS][DRUM_PATTERN_LENGTH] =
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0},
        {0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},
        {0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0},
        {1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0},
        {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},
        {1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1},
        {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0},
        {1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };
    
    const int perc1Pattern[NUM_OF_DRUM_PATTERNS][DRUM_PATTERN_LENGTH] =
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0},
        {0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0},
        {0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0},
        {0,0,1,0,0,1,1,0,1,0,1,0,1,0,1,0},
        {1,0,0,0,0,0,1,0,1,0,0,1,0,1,1,0},
        {0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0},
        {1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1},
        {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0},
        {1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };
    
    const int perc2Pattern[NUM_OF_DRUM_PATTERNS][DRUM_PATTERN_LENGTH] =
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0},
        {0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0},
        {0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0},
        {0,0,1,0,0,1,1,0,1,0,1,0,1,0,1,0},
        {1,0,0,0,0,0,1,0,1,0,0,1,0,1,1,0},
        {0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0},
        {1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1},
        {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0},
        {1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };
    
}


const int noteAmount[NUM_OF_NOTE_AMOUNTS] = {1,1,2,4,8,12,16};


#endif  // SCALES_H_INCLUDED
