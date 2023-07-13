A small demo of a gtk3 app.

Used to test "App Menu" and menubar at top of screen on MacOS
versus menubar at top of window on Linux.
Chasing down a possible bug in Gtk3 re radio button menu items not appearing
on MacOS.
So what is demoed is only the topmost part of an app, with a radio button group of menu items.

I don't understand the code completely.
My comments may be wrong.
I just hacked this together from:

      https://github.com/JonathanKang/gtk-demo

      and the imap plugin of Gimp

The repo also should contain:

      a Portfile for Macports to build this on a MacOS
      a vagga.yaml script to build this in a container on Linux

Use vagga if you don't have the requirements installed on your system:
gtk3 libs, meson build system, etc.

When you build, this directory may contain two build dirs,
not tracked in git:

       .vagga containers managed by vagga
       gtk-demoBuild the build dir managed by meson