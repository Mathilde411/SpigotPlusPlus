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

#include "jvm/JavaClass.h"

#include <stdexcept>

#include "jvm/JavaUtil.h"
#include "jvm/JavaEnv.h"
#include "jvm/JavaStaticField.h"

using namespace SpigotPlusPlus;

JavaStaticField JavaClass::getStaticField(std::string const& name, JavaType const& type) const {
    JavaEnv env;
    jfieldID field = env.getEnv()->GetStaticFieldID(m_class, name.c_str(), type.getSignature().c_str());
    if(field == NULL) {
        throw std::runtime_error("Static field " + name + " not found in class " + m_name + ".");
    }
    return JavaStaticField(m_class, m_name, field, type, name);
}

JavaStaticMethod JavaClass::getStaticMethod(std::string const& name, JavaType const& returnType,
                                            std::vector<JavaType> const& argumentTypes) const {
    JavaEnv env;
    std::string sig = JavaUtil::getMethodSignature(returnType, argumentTypes);
    jmethodID method = env.getEnv()->GetStaticMethodID(m_class, name.c_str(), sig.c_str());
    if(method == NULL) {
        throw std::runtime_error("Static method " + name + " with signature " + sig + " not found in class " + m_name + ".");
    }
    return JavaStaticMethod(m_class, m_name, method, returnType, argumentTypes, name);
}

JavaConstructor JavaClass::getConstructor(std::vector<JavaType> const& argumentTypes) const {
    JavaEnv env;
    std::string sig = JavaUtil::getMethodSignature(JavaType::VOID, argumentTypes);
    jmethodID constructor = env.getEnv()->GetMethodID(m_class, "<init>", sig.c_str());
    if(constructor == NULL) {
        throw std::runtime_error("Constructor with signature " + sig + " not found in class " + m_name + ".");
    }
    return JavaConstructor(m_class, m_name, constructor, argumentTypes);
}

jclass JavaClass::getClass() const {
    return m_class;
}

std::string JavaClass::getClassName() const {
    return m_name;
}

JavaClass::JavaClass(jclass const& clazz, std::string const& name) : m_class(clazz), m_name(name) {}
