build_dir = build
source_dir = src
flags = -c -o

main: main.o memory.o scanner.o value.o object.o compiler.o chunk.o vm.o debug.o
	@cc -o $(build_dir)/main      \
		$(build_dir)/memory.o     \
		$(build_dir)/scanner.o    \
		$(build_dir)/value.o      \
		$(build_dir)/object.o     \
		$(build_dir)/compiler.o   \
		$(build_dir)/chunk.o      \
		$(build_dir)/vm.o         \
		$(build_dir)/debug.o      \
		$(build_dir)/main.o

main.o: $(source_dir)/main.c
	@cc $(flags) \
		$(build_dir)/main.o \
		$(source_dir)/main.c

chunk.o: $(source_dir)/chunk.c $(source_dir)/chunk.h
	@cc $(flags) \
		$(build_dir)/chunk.o \
		$(source_dir)/chunk.c

memory.o: $(source_dir)/memory.c $(source_dir)/memory.h
	@cc $(flags) \
		$(build_dir)/memory.o \
		$(source_dir)/memory.c

debug.o: $(source_dir)/debug.c $(source_dir)/debug.h
	@cc $(flags) \
		$(build_dir)/debug.o \
		$(source_dir)/debug.c

value.o: $(source_dir)/value.c $(source_dir)/value.h
	@cc $(flags) \
		$(build_dir)/value.o \
		$(source_dir)/value.c

vm.o: $(source_dir)/vm.c $(source_dir)/vm.h
	@cc $(flags) \
		$(build_dir)/vm.o \
		$(source_dir)/vm.c

scanner.o: $(source_dir)/scanner.c $(source_dir)/scanner.h
	@cc $(flags) \
		$(build_dir)/scanner.o \
		$(source_dir)/scanner.c

compiler.o: $(source_dir)/compiler.c $(source_dir)/compiler.h
	@cc $(flags) \
		$(build_dir)/compiler.o \
		$(source_dir)/compiler.c

object.o: $(source_dir)/object.c $(source_dir)/object.h
	@cc $(flags) \
		$(build_dir)/object.o \
		$(source_dir)/object.c

clean:
	@rm $(build_dir)/*.o
	@rm $(build_dir)/main
