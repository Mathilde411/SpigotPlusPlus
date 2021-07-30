MKDIR:=mkdir -p
CMAKE:=cmake
GRADLE:=./gradlew

SRC:=src
BUILD_DIR:=build
RESOURCE_DIR = ${SRC}/main/resources
JAVA_DIR = ${SRC}/main/java
INCLUDE_DIR = ${SRC}/cpp/include
NATIVE_DIR=$(RESOURCE_DIR)/native

.phony: all package native native-all

all: native-all package

javaCompile:
	${GRADLE} compileJava

jni-header: javaCompile
	cp ${BUILD_DIR}/generated/sources/headers/java/main/fr_bastoup_spigotplusplus_link_CPPLink.h $(INCLUDE_DIR)/CPPLink.h

test:
	${GRADLE} test

clean: clean-native clean-java

native-all: win32 win64 linux32 linux64 linux-arm linux-arm64

win32: jni-header
	${CMAKE} -B CMake -DBUILD_WINDOWS=True -DBUILD_x86=True -DCMAKE_SYSTEM_NAME=Windows -DCMAKE_SYSTEM_PROCESSOR=x86 -DCMAKE_C_COMPILER=/usr/bin/i686-w64-mingw32-gcc -DCMAKE_CXX_COMPILER=/usr/bin/i686-w64-mingw32-g++ -DCMAKE_RANLIB=/usr/bin/i686-w64-mingw32-ranlib .
	${CMAKE} --build CMake
	${MKDIR} ${NATIVE_DIR}/Windows/x86
	cp CMake/libSpigotPlusPlus.dll ${NATIVE_DIR}/Windows/x86/SpigotPlusPlus.dll
	rm -r CMake/

win64: jni-header
	${CMAKE} -B CMake -DBUILD_WINDOWS=True -DBUILD_x86-64=True -DCMAKE_SYSTEM_NAME=Windows -DCMAKE_SYSTEM_PROCESSOR=x86_64 -DCMAKE_C_COMPILER=/usr/bin/x86_64-w64-mingw32-gcc -DCMAKE_CXX_COMPILER=/usr/bin/x86_64-w64-mingw32-g++ -DCMAKE_RANLIB=/usr/bin/x86_64-w64-mingw32-ranlib .
	${CMAKE} --build CMake
	${MKDIR} ${NATIVE_DIR}/Windows/x86_64
	cp CMake/libSpigotPlusPlus.dll ${NATIVE_DIR}/Windows/x86_64/SpigotPlusPlus.dll
	rm -r CMake/

linux32: jni-header
	${CMAKE} -B CMake -DBUILD_UNIX=True -DBUILD_x86=True -DCMAKE_SYSTEM_NAME=Unix -DCMAKE_SYSTEM_PROCESSOR=x86 -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -DCMAKE_RANLIB=/usr/bin/ranlib .
	${CMAKE} --build CMake
	${MKDIR} ${NATIVE_DIR}/Linux/x86
	cp CMake/libSpigotPlusPlus.so ${NATIVE_DIR}/Linux/x86/SpigotPlusPlus.so
	rm -r CMake/

linux64: jni-header
	${CMAKE} -B CMake -DBUILD_UNIX=True -DBUILD_x86-64=True -DCMAKE_SYSTEM_NAME=Unix -DCMAKE_SYSTEM_PROCESSOR=x86_64 -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -DCMAKE_RANLIB=/usr/bin/ranlib .
	${CMAKE} --build CMake
	${MKDIR} ${NATIVE_DIR}/Linux/x86_64
	cp CMake/libSpigotPlusPlus.so ${NATIVE_DIR}/Linux/x86_64/SpigotPlusPlus.so
	rm -r CMake/

linux-arm: jni-header
	${CMAKE} -B CMake -DBUILD_UNIX=True -DBUILD_ARM=True -DCMAKE_SYSTEM_NAME=Unix -DCMAKE_SYSTEM_PROCESSOR=ARM -DCMAKE_C_COMPILER=/usr/bin/arm-linux-gnueabi-gcc -DCMAKE_CXX_COMPILER=/usr/bin/arm-linux-gnueabi-g++ -DCMAKE_RANLIB=/usr/bin/arm-linux-gnueabi-gcc-ranlib .
	${CMAKE} --build CMake
	${MKDIR} ${NATIVE_DIR}/Linux/arm
	cp CMake/libSpigotPlusPlus.so ${NATIVE_DIR}/Linux/arm/SpigotPlusPlus.so
	rm -r CMake/

linux-arm64: jni-header
	${CMAKE} -B CMake -DBUILD_UNIX=True -DBUILD_ARM64=True -DCMAKE_SYSTEM_NAME=Unix -DCMAKE_SYSTEM_PROCESSOR=ARM64 -DCMAKE_C_COMPILER=/usr/bin/aarch64-linux-gnu-gcc -DCMAKE_CXX_COMPILER=/usr/bin/aarch64-linux-gnu-g++ -DCMAKE_RANLIB=/usr/bin/aarch64-linux-gnu-gcc-ranlib .
	${CMAKE} --build CMake
	${MKDIR} ${NATIVE_DIR}/Linux/arm64
	cp CMake/libSpigotPlusPlus.so ${NATIVE_DIR}/Linux/arm64/SpigotPlusPlus.so
	rm -r CMake/

package:
	${GRADLE} assemble

clean-native:
	rm -f ${INCLUDE_DIR}/CPPLink.h
	rm -fr ${NATIVE_DIR}
	rm -fr CMake/

clean-java:
	${GRADLE} clean
