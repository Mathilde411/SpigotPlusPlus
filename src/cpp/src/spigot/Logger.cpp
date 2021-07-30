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

#include "spigot/Logger.h"

using namespace SpigotPlusPlus;

Logger::Logger(CPPPlugin *plugin) : m_plugin(plugin) {}

void Logger::log(LogLevel level, const std::string &message) {

}

void Logger::logSevere(const std::string &message) {
    log(LogLevel::SEVERE, message);
}

void Logger::logWarning(const std::string &message) {
    log(LogLevel::WARNING, message);
}

void Logger::logInfo(const std::string &message) {
    log(LogLevel::INFO, message);
}

void Logger::logConfig(const std::string &message) {
    log(LogLevel::CONFIG, message);
}

void Logger::logFine(const std::string &message) {
    log(LogLevel::FINE, message);
}

void Logger::logFiner(const std::string &message) {
    log(LogLevel::FINER, message);
}

void Logger::logFinest(const std::string &message) {
    log(LogLevel::FINEST, message);
}

