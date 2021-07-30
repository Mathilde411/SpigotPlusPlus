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
#include <vector>

#include "jvm/JavaField.h"
#include "jvm/JavaMethod.h"
#include "jvm/JavaType.h"

namespace SpigotPlusPlus {
    class JavaObject {
    public:
        JavaField getField(std::string const& name, JavaType const& type) const;
        JavaMethod getMethod(std::string const& name, JavaType const& returnType, std::vector<JavaType> const& argumentTypes) const;
        jclass getClass() const;
        std::string getClassName() const;
        JavaObject(jclass const& clazz, std::string const& name, jobject const& object);

    private:
        jclass m_class;
        std::string m_name;
        jobject m_object;
    };
}


