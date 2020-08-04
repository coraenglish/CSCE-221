all: test

test: Collection_test.o Stress_ball.o Stress_ball_test.o Jeans.o Jeans_test.o 
	c++ -std=c++11 Collection_test.o Stress_ball.o Stress_ball_test.o Jeans.o Jeans_test.o -o test

Collection_test.o: Collection_test.cpp
	c++ -std=c++11 -c Collection_test.cpp

Stress_ball.o: Stress_ball.cpp Stress_ball.h
	c++ -std=c++11 -c Stress_ball.cpp
	
Stress_ball_test.o: Stress_ball_test.cpp
	c++ -std=c++11 -c Stress_ball_test.cpp
	
Jeans.o: Jeans.cpp Jeans.h
	c++ -std=c++11 -c Jeans.cpp

Jeans_test.o: Jeans_test.cpp
	c++ -std=c++11 -c Jeans_test.cpp

clean:
	rm -f *.o test
