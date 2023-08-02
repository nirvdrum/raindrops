#include <ruby.h>
#include <ruby/io.h>

#ifdef HAVE_RB_IO_DESCRIPTOR
#	define my_fileno(io) rb_io_descriptor(io)
#else /* Ruby <3.1 */
static int my_fileno(VALUE io)
{
	rb_io_t *fptr;

fprintf(stderr, "KEVIN> before my_fileno\n");
	GetOpenFile(io, fptr);
	rb_io_check_closed(fptr);
fprintf(stderr, "KEVIN> after my_fileno\n");

	return fptr->fd;
}
#endif /* Ruby <3.1 !HAVE_RB_IO_DESCRIPTOR */
