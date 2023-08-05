CC := g++

SRC_DIR := ../src
BUILD_DIR := build
STD := c++11
OUTPUT := output 
INCLUDE_DIR := ../include

build_dir:
	mkdir -p ${BUILD_DIR}

compile: build_dir \
		${BUILD_DIR}/glad.o \
		${BUILD_DIR}/App.o \
		${BUILD_DIR}/ShowImage.o \
		${BUILD_DIR}/Shader.o \
		${BUILD_DIR}/main.o 

${BUILD_DIR}/App.o:${SRC_DIR}/App.cpp
	${CC} -std=${STD} -c ${SRC_DIR}/App.cpp -o ${BUILD_DIR}/App.o -I ${INCLUDE_DIR}/

${BUILD_DIR}/Shader.o:${SRC_DIR}/Shader.cpp
	${CC} -std=${STD} -c ${SRC_DIR}/Shader.cpp -o ${BUILD_DIR}/Shader.o -I ${INCLUDE_DIR}/

${BUILD_DIR}/ShowImage.o:${SRC_DIR}/ShowImage.cpp
	${CC} -std=${STD} -c ${SRC_DIR}/ShowImage.cpp -o ${BUILD_DIR}/ShowImage.o -I ${INCLUDE_DIR}/

${BUILD_DIR}/glad.o:${SRC_DIR}/glad.cpp
	${CC} -std=${STD} -c ${SRC_DIR}/glad.cpp -o ${BUILD_DIR}/glad.o -I ${INCLUDE_DIR}/

${BUILD_DIR}/main.o:${SRC_DIR}/main.cpp
	${CC} -std=${STD} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o -I ${INCLUDE_DIR}/

link:compile
	${CC} ${BUILD_DIR}/*.o -o ${BUILD_DIR}/showimage.exe -Llib -lglfw3dll
	
run:link
	${BUILD_DIR}/showimage ../gakki.jpg

# test_compile:
# 	${CC} ${SRC_DIR}/test.cpp -o ${BUILD_DIR}/test -I include/
	
# test:test_compile
# 	${BUILD_DIR}/test

# assemble:link
# 	mkdir -p ${BUILD_DIR}/${OUTPUT}
# 	cp -r assets ${BUILD_DIR}/${OUTPUT}
# 	cp -r shader ${BUILD_DIR}/${OUTPUT}
# 	cp -r ${BUILD_DIR}/main.exe ${BUILD_DIR}/${OUTPUT}
# 	cp -r *.dll ${BUILD_DIR}/${OUTPUT}

clean:
	rm -f ${BUILD_DIR}/*.o 
	rm -f ${BUILD_DIR}/showimage.exe
	rm -rf ${BUILD_DIR}/${OUTPUT}