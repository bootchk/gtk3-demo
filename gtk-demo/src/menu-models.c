
#include <gtk/gtk.h>


/* Menu model and actions.
 * Lifted from the imap plugin of Gimp.
 *
 * Just two radio buttons.
 */

/* Get a builder that will return a menu model. */
GtkBuilder *
app_get_builder ()
{
  GtkBuilder *builder;

    builder = gtk_builder_new_from_string (
      "<interface>"
        "<menu id=\"menubar\">"
            "<submenu>"
              "<attribute name=\"label\">View</attribute>"
                "<section>"
                  "<submenu>"
                    "<attribute name=\"label\">Zoom To</attribute>"
                      "<section>"
                        "<item>"
                          "<attribute name=\"label\" translatable=\"yes\">1:1</attribute>"
                          "<attribute name=\"action\">app.zoom</attribute>"
                          "<attribute name=\"target\">1</attribute>"
                        "</item>"
                        "<item>"
                          "<attribute name=\"label\" translatable=\"yes\">1:2</attribute>"
                          "<attribute name=\"action\">app.zoom</attribute>"
                          "<attribute name=\"target\">2</attribute>"
                        "</item>"
                      "</section>"
                  "</submenu>"
                "</section>"
            "</submenu>"
        "</menu>"
      "</interface>",
      -1);
  return builder;
}


/* Ultimate callback when user chooses a radio button.*/
void
set_zoom(gint zoom_factor)
{
  /* Impotent, no visual effects. */
}

/* Callback from widgets implementing the radio button group. */
void
set_zoom_factor (GSimpleAction *action,
                 GVariant      *new_state,
                 gpointer       user_data)
{
  gchar *str;
  gint   factor = 1;

  str = g_strdup_printf ("%s", g_variant_get_string (new_state, NULL));
  factor = atoi (str);
  g_free (str);

  set_zoom (factor);

  g_simple_action_set_state (action, new_state);
}


static const GActionEntry ACTIONS[] =
{
  /* Radio Options */
  { "zoom", set_zoom_factor, "s", "'1'", NULL }
};


/* The app implements ActionMap interface. */
void
app_add_actions (GtkApplication *application)
{
  g_action_map_add_action_entries (G_ACTION_MAP (application),
                                   ACTIONS,
                                   1,
                                   NULL);   // user data
}


/* Return menu model.
* GMenu is a model, not a widget.
* GMenu is subclass of GMenuModel w/ more methods.
* A menu widget is-a GtkMenu.
*/

/* Get a menu model built programatically. */
static GMenu *
get_static_menu_model ()
{
  GMenu *app_menu;

  g_debug ("%s", G_STRFUNC);

  app_menu = g_menu_new ();

  /* append item. */
  g_menu_append (app_menu, "MyFoo", "win.quit");
  g_menu_append (app_menu, "MyBar", "win.quit");

  // Caller should destroy
  return app_menu;
}

/* Get a menu model built from a declarative string. */
static GMenu*
get_built_menu_model ()
{
  GMenu *model;

  g_debug ("%s", G_STRFUNC);

  model = G_MENU(
            /* Returns a GObject which you must upcast */
            gtk_builder_get_object (
              app_get_builder(),
              "menubar"));
  if (model == NULL)
    g_warning ("%s builder returned NULL object", G_STRFUNC);
  return model;
}

/* return model for the app menu, in upper left of screen. */
GMenu *
get_app_menu_model ()
{
  g_debug ("%s", G_STRFUNC);

  return get_built_menu_model ();
  // OR return get_static_menu_model ();
}

/* return model for the app menu, in upper left of screen.
 * You can use the same actions in many places.
 */
GMenu *
get_menubar_model ()
{
  /* For now, same as app menu */
  g_debug ("%s", G_STRFUNC);
  return get_app_menu_model ();
}