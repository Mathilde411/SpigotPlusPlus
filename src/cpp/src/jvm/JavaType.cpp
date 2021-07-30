// Copyright 2021 BastouP
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

#include "jvm/JavaType.h"

#include <string>


using namespace SpigotPlusPlus;

std::string JavaType::getSignature() const {
    return m_signature;
}

JavaType JavaType::asArray() const {
    return JavaType("[" + m_signature, JValueMarker::ARRAY);
}

JValueMarker JavaType::getMarker() const {
    return m_marker;
}

JavaType::JavaType(std::string const& symbol) : m_signature(symbol), m_marker(JValueMarker::NONE) {}

JavaType::JavaType(std::string const&symbol, JValueMarker const& marker) : m_signature(symbol), m_marker(marker) {}

JavaType JavaType::BOOLEAN("Z", JValueMarker::BOOLEAN);
JavaType JavaType::BYTE("B", JValueMarker::BYTE);
JavaType JavaType::CHAR("C", JValueMarker::CHAR);
JavaType JavaType::SHORT("S", JValueMarker::SHORT);
JavaType JavaType::INTEGER("I", JValueMarker::INTEGER);
JavaType JavaType::LONG("J", JValueMarker::LONG);
JavaType JavaType::FLOAT("F", JValueMarker::FLOAT);
JavaType JavaType::DOUBLE("D", JValueMarker::DOUBLE);
JavaType JavaType::VOID("V", JValueMarker::VOID);
JavaType JavaType::STRING("Ljava/lang/String;", JValueMarker::STRING);



