/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * (C) Copyright 2009-2017, Arnaud Roques
 *
 * Project Info:  http://plantuml.com
 * 
 * This file is part of PlantUML.
 *
 * PlantUML is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PlantUML distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 *
 * Original Author:  Arnaud Roques
 *
 *
 *
 *
 *************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************
 *
 */
package gen.lib.cgraph;
import h.*;
import smetana.core.*;
import static smetana.core.Macro.*;
import static smetana.core.JUtils.*;
import static gen.lib.cdt.dtclose__c.*;
import static gen.lib.cdt.dtdisc__c.*;
import static gen.lib.cdt.dtextract__c.*;
import static gen.lib.cdt.dtflatten__c.*;
import static gen.lib.cdt.dthash__c.*;
import static gen.lib.cdt.dtlist__c.*;
import static gen.lib.cdt.dtmethod__c.*;
import static gen.lib.cdt.dtopen__c.*;
import static gen.lib.cdt.dtrenew__c.*;
import static gen.lib.cdt.dtrestore__c.*;
import static gen.lib.cdt.dtsize__c.*;
import static gen.lib.cdt.dtstat__c.*;
import static gen.lib.cdt.dtstrhash__c.*;
import static gen.lib.cdt.dttreeset__c.*;
import static gen.lib.cdt.dttree__c.*;
import static gen.lib.cdt.dtview__c.*;
import static gen.lib.cdt.dtwalk__c.*;
import static gen.lib.cgraph.agerror__c.*;
import static gen.lib.cgraph.agxbuf__c.*;
import static gen.lib.cgraph.apply__c.*;
import static gen.lib.cgraph.attr__c.*;
import static gen.lib.cgraph.cmpnd__c.*;
import static gen.lib.cgraph.edge__c.*;
import static gen.lib.cgraph.flatten__c.*;
import static gen.lib.cgraph.grammar__c.*;
import static gen.lib.cgraph.graph__c.*;
import static gen.lib.cgraph.id__c.*;
import static gen.lib.cgraph.imap__c.*;
import static gen.lib.cgraph.io__c.*;
import static gen.lib.cgraph.main__c.*;
import static gen.lib.cgraph.mem__c.*;
import static gen.lib.cgraph.node__c.*;
import static gen.lib.cgraph.obj__c.*;
import static gen.lib.cgraph.pend__c.*;
import static gen.lib.cgraph.rec__c.*;
import static gen.lib.cgraph.refstr__c.*;
import static gen.lib.cgraph.scan__c.*;
import static gen.lib.cgraph.subg__c.*;
import static gen.lib.cgraph.tester__c.*;
import static gen.lib.cgraph.utils__c.*;
import static gen.lib.cgraph.write__c.*;
import static gen.lib.cgraph.y_tab__c.*;
import static gen.lib.circogen.blockpath__c.*;
import static gen.lib.circogen.blocktree__c.*;
import static gen.lib.circogen.block__c.*;
import static gen.lib.circogen.circpos__c.*;
import static gen.lib.circogen.circularinit__c.*;
import static gen.lib.circogen.circular__c.*;
import static gen.lib.circogen.deglist__c.*;
import static gen.lib.circogen.edgelist__c.*;
import static gen.lib.circogen.nodelist__c.*;
import static gen.lib.circogen.nodeset__c.*;
import static gen.lib.common.args__c.*;
import static gen.lib.common.arrows__c.*;
import static gen.lib.common.colxlate__c.*;
import static gen.lib.common.ellipse__c.*;
import static gen.lib.common.emit__c.*;
import static gen.lib.common.geom__c.*;
import static gen.lib.common.globals__c.*;
import static gen.lib.common.htmllex__c.*;
import static gen.lib.common.htmlparse__c.*;
import static gen.lib.common.htmltable__c.*;
import static gen.lib.common.input__c.*;
import static gen.lib.common.intset__c.*;
import static gen.lib.common.labels__c.*;
import static gen.lib.common.memory__c.*;
import static gen.lib.common.ns__c.*;
import static gen.lib.common.output__c.*;
import static gen.lib.common.pointset__c.*;
import static gen.lib.common.postproc__c.*;
import static gen.lib.common.psusershape__c.*;
import static gen.lib.common.routespl__c.*;
import static gen.lib.common.shapes__c.*;
import static gen.lib.common.splines__c.*;
import static gen.lib.common.strcasecmp__c.*;
import static gen.lib.common.strncasecmp__c.*;
import static gen.lib.common.taper__c.*;
import static gen.lib.common.textspan__c.*;
import static gen.lib.common.timing__c.*;
import static gen.lib.common.utils__c.*;
import static gen.lib.common.y_tab__c.*;
import static gen.lib.dotgen.acyclic__c.*;
import static gen.lib.dotgen.aspect__c.*;
import static gen.lib.dotgen.class1__c.*;
import static gen.lib.dotgen.class2__c.*;
import static gen.lib.dotgen.cluster__c.*;
import static gen.lib.dotgen.compound__c.*;
import static gen.lib.dotgen.conc__c.*;
import static gen.lib.dotgen.decomp__c.*;
import static gen.lib.dotgen.dotinit__c.*;
import static gen.lib.dotgen.dotsplines__c.*;
import static gen.lib.dotgen.fastgr__c.*;
import static gen.lib.dotgen.flat__c.*;
import static gen.lib.dotgen.mincross__c.*;
import static gen.lib.dotgen.position__c.*;
import static gen.lib.dotgen.rank__c.*;
import static gen.lib.dotgen.sameport__c.*;
import static gen.lib.dotgen2.decomp__c.*;
import static gen.lib.dotgen2.dotinit__c.*;
import static gen.lib.dotgen2.groups__c.*;
import static gen.lib.dotgen2.level__c.*;
import static gen.lib.dotgen2.minc2__c.*;
import static gen.lib.dotgen2.minc_utils__c.*;
import static gen.lib.dotgen2.ns__c.*;
import static gen.lib.fdpgen.clusteredges__c.*;
import static gen.lib.fdpgen.comp__c.*;
import static gen.lib.fdpgen.dbg__c.*;
import static gen.lib.fdpgen.fdpinit__c.*;
import static gen.lib.fdpgen.grid__c.*;
import static gen.lib.fdpgen.layout__c.*;
import static gen.lib.fdpgen.tlayout__c.*;
import static gen.lib.fdpgen.xlayout__c.*;
import static gen.lib.gvc.gvbuffstderr__c.*;
import static gen.lib.gvc.gvconfig__c.*;
import static gen.lib.gvc.gvcontext__c.*;
import static gen.lib.gvc.gvc__c.*;
import static gen.lib.gvc.gvdevice__c.*;
import static gen.lib.gvc.gvevent__c.*;
import static gen.lib.gvc.gvjobs__c.*;
import static gen.lib.gvc.gvlayout__c.*;
import static gen.lib.gvc.gvloadimage__c.*;
import static gen.lib.gvc.gvplugin__c.*;
import static gen.lib.gvc.gvrender__c.*;
import static gen.lib.gvc.gvtextlayout__c.*;
import static gen.lib.gvc.gvusershape__c.*;
import static gen.lib.gvc.regex_win32__c.*;
import static gen.lib.label.index__c.*;
import static gen.lib.label.node__c.*;
import static gen.lib.label.nrtmain__c.*;
import static gen.lib.label.rectangle__c.*;
import static gen.lib.label.split_q__c.*;
import static gen.lib.label.xlabels__c.*;
import static gen.lib.ortho.fPQ__c.*;
import static gen.lib.ortho.maze__c.*;
import static gen.lib.ortho.ortho__c.*;
import static gen.lib.ortho.partition__c.*;
import static gen.lib.ortho.rawgraph__c.*;
import static gen.lib.ortho.sgraph__c.*;
import static gen.lib.ortho.trapezoid__c.*;
import static gen.lib.pack.ccomps__c.*;
import static gen.lib.pack.pack__c.*;
import static gen.lib.pack.ptest__c.*;
import static gen.lib.pathplan.cvt__c.*;
import static gen.lib.pathplan.inpoly__c.*;
import static gen.lib.pathplan.route__c.*;
import static gen.lib.pathplan.shortestpth__c.*;
import static gen.lib.pathplan.shortest__c.*;
import static gen.lib.pathplan.solvers__c.*;
import static gen.lib.pathplan.triang__c.*;
import static gen.lib.pathplan.util__c.*;
import static gen.lib.pathplan.visibility__c.*;
import static gen.lib.xdot.xdot__c.*;

