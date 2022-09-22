objects = process_generator
all: $(objects)

$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean: $(objects)
	rm $(objects)
