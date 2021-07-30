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

#include "CPPLink.h"

#include <iostream>

#include "jvm/JavaEnv.h"

using namespace SpigotPlusPlus;

void Java_fr_bastoup_spigotplusplus_link_CPPLink_loadPlugin(JNIEnv *e, jclass clazz, jstring jStr) {

}

void Java_fr_bastoup_spigotplusplus_link_CPPLink_init(JNIEnv *env, jclass clazz) {
    env->GetJavaVM(&JavaEnv::JVM);
}

