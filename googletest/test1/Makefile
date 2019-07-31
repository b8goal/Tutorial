GTEST_DIR=googletest/googletest
all:
		g++ -o main main.cc sum.cc
test:
		g++ -o sum_test sum_test.cc sum.cc -isystem ${GTEST_DIR}/include -L${GTEST_DIR}/build -pthread -lgtest
		./sum_test
