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

#include "jvm/JavaConstructor.h"

#include "jvm/JavaEnv.h"

using namespace SpigotPlusPlus;

JavaConstructor::JavaConstructor(jclass const& clazz, std::string const& className, jmethodID const& method,
                                 std::vector<JavaType> const& argumentTypes) :
                                 m_class(clazz), m_className(className), m_method(method), m_argumentTypes(argumentTypes){}

JavaObject JavaConstructor::call(jvalue *args) const {
    JavaEnv env;
    jobject obj = env.getEnv()->NewObjectA(m_class, m_method, args);
    return JavaObject(m_class, m_className, obj);
}

std::vector<JavaType> JavaConstructor::getArgumentTypes() const {
    return m_argumentTypes;
}

jclass JavaConstructor::getClass() const {
    return m_class;
}

std::string JavaConstructor::getClassName() const {
    return m_className;
}
