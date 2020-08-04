all: test

test: Stress_ball.o Stress_ball_test.o
	c++ -std=c++11 Stress_ball.o Stress_ball_test.o -o test

Stress_ball.o: Stress_ball.cpp Stress_ball.h
	c++ -std=c++11 -c Stress_ball.cpp

Stress_ball_test.o: Stress_ball_test.cpp
	c++ -std=c++11 -c Stress_ball_test.cpp

clean:
	rm -f *.o test
