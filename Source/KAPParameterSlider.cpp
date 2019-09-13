/*
  ==============================================================================

    KAPParameterSlider.cpp
    Created: 21 Aug 2019 9:22:23am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "KAPParameterSlider.h"

KAPParameterSlider::KAPParameterSlider(AudioProcessorValueTreeState& stateToControl,
                                       const String& parameterID,
                                       const String& parameterLabel)
:   juce::Slider(parameterLabel)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextBoxBelow, false, 0, 0);
    
    setRange(0.0f, 1.0f, 0.001f);
    
    mAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(stateToControl, parameterID, *this);
    
}

KAPParameterSlider::~KAPParameterSlider()
{
    
    
}
