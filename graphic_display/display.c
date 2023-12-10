#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK Widget Example");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 300, 200);

    // Create a label widget
    GtkWidget *label = gtk_label_new("Hello, GTK!");

    // Add the label to the main window
    gtk_container_add(GTK_CONTAINER(window), label);

    // Connect the "destroy" signal to quit the application
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Show all widgets
    gtk_widget_show_all(window);

    // Run the GTK main loop
    gtk_main();
    printf("hello world");
    return 0;
}
