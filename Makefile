build_dir = build
source_dir = src
flags = -c -o

main: main.o memory.o value.o chunk.o vm.o debug.o
	@cc -o $(build_dir)/main  \
		$(build_dir)/memory.o \
		$(build_dir)/value.o  \
		$(build_dir)/chunk.o  \
		$(build_dir)/vm.o     \
		$(build_dir)/debug.o  \
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

clean:
	@rm $(build_dir)/*.o
	@rm $(build_dir)/main
