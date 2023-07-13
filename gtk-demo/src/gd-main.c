#include <gtk/gtk.h>

#include "gd-application.h"

int
main (int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gd_application_new ();
    status = g_application_run (G_APPLICATION (app), argc, argv);

    return status;
}
