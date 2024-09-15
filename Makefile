PKG_CONFIG?=pkg-config

PKGS="wlroots-0.19" wayland-server
CFLAGS_PKG_CONFIG!=$(PKG_CONFIG) --cflags $(PKGS)
CFLAGS+=$(CFLAGS_PKG_CONFIG)
LIBS!=$(PKG_CONFIG) --libs $(PKGS)

all: nervwm

nervwm.o: src/nervwm.c
	$(CC) -c $< -g -Werror $(CFLAGS) -I. -DWLR_USE_UNSTABLE -o $@
nervwm: nervwm.o
	$(CC) $^ $> -g -Werror $(CFLAGS) $(LDFLAGS) $(LIBS) -o $@

clean:
	rm -f nervwm nervwm.o

.PHONY: all clean

