CC = gcc
CFLAGS = -Wall -O -g 

#【1】makefile中打印变量的方法：$(warning $(TARGET) )， $(info $(TARGET_DEVICE) )， $(error "error: this will stop the compile")
ifndef TARGET
$(error TARGET undefined!!!)
else
$(warning $(TARGET) )
endif

#【2】Makefile内置的findstring 、filter方法，这个不能使用通配符
ifeq ($(findstring app_*.so,$(TARGET)),app_)
$(warning $(filter app_%.so, app_sfd.so ))
endif

#【3】makefile的与 通过两边的拼接实现
ifeq ($(findstring app_,$(TARGET))$(suffix $(TARGET)), app_.so)
endif

#【4】CURDIR是makefile的内嵌变量，显示当前路径
$(warning $(CURDIR) )

#或者用shell命令获取当前路径
PWD=$(shell pwd)



INC = ./include
BIN = ./bin
SRC = ./src

vpath %.h $(INC)
vpath %.c $(SRC)

TARGETS = myThread
OBJ = main.o thread.o userInterface.o 

all : $(TARGETS) clean
#clean 表示生成targets后运行下面的clean标号

myThread : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ -lpthread 
	mv $(TARGETS) $(BIN)

main.o : main.c thread.h userInterface.h 
	$(CC) $(CFLAGS) -c $< -I$(INC)
	
thread.o : thread.c thread.h 
	$(CC) $(CFLAGS) -c $< -I$(INC)
	
userInterface.o : userInterface.c thread.h userInterface.h 
	$(CC) $(CFLAGS) -c $< -I$(INC)
	
.PHONY : all clean install uninstall

clean :
	rm $(OBJ)
install :  
	cp $(TARGETS) /usr/bin  
uninstall :  
	rm /usr/bin/$(TARGETS)
	
