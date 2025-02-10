# comment
# (note: the <tab> in the command line is necessary for make to work) 
# target:  dependency1 dependency2 ...
#       <tab> command
#
# Reference from: http://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html

TARGET = hellomake.bin


all:
	make clean
	make compile
	make run
	

compile: hellomake.c hellofunc.c
	gcc -o $(TARGET) hellomake.c hellofunc.c
	
run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)

