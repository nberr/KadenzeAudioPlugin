/*
  ==============================================================================

    KAPGain.cpp
    Created: 19 Aug 2019 10:08:05am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "KAPGain.h"

#include "KAPAudioHelpers.h"

KAPGain::KAPGain()
:   mOutputSmoothed(0)
{
    
}

KAPGain::~KAPGain()
{
    
}

void KAPGain::process(float* inAudio, float inGain, float* outAudio, int inNumSamplesToRender)
{
    // gain as a decimal mapped to decibels
    float gainMapped = jmap(inGain, 0.0f, 1.0f, -24.0f, 24.0f);
    gainMapped = Decibels::decibelsToGain(gainMapped, -24.0f);
    
    for (int i = 0; i < inNumSamplesToRender; i++)
    {
        outAudio[i] = inAudio[i] * gainMapped;
    }
    
    float absValue = fabs(outAudio[0]);
    mOutputSmoothed = kMeterSmoothingCoeff * (mOutputSmoothed - absValue) + absValue;
}

float KAPGain::getMeterLevel()
{
    return mOutputSmoothed;
}
