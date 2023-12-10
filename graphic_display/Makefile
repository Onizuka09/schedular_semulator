LDFLAGS := `pkg-config --cflags --libs gtk+-3.0` -pthread
disp:queue.o afficher2.c afficher2.h  ../process_def.h
	gcc -o $@ $^ $(LDFLAGS)
queue.o: ../dataStruct/queue.c ../dataStruct/queue.h ../process_def.h ../dataStruct/node.h
	gcc  -c $< -o $@