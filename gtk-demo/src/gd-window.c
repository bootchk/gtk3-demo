#include <gtk/gtk.h>

#include "gd-window.h"

struct _GdWindow
{
    /* <private> */
    GtkApplicationWindow parent_instance;
};

G_DEFINE_TYPE (GdWindow, gd_window, GTK_TYPE_APPLICATION_WINDOW)

static void
gd_window_init (GdWindow *window)
{
    gtk_widget_init_template (GTK_WIDGET (window));
}

static void
gd_window_class_init (GdWindowClass *klass)
{
    GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

    gtk_widget_class_set_template_from_resource (widget_class,
                                                 "/org/gtk/demo/gd-window.ui");
}

GtkWidget *
gd_window_new (GtkApplication *application)
{
    return g_object_new (GD_TYPE_WINDOW,
                         "application", application,
                         NULL);
}
