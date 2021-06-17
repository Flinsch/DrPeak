/*
  ==============================================================================

    VolumeStats.h
    Created: 16 Jun 2021 2:47:35pm
    Author:  sflei_01

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class VolumeStats
{

public:
    VolumeStats();
    ~VolumeStats();

public:
    float peak;

public:
    void reset();
    void prepare_for_incoming_data(size_t sample_count);
    void register_new_sample(float sample);

public:
    bool operator == (const VolumeStats& rhs) const;
    bool operator != (const VolumeStats& rhs) const { return !(*this == rhs); }

};
