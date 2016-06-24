///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                    
//                                                          //  IsaacFramework  //
//                                                         //////////////////////
// 
// Copyright (c) 2014 Horatiu Condrea
// 
// This software is provided 'as-is', without any express or implied warranty. 
// In no event will the authors be held liable for any damages arising from the use of this software.
// 
// Permission is granted to anyone to use this software for any purpose, including commercial applications, 
// and to alter it and redistribute it freely, subject to the following restrictions:
// 
//  1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. a
//     If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
// 
//  2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
// 
//  3. This notice may not be removed or altered from any source distribution.
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Copyright @ 2014
Author Horatiu Condrea [ horiacondrea.com ]
Revision | Who      | Date       | Comment
------------------------------------------------------------------------------------------------------------------------------------------
1.0      | hc       | June 2016| Created
*/
//                             Headers
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <ITrigger.h>

namespace isaac
{
  /*!
  This one is a numeric trigger it will check if a tracked value is equal
  greater or lesser that a given value.
  */
  template <class type>
  class EXPORT_API CNumericTrigger : public isaac::ITrigger
  {
  public:
    /*!
    Structure defining the trigger properties.
    */
    struct NumericProp
    {
      isaac::Signs mv_Signs;
      type         mv_typeValue;
    };

  private:
    mutable NumericProp mv_NumericProp;
    mutable type mv_typeTheValue;
  public:
    CNumericTrigger(std::string ac_szTriggerName)
    {
      mv_NumericProp = { isaac::Signs::en_UnknowPosition, std::numeric_limits<type>::quiet_NaN };
    }

    /*!
    Init the trigger with the given value and the real one.
    */
    void mp_InitTrigger(type& av_TheValue, const NumericProp& ac_NumericProp) const
    {
      mv_typeTheValue = av_TheValue;
      mv_NumericProp = ac_NumericProp;
    }

    const bool mf_bCheckTrigger(sf::Event) const override
    {
      switch (mv_NumericProp.mv_Signs)
      {
      case isaac::Signs::en_EqualWith:
      {
        if (mv_typeTheValue == mv_NumericProp.mv_typeValue)
          return true;
        return false;
        break;
      }
      case isaac::Signs::en_GraterThen:
      {
        if (mv_typeTheValue > mv_NumericProp.mv_typeValue)
          return true;
        return false;
        break;
      }
      case isaac::Signs::en_LessThen:
      {
        if (mv_typeTheValue < mv_NumericProp.mv_typeValue)
          return true;
        return false;
        break;
      }
      case isaac::Signs::en_UnknowPosition:
        return false;
      default:
        break;
      }
    }

    virtual ~CNumericTrigger();
  };
}
