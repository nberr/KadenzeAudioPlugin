/*
  ==============================================================================

    KAPDelay.cpp
    Created: 19 Aug 2019 10:08:23am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "KAPDelay.h"

#include <JuceHeader.h>
#include "KAPAudioHelpers.h"
#include "KAPFxPanel.h"

KAPDelay::KAPDelay()
:   mSampleRate(-1),
    mFeedbackSample(0.0),
    mTimeSmoothed(0),
    mDelayIndex(0)
{

}

KAPDelay::~KAPDelay()
{
    
}

void KAPDelay::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void KAPDelay::reset()
{
    // clear the buffer
    zeromem(mBuffer, sizeof(double) * maxBufferSize);
    
    mTimeSmoothed = 0;
}

void KAPDelay::process(float* inAudio, float inTime, float inFeedback, float inWetDry, float inType, float* inModulationBuffer, float* outAudio, int inNumSamplesToRender)
{
    const float wet = inWetDry;
    const float dry = 1.0f - wet;
    float feedbackMapped = 0.0f;
    
    if ((int)inType == (int)kKAPDelayType_Delay) {
        feedbackMapped = jmap(inFeedback, 0.0f, 1.0f, 0.0f, 1.20f);
    }
    
    for (int i = 0; i < inNumSamplesToRender; i++)
    {
        if ((int)inType == kKAPDelayType_Delay) {
             mTimeSmoothed = mTimeSmoothed - kParameterSmoothingCoeff_Fine * (mTimeSmoothed - inTime);
        }
        else
        {
            const double delayTimeModulation = 0.003 + (0.002 * inModulationBuffer[i]);
            mTimeSmoothed = mTimeSmoothed - kParameterSmoothingCoeff_Fine * (mTimeSmoothed - delayTimeModulation);
        }
        
        const double delayTimeInSamples = mTimeSmoothed * mSampleRate;
        const double sample = getInterpolatedSample(delayTimeInSamples);
        
        mBuffer[mDelayIndex] = tanh_clip(inAudio[i] + (mFeedbackSample * feedbackMapped));
        
        mFeedbackSample = sample;
        
        outAudio[i] = inAudio[i] * dry + sample * wet;
        
        mDelayIndex++;
        
        if (mDelayIndex >= maxBufferSize)
        {
            mDelayIndex -= maxBufferSize;
        }
    }
}

double KAPDelay::getInterpolatedSample(float inDelayTimeInSamples)
{
    double readPosition = (double)mDelayIndex - inDelayTimeInSamples;
    
    if (readPosition < 0) {
        readPosition += maxBufferSize;
    }
    
    int index_y0 = (int)readPosition - 1;
    // wrap around
    if (index_y0 <= 0)
    {
        index_y0 += maxBufferSize;
    }
    
    int index_y1 = readPosition;
    // wrap around
    if (index_y1 > maxBufferSize)
    {
        index_y1 -= maxBufferSize;
    }
    
    const float sample_y0 = mBuffer[index_y0];
    const float sample_y1 = mBuffer[index_y1];
    
    const float t = readPosition - (int)readPosition;
    double outSample = kap_linear_interp(sample_y0, sample_y1, t);
    
    return outSample;
    
}
