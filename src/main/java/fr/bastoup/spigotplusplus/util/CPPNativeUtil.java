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

package fr.bastoup.spigotplusplus.util;


import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.NoSuchFileException;
import java.nio.file.Path;

public class CPPNativeUtil {

    private static String getLibraryPath(String library) {
        String osName = OSInfo.getOSName();
        return OSInfo.getNativeLibFolderPathForCurrentOS() + "/" + library +
                (osName.equalsIgnoreCase("windows") ? ".dll" : (osName.equalsIgnoreCase("mac") ? ".dylib" : ".so"));
    }

    private static InputStream getLibraryStream(String path) {
        return CPPNativeUtil.class.getResourceAsStream("/" + path);
    }

    public static Path extractStream(Path filePath, InputStream stream) throws IOException {

        try {
            Files.delete(filePath);
        } catch (NoSuchFileException ignored) {}

        Files.createDirectories(filePath.getParent());
        Files.copy(stream, filePath);

        return filePath;
    }

    public static Path extractLibrary(Path folder, String library) throws IOException {
        String path = getLibraryPath(library);
        InputStream stream = getLibraryStream(path);
        if(stream == null)
            throw new FileNotFoundException("There is no distribution availiable for this configuration.");

        Path filePath = folder.resolve(path);

        return extractStream(filePath, stream);
    }


}
