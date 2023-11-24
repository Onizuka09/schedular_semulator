
# Define variables
CC = gcc
CFLAGS = -Wall -Wextra -g 
SRCDIR = .
OBJDIR = obj
BIN = main
# Define targets
all: $(BIN)

$(BIN): $(OBJDIR)/queue.o $(OBJDIR)/fifo_algorithm.o $(OBJDIR)/proc.o $(OBJDIR)/display.o
	$(CC)  $^ -o $@

GANT: $(OBJDIR)/queue.o $(OBJDIR)/gantt_diag.o $(OBJDIR)/proc.o $(OBJDIR)/display.o
	$(CC)  $^ -o $@

$(OBJDIR)/gantt_diag.o:  $(SRCDIR)/gantt_diagram.c  
	$(CC) $(CFLAGS) -c $<   -IdataStruct -Idisplay_manger -o $@


$(OBJDIR)/fifo_algorithm.o:  $(SRCDIR)/fifo_algorithm.c  
	$(CC) $(CFLAGS) -c $<   -IdataStruct -Idisplay_manger -o $@

$(OBJDIR)/queue.o: dataStruct/queue.c dataStruct/queue.h process_config/global_config.h
	$(CC) $(CFLAGS) -c $<  -Iprocess_config -o $@

obj/display.o: display_manger/display_conf.c display_manger/display_conf.h
	$(CC) $(CFLAGS) -c $< -Idisplay_manger -o $@

obj/proc.o: process_config/global_config.c process_config/global_config.h  dataStruct/queue.h 
	$(CC) $(CFLAGS) -c $< -Iprocess_config  -o $@
clean:
	rm  $(OBJDIR)/*.o
	rm $(BIN)

