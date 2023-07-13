#ifndef GD_WINDOW_H_
#define GD_WINDOW_H_

#include <gtk/gtk.h>

#define GD_TYPE_WINDOW (gd_window_get_type ())
G_DECLARE_FINAL_TYPE (GdWindow, gd_window, GD, WINDOW, GtkApplicationWindow)

GtkWidget *gd_window_new (GtkApplication *application);

#endif /* GD_WINDOW_H_ */
