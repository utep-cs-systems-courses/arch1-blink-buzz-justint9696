COMMON_OBJECTS 	= 
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

CC 		= msp430-elf-gcc
AS		= msp430-elf-as

all: main.elf

main.elf: ${COMMON_OBJECTS} uimain.o led.o button.o wdInterruptHandler.o p1_interrupt_handler.o timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ 

clean:
	rm -rf *.o *.h~ *.o~ *~ *.elf

load: main.elf
	msp430loader.sh main.elf


