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

#include "jvm/JavaEnv.h"

#include <jni.h>
#include <stdexcept>


using namespace SpigotPlusPlus;

JavaVM* JavaEnv::JVM(nullptr);

JavaEnv::JavaEnv() : m_attached(false), m_env(nullptr){
    m_attached = getJNIEnv(JVM, &m_env);
}

JNIEnv *JavaEnv::getEnv() const {
    return m_env;
}

bool JavaEnv::isAttached() const {
    return m_attached;
}

JavaClass JavaEnv::getClass(std::string const& className) const {
    jclass clazz = m_env->FindClass(className.c_str());
    if(clazz == NULL) {
        throw std::runtime_error("Class " + className + " not found.");
    }
    return JavaClass(clazz, className);
}

bool JavaEnv::getJNIEnv(JavaVM* vm, JNIEnv** env) {
    bool did_attach_thread = false;
    *env = nullptr;
    // Check if the current thread is attached to the VM
    auto get_env_result = vm->GetEnv((void**)env, JNI_VERSION_10);
    if (get_env_result == JNI_EDETACHED) {
        if (vm->AttachCurrentThread((void**)env, NULL) == JNI_OK) {
            did_attach_thread = true;
        }
    } else if (get_env_result == JNI_OK) {
        did_attach_thread = true;
    }
    return did_attach_thread;
}
