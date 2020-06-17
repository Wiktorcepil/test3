CC = g++

#INSTRUKCJE
all:
	$(CC) -c "main.cpp" -o main.o
	$(CC) -c "Character_class.cpp" -o Character_class.o
	$(CC) -c "Controller.cpp" -o Controller.o
	$(CC) -c "Create_Character.cpp" -o Create_Character.o
	$(CC) -o WH2GEN Character_class.o Controller.o Create_Character.o main.o $(LIBS)
	
.PHONY: run
run: WH2GEN
  ./WH2GEN
