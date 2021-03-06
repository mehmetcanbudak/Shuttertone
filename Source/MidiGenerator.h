/*
  ==============================================================================

    MidiGenerator.h
    Created: 13 Dec 2014 2:39:09pm
    Author:  Liam Lacey

  ==============================================================================
*/

#ifndef MIDIGENERATOR_H_INCLUDED
#define MIDIGENERATOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Scales&Patterns.h"

//This is my first attempt at a struct for storing note data so we can play a sequence of notes.
//When searching through arrays of this struct, it should only process the object/note
//if the current time/step matches the step number.
//I am sorting the arrays by note_step_num, so this makes
//it possible to only have to search through a particular range of the array,
//not the whole thing, which was very CPU intensive when I tried this.

struct NoteMessageData
{
    int note_step_num; //timestamp
    int note_chan;
    int note_num;
    int note_vel;
    int note_length; //in step numbers
};

#define NUM_OF_LAYERS NUM_IMG_SECTIONS

enum SequencerLayers
{
    LAYER_MELODY = 0,
    LAYER_PAD,
    LAYER_BASS,
    LAYER_PERC
};

#define SEQ_MAX_NUM_OF_STEPS 128 //keep this as a division of 16 otherwise it'll break things currently!
#define SEQ_MAX_NUM_OF_NOTES 512
#define SIZE_OF_NOTE_OFF_BUF 64

#define SEQ_MELODY_CHAN 1
#define SEQ_PAD_CHAN 2
#define SEQ_BASS_CHAN 3
#define SEQ_PERC_CHAN 4

#define NO_NOTE -1

#define NOTE_NUM_KICK 36
#define NOTE_NUM_SNARE 38
#define NOTE_NUM_PERC1 37
#define NOTE_NUM_PERC2 43


class MidiGenerator : public Thread
{
    
public:
    //==============================================================================
    
    MidiGenerator();
    ~MidiGenerator();
    
    void setSequenceData();
    
    //Thread callback function
    void run();
    
    void sendMidiMessage (MidiMessage midiMessage);
    
    void setMidiOutputDevice (int deviceListIndex);
    StringArray getMidiOutputListNames();
    
    void setAverageRed (int section_num, float value);
    void setAverageGreen (int section_num, float value);
    void setAverageBlue (int section_num, float value);
    void setAverageBrightness (int section_num, float value);
    void setAveragePerceivedBrightness (int section_num, float value);
    void setAverageHue (int section_num, float value);
    void setAverageSaturation (int section_num, float value);
    
    float getAverageRed (int section_num);
    float getAverageGreen (int section_num);
    float getAverageBlue (int section_num);
    float getAverageBrightness (int section_num);
    float getAveragePerceivedBrightness (int section_num);
    float getAverageHue (int section_num);
    float getAverageSaturation (int section_num);
    
private:
    //==============================================================================
    
    //MIDI output device stuff...
    std::unique_ptr<MidiOutput> midiOutputDevice;
    Array <MidiDeviceInfo> midiDeviceInfoArray;
    int virtualMidiOuputDeviceIndex = -1;
    
    //variables to store the average colour values for each image section (including a whole-image average)
    float averageRed[NUM_IMG_SECTIONS + 1];
    float averageGreen[NUM_IMG_SECTIONS + 1];
    float averageBlue[NUM_IMG_SECTIONS + 1];
    float averageBrightness[NUM_IMG_SECTIONS + 1];
    float averagePerceivedBrightness[NUM_IMG_SECTIONS + 1];
    float averageHue[NUM_IMG_SECTIONS + 1];
    float averageSaturation[NUM_IMG_SECTIONS + 1];
    
    //arrays to store sequences of note data
    NoteMessageData noteSequence[NUM_OF_LAYERS][SEQ_MAX_NUM_OF_NOTES];
    
    int stepInterval; //used as a tempo indicator
    
    //array that, during play time, stores the current position we are getting notes out of noteSequence for each layer.
    //this is so that for each step we don't need to look through the entire length of each array (as this was causing very high CPU).
    int currentArrayPos[NUM_OF_LAYERS];
    //stores the first index of noteSequence that stores an actual note, as opposed to -1 (NO_NOTE), for each layer.
    //used in conjuntion with the above array.
    int startArrayPos[NUM_OF_LAYERS];
};



#endif  // MIDIGENERATOR_H_INCLUDED
