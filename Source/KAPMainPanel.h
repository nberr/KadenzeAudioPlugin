/*
  ==============================================================================

    KAPMainPanel.h
    Created: 19 Aug 2019 8:10:42pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"

#include "KAPTopPanel.h"
#include "KAPGainPanel.h"
#include "KAPCenterPanel.h"

class KAPMainPanel
:   public KAPPanelBase
{
public:
    KAPMainPanel(KadenzeAudioPluginAudioProcessor *inProcessor);
    ~KAPMainPanel();

    
private:
    std::unique_ptr<KAPTopPanel> mTopPanel;
    std::unique_ptr<KAPGainPanel> mInputGainPanel;
    std::unique_ptr<KAPGainPanel> mOutputGainPanel;
    std::unique_ptr<KAPCenterPanel> mCenterPanel;

};
