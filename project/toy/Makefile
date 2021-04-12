# makfile configuration

COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: toy.elf

#additional rules for files
toy.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o switches.o toyMain.o buzzer.o statemachine.o led.o wdInterruptHandler.o ../lib/libTimer.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.elf


led.o: led.h
wdInterruptHandler.o: statemachine.h buzzer.h led.h switches.h
statemachine.o: led.h buzzer.h statemachine.h
buzzer.o: buzzer.h
switches.o:  switches.h led.h statemachine.h buzzer.h
p1_interrupt_handler.o: switches.h
