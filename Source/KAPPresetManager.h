/*
  ==============================================================================

    KAPPresetManager.h
    Created: 6 Sep 2019 10:13:50pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#define PRESET_FILE_EXTENSION ".kpf"

class KAPPresetManager
{
public:
    KAPPresetManager(AudioProcessor* inProcssor);
    ~KAPPresetManager();
    
    void getXmlForPreset(XmlElement* inElement);
    void loadPresetForXml(XmlElement* inElement);
    
    int getNumberOfPresets();
    String getPresetName(int inPresetIndex);
    void createNewPreset();
    void savePreset();
    void saveAsPreset(String inPresetName);
    void loadPreset(int inPresetIndex);
    bool getIsCurrentPresetSaved();
    String getCurrentPresetName();
    
private:
    void storeLocalPreset();
    
    bool mCurrentPresetIsSaved;
    
    File mCurrentlyLoadedPreset;
    Array<File> mLocalPresets;
    
    String mCurrentPresetName;
    String mPresetDirectory;
    
    AudioProcessor* mProcessor;
    
    XmlElement* mCurrentPresetXml;
};
