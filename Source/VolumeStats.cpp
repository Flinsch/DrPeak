/*
  ==============================================================================

    VolumeStats.cpp
    Created: 16 Jun 2021 2:47:35pm
    Author:  sflei_01

  ==============================================================================
*/

#include "VolumeStats.h"

VolumeStats::VolumeStats()
{
    reset();
}

VolumeStats::~VolumeStats()
{
}

void VolumeStats::reset()
{
    peak = 0.0f;
}

void VolumeStats::prepare_for_incoming_data(size_t sample_count)
{
}

void VolumeStats::register_new_sample(float sample)
{
    peak = ::fmaxf(peak, ::abs(sample));
}

bool VolumeStats::operator == (const VolumeStats& rhs) const
{
    return peak == rhs.peak;
}
