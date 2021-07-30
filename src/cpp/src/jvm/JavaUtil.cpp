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

#include "jvm/JavaUtil.h"

#include "jvm/JavaEnv.h"

using namespace SpigotPlusPlus;

std::string JavaUtil::jstringToString(jstring jStr) {
    if (!jStr)
        return "";

    JavaEnv env;

    const jclass stringClass = env.getEnv()->GetObjectClass(jStr);
    const jmethodID getBytes = env.getEnv()->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
    const jbyteArray stringJbytes = (jbyteArray) env.getEnv()->CallObjectMethod(jStr, getBytes, env.getEnv()->NewStringUTF("UTF-8"));

    auto length = (size_t) env.getEnv()->GetArrayLength(stringJbytes);
    jbyte* pBytes = env.getEnv()->GetByteArrayElements(stringJbytes, nullptr);

    std::string ret = std::string((char *)pBytes, length);
    env.getEnv()->ReleaseByteArrayElements(stringJbytes, pBytes, JNI_ABORT);
    env.getEnv()->DeleteLocalRef(stringJbytes);
    env.getEnv()->DeleteLocalRef(stringClass);
    return ret;
}

std::string JavaUtil::getMethodSignature(JavaType const& returnType, std::vector<JavaType> const& argumentTypes) {
    std::string ret("(");
    for(const JavaType &argumentType : argumentTypes)
    {
        ret += argumentType.getSignature();
    }
    ret += ")" + returnType.getSignature();
    return ret;
}
