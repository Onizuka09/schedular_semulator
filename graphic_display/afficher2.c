#include "afficher2.h"
// #include "../../../../usr/include/pango-1.0/pango/pango-font.h"
#define MAX_PROCESSES 20

// GtkWidget *drawing_area = NULL;
int process_count = 0;
G_LOCK_DEFINE_STATIC(myLock);
void getRGB(colors col, RGB *rgb)
{

    switch (col)
    {
    case E_RESET_C:
        rgb->red = 255;
        rgb->green = 255;
        rgb->blue = 255;
        break;
    case E_BLACK_C:
        rgb->red = 80;
        rgb->green = 80;
        rgb->blue = 80;
        break;
    case E_GREY_C:
        rgb->red = 128;
        rgb->green = 128;
        rgb->blue = 128;
        break;
    case E_RED_C:
        rgb->red = 255;
        rgb->green = 0;
        rgb->blue = 0;
        break;
    case E_GREEN_C:
        rgb->red = 0;
        rgb->green = 255;
        rgb->blue = 0;
        break;
    case E_YELLOW_C:
        rgb->red = 255;
        rgb->green = 255;
        rgb->blue = 0;
        break;
    case E_BLUE_C:
        rgb->red = 0;
        rgb->green = 0;
        rgb->blue = 255;
        break;
    case E_PURPLE_C:
        rgb->red = 128;
        rgb->green = 0;
        rgb->blue = 128;
        break;
    case E_CYAN_C:
        rgb->red = 0;
        rgb->green = 255;
        rgb->blue = 255;
        break;
    case E_BRIGHT_GREY_C:
        rgb->red = 192;
        rgb->green = 192;
        rgb->blue = 192;
        break;
    case E_BRIGHT_RED_C:
        rgb->red = 255;
        rgb->green = 128;
        rgb->blue = 128;
        break;
    case E_BRIGHT_GREEN_C:
        rgb->red = 128;
        rgb->green = 255;
        rgb->blue = 128;
        break;
    case E_BRIGHT_YELLOW_C:
        rgb->red = 255;
        rgb->green = 255;
        rgb->blue = 128;
        break;
    case E_BRIGHT_BLUE_C:
        rgb->red = 128;
        rgb->green = 128;
        rgb->blue = 255;
        break;
    case E_BRIGHT_PURPLE_C:
        rgb->red = 255;
        rgb->green = 128;
        rgb->blue = 255;
        break;
    case E_BRIGHT_CYAN_C:
        rgb->red = 128;
        rgb->green = 255;
        rgb->blue = 255;
        break;

    }

    // return rgb;
}
static void close_window(GtkWidget *widget, gpointer user_data)
{
    // ThreadArgs *threadArgs = (ThreadArgs *)arg;
    GtkWidget *window = GTK_WIDGET(user_data);
    gtk_widget_destroy(window);
    gtk_main_quit();
    return ;
}


