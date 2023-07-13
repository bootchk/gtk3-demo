#include <gtk/gtk.h>

#include "gd-application.h"
#include "gd-window.h"
#include "menu-models.h"

/* To see debug messages:
 * export G_MESSAGES_DEBUG=all
 */

/* GDApplication subclasses GtkApplication */
struct _GdApplication
{
    /* <private> */
    GtkApplication parent_instance;
};

G_DEFINE_TYPE (GdApplication, gd_application, GTK_TYPE_APPLICATION)

static void
on_activate (GdApplication *application,
             gpointer user_data)
{
    GtkWidget *window;

    g_debug ("%s", G_STRFUNC);

    // on app activated, create window
    // menubar will be in window, on some platforms
    window = gd_window_new (GTK_APPLICATION (application));
    gtk_widget_show (window);
}

static void
gd_application_init (GdApplication *application)
{
  // G_DEBUG_HERE (); is useless unless you like like to chase line numbers
  g_debug ("%s", G_STRFUNC);

    g_signal_connect (application, "activate",
                      G_CALLBACK (on_activate), NULL);

  /* register app , downcast to G_APP */
  if ( ! g_application_register (
          G_APPLICATION (application),
          NULL,  // GCancellable* cancellable,
          NULL)) // GError** error
    g_warning ("%s fail register app", G_STRFUNC);

  app_add_actions (GTK_APPLICATION (application));

  /* set app menu from model */
  /* !! Pass a GMenu but downcast to subclass GMenuModel */
  gtk_application_set_app_menu (GTK_APPLICATION (application),
                                G_MENU_MODEL (get_app_menu_model ()));

  gtk_application_set_menubar (GTK_APPLICATION (application),
                               G_MENU_MODEL (get_menubar_model ()));
}

static void
gd_application_class_init (GdApplicationClass *klass)
{
}

GtkApplication *
gd_application_new ()
{
  g_debug ("%s", G_STRFUNC);

    return g_object_new (GD_TYPE_APPLICATION,
                         // You can't set the ID until registered
                         // Property pair: (name, value)
                         // "application-id", "org.gtk.demo",
                         NULL);
}
