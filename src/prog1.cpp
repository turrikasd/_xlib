#include <X11/Xlib.h>
#include <assert.h>
#include <unistd.h>

#define NIL (0)

int main()
{
	Display *dpy = XOpenDisplay(NIL);
	assert(dpy);

	int blackColor = BlackPixel(dpy, DefaultScreen(dpy));
	int whiteColor = WhitePixel(dpy, DefaultScreen(dpy));
	int randomColor = 1521;

	// Create the window
	Window w = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy),
			0, 0, 600, 400, 0, blackColor, blackColor);

	// Ask for MapNotify events
	XSelectInput(dpy, w, StructureNotifyMask);

	// Map the window
	XMapWindow(dpy, w);

	// Create a graphics context
	GC gc = XCreateGC(dpy, w, 0, NIL);

	// Set Graphics Context to draw white
	XSetForeground(dpy, gc, whiteColor);

	// Wait for MapNotify event
	while (true)
	{
		XEvent e;
		XNextEvent(dpy, &e);
		if (e.type == MapNotify)
			break;
	}

	XDrawLine(dpy, w, gc, 490, 10, 10, 390);
	XDrawLine(dpy, w, gc, 10, 10, 590, 390);

	// Flush requests to server
	XFlush(dpy);

	sleep(10);

	return 0;
}
