TARGETS += nltrace

all: $(TARGETS)

CFLAGS += -D_GNU_SOURCE -Wall -Wextra -I/usr/include/libnl3 -g -fPIC
LFLAGS += -lnl-3
LFLAGS += -lnl-route-3
LFLAGS += -lnl-genl-3
LFLAGS += -lnl-nf-3

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

NLTRACE_SRC = $(COMMON_SRC)
NLTRACE_SRC += main.o

PRELOAD_LFLAGS = $(LFLAGS)
PRELOAD_LFLAGS += -ldl -shared
PRELOAD_SRC = $(COMMON_SRC)


nltrace: $(NLTRACE_SRC)
	$(CC) $(NLTRACE_SRC) $(LFLAGS) -o $@

indent:
	indent *.c *.h

clean:
	rm -f *.[oais] *~ $(TARGETS)
