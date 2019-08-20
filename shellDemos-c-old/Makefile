EFILES= argDemo envDemo exec forkPipeDemo rwDemo saferFork sigIgn sigPrint
all: $(EFILES)

argDemo: argDemo.o
envDemo: envDemo.o
exec: exec.o
forkPipeDemo: forkPipeDemo.o
rwDemo: rwDemo.o
saferFork: saferFork.o
sigIgn: sigIgn.o
sigPrint: sigPrint.o

clean:
	rm -f *.o $(EFILES)
