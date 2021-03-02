/*
  ==============================================================================

    KAPParameterComboBox.h
    Created: 21 Aug 2019 9:22:39am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class KAPParameterComboBox
:   public ComboBox
{
public:
    KAPParameterComboBox(AudioProcessorValueTreeState& stateToControl, const String& parameterID);
    ~KAPParameterComboBox();
    
private:
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPParameterComboBox)
};
