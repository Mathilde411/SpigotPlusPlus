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

#include "jvm/JavaObject.h"

#include <stdexcept>

#include "jvm/JavaUtil.h"
#include "jvm/JavaEnv.h"

using namespace SpigotPlusPlus;

JavaField JavaObject::getField(std::string const& name, JavaType const& type) const {
    JavaEnv env;
    jfieldID field = env.getEnv()->GetFieldID(m_class, name.c_str(), type.getSignature().c_str());
    if(field == NULL) {
        throw std::runtime_error("Field " + name + " not found in class " + m_name + ".");
    }
    return JavaField(m_class, m_name, m_object, field, type, name);
}

JavaMethod JavaObject::getMethod(std::string const& name, SpigotPlusPlus::JavaType const& returnType, std::vector<JavaType> const& argumentTypes) const {
    JavaEnv env;
    std::string sig = JavaUtil::getMethodSignature(returnType, argumentTypes);
    jmethodID method = env.getEnv()->GetMethodID(m_class, name.c_str(), sig.c_str());
    if(method == NULL) {
        throw std::runtime_error("Method " + name + " with signature " + sig + " not found in class " + m_name + ".");
    }
    return JavaMethod(m_class, m_name, m_object, method, returnType, argumentTypes, name);
}

jclass SpigotPlusPlus::JavaObject::getClass() const {
    return m_class;
}

std::string SpigotPlusPlus::JavaObject::getClassName() const {
    return m_name;
}

SpigotPlusPlus::JavaObject::JavaObject(jclass const& clazz, std::string const& name, jobject const& object) :
m_object(object), m_name(name), m_class(clazz) {}
