TARGET=out
INCLUDE=-I./include -I./rtmp/include 
LIB_PATH= -L./lib -L./rtmp/src -L./rtmp/lib -L./nmOsal 
#LIB=-lpthread -ljson_linux-gcc-4.8.5_libmt
LIB=-lcjson -ltest -lpthread -limp -lalog -lsysutils -lm -lrt -lfaac -lrtmp -lssl -lcrypto -lz -lgaofeng
LIB+=-lnmosal
OBJS=$(patsubst %.cpp,%.o,$(wildcard ./*.cpp ./sock/*.cpp)) 
#OBJS+=./common/common.o
#CC=g++
CC=mips-linux-uclibc-gnu-g++
CFLAGS=-g -Wall  

all:$(TARGET) clean_obj

$(TARGET):$(OBJS)
	$(CC) -o $@ $^ $(LIB_PATH) $(LIB) 

.cpp.o:
	$(CC) -o $@ -c $< $(INCLUDE) 

.PHONY:clean
.PHONY:clean_obj
clean:
	rm -rf  $(TARGET)
clean_obj:
	rm -rf $(OBJS)
