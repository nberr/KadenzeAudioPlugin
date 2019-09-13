/*
  ==============================================================================

    KAPPanelBase.cpp
    Created: 19 Aug 2019 8:12:39pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "KAPPanelBase.h"

#include "KAPInterfaceDefines.h"

KAPPanelBase::KAPPanelBase(KadenzeAudioPluginAudioProcessor *inProcessor)
{
    mProcessor = inProcessor;
}

KAPPanelBase::~KAPPanelBase()
{
    
}

void KAPPanelBase::mouseEnter(const MouseEvent& event)
{
    repaint();
}

void KAPPanelBase::mouseExit(const MouseEvent& event)
{
    repaint();
}

void KAPPanelBase::paint(Graphics& g)
{
    if (isMouseOver())
    {
        //g.setColour(KAPColour_4);
        //g.fillAll();
    }
}
