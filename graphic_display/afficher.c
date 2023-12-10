#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#include "../dataStruct/queue.h"
// #include "../process_config/global_config.h"
#include "../process_def.h"
// #include "../file_manipulation/csv_file_manip.h"

GtkWidget *drawing_area = NULL;

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    queue *q1 = (queue *)user_data;
    Process *tproc = dequeue(q1);
while (tproc != NULL)
{ 
    // printf("%s\n",tproc->name) 
    // while (tproc != NULL) {
        // Draw a rectangle for each task
        cairo_set_source_rgb(cr, 0.5, 0.5, 0.5); // Grey color
        cairo_rectangle(cr, 0, 50, 100, 50); // x, y, width, height
        cairo_fill(cr);

        // Draw the name of the task next to the rectangle
        cairo_set_source_rgb(cr, 1, 1, 1); // Black color
        cairo_move_to(cr, 50, 50);
        cairo_show_text(cr, tproc->name);

        // tproc = dequeue(q1);
    }

    return FALSE; // Indicates that drawing is complete
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    queue q1;
    init_queue(&q1);
    Process *p = malloc(sizeof(Process));
    strcpy(p->name, "p1"); 
    
    enqueue(&q1,p); 
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Gantt Chart - FIFO");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    drawing_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, 800, 100);

    g_signal_connect(drawing_area, "draw", G_CALLBACK(on_draw_event), &q1);

    gtk_container_add(GTK_CONTAINER(window), drawing_area);

    gtk_widget_show_all(window);

    gtk_main();
    free(p);
    return 0;
}
