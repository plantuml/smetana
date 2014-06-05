#line 1 "graphviz-2.38.0\\lib\\gvc\\gvbuffstderr.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvbuffstderr.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvbuffstderr.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvbuffstderr.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvbuffstderr.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvbuffstderr.c" 1

struct buff_s {
    int fd;
    fpos_t pos;
    char *template;
};

/* switch stderr output to temporary file buffering
 */ 
void *buffstderr(void)
{
    char *p;
    struct buff_s *b;

    assert ((b = malloc(sizeof(struct buff_s))));
    assert ((b->template = strdup("/tmp/stderr_buffer_XXXXXX")));
    assert ((p = mktemp(b->template)));
    fflush(stderr);
    fgetpos(stderr, &(b->pos));
    b->fd = dup(fileno(stderr));
    freopen(b->template, "w+", stderr);
    return (void *)b;
}

/* switch stderr output back to normal,
 *    and return any buffered output in a malloc'ed buffer
 */
char *unbuffstderr(struct buff_s *b)
{
    long sz;
    char *t = NULL;
    FILE *f;

    fflush(stderr);
    sz = ftell(stderr);
    dup2(b->fd, fileno(stderr));
    close(b->fd);
    clearerr(stderr);
    fsetpos(stderr, &(b->pos));

    if (sz) {
        /* stderr has been restored; these asserts use normal stderr output */
        assert((t = malloc(sz+1)));
        assert((f = fopen(b->template, "r")));
        assert( fread(t, 1, sz, f) == sz);
        fclose(f);
        t[sz]='\0';
    }

    unlink(b->template);
    free(b->template);
    free(b);

    return t;
}




        
        

        

        
        

        
        
        
        

        
            
            
        

        


