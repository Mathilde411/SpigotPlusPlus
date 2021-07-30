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

#include <string>
#include <jni.h>
#include "jvm/JavaClass.h"


namespace SpigotPlusPlus {
    class JavaEnv {
    public:
        static JavaVM* JVM;

        JavaEnv();
        JavaEnv(JavaEnv const& env) = delete;
        JavaEnv& operator=(JavaEnv const& env) = delete;

        JNIEnv* getEnv() const;
        JavaClass getClass(std::string const& className) const;
        bool isAttached() const;

    private:
        JNIEnv* m_env;
        bool m_attached;

        static bool getJNIEnv(JavaVM* vm, JNIEnv** env);
    };
}




