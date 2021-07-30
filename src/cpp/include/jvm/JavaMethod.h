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

#include "jvm/JavaType.h"

namespace SpigotPlusPlus {
    class JavaMethod {
    public:
        JavaMethod(jclass const& clazz, std::string const& className, jobject const& object, jmethodID const& method, JavaType const& returnType, std::vector<JavaType> const& argumentTypes, std::string const& name);

        jvalue call(jvalue args[]) const;
        std::string getName() const;
        JavaType getReturnType() const;
        std::vector<JavaType> getArgumentTypes() const;
        jclass getClass() const;
        std::string getClassName() const;
        jobject getObject() const;

    private:
        jclass m_class;
        std::string m_className;
        jobject m_object;
        jmethodID m_method;
        JavaType m_returnType;
        std::vector<JavaType> m_argumentTypes;
        std::string m_name;
    };
}


