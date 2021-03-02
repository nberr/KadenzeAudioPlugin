/*
  ==============================================================================

    KAPPanelBase.h
    Created: 19 Aug 2019 8:12:39pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "KAPInterfaceDefines.h"

class KAPPanelBase
:   public Component
{
public:
    
    KAPPanelBase(KadenzeAudioPluginAudioProcessor *inProcessor);
    ~KAPPanelBase();
    
    void mouseEnter(const MouseEvent& event) override;
    void mouseExit(const MouseEvent& event) override;
    
    void paint(Graphics& g) override;
    
protected:
    KadenzeAudioPluginAudioProcessor *mProcessor;
    
};
