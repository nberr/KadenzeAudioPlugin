/*
  ==============================================================================

    KAPAudioHelpers.h
    Created: 19 Aug 2019 10:06:40am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#define kParameterSmoothingCoeff_Generic 0.04
#define kParameterSmoothingCoeff_Fine 0.002
#define kMeterSmoothingCoeff 0.2f

const int maxBufferSize = 192000;

static inline float dBToNormalizeGain(float inValue)
{
    float inValuedB = Decibels::gainToDecibels(inValue + 0.00001f);
    inValuedB = (inValuedB + 96.0f) / 96.0f;
    
    return inValuedB;
}

// check wiki for formula
inline float kap_linear_interp(float v0, float v1, float t)
{
    return (1 - t) * v0 + t * v1;
}

inline double tanh_clip(double x)
{
    return x * (27 + x * x) / (27 + 9 * x * x);
}

inline float kap_denormalize(float inValue)
{
    float abs = fabs(inValue);
    
    if (abs < 1e-15)
    {
        return 0.0f;
    }
    else
    {
        return inValue;
    }
}
