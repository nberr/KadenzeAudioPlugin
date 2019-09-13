/*
  ==============================================================================

    KAPLfo.cpp
    Created: 19 Aug 2019 10:07:52am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "KAPLfo.h"

#include "JuceHeader.h"

KAPLfo::KAPLfo()
{
    reset();
}

KAPLfo::~KAPLfo()
{
    
}

void KAPLfo::reset()
{
    mPhase = 0.0f;
    zeromem(mBuffer, sizeof(float) * maxBufferSize);
}

void KAPLfo::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void KAPLfo::process(float inRate, float inDepth, int inNumSamples)
{
    const float rate = jmap(inRate, 0.0f, 1.0f, 0.01f, 10.0f);
    
    for (int i = 0; i < inNumSamples; i++) {
        mPhase = mPhase + (rate / mSampleRate);
        
        if (mPhase > 1.0f) {
            mPhase -= 1.0f;
        }
        
        const float lfoPosition = sinf(mPhase * M_PI_2) * inDepth;
        mBuffer[i] = lfoPosition;
    }
}

float* KAPLfo::getBuffer()
{
    return mBuffer;
}
