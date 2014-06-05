package h;
import core.*;
import core.annotation.*;

// e3hfh80mtu75t9spasjqrsdrh

public class re_opcode_t {
}

// typedef enum
// {
//     no_op = 0,
// 
//     /* Succeed right away--no more backtracking.  */
//     succeed,
// 
//     /* Followed by one byte giving n, then by n literal bytes.  */
//     exactn,
// 
//     /* Matches any (more or less) character.  */
//     anychar,
// 
//     /* Matches any one char belonging to specified set.  First
//        following byte is number of bitmap bytes.  Then come bytes
//        for a bitmap saying which chars are in.  Bits in each byte
//        are ordered low-bit-first.  A character is in the set if its
//        bit is 1.  A character too large to have a bit in the map is
//        automatically not in the set.  */
//     charset,
// 
//     /* Same parameters as charset, but match any character that is
//        not one of those specified.  */
//     charset_not,
// 
//     /* Start remembering the text that is matched, for storing in a
//        register.  Followed by one byte with the register number, in
//        the range 0 to one less than the pattern buffer's re_nsub
//        field.  Then followed by one byte with the number of groups
//        inner to this one.  (This last has to be part of the
//        start_memory only because we need it in the on_failure_jump
//        of re_match_2.)  */
//     start_memory,
// 
//     /* Stop remembering the text that is matched and store it in a
//        memory register.  Followed by one byte with the register
//        number, in the range 0 to one less than `re_nsub' in the
//        pattern buffer, and one byte with the number of inner groups,
//        just like `start_memory'.  (We need the number of inner
//        groups here because we don't have any easy way of finding the
//        corresponding start_memory when we're at a stop_memory.)  */
//     stop_memory,
// 
//     /* Match a duplicate of something remembered. Followed by one
//        byte containing the register number.  */
//     duplicate,
// 
//     /* Fail unless at beginning of line.  */
//     begline,
// 
//     /* Fail unless at end of line.  */
//     endline,
// 
//     /* Succeeds if at beginning of buffer (if emacs) or at beginning
//        of string to be matched (if not).  */
//     begbuf,
// 
//     /* Analogously, for end of buffer/string.  */
//     endbuf,
// 
//     /* Followed by two byte relative address to which to jump.  */
//     jump,
// 
//     /* Same as jump, but marks the end of an alternative.  */
//     jump_past_alt,
// 
//     /* Followed by two-byte relative address of place to resume at
//        in case of failure.  */
//     on_failure_jump,
// 
//     /* Like on_failure_jump, but pushes a placeholder instead of the
//        current string position when executed.  */
//     on_failure_keep_string_jump,
// 
//     /* Throw away latest failure point and then jump to following
//        two-byte relative address.  */
//     pop_failure_jump,
// 
//     /* Change to pop_failure_jump if know won't have to backtrack to
//        match; otherwise change to jump.  This is used to jump
//        back to the beginning of a repeat.  If what follows this jump
//        clearly won't match what the repeat does, such that we can be
//        sure that there is no use backtracking out of repetitions
//        already matched, then we change it to a pop_failure_jump.
//        Followed by two-byte address.  */
//     maybe_pop_jump,
// 
//     /* Jump to following two-byte address, and push a dummy failure
//        point. This failure point will be thrown away if an attempt
//        is made to use it for a failure.  A `+' construct makes this
//        before the first repeat.  Also used as an intermediary kind
//        of jump when compiling an alternative.  */
//     dummy_failure_jump,
// 
//     /* Push a dummy failure point and continue.  Used at the end of
//        alternatives.  */
//     push_dummy_failure,
// 
//     /* Followed by two-byte relative address and two-byte number n.
//        After matching N times, jump to the address upon failure.  */
//     succeed_n,
// 
//     /* Followed by two-byte relative address, and two-byte number n.
//        Jump to the address N times, then fail.  */
//     jump_n,
// 
//     /* Set the following two-byte relative address to the
//        subsequent two-byte number.  The address *includes* the two
//        bytes of number.  */
//     set_number_at,
// 
//     wordchar,   /* Matches any word-constituent character.  */
//     notwordchar,        /* Matches any char that is not a word-constituent.  */
// 
//     wordbeg,    /* Succeeds if at word beginning.  */
//     wordend,    /* Succeeds if at word end.  */
// 
//     wordbound,  /* Succeeds if at a word boundary.  */
//     notwordbound        /* Succeeds if not at a word boundary.  */
// 
// 
//     
//     
//     
// 
//     
// 
//     
// 
//     
//     
// 
// } re_opcode_t;