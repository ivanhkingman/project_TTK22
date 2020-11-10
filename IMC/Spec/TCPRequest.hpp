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
// IMC XML MD5: ebd615ab4b129fe913b51419fc76c3d2                            *
//***************************************************************************

#ifndef IMC_TCPREQUEST_HPP_INCLUDED_
#define IMC_TCPREQUEST_HPP_INCLUDED_

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
  //! TCP Transmission Request.
  class TCPRequest: public Message
  {
  public:
    //! Request Identifier.
    uint16_t req_id;
    //! Destination.
    std::string destination;
    //! Timeout.
    double timeout;
    //! Message Data.
    InlineMessage<Message> msg_data;

    static uint16_t
    getIdStatic(void)
    {
      return 521;
    }

    static TCPRequest*
    cast(Message* msg__)
    {
      return (TCPRequest*)msg__;
    }

    TCPRequest(void)
    {
      m_header.mgid = TCPRequest::getIdStatic();
      clear();
      msg_data.setParent(this);
    }

    TCPRequest*
    clone(void) const
    {
      return new TCPRequest(*this);
    }

    void
    clear(void)
    {
      req_id = 0;
      destination.clear();
      timeout = 0;
      msg_data.clear();
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::TCPRequest& other__ = static_cast<const TCPRequest&>(msg__);
      if (req_id != other__.req_id) return false;
      if (destination != other__.destination) return false;
      if (timeout != other__.timeout) return false;
      if (msg_data != other__.msg_data) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(req_id, ptr__);
      ptr__ += IMC::serialize(destination, ptr__);
      ptr__ += IMC::serialize(timeout, ptr__);
      ptr__ += msg_data.serialize(ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(req_id, bfr__, size__);
      bfr__ += IMC::deserialize(destination, bfr__, size__);
      bfr__ += IMC::deserialize(timeout, bfr__, size__);
      bfr__ += msg_data.deserialize(bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::reverseDeserialize(req_id, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(destination, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(timeout, bfr__, size__);
      bfr__ += msg_data.reverseDeserialize(bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return TCPRequest::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "TCPRequest";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 10;
    }

    size_t
    getVariableSerializationSize(void) const
    {
      return IMC::getSerializationSize(destination) + msg_data.getSerializationSize();
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "req_id", req_id, nindent__);
      IMC::toJSON(os__, "destination", destination, nindent__);
      IMC::toJSON(os__, "timeout", timeout, nindent__);
      msg_data.toJSON(os__, "msg_data", nindent__);
    }

  protected:
    void
    setTimeStampNested(double value__)
    {
      if (!msg_data.isNull())
      {
        msg_data.get()->setTimeStamp(value__);
      }
    }

    void
    setSourceNested(uint16_t value__)
    {
      if (!msg_data.isNull())
      {
        msg_data.get()->setSource(value__);
      }
    }

    void
    setSourceEntityNested(uint8_t value__)
    {
      if (!msg_data.isNull())
      {
        msg_data.get()->setSourceEntity(value__);
      }
    }

    void
    setDestinationNested(uint16_t value__)
    {
      if (!msg_data.isNull())
      {
        msg_data.get()->setDestination(value__);
      }
    }

    void
    setDestinationEntityNested(uint8_t value__)
    {
      if (!msg_data.isNull())
      {
        msg_data.get()->setDestinationEntity(value__);
      }
    }
  };
}

#endif
