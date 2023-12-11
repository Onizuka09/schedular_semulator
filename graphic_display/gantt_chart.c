#include "gantt_chart.h"
#define MAX_PROCESSES 20
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
}
static void close_window(GtkWidget *widget, gpointer user_data)
{
    GtkWidget *window = GTK_WIDGET(user_data);
    gtk_widget_destroy(window);
    gtk_main_quit();
    return ;
}
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
    queue *q1 = (queue *)user_data;
    node *tmp;
    tmp = q1->head;
    RGB rgb;
    char st[20];
    int i = 0;
    while (tmp!=NULL  )
    {
        colors col = tmp->proc.color;
        getRGB(col, &rgb);
        cairo_set_source_rgb(cr, rgb.red / 255.0, rgb.green / 255.0, rgb.blue / 255.0); 
        cairo_rectangle(cr, tmp->proc.ta * 30, 50, tmp->proc.te * 30, 50);              
        cairo_fill(cr);
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_move_to(cr, (tmp->proc.ta * 30) + 5, 70);
        cairo_show_text(cr, tmp->proc.name);
        cairo_set_source_rgb(cr, 0, 0, 0);
        cairo_move_to(cr, tmp->proc.ta * 30, 100);
        sprintf(st, "%d", tmp->proc.ta);
        cairo_show_text(cr, st);
        if (tmp->next ==NULL)
        {
            cairo_set_source_rgb(cr, 1, 1, 1);
            cairo_move_to(cr, (tmp->proc.ta + tmp->proc.te) * 30, 100);
            sprintf(st, "%d", tmp->proc.ta + tmp->proc.te);
            cairo_show_text(cr, st);
        }
        tmp = tmp->next;
    }
    return FALSE; 
}
 void create_widget(queue *q1,char* title)
{
    GtkWidget *drawing_area=NULL; 
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), title);
    drawing_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, 1400, 200);
    g_signal_connect(drawing_area, "draw", G_CALLBACK(on_draw_event), q1);
    GtkWidget *button = gtk_button_new_with_label("Close");
    g_signal_connect(button, "clicked", G_CALLBACK(close_window), window);
    GtkWidget *label = gtk_label_new(title);
    PangoFontDescription *font_desc = pango_font_description_new();
    pango_font_description_set_size(font_desc, 12 * PANGO_SCALE);
    gtk_widget_override_font(label, font_desc);
    GtkWidget *vbox = gtk_vbox_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), drawing_area, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_show_all(window);
    gtk_main();
    return ;
}
void init_gtk()
{
    gtk_init(NULL, NULL);
}
