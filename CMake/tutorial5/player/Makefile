EXEC = main
CXX = g++
CFLAGS = -Wall -I../test01 -I../test02

$(EXEC): main.o
		$(CXX) -o main main.o ../test01/test01.a ../test02/test02.a

%.o: %.cpp
		$(CXX) -c $(CFLAGS) $< -o $@

clean:
		rm main.o main
