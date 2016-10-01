CXX = g++
CXXFLAGS = -g
EXEC = flood
OBJECTS = cell.o controller.o game.o graphicdisplay.o main.o view.o window.o textdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
