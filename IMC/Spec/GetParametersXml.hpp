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

#ifndef IMC_GETPARAMETERSXML_HPP_INCLUDED_
#define IMC_GETPARAMETERSXML_HPP_INCLUDED_

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
  //! Get Parameters XML.
  class GetParametersXml: public Message
  {
  public:

    static uint16_t
    getIdStatic(void)
    {
      return 894;
    }

    static GetParametersXml*
    cast(Message* msg__)
    {
      return (GetParametersXml*)msg__;
    }

    GetParametersXml(void)
    {
      m_header.mgid = GetParametersXml::getIdStatic();
      clear();
    }

    GetParametersXml*
    clone(void) const
    {
      return new GetParametersXml(*this);
    }

    void
    clear(void)
    {
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      (void)bfr__;
      (void)size__;
      return 0;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      (void)bfr__;
      (void)size__;
      return 0;
    }

    uint16_t
    getId(void) const
    {
      return GetParametersXml::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "GetParametersXml";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 0;
    }
  };
}

#endif
