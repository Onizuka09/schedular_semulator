# Define variables
CC = gcc
CFLAGS = -Wall -Wextra -g 
SRCDIR = .
BUILD_DIR := build
FIFO_bin := fifo
RR_bin := round_robin 
SRT_bin := srt 
PRIORITY_bin := priority
Multi_bin := multiLevel
PP_bin := PP

BIN := schedular_semulator 
LDFLAGS := `pkg-config --cflags --libs gtk+-3.0` -lm 

all: create_BUILD_DIR $(BIN)



#----------------------------  -----
$(BIN): menu_example.c process_def.h   $(BUILD_DIR)/csv.o $(BUILD_DIR)/linkedlist.o $(BUILD_DIR)/queue.o  $(BUILD_DIR)/conf.o $(BUILD_DIR)/display.o scheduling_algorithms/fifo_algorithm.c scheduling_algorithms/Round_Robin.c scheduling_algorithms/priority_algorithm.c scheduling_algorithms/SRT_2.c scheduling_algorithms/PP.c graphic_display/gantt_chart.h graphic_display/gantt_chart.c
	@gcc $^ -o $@ $(LDFLAGS) 


# --------------------------------------------- ---------------------------------


# ---------------------  ------------------ 
$(BUILD_DIR)/round_robin.o:  scheduling_algorithms/Round_Robin.c $(SRCDIR)/process_def.h 
	$(CC) $(CFLAGS) -c $< -IdataStruct -Idisplay_manger -o $@


$(BUILD_DIR)/fifo_algorithm.o: scheduling_algorithms/fifo_algorithm.c $(SRCDIR)/process_def.h graphic_display/afficher2.h
	$(CC) $(CFLAGS) -c $< -IdataStruct -Idisplay_manger -o $@

$(BUILD_DIR)/srt.o: scheduling_algorithms/SRT_2.c $(SRCDIR)/process_def.h 
	$(CC) $(CFLAGS) -c $< -IdataStruct -Idisplay_manger -o $@

$(BUILD_DIR)/priority_algorithm.o: scheduling_algorithms/priority_algorithm.c $(SRCDIR)/process_def.h 
	$(CC) $(CFLAGS) -c $< -IdataStruct -Idisplay_manger -o $@

$(BUILD_DIR)/multi_Level.o: scheduling_algorithms/multi_Level.c $(SRCDIR)/process_def.h 
	$(CC) $(CFLAGS) -c $< -IdataStruct -Idisplay_manger -o $@

# --------------------------    ---------------------
$(BUILD_DIR)/queue.o: dataStruct/queue.c dataStruct/queue.h $(SRCDIR)/process_def.h dataStruct/node.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/linkedlist.o: dataStruct/linkedlist.c dataStruct/linkedlist.h $(SRCDIR)/process_def.h dataStruct/node.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/display.o: display_manger/display_conf.c display_manger/display_conf.h process_config/global_config.h $(SRCDIR)/process_def.h dataStruct/queue.h 
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/conf.o: process_config/global_config.c process_config/global_config.h $(SRCDIR)/process_def.h dataStruct/node.h
	$(CC) $(CFLAGS) -c $< -o $@ 
$(BUILD_DIR)/csv.o: file_manipulation/csv_file_manip.c file_manipulation/csv_file_manip.h $(SRCDIR)/process_def.h process_config/global_config.h 
	$(CC) $(CFLAGS) -c $< -o $@
# --------------------------------------------------------------------------------------------
create_BUILD_DIR: 
	mkdir -p $(PWD)/$(BUILD_DIR)

unintsall_bin: 
	bash sudo ./My_scripts/uninstall.sh

install_depenencies: 
	bash  My_scripts/install_dpendencies.sh

install_bin:
	bash sudo ./My_scripts/instal_app.sh

clean:
	@if [ -d $(BUILD_DIR) ]; then\
		rm -rf $(BUILD_DIR);\
		echo "Removed build directory.";\
	fi
	@if [ -e $(BIN) ]; then \
		rm $(BIN); \
		echo "Removed $(BIN)."; \
	fi
