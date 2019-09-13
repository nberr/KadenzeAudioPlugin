/*
  ==============================================================================

    KAPTopPanel.h
    Created: 19 Aug 2019 8:11:37pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"

class KAPTopPanel
:   public KAPPanelBase,
    public Button::Listener,
    public ComboBox::Listener
{
public:
    KAPTopPanel(KadenzeAudioPluginAudioProcessor *inProcessor);
    ~KAPTopPanel();
    
    void paint(Graphics& g) override;
    
    void buttonClicked(Button*) override;
    void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;
    
private:
    void displaySaveAsPopup();
    
    void updatePresetComboBox();
    
    std::unique_ptr<ComboBox> mPresetDisplay;
    
    std::unique_ptr<TextButton> mNewPreset, mSavePreset, mSaveAsPreset;
    
};
