package h;
import core.*;
import core.annotation.*;

// 4mff7kl30vs5cmzxe47j17hex

@TranslatedBy("plantuml")
public class gvplugin_available_s extends Structure {
	public gvplugin_available_t next;     /* next plugin in linked list, or NULL */
	public StarChar typestr;		/* type string, e.g. "png" or "ps" */
	public int quality;			/* Programmer assigned quality ranking within type (+ve or -ve int).
					First implementation of type should be given "0" quality */
	public gvplugin_package_t package_;	/* details of library containing plugin */
	public gvplugin_installed_t typeptr;  /* pointer to jumptable for plugin,
					or NULL if not yet loaded */
}

// struct gvplugin_available_s {
// 	gvplugin_available_t *next;     /* next plugin in linked list, or NULL */
// 	const char *typestr;		/* type string, e.g. "png" or "ps" */
// 	int quality;			/* Programmer assigned quality ranking within type (+ve or -ve int).
// 					First implementation of type should be given "0" quality */
// 	gvplugin_package_t *package;	/* details of library containing plugin */
// 	gvplugin_installed_t *typeptr;  /* pointer to jumptable for plugin,
// 					or NULL if not yet loaded */
//     };