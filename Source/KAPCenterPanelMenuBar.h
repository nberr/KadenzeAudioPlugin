/*
  ==============================================================================

    KAPCenterPanelMenuBar.h
    Created: 19 Aug 2019 8:10:57pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"

#include "KAPParameterComboBox.h"

class KAPCenterPanelMenuBar
:   public KAPPanelBase
{
public:
    KAPCenterPanelMenuBar(KadenzeAudioPluginAudioProcessor *inProcessor);
    ~KAPCenterPanelMenuBar();
    
    void addFxTypeComboBoxListener(ComboBox::Listener* inListener);
    void removeFxTypeComboBoxListener(ComboBox::Listener* inListener);
    
private:
    std::unique_ptr<KAPParameterComboBox> mFxTypeComboBox;
};

