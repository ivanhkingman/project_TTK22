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
// IMC XML MD5: ea521376f44f776f843b4b5374c01b9a                            *
//***************************************************************************

#ifndef IMC_SAVEENTITYPARAMETERS_HPP_INCLUDED_
#define IMC_SAVEENTITYPARAMETERS_HPP_INCLUDED_

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

namespace IMC
{
  //! SaveEntityParameters.
  class SaveEntityParameters: public Message
  {
  public:
    //! Entity Name.
    std::string name;

    static uint16_t
    getIdStatic(void)
    {
      return 805;
    }

    static SaveEntityParameters*
    cast(Message* msg__)
    {
      return (SaveEntityParameters*)msg__;
    }

    SaveEntityParameters(void)
    {
      m_header.mgid = SaveEntityParameters::getIdStatic();
      clear();
    }

    SaveEntityParameters*
    clone(void) const
    {
      return new SaveEntityParameters(*this);
    }

    void
    clear(void)
    {
      name.clear();
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::SaveEntityParameters& other__ = static_cast<const SaveEntityParameters&>(msg__);
      if (name != other__.name) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(name, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(name, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::reverseDeserialize(name, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return SaveEntityParameters::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "SaveEntityParameters";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 0;
    }

    size_t
    getVariableSerializationSize(void) const
    {
      return IMC::getSerializationSize(name);
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "name", name, nindent__);
    }
  };
}

#endif
