/*
  ==============================================================================

    KAPCenterPanel.cpp
    Created: 19 Aug 2019 8:10:48pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "KAPCenterPanel.h"
#include "KAPParameters.h"

KAPCenterPanel::KAPCenterPanel(KadenzeAudioPluginAudioProcessor *inProcessor)
:   KAPPanelBase(inProcessor)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    
    mMenuBar = std::make_unique<KAPCenterPanelMenuBar>(inProcessor);
    mMenuBar->setTopLeftPosition(0, 0);
    addAndMakeVisible(*mMenuBar);
    
    mFxPanel = std::make_unique<KAPFxPanel>(inProcessor);
    mFxPanel->setTopLeftPosition((int)*(mProcessor->parameters.getRawParameterValue(KAPParameterID[kParameter_DelayType])),
                                 CENTER_PANEL_MENU_BAR_HEIGHT);
    addAndMakeVisible(*mFxPanel);
    
    mMenuBar->addFxTypeComboBoxListener(mFxPanel.get());
}

KAPCenterPanel::~KAPCenterPanel()
{
    mMenuBar->removeFxTypeComboBoxListener(mFxPanel.get());
}
