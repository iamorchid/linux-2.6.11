obj-m	:= hello.o
 
KERNELDIR := /lib/modules/$(shell uname -r)/build
PWD       := $(shell pwd)
MAKE      := make
 
all: default
 
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
 
clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions *.symvers *.order
