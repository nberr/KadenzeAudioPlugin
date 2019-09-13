/*
  ==============================================================================

    KAPFxPanel.h
    Created: 19 Aug 2019 8:11:12pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPParameterSlider.h"

enum KAPFxPanelStyle
{
    kKAPFxPanelStyle_Delay = 0,
    kKAPFxPanelStyle_Chorus,
    kKAPFxPanelStyle_TotalNumStyles
};

class KAPFxPanel
:   public KAPPanelBase,
    public ComboBox::Listener
{
public:
    KAPFxPanel(KadenzeAudioPluginAudioProcessor *inProcessor);
    ~KAPFxPanel();
    
    void paint(Graphics& g) override;
    
    void setFxPanelStyle(KAPFxPanelStyle inStyle);
    
    void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;
    
private:
    KAPFxPanelStyle mStyle;
    OwnedArray<KAPParameterSlider> mSliders;
    
};
