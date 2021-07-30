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

#include <jni.h>
#include <string>

#include "jvm/JavaType.h"

namespace SpigotPlusPlus {
    class JavaField {
    public:
        JavaField(jclass const& clazz, std::string const& className, jobject const& object, jfieldID const& field, JavaType const& type, std::string const& name);

        jvalue value() const;
        std::string getName() const;
        JavaType getType() const;
        jclass getClass() const;
        jobject getObject() const;
        std::string getClassName() const;

    private:
        jclass m_class;
        std::string m_className;
        jobject m_object;
        jfieldID m_field;
        JavaType m_type;
        std::string m_name;
    };
}


