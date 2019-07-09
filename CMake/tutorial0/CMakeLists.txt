cmake_minimum_required(VERSION 2.8)
PROJECT(hello)

SET(SRCS
	hello.cpp
	name.cpp
)
ADD_EXECUTABLE(hello ${SRCS})
ADD_EXECUTABLE(foo foo.cpp)

FILE(WRITE "strad""first message\n")
FILE(APPEND "vision""second message\n")
FILE(APPEND "hello""third message\n")
