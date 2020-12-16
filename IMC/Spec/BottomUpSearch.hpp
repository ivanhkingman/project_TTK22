//***************************************************************************
// Copyright 2017 OceanScan - Marine Systems & Technology, Lda.             *
//***************************************************************************
// Licensed under the Apache License, Version 2.0 (the "License");          *
// you may not use this file except in compliance with the License.         *
// You may obtain a copy of the License at                                  *
//                                                                          *
// http://www.apache.org/licenses/LICENSE-2.0                               *
//                                                                          *
// Unless required by applicable law or agreed to in writing, software      *
// distributed under the License is distributed on an "AS IS" BASIS,        *
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
// See the License for the specific language governing permissions and      *
// limitations under the License.                                           *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************
// Automatically generated.                                                 *
//***************************************************************************
// IMC XML MD5: 06d0bcdb61bc5c098b62564e5a98a2a0                            *
//***************************************************************************

#ifndef IMC_BOTTOMUPSEARCH_HPP_INCLUDED_
#define IMC_BOTTOMUPSEARCH_HPP_INCLUDED_

// ISO C++ 98 headers.
#include <ostream>
#include <string>
#include <vector>

// IMC headers.
#include <IMC/Base/Config.hpp>
#include <IMC/Base/Message.hpp>
#include <IMC/Base/InlineMessage.hpp>
#include <IMC/Base/MessageList.hpp>
#include <IMC/Base/JSON.hpp>
#include <IMC/Base/Serialization.hpp>
#include <IMC/Spec/Enumerations.hpp>
#include <IMC/Spec/Bitfields.hpp>
#include <IMC/Spec/Maneuver.hpp>

namespace IMC
{
  //! Bottom Up Search Maneuver.
  class BottomUpSearch: public Maneuver
  {
  public:
    //! Timeout.
    uint16_t timeout;
    //! Latitude WGS-84.
    double lat;
    //! Longitude WGS-84.
    double lon;
    //! Z Reference.
    float z;
    //! Z Units.
    uint8_t z_units;
    //! Speed.
    float speed;
    //! Speed Units.
    uint8_t speed_units;
    //! Roll.
    double roll;
    //! Pitch.
    double pitch;
    //! Yaw.
    double yaw;
    //! Desired Pitch.
    double desired_pitch;
    //! Surface Threshold.
    float surface_threshold;
    //! Thrust Duration.
    uint16_t thrust_duration;
    //! Pitch Threshold.
    double pitch_threshold;
    //! Burst RPM.
    float burst_rpm;
    //! Custom settings for maneuver.
    std::string custom;

    static uint16_t
    getIdStatic(void)
    {
      return 497;
    }

    static BottomUpSearch*
    cast(Message* msg__)
    {
      return (BottomUpSearch*)msg__;
    }

    BottomUpSearch(void)
    {
      m_header.mgid = BottomUpSearch::getIdStatic();
      clear();
    }

    BottomUpSearch*
    clone(void) const
    {
      return new BottomUpSearch(*this);
    }

