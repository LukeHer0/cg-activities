LIBS = -lGLU -lglut -lGL -lm
all: catavento.cpp
	g++ catavento.cpp -o main $(LIBS)
	./main