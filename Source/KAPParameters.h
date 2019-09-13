/*
  ==============================================================================

    KAPParameters.h
    Created: 20 Aug 2019 9:31:27am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

enum KAPParameter
{
    kParameter_InputGain = 0,
    kParameter_ModulationRate,
    kParameter_ModulationDepth,
    kParameter_DelayTime,
    kParameter_DelayFeedback,
    kParameter_DelayWetDry,
    kParameter_DelayType,
    kParameter_OutputGain,
    kParameter_TotalNumParameters
};

static const String KAPParameterID[kParameter_TotalNumParameters] =
{
    "InputGain",
    "ModulationRate",
    "ModulationDepth",
    "DelayTime",
    "DelayFeedback",
    "DelayWetDry",
    "DelayType",
    "OutputGain",
};

static const String KAPParameterLabel[kParameter_TotalNumParameters] =
{
    "Input Gain",
    "Modulation Rate",
    "Modulation Depth",
    "Delay Time",
    "Delay Feedback",
    "Delay WetDry",
    "Delay Type",
    "Output Gain",
};

static const float KAPParameterDefaultValue[kParameter_TotalNumParameters] =
{
    0.5f,
    0.5f,
    0.5f,
    0.5f,
    0.5f,
    0.5f,
    0.5f,
    0.5f,
};
