package h;
import core.*;
import core.annotation.*;

// ap7c4ii9ux7nlggs68fm76fy6

public class reg_errcode_t {
}

// typedef enum
//     {
//         REG_NOERROR = 0,        /* Success.  */
//         REG_NOMATCH,            /* Didn't find a match (for regexec).  */
// 
//         /* POSIX regcomp return error codes.  (In the order listed in the
//            standard.)  */
//         REG_BADPAT,             /* Invalid pattern.  */
//         REG_ECOLLATE,           /* Not implemented.  */
//         REG_ECTYPE,             /* Invalid character class name.  */
//         REG_EESCAPE,            /* Trailing backslash.  */
//         REG_ESUBREG,            /* Invalid back reference.  */
//         REG_EBRACK,             /* Unmatched left bracket.  */
//         REG_EPAREN,             /* Parenthesis imbalance.  */
//         REG_EBRACE,             /* Unmatched \{.  */
//         REG_BADBR,              /* Invalid contents of \{\}.  */
//         REG_ERANGE,             /* Invalid range end.  */
//         REG_ESPACE,             /* Ran out of memory.  */
//         REG_BADRPT,             /* No preceding re for repetition op.  */
// 
//         /* Error codes we've added.  */
//         REG_EEND,               /* Premature end.  */
//         REG_ESIZE,              /* Compiled pattern bigger than 2^16 bytes.  */
//         REG_ERPAREN             /* Unmatched ) or \); not returned from regcomp.  */
//     } reg_errcode_t;