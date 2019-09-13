/*
  ==============================================================================

    KAPParameterComboBox.cpp
    Created: 21 Aug 2019 9:22:39am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "KAPParameterComboBox.h"

KAPParameterComboBox::KAPParameterComboBox(AudioProcessorValueTreeState& stateToControl, const String& parameterID)
:   juce::ComboBox(parameterID)
{
    mAttachment = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(stateToControl, parameterID, *this);
    
}

KAPParameterComboBox::~KAPParameterComboBox()
{
    
}
