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

#include "jvm/JavaField.h"

#include "jvm/JavaEnv.h"

using namespace SpigotPlusPlus;

JavaField::JavaField(jclass const& clazz, std::string const& className, jobject const& object, jfieldID const& field,
                     JavaType const& type, std::string const& name) : m_class(clazz), m_className(className), m_object(object),
                     m_field(field), m_type(type), m_name(name) {}

jvalue JavaField::value() const {
    JavaEnv env;
    jvalue v;
    switch(m_type.getMarker()) {
        case JValueMarker::STRING:
        case JValueMarker::VOID:
        case JValueMarker::ARRAY:
        case JValueMarker::NONE:
            v.l = env.getEnv() ->GetObjectField(m_object, m_field);
            break;
        case JValueMarker::FLOAT:
            v.f = env.getEnv() -> GetFloatField(m_object, m_field);
            break;
        case JValueMarker::INTEGER:
            v.i = env.getEnv() -> GetIntField(m_object, m_field);
            break;
        case JValueMarker::LONG:
            v.j = env.getEnv() -> GetLongField(m_object, m_field);
            break;
        case JValueMarker::SHORT:
            v.s = env.getEnv() -> GetShortField(m_object, m_field);
            break;
        case JValueMarker::CHAR:
            v.c = env.getEnv() -> GetCharField(m_object, m_field);
            break;
        case JValueMarker::BYTE:
            v.b = env.getEnv() -> GetByteField(m_object, m_field);
            break;
        case JValueMarker::BOOLEAN:
            v.z = env.getEnv() -> GetBooleanField(m_object, m_field);
            break;
        case JValueMarker::DOUBLE:
            v.d = env.getEnv() -> GetDoubleField(m_object, m_field);
            break;
    }
    return v;
}

std::string JavaField::getName() const {
    return m_name;
}

JavaType JavaField::getType() const {
    return m_type;
}

jclass JavaField::getClass() const {
    return m_class;
}

jobject JavaField::getObject() const {
    return m_object;
}

std::string JavaField::getClassName() const {
    return m_className;
}
