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

#include "jvm/JavaStaticMethod.h"

#include "jvm/JavaEnv.h"

using namespace SpigotPlusPlus;

JavaStaticMethod::JavaStaticMethod(jclass const& clazz, std::string const& className, jmethodID const& method,
                                   JavaType const& returnType, std::vector<JavaType> const& argumentTypes,
                                   std::string const& name) : m_class(clazz), m_className(className), m_method(method),
                                                              m_returnType(returnType), m_argumentTypes(argumentTypes),
                                                              m_name(name){}

jvalue JavaStaticMethod::call(jvalue *args) const {
    JavaEnv env;
    jvalue v;
    switch(m_returnType.getMarker()) {
        case JValueMarker::STRING:
        case JValueMarker::ARRAY:
        case JValueMarker::NONE:
            v.l = env.getEnv() -> CallStaticObjectMethodA(m_class, m_method, args);
            break;
        case JValueMarker::FLOAT:
            v.f = env.getEnv() -> CallStaticFloatMethodA(m_class, m_method, args);
            break;
        case JValueMarker::INTEGER:
            v.i = env.getEnv() -> CallStaticIntMethodA(m_class, m_method, args);
            break;
        case JValueMarker::LONG:
            v.j = env.getEnv() -> CallStaticLongMethodA(m_class, m_method, args);
            break;
        case JValueMarker::SHORT:
            v.s = env.getEnv() -> CallStaticShortMethodA(m_class, m_method, args);
            break;
        case JValueMarker::CHAR:
            v.c = env.getEnv() -> CallStaticCharMethodA(m_class, m_method, args);
            break;
        case JValueMarker::BYTE:
            v.b = env.getEnv() -> CallStaticByteMethodA(m_class, m_method, args);
            break;
        case JValueMarker::BOOLEAN:
            v.z = env.getEnv() -> CallStaticBooleanMethodA(m_class, m_method, args);
            break;
        case JValueMarker::DOUBLE:
            v.d = env.getEnv() -> CallStaticDoubleMethodA(m_class, m_method, args);
            break;
        case JValueMarker::VOID:
            env.getEnv() -> CallStaticVoidMethodA(m_class, m_method, args);
            break;
    }
    return v;
}

std::string JavaStaticMethod::getName() const {
    return m_name;
}

JavaType JavaStaticMethod::getReturnType() const {
    return m_returnType;
}

std::vector<JavaType> JavaStaticMethod::getArgumentTypes() const {
    return m_argumentTypes;
}

jclass JavaStaticMethod::getClass() const {
    return m_class;
}

std::string JavaStaticMethod::getClassName() const {
    return m_className;
}
