TARGET = libcnary.a
OBJECTS = node.o node_list.o
CFLAGS=-I./include -I/opt/local/include -mmacosx-version-min=10.5 -arch i386 -isysroot /Developer/SDKs/MacOSX10.5.sdk
LDFLAGS=-L/opt/local/lib -framework CoreFoundation -mmacosx-version-min=10.5 -arch i386 -isysroot /Developer/SDKs/MacOSX10.5.sdk -Wl,-no_compact_linkedit


%.o: %.c
	$(CC) -o $(@) -c $(^) $(CFLAGS)

$(TARGET): $(OBJECTS)
	$(AR) rs $(TARGET) $(OBJECTS)

all: $(TARGET)

clean:
	rm -rf $(TARGET) $(OBJECTS)