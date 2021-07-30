
/*
 * Copyright 2021 BastouP
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

package fr.bastoup.spigotplusplus.link;

import fr.bastoup.spigotplusplus.SpigotPlusPlus;
import fr.bastoup.spigotplusplus.util.CPPNativeUtil;

import java.io.File;
import java.io.IOException;

public class CPPLink {

    private static final String libPath;

    static {
        try {
            libPath = CPPNativeUtil.extractLibrary(SpigotPlusPlus.getPlugin(SpigotPlusPlus.class).getDataFolder().toPath(), "SpigotPlusPlus")
                    .toAbsolutePath().toString();
            System.load(libPath);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void loadPlugin(File binary) {
        //if(!binary.exists() || !binary.isFile())
        //    throw new IllegalArgumentException("The provided binary does not exist.");
        loadPlugin("Test de test");
    }

    private static native void loadPlugin(String path);

    public static native void init();
}
