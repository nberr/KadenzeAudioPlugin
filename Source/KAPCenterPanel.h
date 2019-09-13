/*
  ==============================================================================

    KAPCenterPanel.h
    Created: 19 Aug 2019 8:10:48pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"

#include "KAPCenterPanelMenuBar.h"
#include "KAPFxPanel.h"

class KAPCenterPanel
:   public KAPPanelBase
{
public:
    KAPCenterPanel(KadenzeAudioPluginAudioProcessor *inProcessor);
    ~KAPCenterPanel();
    
private:
    std::unique_ptr<KAPCenterPanelMenuBar> mMenuBar;
    std::unique_ptr<KAPFxPanel> mFxPanel;
    
};
