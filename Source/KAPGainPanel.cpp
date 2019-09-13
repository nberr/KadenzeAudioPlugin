/*
  ==============================================================================

    KAPGainPanel.cpp
    Created: 19 Aug 2019 8:11:23pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "KAPGainPanel.h"

#include "KAPParameters.h"
#include "KAPHelperFunctions.h"

KAPGainPanel::KAPGainPanel(KadenzeAudioPluginAudioProcessor *inProcessor)
:   KAPPanelBase(inProcessor)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
    
    const int meter_w = 64;
    
    mVuMeter = std::make_unique<KAPVuMeter>(mProcessor);
    mVuMeter->setBounds((getWidth() * 0.5) - (meter_w * 0.5),
                        (getHeight() * 0.55) - (meter_w * 0.5),
                        meter_w,
                        getHeight() * 0.45);
    addAndMakeVisible(*mVuMeter);
}

KAPGainPanel::~KAPGainPanel()
{
    
}

void KAPGainPanel::paint(Graphics& g)
{
    KAPPanelBase::paint(g);
    
    if (mSlider != nullptr)
    {
        paintComponentLabel(g, mSlider.get());
    }
    
}

void KAPGainPanel::setParameterID(int inParameterID)
{
    mSlider = std::make_unique<KAPParameterSlider>(mProcessor->parameters,
                                                   KAPParameterID[inParameterID],
                                                   KAPParameterLabel[inParameterID]);
    
    const int slider_size = 54;
    
    mSlider->setBounds((getWidth() * 0.5) - (slider_size * 0.5),
                       (getHeight() * 0.25) - (slider_size * 0.5) - 10,
                       slider_size,
                       slider_size);
    
    addAndMakeVisible(*mSlider);
    
    mVuMeter->setParameterID(inParameterID);
}

