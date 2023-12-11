#include <gtk/gtk.h>
int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK Widget Example");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 300, 200);
    GtkWidget *label = gtk_label_new("Hello, GTK!");
    gtk_container_add(GTK_CONTAINER(window), label);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);
    gtk_main();
    printf("hello world");
    return 0;
}
