

INC_DIR := .
SRC := main.c module1.c

main.out:
	gcc $(SRC) -I $(INC_DIR) -o $@

demo.out:
	gcc demo.c -o demo.out

.PHONY: clean
clean:
	# note: there are no object .o files because the compilation
	# step is completed all in one go (no -c flag to build each object file)
	rm *.out