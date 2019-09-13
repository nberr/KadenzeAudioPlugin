/*
  ==============================================================================

    KAPGainPanel.h
    Created: 19 Aug 2019 8:11:23pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPParameterSlider.h"
#include "KAPVuMeter.h"

class KAPGainPanel
:   public KAPPanelBase
{
public:
    KAPGainPanel(KadenzeAudioPluginAudioProcessor *inProcessor);
    ~KAPGainPanel();
    
    void paint(Graphics& g) override;
    
    void setParameterID(int inParameterID);
    
private:
    std::unique_ptr<KAPParameterSlider> mSlider;
    
    std::unique_ptr<KAPVuMeter> mVuMeter;
};
