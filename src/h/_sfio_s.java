package h;
import core.*;
import core.annotation.*;

// 623bw40nnqm322zd5kbji5vmv

public class _sfio_s {
}

// struct _sfio_s {
// 	unsigned char *next;	/* next position to read/write from     */
// 	unsigned char *endw;	/* end of write buffer                  */
// 	unsigned char *endr;	/* end of read buffer                   */
// 	unsigned char *endb;	/* end of buffer                        */
// 	Sfio_t *push;		/* the stream that was pushed on        */
// 	unsigned short flags;	/* type of stream                       */
// 	short file;		/* file descriptor                      */
// 	unsigned char *data;	/* base of data buffer                  */
// 	ssize_t size;		/* buffer size                          */
// 	ssize_t val;		/* values or string lengths             */
// 
// 	 
// 
//     };