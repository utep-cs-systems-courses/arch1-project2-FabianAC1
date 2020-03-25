COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

CC              = msp430-elf-gcc
AS              = msp430-elf-as



all: main.elf
main.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o led.o switches.o main.o buzzer.o stateMachine.o wdInterruptHandler.o reset.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^
load: main.elf
	msp430loader.sh main.elf
clean:
	rm -f *.o *.elf

led.c: led.h
wdInterruptHandler.o: stateMachine.h
stateMachine.o: led.h stateMachine.h
buzzer.c: buzzer.h
switches.c: switches.h
main.o: led.h buzzer.h switches.h
