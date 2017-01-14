GCC = g++
CFLAGS = -Wall -std=c++11
LDFLAGS = -Wl,--no-as-needed
INFILE = -lsfml-system -lsfml-graphics -lsfml-window -pthread -lX11
EXEC = appExe.exe

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC) : $(OBJ)
	@$(GCC) -o $@ $^ $(INFILE) $(LDFLAGS)

%.o : %.cpp
	@$(GCC) -o $@ -c $< $(CFLAGS) $(INFILE)

.PHONY: clean mrproper

clean :
	@rm -rf *.o

mrproper : clean
	@rm -rf $(EXEC)

test :
	./$(EXEC)
