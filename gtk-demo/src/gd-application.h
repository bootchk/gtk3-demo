#ifndef GD_APPLICATION_H_
#define GD_APPLICATION_H_

#include <gtk/gtk.h>

#define GD_TYPE_APPLICATION (gd_application_get_type ())
G_DECLARE_FINAL_TYPE (GdApplication, gd_application, GD, APPLICATION, GtkApplication)

GtkApplication *gd_application_new (void);

#endif /* GD_APPLICATION_H_ */
