/*
  ==============================================================================

    KAPVuMeter.h
    Created: 11 Sep 2019 10:44:03pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"

class KAPVuMeter
:   public Component,
    public Timer
{
public:
    KAPVuMeter(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPVuMeter();
    
    void paint(Graphics& g) override;
    
    void timerCallback() override;
    
    void setParameterID(int inParameterID);
    
private:
    int mParameterID;
    
    float mCh0Level;
    float mCh1Level;
    
    KadenzeAudioPluginAudioProcessor* mProcessor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPVuMeter)
};
