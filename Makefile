
# Define variables
CC = gcc
CFLAGS = -Wall -Wextra -g 
SRCDIR = .
OBJDIR = obj
FIFO_bin = fifo
RR_bin = round_robin 
# Define targets
all: $(FIFO_bin) 

$(FIFO_bin): $(OBJDIR)/queue.o $(OBJDIR)/fifo_algorithm.o $(OBJDIR)/proc.o $(OBJDIR)/display.o
	$(CC)  $^ -o $@ -lm

$(RR_bin): $(OBJDIR)/linkedlist.o  $(OBJDIR)/queue.o $(OBJDIR)/round_robin.o $(OBJDIR)/proc.o $(OBJDIR)/display.o
	$(CC)  $^ -o $@ -lm

$(OBJDIR)/round_robin.o:  $(SRCDIR)/Round_Robin.c  $(SRCDIR)/process_def.h 
	$(CC) $(CFLAGS) -c $<   -IdataStruct -Idisplay_manger -o $@


$(OBJDIR)/fifo_algorithm.o:  $(SRCDIR)/fifo_algorithm.c $(SRCDIR)/process_def.h 
	$(CC) $(CFLAGS) -c $<   -IdataStruct -Idisplay_manger -o $@

$(OBJDIR)/queue.o: dataStruct/queue.c dataStruct/queue.h  $(SRCDIR)/process_def.h dataStruct/node.h
	$(CC) $(CFLAGS) -c $<   -o $@


$(OBJDIR)/linkedlist.o: dataStruct/linkedlist.c dataStruct/linkedlist.h  $(SRCDIR)/process_def.h dataStruct/node.h
	$(CC) $(CFLAGS) -c $<   -o $@

obj/display.o: display_manger/display_conf.c display_manger/display_conf.h $(SRCDIR)/process_def.h dataStruct/queue.h 
	$(CC) $(CFLAGS) -c $<  -o $@

obj/proc.o: process_config/global_config.c process_config/global_config.h  dataStruct/queue.h $(SRCDIR)/process_def.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm  $(OBJDIR)/*.o
	rm $(BIN)

