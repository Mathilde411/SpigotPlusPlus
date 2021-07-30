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

#include <vector>
#include <string>
#include <jni.h>

#include "jvm/JavaType.h"
#include "jvm/JavaStaticField.h"
#include "jvm/JavaStaticMethod.h"
#include "jvm/JavaConstructor.h"

namespace SpigotPlusPlus {
    class JavaClass {
    public:
        JavaStaticField getStaticField(std::string const& name, JavaType const& type) const;
        JavaStaticMethod getStaticMethod(std::string const& name, JavaType const& returnType, std::vector<JavaType> const& argumentTypes) const;
        JavaConstructor getConstructor(std::vector<JavaType> const& argumentTypes) const;
        jclass getClass() const;
        std::string getClassName() const;
        JavaClass(jclass const& clazz, std::string const& name);

    private:
        jclass m_class;
        std::string m_name;
    };
}




