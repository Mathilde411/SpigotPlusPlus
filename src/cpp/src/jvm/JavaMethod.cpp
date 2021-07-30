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

#include "jvm/JavaMethod.h"

#include "jvm/JavaEnv.h"

using namespace SpigotPlusPlus;

JavaMethod::JavaMethod(jclass const& clazz, std::string const& className, jobject const& object,
                       jmethodID const& method, JavaType const& returnType, std::vector<JavaType> const& argumentTypes,
                       std::string const& name) : m_class(clazz), m_className(className), m_object(object),
                       m_method(method), m_returnType(returnType), m_argumentTypes(argumentTypes), m_name(name) {}

jvalue JavaMethod::call(jvalue *args) const {
    JavaEnv env;
    jvalue v;
    switch(m_returnType.getMarker()) {
        case JValueMarker::STRING:
        case JValueMarker::ARRAY:
        case JValueMarker::NONE:
            v.l = env.getEnv() -> CallObjectMethodA(m_object, m_method, args);
            break;
        case JValueMarker::FLOAT:
            v.f = env.getEnv() -> CallFloatMethodA(m_object, m_method, args);
            break;
        case JValueMarker::INTEGER:
            v.i = env.getEnv() -> CallIntMethodA(m_object, m_method, args);
            break;
        case JValueMarker::LONG:
            v.j = env.getEnv() -> CallLongMethodA(m_object, m_method, args);
            break;
        case JValueMarker::SHORT:
            v.s = env.getEnv() -> CallShortMethodA(m_object, m_method, args);
            break;
        case JValueMarker::CHAR:
            v.c = env.getEnv() -> CallCharMethodA(m_object, m_method, args);
            break;
        case JValueMarker::BYTE:
            v.b = env.getEnv() -> CallByteMethodA(m_object, m_method, args);
            break;
        case JValueMarker::BOOLEAN:
            v.z = env.getEnv() -> CallBooleanMethodA(m_object, m_method, args);
            break;
        case JValueMarker::DOUBLE:
            v.d = env.getEnv() -> CallDoubleMethodA(m_object, m_method, args);
            break;
        case JValueMarker::VOID:
            env.getEnv() -> CallVoidMethodA(m_object, m_method, args);
            break;
    }
    return v;
}

std::string JavaMethod::getName() const {
    return m_name;
}

JavaType JavaMethod::getReturnType() const {
    return m_returnType;
}

std::vector<JavaType> JavaMethod::getArgumentTypes() const {
    return m_argumentTypes;
}

jclass JavaMethod::getClass() const {
    return m_class;
}

std::string JavaMethod::getClassName() const {
    return m_className;
}

jobject JavaMethod::getObject() const {
    return m_object;
}
