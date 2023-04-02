CC = clang
C_OPTS = -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wunused-variable -Wnull-dereference -Werror=vla 
LAB_OPTS = -I./src src/lib.c -I/opt/homebrew/Cellar/check/0.15.2/include -L/opt/homebrew/Cellar/check/0.15.2/lib

clean:
	rm -rf dist
prep:
	mkdir dist
compile: lib.a lib.so test.bin

test.bin: test/test.c
	$(CC) $(C_OPTS) $(LAB_OPTS) $< -o ./dist/$@ -lcheck -lm 

test: clean prep compile
	./dist/test.bin

all: clean prep compile check

check:
	clang-format --verbose -dry-run --Werror src/*
	-checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump
doxygen:
	doxygen