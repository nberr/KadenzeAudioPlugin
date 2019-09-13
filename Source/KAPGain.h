/*
  ==============================================================================

    KAPGain.h
    Created: 19 Aug 2019 10:08:05am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

class KAPGain
{
public:
    KAPGain();
    ~KAPGain();
    
    void process(float* inAudio, float inGain, float* outAudio, int inNumSamplesToRender);
    
    float getMeterLevel();
    
private:
    float mOutputSmoothed;
};