    void
    clear(void)
    {
      timeout = 0;
      lat = 0;
      lon = 0;
      z = 0;
      z_units = 0;
      speed = 0;
      speed_units = 0;
      roll = 0;
      pitch = 0;
      yaw = 0;
      desired_pitch = 0;
      surface_threshold = 0;
      thrust_duration = 0;
      pitch_threshold = 0;
      burst_rpm = 0;
      custom.clear();
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::BottomUpSearch& other__ = static_cast<const BottomUpSearch&>(msg__);
      if (timeout != other__.timeout) return false;
      if (lat != other__.lat) return false;
      if (lon != other__.lon) return false;
      if (z != other__.z) return false;
      if (z_units != other__.z_units) return false;
      if (speed != other__.speed) return false;
      if (speed_units != other__.speed_units) return false;
      if (roll != other__.roll) return false;
      if (pitch != other__.pitch) return false;
      if (yaw != other__.yaw) return false;
      if (desired_pitch != other__.desired_pitch) return false;
      if (surface_threshold != other__.surface_threshold) return false;
      if (thrust_duration != other__.thrust_duration) return false;
      if (pitch_threshold != other__.pitch_threshold) return false;
      if (burst_rpm != other__.burst_rpm) return false;
      if (custom != other__.custom) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(timeout, ptr__);
      ptr__ += IMC::serialize(lat, ptr__);
      ptr__ += IMC::serialize(lon, ptr__);
      ptr__ += IMC::serialize(z, ptr__);
      ptr__ += IMC::serialize(z_units, ptr__);
      ptr__ += IMC::serialize(speed, ptr__);
      ptr__ += IMC::serialize(speed_units, ptr__);
      ptr__ += IMC::serialize(roll, ptr__);
      ptr__ += IMC::serialize(pitch, ptr__);
      ptr__ += IMC::serialize(yaw, ptr__);
      ptr__ += IMC::serialize(desired_pitch, ptr__);
      ptr__ += IMC::serialize(surface_threshold, ptr__);
      ptr__ += IMC::serialize(thrust_duration, ptr__);
      ptr__ += IMC::serialize(pitch_threshold, ptr__);
      ptr__ += IMC::serialize(burst_rpm, ptr__);
      ptr__ += IMC::serialize(custom, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(timeout, bfr__, size__);
      bfr__ += IMC::deserialize(lat, bfr__, size__);
      bfr__ += IMC::deserialize(lon, bfr__, size__);
      bfr__ += IMC::deserialize(z, bfr__, size__);
      bfr__ += IMC::deserialize(z_units, bfr__, size__);
      bfr__ += IMC::deserialize(speed, bfr__, size__);
      bfr__ += IMC::deserialize(speed_units, bfr__, size__);
      bfr__ += IMC::deserialize(roll, bfr__, size__);
      bfr__ += IMC::deserialize(pitch, bfr__, size__);
      bfr__ += IMC::deserialize(yaw, bfr__, size__);
      bfr__ += IMC::deserialize(desired_pitch, bfr__, size__);
      bfr__ += IMC::deserialize(surface_threshold, bfr__, size__);
      bfr__ += IMC::deserialize(thrust_duration, bfr__, size__);
      bfr__ += IMC::deserialize(pitch_threshold, bfr__, size__);
      bfr__ += IMC::deserialize(burst_rpm, bfr__, size__);
      bfr__ += IMC::deserialize(custom, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::reverseDeserialize(timeout, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(lat, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(lon, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(z, bfr__, size__);
      bfr__ += IMC::deserialize(z_units, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(speed, bfr__, size__);
      bfr__ += IMC::deserialize(speed_units, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(roll, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(pitch, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(yaw, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(desired_pitch, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(surface_threshold, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(thrust_duration, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(pitch_threshold, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(burst_rpm, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(custom, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return BottomUpSearch::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "BottomUpSearch";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 78;
    }

    size_t
    getVariableSerializationSize(void) const
    {
      return IMC::getSerializationSize(custom);
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "timeout", timeout, nindent__);
      IMC::toJSON(os__, "lat", lat, nindent__);
      IMC::toJSON(os__, "lon", lon, nindent__);
      IMC::toJSON(os__, "z", z, nindent__);
      IMC::toJSON(os__, "z_units", z_units, nindent__);
      IMC::toJSON(os__, "speed", speed, nindent__);
      IMC::toJSON(os__, "speed_units", speed_units, nindent__);
      IMC::toJSON(os__, "roll", roll, nindent__);
      IMC::toJSON(os__, "pitch", pitch, nindent__);
      IMC::toJSON(os__, "yaw", yaw, nindent__);
      IMC::toJSON(os__, "desired_pitch", desired_pitch, nindent__);
      IMC::toJSON(os__, "surface_threshold", surface_threshold, nindent__);
      IMC::toJSON(os__, "thrust_duration", thrust_duration, nindent__);
      IMC::toJSON(os__, "pitch_threshold", pitch_threshold, nindent__);
      IMC::toJSON(os__, "burst_rpm", burst_rpm, nindent__);
      IMC::toJSON(os__, "custom", custom, nindent__);
    }
  };
}

#endif
