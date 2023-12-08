all: conf.o csv.o display.o linkedlist.o csv_process_generator.c csv_file_manip.h
	gcc $^ -o main -lm
csv.o: csv_file_manip.c csv_file_manip.h ../process_def.h ../process_config/global_config.h 
	gcc -c $< -o $@
conf.o: ../process_config/global_config.c ../process_config/global_config.h ../process_def.h ../dataStruct/linkedlist.h ../display_manger/display_conf.h
	gcc -c $< -o $@ 
#queue.o: ../dataStruct/queue.c ../dataStruct/queue.h ../process_def.h ../dataStruct/node.h
#	gcc -c $< -o $@

linkedlist.o: ../dataStruct/linkedlist.c ../dataStruct/linkedlist.h ../process_def.h ../dataStruct/node.h
	gcc -c $< -o $@

display.o: ../display_manger/display_conf.c ../display_manger/display_conf.h ../process_config/global_config.h ../process_def.h ../dataStruct/queue.h 
	gcc -c $< -o $@



clean: 
	rm *.o 
	rm main 
	rm *.csv