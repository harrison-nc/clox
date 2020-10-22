build_dir = build
source_dir = src

main: main.o
	@cc -o $(build_dir)/main $(build_dir)/chunk.o $(build_dir)/memory.o $(build_dir)/main.o

main.o: $(source_dir)/main.c
	@cc $(source_dir)/main.c -c -o $(build_dir)/main.o

chunk.o: $(source_dir)/chunk.c
	@cc $(source_dir)/chunk.c -c -o $(build_dir)/chunk.o

memory.o: $(source_dir)/memory.c
	@cc $(source_dir)/memory.c -c -o $(build_dir)/memory.o

clean:
	@rm -r $(build_dir)
