/*
  ==============================================================================

    KAPLfo.h
    Created: 19 Aug 2019 10:07:52am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "KAPAudioHelpers.h"

class KAPLfo
{
public:
    KAPLfo();
    ~KAPLfo();
    
    void reset();
    void setSampleRate(double inSampleRate);
    void process(float inRate, float inDepth, int inNumSamples);
    
    float* getBuffer();
    
private:
    double mSampleRate;
    float mPhase;
    float mBuffer[maxBufferSize];
    
};