static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
    queue *q1 = (queue *)user_data;
    node *tmp;
    // = (node *)malloc(sizeof(node));
    tmp = q1->head; 
    RGB rgb;
    char st[20];
    int i = 0;
    // Dequeue processes and store in array
    while (tmp!=NULL && i<MAX_num_proc )
    {
        Process *tproc =&( tmp->proc);
        colors col = tproc->color;
        getRGB(col, &rgb);
        printf("%d %d %d\n",rgb.red,rgb.green,rgb.blue );
        // getRGB(col, &cl);
        // Draw a rectangle for each task
        cairo_set_source_rgb(cr, rgb.red / 255.0, rgb.green / 255.0, rgb.blue / 255.0); // Grey color
        cairo_rectangle(cr, tproc->ta*30, 50, tproc->te*30, 50); // x, y, width, height
        cairo_fill(cr);

        // Draw the name of the task next to the rectangle
        cairo_set_source_rgb(cr, 0, 0, 0); // Black color
        cairo_move_to(cr, (tproc->ta*30) + 5, 70);
        cairo_show_text(cr, tproc->name);
        cairo_set_source_rgb(cr, 0, 0, 0);
        cairo_move_to(cr, tproc->ta*30, 100);
        sprintf(st, "%d", tproc->ta);
        cairo_show_text(cr, st);
        if (i == process_count-1)
        {
            cairo_set_source_rgb(cr, 1, 1, 1);
            cairo_move_to(cr, (tproc->ta + tproc->te)*30, 100);
            sprintf(st, "%d", tproc->ta + tproc->te);
            cairo_show_text(cr, st);
        }
        i ++ ; 
    }
        // free(tmp); 
        return FALSE; // Indicates that drawing is complete
}
 void* create_widget(void* arg)
{
    gdk_threads_init();
    ThreadArgs *threadArgs = (ThreadArgs *)arg;
    GtkWidget *drawing_area=NULL; 
        // Initialize queue
    queue *q1 = threadArgs->q;

    
    // Create GTK window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "threadArgs message");
    // g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    threadArgs->window = window;
    // Create drawing area
    drawing_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, 1400, 200);

    // Connect drawing event
    g_signal_connect(drawing_area, "draw", G_CALLBACK(on_draw_event), &q1);

    // Add drawing area to the window
    GtkWidget *button = gtk_button_new_with_label("Close");
    g_signal_connect(button, "clicked", G_CALLBACK(close_window), window);

    // adding a label
    GtkWidget *label = gtk_label_new("threadArgs message");
    PangoFontDescription *font_desc = pango_font_description_new();

    pango_font_description_set_size(font_desc, 12 * PANGO_SCALE);

    // Set the new font description for the label
    gtk_widget_override_font(label, font_desc);

    // GtkWidget *vbox = gtk_vbox_new(FALSE, 5);
    GtkWidget *vbox = gtk_vbox_new(GTK_ORIENTATION_VERTICAL, 5);
    // GtkWidget *vbox2 = gtk_vbox_new(GTK_ORIENTATION_VERTICAL, 5);

    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
    
    gtk_box_pack_start(GTK_BOX(vbox), drawing_area, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);

    // gtk_container_add(GTK_CONTAINER(window), vbox2);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Show all widgets
    gtk_widget_show_all(window);

    // Enqueue processes
   

    // Start the GTK main loop
    gtk_main();
    // Clean up the font description when you're done
    // pango_font_description_free(font_desc);
    // Clean up allocated memory
    
    return NULL;
    // free(threadArgs);
    // printf("done !!");
}
void init_gtk()
{
    gtk_init(NULL, NULL);
}
void setup_display_GUI(queue *q1)
{
    pthread_t myThread;
    ThreadArgs *threadArgs = malloc(sizeof(ThreadArgs));
    threadArgs->q = q1;
    threadArgs->message = "FiFo execution"; 
    // Create the thread
    int threadCreationResult = pthread_create(&myThread, NULL, create_widget, (void *)threadArgs);

    // Check if the thread creation was successful
    if (threadCreationResult != 0)
    {
        fprintf(stderr, "Error creating thread: %d\n", threadCreationResult);
        return 1;
    }

    // Main thread continues its execution
    //printf("Main thread is running\n");
    pthread_join(myThread, NULL);
}
/*
int main(int argc, char *argv[])
{
    queue q1;
    init_queue(&q1);
    Process *p = malloc(sizeof(Process));
    strcpy(p->name, "p1");
    p->ta = 0;
    p->te = 50;
    p->color = E_GREEN_C;

    Process *p2 = malloc(sizeof(Process));
    strcpy(p2->name, "p2");
    p2->ta = 50;
    p2->te = 100;
    p2->color = E_RED_C;

    Process *p3 = malloc(sizeof(Process));
    strcpy(p3->name, "p3");
    p3->ta = 150;
    p3->te = 50;
    p3->color = E_BLUE_C;

    enqueue(&q1, p);
    enqueue(&q1, p2);
    enqueue(&q1, p3);

    setup_thread(&q1);
    return EXIT_SUCCESS;
}
*/