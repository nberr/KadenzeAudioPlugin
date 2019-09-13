/*
  ==============================================================================

    KAPMainPanel.cpp
    Created: 19 Aug 2019 8:10:42pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "KAPMainPanel.h"

#include "KAPParameters.h"

KAPMainPanel::KAPMainPanel(KadenzeAudioPluginAudioProcessor *inProcessor)
:   KAPPanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mTopPanel = std::make_unique<KAPTopPanel>(inProcessor);
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(*mTopPanel);
    
    mInputGainPanel = std::make_unique<KAPGainPanel>(inProcessor);
    mInputGainPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    mInputGainPanel->setParameterID(kParameter_InputGain);
    addAndMakeVisible(*mInputGainPanel);
    
    
    mOutputGainPanel = std::make_unique<KAPGainPanel>(inProcessor);
    mOutputGainPanel->setTopLeftPosition(MAIN_PANEL_WIDTH - GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    mOutputGainPanel->setParameterID(kParameter_OutputGain);
    addAndMakeVisible(*mOutputGainPanel);
    
    mCenterPanel = std::make_unique<KAPCenterPanel>(inProcessor);
    mCenterPanel->setTopLeftPosition(GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(*mCenterPanel);
}

KAPMainPanel::~KAPMainPanel()
{
    
}
