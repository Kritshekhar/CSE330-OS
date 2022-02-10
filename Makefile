src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lpthread

process_generator: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) process_generator