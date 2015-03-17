/**********************************************************\
Original Author: Richard Bateman (taxilian)

Created:    Mar 11, 2015
License:    Dual license model; choose one of two:
            New BSD License
            http://www.opensource.org/licenses/bsd-license.php
            - or -
            GNU Lesser General Public License, version 2.1
            http://www.gnu.org/licenses/lgpl-2.1.html

Copyright 2015 Richard Bateman, Firebreath development team
\**********************************************************/

#include "WyrmVariantUtil.h"

using namespace FB::FireWyrm;
template<class T>
ValueBuilderMap::value_type makeBuilderEntry()
{
    return ValueBuilderMap::value_type(&typeid(T), select_jsonvalue_builder::select<T>());
}

ValueBuilderMap makeJsonValueBuilderMap()
{
    ValueBuilderMap tdm;
    tdm.insert(makeBuilderEntry<bool>());
    tdm.insert(makeBuilderEntry<char>());
    tdm.insert(makeBuilderEntry<unsigned char>());
    tdm.insert(makeBuilderEntry<short>());
    tdm.insert(makeBuilderEntry<unsigned short>());
    tdm.insert(makeBuilderEntry<int>());
    tdm.insert(makeBuilderEntry<unsigned int>());
    tdm.insert(makeBuilderEntry<long>());
    tdm.insert(makeBuilderEntry<unsigned long>());

#ifndef BOOST_NO_LONG_LONG
    tdm.insert(makeBuilderEntry<long long>());
    tdm.insert(makeBuilderEntry<unsigned long long>());
#endif

    tdm.insert(makeBuilderEntry<float>());
    tdm.insert(makeBuilderEntry<double>());

    tdm.insert(makeBuilderEntry<std::string>());
    tdm.insert(makeBuilderEntry<std::wstring>());

    tdm.insert(makeBuilderEntry<FB::FBNull>());
    tdm.insert(makeBuilderEntry<FB::FBVoid>());
    //tdm.insert(makeBuilderEntry<FB::FBDateString>());
    tdm.insert(makeBuilderEntry<FB::VariantList>());
    tdm.insert(makeBuilderEntry<FB::VariantMap>());
    tdm.insert(makeBuilderEntry<FB::JSAPIPtr>());
    tdm.insert(makeBuilderEntry<FB::JSAPIWeakPtr>());
    tdm.insert(makeBuilderEntry<FB::JSObjectPtr>());
    tdm.insert(makeBuilderEntry<const std::exception>());

    return tdm;
}

const ValueBuilderMap& FB::FireWyrm::getJsonValueBuilderMap()
{
    static const ValueBuilderMap tdm = makeJsonValueBuilderMap();
    return tdm;
}