public class agerror__c {
//1 9k44uhd5foylaeoekf3llonjq
// extern Dtmethod_t* 	Dtset


//1 1ahfywsmzcpcig2oxm7pt9ihj
// extern Dtmethod_t* 	Dtbag


//1 anhghfj3k7dmkudy2n7rvt31v
// extern Dtmethod_t* 	Dtoset


//1 5l6oj1ux946zjwvir94ykejbc
// extern Dtmethod_t* 	Dtobag


//1 2wtf222ak6cui8cfjnw6w377z
// extern Dtmethod_t*	Dtlist


//1 d1s1s6ibtcsmst88e3057u9r7
// extern Dtmethod_t*	Dtstack


//1 axa7mflo824p6fspjn1rdk0mt
// extern Dtmethod_t*	Dtqueue


//1 ega812utobm4xx9oa9w9ayij6
// extern Dtmethod_t*	Dtdeque


//1 cyfr996ur43045jv1tjbelzmj
// extern Dtmethod_t*	Dtorder


//1 wlofoiftbjgrrabzb2brkycg
// extern Dtmethod_t*	Dttree


//1 12bds94t7voj7ulwpcvgf6agr
// extern Dtmethod_t*	Dthash


//1 9lqknzty480cy7zsubmabkk8h
// extern Dtmethod_t	_Dttree


//1 bvn6zkbcp8vjdhkccqo1xrkrb
// extern Dtmethod_t	_Dthash


//1 9lidhtd6nsmmv3e7vjv9e10gw
// extern Dtmethod_t	_Dtlist


//1 34ujfamjxo7xn89u90oh2k6f8
// extern Dtmethod_t	_Dtqueue


//1 3jy4aceckzkdv950h89p4wjc8
// extern Dtmethod_t	_Dtstack


//1 8dfqgf3u1v830qzcjqh9o8ha7
// extern Agmemdisc_t AgMemDisc


//1 18k2oh2t6llfsdc5x0wlcnby8
// extern Agiddisc_t AgIdDisc


//1 a4r7hi80gdxtsv4hdoqpyiivn
// extern Agiodisc_t AgIoDisc


//1 bnzt5syjb7mgeru19114vd6xx
// extern Agdisc_t AgDefaultDisc


//1 35y2gbegsdjilegaribes00mg
// extern Agdesc_t Agdirected, Agstrictdirected, Agundirected,     Agstrictundirected


//1 c2rygslq6bcuka3awmvy2b3ow
// typedef Agsubnode_t	Agnoderef_t


//1 xam6yv0dcsx57dtg44igpbzn
// typedef Dtlink_t	Agedgeref_t


//1 6ayavpu39aihwyojkx093pcy3
// extern Agraph_t *Ag_G_global


//1 871mxtg9l6ffpxdl9kniwusf7
// extern char *AgDataRecName


//1 c0o2kmml0tn6hftuwo0u4shwd
// extern Dtdisc_t Ag_subnode_id_disc


//1 8k15pyu256unm2kpd9zf5pf7k
// extern Dtdisc_t Ag_subnode_seq_disc


//1 e3d820y06gpeusn6atgmj8bzd
// extern Dtdisc_t Ag_mainedge_id_disc


//1 cbr0772spix9h1aw7h5v7dv9j
// extern Dtdisc_t Ag_subedge_id_disc


//1 akd0c3v0j7m2npxcb9acit1fa
// extern Dtdisc_t Ag_mainedge_seq_disc


//1 12d8la07351ww7vwfzucjst8m
// extern Dtdisc_t Ag_subedge_seq_disc


//1 29eokk7v88e62g8o6lizmo967
// extern Dtdisc_t Ag_subgraph_id_disc


//1 4xd9cbgy6hk5g6nhjcbpzkx14
// extern Agcbdisc_t AgAttrdisc


//1 461g755qnm9wvxv8jui6a24t
// static agerrlevel_t agerrno


//1 e5usqd9mv6o7qtqhzn1ooq8f7
// static agerrlevel_t agerrlevel = AGWARN


//1 65wyo1e2rqlpvn8cmykslgkdk
// static int agmaxerr


//1 cyxwkk5enwxhnbcphn28qfacp
// static long aglast


//1 5rorjmu2xqe7cz2swf6rpoim7
// static FILE *agerrout


//1 bh4ymcg6wung4rp51y2goh1d4
// static agusererrf usererrf




//3 4629q3lk91auv6a511v0x4vlz
// agusererrf agseterrf (agusererrf newf) 
public static Object agseterrf(Object... arg) {
UNSUPPORTED("8jzbxfdt0lvxx1g5lts7oux6h"); // agusererrf
UNSUPPORTED("7ncs6gpd4ul7ye0ebi5sdte6g"); // agseterrf (agusererrf newf)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("e1odaj7t2d733eovc749xtxoz"); //     agusererrf oldf = usererrf;
UNSUPPORTED("c1j7e26jj1cw14qzyy94k59pg"); //     usererrf = newf;
UNSUPPORTED("3ecn7hsti915o9tbvklji7c1a"); //     return oldf;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 e5jdgza2l5zc0kupfteq5aukb
// agerrlevel_t agseterr(agerrlevel_t lvl) 
public static Object agseterr(Object... arg) {
UNSUPPORTED("1jwdh9fku47yepwmadw9neu42"); // agerrlevel_t agseterr(agerrlevel_t lvl)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8wc85fvp4ue7rkh584kznlnga"); //     agerrlevel_t oldv = agerrlevel;
UNSUPPORTED("76wyk73unc469eyq5uv58o9r5"); //     agerrlevel = lvl;
UNSUPPORTED("bzei33ohmcbm4iyavn26ua9io"); //     return oldv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 603i8wgwc04zi1eda5oxbfu3t
// char *aglasterr() 
public static Object aglasterr(Object... arg) {
UNSUPPORTED("7sb3l26vza0sr80wy19whq07s"); // char *aglasterr()
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4kj8gevgj79zghoenj66c47jd"); //     long endpos;
UNSUPPORTED("3k6eefo2ppnicc6mmsp8y2wtd"); //     long len;
UNSUPPORTED("6ik3p99apk5rihypipg0uxu8i"); //     char *buf;
UNSUPPORTED("5hxnce09gegtlijkrkjld0w6i"); //     if (!agerrout)
UNSUPPORTED("c9ckhc8veujmwcw0ar3u3zld4"); // 	return 0;
UNSUPPORTED("6rc2guy7n7l2kfuv44bitbkr9"); //     fflush(agerrout);
UNSUPPORTED("8nylts7ocqt9195btb9qnb915"); //     endpos = ftell(agerrout);
UNSUPPORTED("5i545onvth9wso94ub314pe4o"); //     len = endpos - aglast;
UNSUPPORTED("50nts7uovqys70g293t0b5amj"); //     buf = (char*)malloc(len + 1);
UNSUPPORTED("5tkqcw5p1pfzida9gmkbjsc5g"); //     fseek(agerrout, aglast, SEEK_SET);
UNSUPPORTED("474haq9m7a4n7kqe7paej6qbi"); //     fread(buf, sizeof(char), len, agerrout);
UNSUPPORTED("3w01p3l63zt07scumxz12foyc"); //     buf[len] = '\0';
UNSUPPORTED("7ik9s8s97py1jire6mujjn05a"); //     fseek(agerrout, endpos, SEEK_SET);
UNSUPPORTED("5jfpogdyby101eyuw2dhtb5cg"); //     return buf;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8nu6iilhr8fc6ltddy6ukbeav
// static void userout (agerrlevel_t level, const char *fmt, va_list args) 
public static Object userout(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("a92ywlsdaen90yka53m479wkl"); // userout (agerrlevel_t level, const char *fmt, va_list args)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("xo6m9cruoz5kdd6mzt4sfknp"); //     static char* buf;
UNSUPPORTED("bptaq1iwtcs1mly3uja15t0j1"); //     static int bufsz = 1024;
UNSUPPORTED("d3z5r251dmhlyub2gj2x1w46q"); //     char* np;
UNSUPPORTED("5jiiwgyq1pv7khw5ygfo33wmr"); //     int n;
UNSUPPORTED("cjyiejw67ffjjsk60tgeebvif"); //     if (!buf) {
UNSUPPORTED("40oxx4fb70iotl4q5l9cft8qb"); // 	buf = (char*)malloc(bufsz);
UNSUPPORTED("1qmkdostw44gpi19vfg7p7n4j"); // 	if (!buf) {
UNSUPPORTED("91m823gnagh03x83drfk3mo8m"); // 	    fputs("userout: could not allocate memory\n", stderr );
UNSUPPORTED("6cprbghvenu9ldc0ez1ifc63q"); // 	    return;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("6t1zqtkodps5c0ip5z9m4ys5c"); //     if (level != AGPREV) {
UNSUPPORTED("986dz74hfht24rg9hgakv8o54"); // 	usererrf ((level == AGERR) ? "Error" : "Warning");
UNSUPPORTED("auhftu1jph1rzzhrtj7f3pnou"); // 	usererrf (": ");
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("5ya9apu1bgpt462vp1v11qhyg"); //     while (1) {
UNSUPPORTED("4ybihr3u2ey4klcf9a6u65435"); // 	n = vsnprintf(buf, bufsz, fmt, args);
UNSUPPORTED("qqfwwqxfm9i6sfc0lugd66nf"); // 	if ((n > -1) && (n < bufsz)) {
UNSUPPORTED("4tqvj0fhss0ek9tp1adme5vk9"); // 	    usererrf (buf);
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dnk7v6jvu1uasfcyydkzf1jz2"); // 	bufsz = ((bufsz*2)>(n+1)?(bufsz*2):(n+1));
UNSUPPORTED("bbchby3jmfv3jbe401wrjuxzt"); // 	if ((np = (char*)realloc(buf, bufsz)) == NULL) {
UNSUPPORTED("91m823gnagh03x83drfk3mo8m"); // 	    fputs("userout: could not allocate memory\n", stderr );
UNSUPPORTED("6cprbghvenu9ldc0ez1ifc63q"); // 	    return;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("46b127jugogkjrjxb2n977bmx"); //     va_end(args);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 bg9mt0ayklk7lbw3v07dtfigf
// static int agerr_va(agerrlevel_t level, const char *fmt, va_list args) 
public static Object agerr_va(Object... arg) {
UNSUPPORTED("863t2xdlf52lqifpg4efkawgu"); // static int agerr_va(agerrlevel_t level, const char *fmt, va_list args)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("eyawtts92lihkxvbr369hkd5y"); //     agerrlevel_t lvl;
UNSUPPORTED("6lzzzfyhdb5tirbg1ccf9a5m3"); //     /* Use previous error level if continuation message;
UNSUPPORTED("czykt0ac8rrwoqsh6nt389fu3"); //      * Convert AGMAX to AGERROR;
UNSUPPORTED("4f8vlc80ixgxk5xc2y425pevt"); //      * else use input level
UNSUPPORTED("795vpnc8yojryr8b46aidsu69"); //      */
UNSUPPORTED("9u6tfrdzyinkomy2qh16oj4d2"); //     lvl = (level == AGPREV ? agerrno : (level == AGMAX) ? AGERR : level);
UNSUPPORTED("ah9u8brmn3qarkrtj9yx70p41"); //     /* store this error level */
UNSUPPORTED("9e0amfta5xoupadiuupa6cuk7"); //     agerrno = lvl;
UNSUPPORTED("bwyv65veemjr0y9un4vygtwxb"); //     agmaxerr = ((agmaxerr)>(agerrno)?(agmaxerr):(agerrno));
UNSUPPORTED("8s6ysspbpufy37chp503snd3k"); //     /* We report all messages whose level is bigger than the user set agerrlevel
UNSUPPORTED("4e7jp3qf7pzapc314u0v666ze"); //      * Setting agerrlevel to AGMAX turns off immediate error reporting.
UNSUPPORTED("795vpnc8yojryr8b46aidsu69"); //      */
UNSUPPORTED("588lzo1simvq8koio5n8dzesh"); //     if (lvl >= agerrlevel) {
UNSUPPORTED("d201l1bxazbzd0nlukhvkxtcs"); // 	if (usererrf)
UNSUPPORTED("3go4zq0x8ul8ywoga0jkifagx"); // 	    userout (level, fmt, args);
UNSUPPORTED("8k75h069sv2k9b6tgz77dscwd"); // 	else {
UNSUPPORTED("19tsxpp6yrcfw8o24jbkr1vi2"); // 	    if (level != AGPREV)
UNSUPPORTED("bl903wgo0kk135i25d7zw09r6"); // 		fprintf(stderr, "%s: ", (level == AGERR) ? "Error" : "Warning");
UNSUPPORTED("6ua1mju1v7qfokep4q7orohn"); // 	    vfprintf(stderr, fmt, args);
UNSUPPORTED("8egqb590juz3lqxaevjssja42"); // 	    va_end(args);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c9ckhc8veujmwcw0ar3u3zld4"); // 	return 0;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("alerbgdhkd2yzpj6s9lljgxfs"); //     if (!agerrout) {
UNSUPPORTED("ekzfh0kvyswlemi42n42ohs2g"); // 	agerrout = tmpfile();
UNSUPPORTED("5zhg56z3tqisbs9qbue0mopri"); // 	if (!agerrout)
UNSUPPORTED("btmwubugs9vkexo4yb7a5nqel"); // 	    return 1;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("5ceb5u5voh8555yqssrjmx6gr"); //     if (level != AGPREV)
UNSUPPORTED("a0zpkl87k498gutehuvchd3nh"); // 	aglast = ftell(agerrout);
UNSUPPORTED("85nv28rgbwdyknpacqqgv44mo"); //     vfprintf(agerrout, fmt, args);
UNSUPPORTED("46b127jugogkjrjxb2n977bmx"); //     va_end(args);
UNSUPPORTED("5oxhd3fvp0gfmrmz12vndnjt"); //     return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 f1dcuhccwam2p309jxc9b2r0t
// int agerr(agerrlevel_t level, const char *fmt, ...) 
public static Object agerr(Object... arg) {
UNSUPPORTED("ducszxizpq2a6cql4p9bb47a0"); // int agerr(agerrlevel_t level, const char *fmt, ...)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("e0w8vmmpk3wfxblsmz0uoazgs"); //     va_list args;
UNSUPPORTED("4k15snpcm2gg90dw68lllbtzl"); //     va_start(args, fmt);
UNSUPPORTED("13n0ghn77wo5crn8kvxkrhzbu"); //     return agerr_va(level, fmt, args);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 7e34h9jajkjs3ho44gntjj2j7
// void agerrorf(const char *fmt, ...) 
public static Object agerrorf(Object... arg) {
UNSUPPORTED("6x8x6k3hp05ros0ch1hlv6581"); // void agerrorf(const char *fmt, ...)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("e0w8vmmpk3wfxblsmz0uoazgs"); //     va_list args;
UNSUPPORTED("4k15snpcm2gg90dw68lllbtzl"); //     va_start(args, fmt);
UNSUPPORTED("30oktqf2os0275j4d3su6q4l"); //     agerr_va(AGERR, fmt, args);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 gpzdsjhtcu403ei3vn2ux3bm
// void agwarningf(const char *fmt, ...) 
public static Object agwarningf(Object... arg) {
UNSUPPORTED("715xbkxnriyga0q1ic2xuml6n"); // void agwarningf(const char *fmt, ...)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("e0w8vmmpk3wfxblsmz0uoazgs"); //     va_list args;
UNSUPPORTED("4k15snpcm2gg90dw68lllbtzl"); //     va_start(args, fmt);
UNSUPPORTED("dc1ifhst6g6drubm0t70yjtv"); //     agerr_va(AGWARN, fmt, args);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6by0h6d4uor86q4dcd9xjw31m
// int agerrors() 
public static Object agerrors(Object... arg) {
UNSUPPORTED("92pi4jdtb8fnjjy0lzzbtg1so"); // int agerrors() { return agmaxerr; }

throw new UnsupportedOperationException();
}




//3 aj45yt9ph7b1gdx6hqrt0zr2s
// int agreseterrors()  
public static Object agreseterrors(Object... arg) {
UNSUPPORTED("dw5u39aul656iwk9wm0luqblz"); // int agreseterrors() 
UNSUPPORTED("yo7buicdiu29rv5vxhas0v3s"); // { 
UNSUPPORTED("48ud8ypoh34wmhdfdct9ihz28"); //     int rc = agmaxerr;
UNSUPPORTED("8qk2j9d2ppvfm7m5c7elh2hv1"); //     agmaxerr = 0;
UNSUPPORTED("3jqypku7gzo7r35oqqr8iwfss"); //     return rc; 
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
