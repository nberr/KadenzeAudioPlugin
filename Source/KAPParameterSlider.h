/*
  ==============================================================================

    KAPParameterSlider.h
    Created: 21 Aug 2019 9:22:23am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class KAPParameterSlider
:   public Slider
{
public:
    KAPParameterSlider(AudioProcessorValueTreeState& stateToControl,
                       const String& parameterID,
                       const String& parameterLabel);
    ~KAPParameterSlider();
    
    
private:
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPParameterSlider)
};
