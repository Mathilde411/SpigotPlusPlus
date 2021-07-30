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

#include "jvm/JavaStaticField.h"

#include "jvm/JavaEnv.h"

using namespace SpigotPlusPlus;

JavaStaticField::JavaStaticField(jclass const& clazz, std::string  const& className, jfieldID const& field, JavaType const& type, std::string const& name) : m_class(clazz), m_className(className), m_field(field), m_type(type), m_name(name){}

jvalue JavaStaticField::value() const {
    JavaEnv env;
    jvalue v;
    switch(m_type.getMarker()) {
        case JValueMarker::STRING:
        case JValueMarker::VOID:
        case JValueMarker::ARRAY:
        case JValueMarker::NONE:
            v.l = env.getEnv() -> GetStaticObjectField(m_class, m_field);
            break;
        case JValueMarker::FLOAT:
            v.f = env.getEnv() -> GetStaticFloatField(m_class, m_field);
            break;
        case JValueMarker::INTEGER:
            v.i = env.getEnv() -> GetStaticIntField(m_class, m_field);
            break;
        case JValueMarker::LONG:
            v.j = env.getEnv() -> GetStaticLongField(m_class, m_field);
            break;
        case JValueMarker::SHORT:
            v.s = env.getEnv() -> GetStaticShortField(m_class, m_field);
            break;
        case JValueMarker::CHAR:
            v.c = env.getEnv() -> GetStaticCharField(m_class, m_field);
            break;
        case JValueMarker::BYTE:
            v.b = env.getEnv() -> GetStaticByteField(m_class, m_field);
            break;
        case JValueMarker::BOOLEAN:
            v.z = env.getEnv() -> GetStaticBooleanField(m_class, m_field);
            break;
        case JValueMarker::DOUBLE:
            v.d = env.getEnv() -> GetStaticDoubleField(m_class, m_field);
            break;
    }
    return v;
}

std::string JavaStaticField::getName() const {
    return m_name;
}

JavaType JavaStaticField::getType() const {
    return m_type;
}

jclass JavaStaticField::getClass() const {
    return m_class;
}

std::string JavaStaticField::getClassName() const {
    return m_className;
}
