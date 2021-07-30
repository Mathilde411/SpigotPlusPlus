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

#pragma once
#include <string>

namespace SpigotPlusPlus {
    enum class JValueMarker {
        NONE,
        INTEGER,
        BOOLEAN,
        BYTE,
        CHAR,
        STRING,
        SHORT,
        LONG,
        FLOAT,
        DOUBLE,
        ARRAY,
        VOID
    };

    class JavaType {
    public:
        explicit JavaType(std::string const& symbol);
        std::string getSignature() const;
        JavaType asArray() const;
        JValueMarker getMarker() const;

        static JavaType INTEGER;
        static JavaType BOOLEAN;
        static JavaType BYTE;
        static JavaType CHAR;
        static JavaType STRING;
        static JavaType SHORT;
        static JavaType LONG;
        static JavaType FLOAT;
        static JavaType DOUBLE;
        static JavaType VOID;

    private:
        JavaType(std::string const& symbol, JValueMarker const& marker);
        std::string m_signature;
        JValueMarker m_marker;
    };
}


