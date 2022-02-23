obj-m = producer_consumer.o
all:
	#$(MAKE) -f ./process_gen/Makefile
	cd process_gen && $(MAKE)
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	#make -f ./process_gen/Makefile clean
	cd process_gen && $(MAKE) clean
