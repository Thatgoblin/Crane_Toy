CraneProject.exe: Driver.o Crane.o Stage.o Sprite.o Floor.o glm.o
	g++ -o CraneProject.exe Driver.o Crane.o Stage.o Sprite.o Floor.o  glm.o -lglut -lGL -lGLU -lGLEW

Driver.o: Driver.cpp
	g++ -c Driver.cpp

Crane.o: Crane.cpp
	g++ -c Crane.cpp -w

Stage.o: Stage.cpp
	g++ -c Stage.cpp

Sprite.o: Sprite.cpp
	g++ -c Sprite.cpp

Floor.o: Floor.cpp
	g++ -c Floor.cpp -w

glm.o: glm.c
	g++ -c glm.c -w
