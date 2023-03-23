CC = clang
C_OPTS = -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wunused-variable -Wnull-dereference -Werror=vla 
LAB_OPTS = -I../lib1 -L../lib1 -I../module-library/src 

clean:
	rm -rf dist
prep:
	mkdir dist
compile: main.bin 

main.bin: src/main.c
	$(CC) $(C_OPTS) $(LAB_OPTS) $< -llib -o ./dist/$@
	cp ../lib1/liblib.so ./dist
run: clean prep compile
	LD_LIBRARY_PATH=./dist ./dist/main.bin
check:
	clang-format --verbose -dry-run --Werror src/*
	-checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump
doxygen:
	doxygen
