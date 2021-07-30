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
#include "CPPPlugin.h"

namespace SpigotPlusPlus {
    enum class LogLevel {
        SEVERE = 6,
        WARNING = 5,
        INFO = 4,
        CONFIG = 3,
        FINE = 2,
        FINER = 1,
        FINEST = 0
    };

    class Logger {
    public:
        void log( LogLevel level, std::string const& message);
        void logSevere( std::string const& message);
        void logWarning( std::string const& message);
        void logInfo( std::string const& message);
        void logConfig( std::string const& message);
        void logFine( std::string const& message);
        void logFiner( std::string const& message);
        void logFinest( std::string const& message);
        Logger(CPPPlugin* plugin);

    private:
        CPPPlugin* m_plugin;
    };
}
