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

public class y_tab__c {
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


//1 l93jrnsrrc44i9w1flfji33i
// static char Key[] = 


//1 2g1ly3x17dy8fjpj9ckfeac93
// static Agraph_t *G
private static Agraph_s G;
//1 a00t38gjjcwqriw9cdxo4tdnd
// static	Agdisc_t	*Disc


//1 44jpikta5pmbq5n8xvvx5afcg
// static gstack_t *S


//1 3m6d1cijfc6a7zhs4el1r1r80
// extern YYSTYPE yylval


//1 7lxd9viqkr2d4upq5ly0ss23m
// typedef unsigned char yytype_uint8


//1 4a59l0x62df4kmcnnzny7qrta
// typedef short int yytype_int8


//1 2nrjyi2x4xpr9jjzho0bpu8cm
// typedef unsigned short int yytype_uint16


//1 2y29tbvfe4gv3ykm9x1h2cg2q
// typedef short int yytype_int16


//1 9qwi2bqmubtpuj0q2nzopdjmd
// static const yytype_uint8 yytranslate[] = 


//1 f1buad3gyd23pv7hrfly1rvb8
// static const yytype_uint8 yyr1[] = 


//1 ee0i1wzuwd9rlegz7ius77osk
// static const yytype_uint8 yyr2[] = 


//1 c5eiute6grhi1cq8ofu1271wj
// static const yytype_uint8 yydefact[] = 


//1 9qzkmyw79odphzqvkw5neqvcd
// static const yytype_int8 yydefgoto[] = 


//1 1n2t5e3kd43f0uerl7cpp9j59
// static const yytype_int8 yypact[] = 


//1 6s0w4p8r9wet5n294wymb0er3
// static const yytype_int8 yypgoto[] = 


//1 44y9if5hm7ki2by191xulfanc
// static const yytype_int8 yytable[] = 


//1 2jp585gan0jlx60oxv3y7uha8
// static const yytype_uint8 yycheck[] = 


//1 nia7d4v6w2k5odlq66eikme4
// static const yytype_uint8 yystos[] = 




//3 d4f3pmjir7ks7uczm389ee342
// static void yydestruct (yymsg, yytype, yyvaluep)     const char *yymsg
public static Object yydestruct(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("6z3valttodfef9p0v0b90b7xy"); // yydestruct (yymsg, yytype, yyvaluep)
UNSUPPORTED("cbmgfstdv3sdevyp8bmuc9pix"); //     const char *yymsg;
UNSUPPORTED("6s7nq7d7qgx01kysn7094jwfe"); //     int yytype;
UNSUPPORTED("56gviyihbbn59yr16tfma815d"); //     YYSTYPE *yyvaluep;
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2785h7uyj7xmjojjiuapbyvfg"); //   ((void) (yyvaluep));
UNSUPPORTED("6zruki2d3oxvwe5rkhm4rrec3"); //   if (!yymsg)
UNSUPPORTED("ex05njmls0f5y8vumog0i9v30"); //     yymsg = "Deleting";
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("9aisjuert8kedobv3bvynam1l"); //   switch (yytype)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("5vhsnixpf0pg2oz10ps2valyn"); //       default:
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


//1 4t3eaa1wxy67rmdq020suek5g
// int yychar


//1 65txx0ps68nds1ofl4me400po
// YYSTYPE yylval


//1 66amrdqtj9gqnibr2wzhjhyzh
// int yynerrs




//3 4v43nszrg2xsupcvdk2hw1l9s
// int yyparse ()    
public static Object yyparse(Object... arg) {
UNSUPPORTED("etrjsq5w49uo9jq5pzifohkqw"); // int
UNSUPPORTED("b6v65fna6ryyq0tpig4iyu9vg"); // yyparse ()
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("1dk3m00u84t1a2kyszepn80j6"); //     int yystate;
UNSUPPORTED("9s1gvm4tg9jub4ua9d2z36uh"); //     /* Number of tokens to shift before error messages enabled.  */
UNSUPPORTED("42c9eysu6d2pg1bypeyxm3qtj"); //     int yyerrstatus;
UNSUPPORTED("9ok1ifmve6y93u5i4275oxt1d"); //     /* The stacks and their tools:
UNSUPPORTED("4fukmr5oau0fjzcj04ar3kqkn"); //        `yyss': related to states.
UNSUPPORTED("8dhqnx1y3sapyexks84pvseir"); //        `yyvs': related to semantic values.
UNSUPPORTED("dfvqwf4g1d3d2zdxg9zrr8mjq"); //        Refer to the stacks through separate pointers, to allow yyoverflow
UNSUPPORTED("e8cfmvs5ozsrhl6v1u6mp3dw0"); //        to reallocate them elsewhere.  */
UNSUPPORTED("e0svr3ez9dsitn8x3e0ix2b6q"); //     /* The state stack.  */
UNSUPPORTED("2sqc8pekv6u4g5y7c671l43pw"); //     yytype_int16 yyssa[200];
UNSUPPORTED("f2qhrruh315q5l58ry41iaim2"); //     yytype_int16 *yyss;
UNSUPPORTED("c8itx6pxbsl031qaw5zpkmsy5"); //     yytype_int16 *yyssp;
UNSUPPORTED("3a5u4tdfyqrq2c72j4bf9ukca"); //     /* The semantic value stack.  */
UNSUPPORTED("1ng7z6w87duh2o6pk6c01x7g9"); //     YYSTYPE yyvsa[200];
UNSUPPORTED("3ude8ur34xko5iu75o2ebjtng"); //     YYSTYPE *yyvs;
UNSUPPORTED("1lyjomk5bc8y38szkrc1zv6z"); //     YYSTYPE *yyvsp;
UNSUPPORTED("9qxqwb5bwozch7m33wn87kzh9"); //     unsigned int yystacksize;
UNSUPPORTED("673206wu93ogvv72r0qab0vb7"); //   int yyn;
UNSUPPORTED("2yqvcni7p2qhfskomav9gkalo"); //   int yyresult;
UNSUPPORTED("15mkyt2y35y6b3kw61tcv89hz"); //   /* Lookahead token as an internal (translated) token number.  */
UNSUPPORTED("8f8xkti3pqf2hlqkoccpjmkfp"); //   int yytoken;
UNSUPPORTED("8e8sr2gy45snswwlopuywd4"); //   /* The variables used to return semantic value and location from the
UNSUPPORTED("d4q0w76h1grh0723v2ors4nxs"); //      action routines.  */
UNSUPPORTED("byt2amdyt07x4v308utxp7wxg"); //   YYSTYPE yyval;
UNSUPPORTED("8s5ggdw8hglgk87czklidx1pl"); //   /* The number of symbols on the RHS of the reduced rule.
UNSUPPORTED("d7da55fsvudhvjfgejvxp4301"); //      Keep to zero when no symbol should be popped.  */
UNSUPPORTED("548izgfrh6bp1djl5o8ct1dgu"); //   int yylen = 0;
UNSUPPORTED("827mn3d1rkymtmbgdamswh8cd"); //   yytoken = 0;
UNSUPPORTED("bh0phzvw63qgpbgd16c8y9pwx"); //   yyss = yyssa;
UNSUPPORTED("bv2p6df0685hzt5m8cbuo173n"); //   yyvs = yyvsa;
UNSUPPORTED("ed2zq9u3o6ujzfwp9w2m9vr1s"); //   yystacksize = 200;
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("da1w9jcv3yts73g3wnb545sy9"); //   yystate = 0;
UNSUPPORTED("c70k37zof8xfzzd0dkp9evil8"); //   yyerrstatus = 0;
UNSUPPORTED("6bq75neqmnb7w2ltzm59t0db"); //   yynerrs = 0;
UNSUPPORTED("5xul3512dbcz7ghodgtlsriid"); //   yychar = (-2); /* Cause a token to be read.  */
UNSUPPORTED("f0kbtpk40bbe7m53uwx0eezp4"); //   /* Initialize stack pointers.
UNSUPPORTED("d8dtor5u60ag1mqqgil372nvk"); //      Waste one element of value and location stack
UNSUPPORTED("7ev6rqep9cwoby6w6f1tx2osc"); //      so that they stay on the same level as the state stack.
UNSUPPORTED("yd2jbvtitsi6j7lrxgzvchcv"); //      The wasted elements are never initialized.  */
UNSUPPORTED("9snje1pqr60ts9nh3hlkoybon"); //   yyssp = yyss;
UNSUPPORTED("6yijppbac4k1kbgx8vhht99fc"); //   yyvsp = yyvs;
UNSUPPORTED("bbhte1t33cpgfhqlwi01134bj"); //   goto yysetstate;
UNSUPPORTED("4flvn46w2728mhozqf9kuosm2"); // /*------------------------------------------------------------.
UNSUPPORTED("b2z6zko7vznmus9njmk7hc5wq"); // | yynewstate -- Push a new state, which is found in yystate.  |
UNSUPPORTED("a6znfp1d4ixngc79hwpyrw4wp"); // `------------------------------------------------------------*/
UNSUPPORTED("9mj285eb90wl3pdaog8uvexts"); //  yynewstate:
UNSUPPORTED("ej0agaz4g5pjpstralb0dkmdd"); //   /* In all cases, when you get here, the value and location stacks
UNSUPPORTED("7wmq2lqpn4jmj4m6nxe2ndmc5"); //      have just been pushed.  So pushing a state here evens the stacks.  */
UNSUPPORTED("2wy3sro4u4uf9kb8vl7d7xwlj"); //   yyssp++;
UNSUPPORTED("afv9alv5cytatzfp7ve1iimwh"); //  yysetstate:
UNSUPPORTED("944cbn8sbyvyrtpfe3hx2j2uh"); //   *yyssp = yystate;
UNSUPPORTED("bi6mggybevzfmmidanfaspr11"); //   if (yyss + yystacksize - 1 <= yyssp)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("548pbbpfwcnj355codzyz202a"); //       /* Get the current used size of the three stacks, in elements.  */
UNSUPPORTED("ec8ld8t5quqy3vtn60ki30o6z"); //       unsigned int yysize = yyssp - yyss + 1;
UNSUPPORTED("74tyblyhdau9tp40uzltqv3x7"); //       /* Extend the stack our own way.  */
UNSUPPORTED("b5eatrtbq7sduonqte8f21so4"); //       if (10000 <= yystacksize)
UNSUPPORTED("eon6lih6282gufu0qvrgl5g2j"); // 	goto yyexhaustedlab;
UNSUPPORTED("1ulf4xdxoqrvyivaown8lyg3a"); //       yystacksize *= 2;
UNSUPPORTED("5cyf16zzve41ehkzbbvk41ock"); //       if (10000 < yystacksize)
UNSUPPORTED("8wopg9oj560fnhrwhbn2j3hfi"); // 	yystacksize = 10000;
UNSUPPORTED("cdsm9962a8k19vkufzg36hzc8"); //       {
UNSUPPORTED("bdtlcizwtve6v93tfpmbq06cu"); // 	yytype_int16 *yyss1 = yyss;
UNSUPPORTED("6kjwclkp9xma7gvqfp0g5v0o1"); // 	union yyalloc *yyptr =
UNSUPPORTED("3qskr4yclsahj4ier4leil4dm"); // 	  (union yyalloc *) malloc (((yystacksize) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) + (sizeof (union yyalloc) - 1)));
UNSUPPORTED("34qleckicraurrnbukjcrgonl"); // 	if (! yyptr)
UNSUPPORTED("8rt03qxk4s7zcewhu9gjlvwfn"); // 	  goto yyexhaustedlab;
UNSUPPORTED("5lfskp4hg9damhy7dk6v1ypr8"); // 	do { unsigned int yynewbytes; do { unsigned int yyi; for (yyi = 0; yyi < (yysize); yyi++) (&yyptr->yyss_alloc)[yyi] = (yyss)[yyi]; } while ((0)); yyss = &yyptr->yyss_alloc; yynewbytes = yystacksize * sizeof (*yyss) + (sizeof (union yyalloc) - 1); yyptr += yynewbytes / sizeof (*yyptr); } while ((0));
UNSUPPORTED("df5ph3w93ni5ifz7znmwh2w3a"); // 	do { unsigned int yynewbytes; do { unsigned int yyi; for (yyi = 0; yyi < (yysize); yyi++) (&yyptr->yyvs_alloc)[yyi] = (yyvs)[yyi]; } while ((0)); yyvs = &yyptr->yyvs_alloc; yynewbytes = yystacksize * sizeof (*yyvs) + (sizeof (union yyalloc) - 1); yyptr += yynewbytes / sizeof (*yyptr); } while ((0));
UNSUPPORTED("3y5wxnh21auk2usfoajv43y1k"); // 	if (yyss1 != yyssa)
UNSUPPORTED("ewhwt0puq4prsa4csu3agdltp"); // 	  free (yyss1);
UNSUPPORTED("dquo3qofk56ds5xl95lhvcthf"); //       }
UNSUPPORTED("f2pnjh52uf3jivu6xtmu1ubb0"); //       yyssp = yyss + yysize - 1;
UNSUPPORTED("dtcliy1g46kqfujpfosyu4wz4"); //       yyvsp = yyvs + yysize - 1;
UNSUPPORTED("3ejmh10g3kyn79v59obt4uwve"); //       ;
UNSUPPORTED("5fttfrirw536vu8kehb2voeql"); //       if (yyss + yystacksize - 1 <= yyssp)
UNSUPPORTED("am10j8773h9xy42gz4l87tvut"); // 	goto yyabortlab;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("8fukdduwa2m8iyt6sp8d55t83"); //   if (yystate == 6)
UNSUPPORTED("2s4c4zxmqpg8f41cf52q11hn2"); //     goto yyacceptlab;
UNSUPPORTED("16s1l456bx80zdf87xqnqq1m7"); //   goto yybackup;
UNSUPPORTED("1js0t0ytcx8ywvz9tsx2kc95p"); // /*-----------.
UNSUPPORTED("8ydoveifd0u2zarzinfbv2mcs"); // | yybackup.  |
UNSUPPORTED("dbmfwil8k8aqwvx0qac9r5n48"); // `-----------*/
UNSUPPORTED("blf4pkg8pdjsi0tr7900g42pu"); // yybackup:
UNSUPPORTED("6yzm6oy5bmq3akecjcji6mxyb"); //   /* Do appropriate processing given the current state.  Read a
UNSUPPORTED("3plrzglhiw3koxy90giytgoee"); //      lookahead token if we need one and don't already have one.  */
UNSUPPORTED("cbfd87dteogvv9rjyncz9jnkm"); //   /* First try to decide what to do without reference to lookahead token.  */
UNSUPPORTED("d4kp3a274os58vujea556wr7c"); //   yyn = yypact[yystate];
UNSUPPORTED("97iem97t2xdzzawk77w2yy568"); //   if (((yyn) == (-18)))
UNSUPPORTED("3fmgyft4gr6wfphigrb3jvrzq"); //     goto yydefault;
UNSUPPORTED("46jyau3ggxbt5nfv3rhpd6lxc"); //   /* Not known => get a lookahead token if don't already have one.  */
UNSUPPORTED("bax3bsy3o04vppl5jub837tlx"); //   /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
UNSUPPORTED("3fzj8g0a8bf26gibx654z00mi"); //   if (yychar == (-2))
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("3ejmh10g3kyn79v59obt4uwve"); //       ;
UNSUPPORTED("ca2sfn8c9d99bizyfbelhuyd5"); //       yychar = yylex ();
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("bwxh0nxiyjroh5agrbyz3kxt1"); //   if (yychar <= 0)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("9yhwy8a16schyp3gns3dfjxlx"); //       yychar = yytoken = 0;
UNSUPPORTED("3ejmh10g3kyn79v59obt4uwve"); //       ;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("8983svt6g1kt3l45bd6ju9mw6"); //   else
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("4ehc6x7nsh357m49olpc4cuhv"); //       yytoken = ((unsigned int) (yychar) <= 268 ? yytranslate[yychar] : 2);
UNSUPPORTED("3ejmh10g3kyn79v59obt4uwve"); //       ;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("7lmyp30l6y4v0glydzcrxhs2d"); //   /* If the proper action on seeing token YYTOKEN is to reduce or to
UNSUPPORTED("b7crt9is4hw3fqusq1xx9sf6a"); //      detect an error, take that action.  */
UNSUPPORTED("4in4os01kde6b0djzao9gs7oy"); //   yyn += yytoken;
UNSUPPORTED("dex15xbesgsbmbkjbg4kot93a"); //   if (yyn < 0 || 59 < yyn || yycheck[yyn] != yytoken)
UNSUPPORTED("3fmgyft4gr6wfphigrb3jvrzq"); //     goto yydefault;
UNSUPPORTED("81lmf51yxrv6xlwbpzxiy6lnd"); //   yyn = yytable[yyn];
UNSUPPORTED("8hdfgl90wbtvfaw1fgn0quf2t"); //   if (yyn <= 0)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("6mbeksrzh2gawgu5dkavj2est"); //       if ((0))
UNSUPPORTED("8zxmh2oycvsns4p6zsq690jz5"); //         goto yyerrlab;
UNSUPPORTED("5k4kf1gjxdqx3fcyrvgr7oueb"); //       yyn = -yyn;
UNSUPPORTED("b2ubjdjd6gwlcu0nmv2mk2zrx"); //       goto yyreduce;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("6m1h8vs57mr1pqnti7d1p21zm"); //   /* Count tokens shifted since error; after three, turn off error
UNSUPPORTED("71k349r438nfbibdaenrctckz"); //      status.  */
UNSUPPORTED("1nwqsayw0ogig9j8u9pl83uf9"); //   if (yyerrstatus)
UNSUPPORTED("281kcss36kmwi4ogfxfs8lni7"); //     yyerrstatus--;
UNSUPPORTED("bg4fkvjteodqrz0juw1viqqjp"); //   /* Shift the lookahead token.  */
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("vmreafe95a9c5qif2txdddol"); //   /* Discard the shifted token.  */
UNSUPPORTED("7kjg2gi4l12wc5k9x58zpfono"); //   yychar = (-2);
UNSUPPORTED("4sw9jayz05xpsc2hc4128mpt9"); //   yystate = yyn;
UNSUPPORTED("dqkpgoae3twion4t14photdkh"); //   *++yyvsp = yylval;
UNSUPPORTED("6nvi85ih8317wifajbvg2pqs2"); //   goto yynewstate;
UNSUPPORTED("52wvjbtwrbu5hxceg6pcdel69"); // /*-----------------------------------------------------------.
UNSUPPORTED("ah2pnhtd1w6vcf81w55ms3jlq"); // | yydefault -- do the default action for the current state.  |
UNSUPPORTED("9hhkvyvbwlemtn3h1klxkqvhu"); // `-----------------------------------------------------------*/
UNSUPPORTED("6tnzvb6g2e5qv3l2lmumev8xt"); // yydefault:
UNSUPPORTED("e4sfm76r6iqywirgkml8i54v4"); //   yyn = yydefact[yystate];
UNSUPPORTED("94c6edlw2m6fjrujc8g6q812t"); //   if (yyn == 0)
UNSUPPORTED("drlqcn07i3xq2agzwe6hu7oxd"); //     goto yyerrlab;
UNSUPPORTED("cn1kd5p4cr0ll8sj11kitg3rt"); //   goto yyreduce;
UNSUPPORTED("e719ikbjilezocbt4m9kwl59z"); // /*-----------------------------.
UNSUPPORTED("bzo9wknoprssg2zk1whgwcmml"); // | yyreduce -- Do a reduction.  |
UNSUPPORTED("22xw21uiel1yqgh9ekbbt357t"); // `-----------------------------*/
UNSUPPORTED("60ilp1j1ms5ef31o9q556t1ob"); // yyreduce:
UNSUPPORTED("6b8rp07vnvxb5qdulsmksjblt"); //   /* yyn is the number of a rule to reduce with.  */
UNSUPPORTED("329u717rvw0xuxfcgvptopun5"); //   yylen = yyr2[yyn];
UNSUPPORTED("1xow6gk24a2ai9mxr7uo7ja67"); //   /* If YYLEN is nonzero, implement the default value of the action:
UNSUPPORTED("2hk39ofhzlvc0dwqdyy9u0vqb"); //      `$$ = $1'.
UNSUPPORTED("z0dyb7fx7wbongcqyjgkdi93"); //      Otherwise, the following line sets YYVAL to garbage.
UNSUPPORTED("9bj8xv378tepxxvoutf7s2jey"); //      This behavior is undocumented and Bison
UNSUPPORTED("cxdh1gg9j5jy0oknt01shgx43"); //      users should not rely upon it.  Assigning to YYVAL
UNSUPPORTED("d2ax79vvmf62r51efz5v31h1f"); //      unconditionally makes the parser a bit smaller, and it avoids a
UNSUPPORTED("jctvjfbzk1f2q35vsx7olb4"); //      GCC warning that YYVAL may be used uninitialized.  */
UNSUPPORTED("e9b07am7pqcwiww0i1rq4nc70"); //   yyval = yyvsp[1-yylen];
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("nputzf5og4rmodhrmks0mqk6"); //   switch (yyn)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("7ywtj1dc9qm2wgh1sjqw8bog0"); //         case 2:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("b8fd3kei953tgmal1b9sjzu1r"); //     {endgraph();}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("4b2fuxeeiy5560zrwr84bw997"); //   case 3:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("2t5nwc1qzrw26wr8rsvm21avj"); //     {if (G) {agclose(G); G = Ag_G_global = ((Agraph_t*)0);}}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("2kesjv7hdrukecjh0rhqep3b5"); //   case 6:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("7hu6za8syfdexjkes07tr847p"); //     {startgraph((yyvsp[(3) - (3)].str),(yyvsp[(2) - (3)].i),(yyvsp[(1) - (3)].i));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("e1luctq6b333dbc9mpaznby6j"); //   case 7:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("5i7fbaq3ri5oq6b55vvweebs1"); //     {(yyval.str)=(yyvsp[(1) - (1)].str);}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("aq0mcxx5aqy1tk410oeaicrz"); //   case 8:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("7ke9hmt8bitanr9k01l74veaz"); //     {(yyval.str)=0;}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("3fjp05wa4on3vfha31n5uf9c3"); //   case 9:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("eq766xujbo6082t71dn4kxo56"); //     {(yyval.i)=1;}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("c8davuytegef9627gd3tg9pvd"); //   case 10:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("7hal6hibw6c5wh0gik1of5vcb"); //     {(yyval.i)=0;}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("6a4jp0jg8be0uejswkuenq95v"); //   case 11:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("23lzqaox8mhnvc21ldmvc2uuk"); //     {(yyval.i) = 0;}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("ddqjsqeuexv5skwq3pcytig9q"); //   case 12:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("6p59vbkfs5gjf07ewb3m4a4mx"); //     {(yyval.i) = 1;}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("epqpoh4lzr1gr3b0h7lv6suoj"); //   case 21:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("dyty95sd6xbpvssm7usiqaxq9"); //     {if ((yyvsp[(2) - (3)].i)) endedge(); else endnode();}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("90jn0veof2gkokrhklmj2yng4"); //   case 24:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("7paqo3i7urec4jfiylb059pns"); //     {getedgeitems(1);}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("a1zicssxikyxg7770ja6oi1qo"); //   case 25:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("3irhhq988c88sf5za8u2p5ed2"); //     {getedgeitems(2);}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("91777erp91zdakf2rq4nhm80d"); //   case 26:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("6p59vbkfs5gjf07ewb3m4a4mx"); //     {(yyval.i) = 1;}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("10s9wf75pcu4xgky3vzfov0rr"); //   case 27:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("23lzqaox8mhnvc21ldmvc2uuk"); //     {(yyval.i) = 0;}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("3n69l4nxtlpullf9g4klblcml"); //   case 30:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("b7j46zq01umtjf1aafwju4ttl"); //     {appendnode((yyvsp[(1) - (1)].str),((char*)0),((char*)0));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("2z2j2xsio9grsk7azwojofq1a"); //   case 31:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("6nqew1sq9lt559wsht49j0qlg"); //     {appendnode((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),((char*)0));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("dgjfss93xjj8va3zpzsmwsc7s"); //   case 32:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("bsjg1nogl495896sp339m4u2"); //     {appendnode((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("9y3ycu2dl1ja9jadl9mg7jk67"); //   case 33:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("6edurolxl337lcrrvels0sm00"); //     {attrstmt((yyvsp[(1) - (3)].i),(yyvsp[(2) - (3)].str));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("esz4cbak5l686zq9r9zbi7yx5"); //   case 34:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("1fvsazgwn40nqej2bdohaw7b3"); //     {attrstmt(258,((char*)0));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("eestp885g0ixxylrl2yz4l4jk"); //   case 35:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("9t9so3ai40xv1ba6516gky9xb"); //     {(yyval.i) = 258;}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("2y0wzj8xq5ozvt6fnm51kl2ij"); //   case 36:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("bdz1bpbx6zb9g8cl0ij7rlzjv"); //     {(yyval.i) = 259;}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("3ftibwfr6yuhieocopced5aby"); //   case 37:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("5vmj2dj6aw4itvep7uj7ijwpl"); //     {(yyval.i) = 260;}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("av4z5qte05unsmsl8oy2jw5wh"); //   case 38:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("bu0c1l0dwc0li5ih5l1fixxs3"); //     {(yyval.str) = (yyvsp[(1) - (2)].str);}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("clipffhxj206f2zoz5tskxfso"); //   case 39:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("c5jlknptu8flktpt9oxu74d64"); //     {(yyval.str) = ((char*)0); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("co51vw9d73gymlc8231s1jobg"); //   case 48:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("2scisx8008v7bce7b36td9wzz"); //     {appendattr((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("3gd6s52j3cevgz1ud9ys8mmpu"); //   case 49:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("1a4c3ojr06abclbxdq5l93a46"); //     {appendattr((yyvsp[(2) - (2)].str),((char*)0));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("605ei0ilu3nz1gtra52oi7mz3"); //   case 51:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("cue6jecp73h0al6yyjmvfsdqw"); //     {opensubg((yyvsp[(1) - (1)].str));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("9qbtgt2eyxxuukc88ljehppv1"); //   case 52:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("a4d6txemsyzgejqzcz4xj5zll"); //     {closesubg();}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("a5l2sixwhiv4x59rzexutoo1"); //   case 53:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("9k0szfkv43kzru8q4bit6lt9p"); //     {(yyval.str)=(yyvsp[(2) - (2)].str);}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("d9qqg2poxec5i2gk2tlzjceze"); //   case 54:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("1x3bxn8s9k3u3am6tkxfk3sxi"); //     {(yyval.str)=((char*)0);}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("19bjcrzc7duy98u3gs54bkn75"); //   case 55:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("1x3bxn8s9k3u3am6tkxfk3sxi"); //     {(yyval.str)=((char*)0);}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("2e8vk62ndof1wckppsf3h1s08"); //   case 59:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("4rw3ma8yg5nkx5z8icorudllr"); //     {(yyval.str) = (yyvsp[(1) - (1)].str);}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("datyn4rldj3j181mig7lm4p15"); //   case 60:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("4rw3ma8yg5nkx5z8icorudllr"); //     {(yyval.str) = (yyvsp[(1) - (1)].str);}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("arwsoeo1a8oc675m9cdqjutkj"); //   case 61:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("4rw3ma8yg5nkx5z8icorudllr"); //     {(yyval.str) = (yyvsp[(1) - (1)].str);}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("dvs3metp9y50zqp24wirfa2mt"); //   case 62:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("646qnhr8llwx69gzvy7bxukh9"); //     {(yyval.str) = concat((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("dlej2d1ppih1bnw53vhocc61k"); //       default: break;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("5cqll1f6ifjhnf5kjarx18ld7"); //   /* User semantic actions sometimes alter yychar, and that requires
UNSUPPORTED("awngk7ukt8o0iti5qo4bas9qu"); //      that yytoken be updated with the new translation.  We take the
UNSUPPORTED("3ylmmve1iqs603x0j5nwz4f7t"); //      approach of translating immediately before every use of yytoken.
UNSUPPORTED("5egmt4bmrda5rwmq0fxaut100"); //      One alternative is translating here after every semantic action,
UNSUPPORTED("cbfgp6r4p0aww4ln7e4wjq5rg"); //      but that translation would be missed if the semantic action invokes
UNSUPPORTED("5e50914xh0fwl1xezevm21gnp"); //      YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
UNSUPPORTED("c4u72wy240sife8xvhjcdf3y"); //      if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
UNSUPPORTED("9oqy8bmho7vno5ewpwljpvk7k"); //      incorrect destructor might then be invoked immediately.  In the
UNSUPPORTED("2dm4du9w60sge1uyx4vrwgtuv"); //      case of YYERROR or YYBACKUP, subsequent parser actions might lead
UNSUPPORTED("55ajnkklldzargdu2v7xxw8jh"); //      to an incorrect destructor call or verbose syntax error message
UNSUPPORTED("2w6gaiusmvs9119tusfj7wmgn"); //      before the lookahead is translated.  */
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("8x7gb1igulyb30k4h1wip0jbw"); //   (yyvsp -= (yylen), yyssp -= (yylen));
UNSUPPORTED("8vm93a8434d8sy5ft2p0ffy2f"); //   yylen = 0;
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("cmccd42l0im45m3od0igu34al"); //   *++yyvsp = yyval;
UNSUPPORTED("8zf4hex7pjvkzs6628u0usoop"); //   /* Now `shift' the result of the reduction.  Determine what state
UNSUPPORTED("9p956m8qfuj78tnsyhxtvs3t4"); //      that goes to, based on the state we popped back to and the rule
UNSUPPORTED("2sr0m6m0qte5wg0zclc83vtln"); //      number reduced by.  */
UNSUPPORTED("3j26tpego5wkr3i7sxhi0vlfi"); //   yyn = yyr1[yyn];
UNSUPPORTED("a48kai6w0c2bkstklhzz29mmi"); //   yystate = yypgoto[yyn - 24] + *yyssp;
UNSUPPORTED("4djaf98s7b9bhg0i0td7pb91l"); //   if (0 <= yystate && yystate <= 59 && yycheck[yystate] == *yyssp)
UNSUPPORTED("qmyvkodfobpxzeqpbyt6bqds"); //     yystate = yytable[yystate];
UNSUPPORTED("8983svt6g1kt3l45bd6ju9mw6"); //   else
UNSUPPORTED("ezkoooak70c5k7d052706fwtk"); //     yystate = yydefgoto[yyn - 24];
UNSUPPORTED("6nvi85ih8317wifajbvg2pqs2"); //   goto yynewstate;
UNSUPPORTED("brpyacmu3j2c5b5b57c44c6xg"); // /*------------------------------------.
UNSUPPORTED("dm7tq63p22rwn6r638bg01ste"); // | yyerrlab -- here on detecting error |
UNSUPPORTED("46kmo9tkqrq2trhedjhrmq5iu"); // `------------------------------------*/
UNSUPPORTED("2i48je78o7b125ljlmo3rrrn9"); // yyerrlab:
UNSUPPORTED("6pctfudiscetk242w9vfsytui"); //   /* Make sure we have latest lookahead translation.  See comments at
UNSUPPORTED("9z8lh3976ui2i6adwx4bu8xtu"); //      user semantic actions for why this is necessary.  */
UNSUPPORTED("8hsfb2i6uh3r92sn6ruoooyek"); //   yytoken = yychar == (-2) ? (-2) : ((unsigned int) (yychar) <= 268 ? yytranslate[yychar] : 2);
UNSUPPORTED("4yyok9q9sqmbmxchbquk9rz3a"); //   /* If not already recovering from an error, report this error.  */
UNSUPPORTED("5tzevilbik2gtdm8eme1d0rr0"); //   if (!yyerrstatus)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("nbgtjj315e9erfjw1966r1nj"); //       ++yynerrs;
UNSUPPORTED("6dvzyrcoug25gdlx878gfncgd"); //       yyerror ("syntax error");
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("55ts2vdfkuwiduyrxm4dthuge"); //   if (yyerrstatus == 3)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("3jyg22xuaw01ib5n6y8iv3xxr"); //       /* If just tried and failed to reuse lookahead token after an
UNSUPPORTED("4zj2myg3clgam20xdvt28usk8"); // 	 error, discard it.  */
UNSUPPORTED("7syst9kqcdmgefgn9sa5pf7o5"); //       if (yychar <= 0)
UNSUPPORTED("98gvqspn5y1bfyr14rwoaqk67"); // 	{
UNSUPPORTED("ps0ydhmk8cvulxq94uiebnl3"); // 	  /* Return failure if at end of input.  */
UNSUPPORTED("cx3jo1wzpr0xulijxy2hr6sc6"); // 	  if (yychar == 0)
UNSUPPORTED("6yhjuhoaoslhl1mcaltg7q7pg"); // 	    goto yyabortlab;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("e2koj2xocq76awegpydpyu62m"); //       else
UNSUPPORTED("98gvqspn5y1bfyr14rwoaqk67"); // 	{
UNSUPPORTED("1jxztkqlg99as0f75qw9zu7hc"); // 	  yydestruct ("Error: discarding",
UNSUPPORTED("d77dp0agmh0vtezh1or0i4739"); // 		      yytoken, &yylval);
UNSUPPORTED("83od8u43ovfv5njq9h6djl0ot"); // 	  yychar = (-2);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("cngu0btwjacz5b793e8yvi9m1"); //   /* Else will try to reuse lookahead token after shifting the error
UNSUPPORTED("38vbb7wijegv8on4kj8r2jh3w"); //      token.  */
UNSUPPORTED("erwd0x8o17qppvw1i027q4w8g"); //   goto yyerrlab1;
UNSUPPORTED("6iskxmjpvgrnnac6655f5jk67"); // /*---------------------------------------------------.
UNSUPPORTED("e8wekw8xk8h4ehfscg9thr469"); // | yyerrorlab -- error raised explicitly by YYERROR.  |
UNSUPPORTED("6a0f8547ydra66tf81ssie9pn"); // `---------------------------------------------------*/
UNSUPPORTED("6sqgsf1ikylmv5xu2vnzb6zfh"); // yyerrorlab:
UNSUPPORTED("skx5cc7fpyqelhc1lbzwq6gy"); //   /* Pacify compilers like GCC when the user code never invokes
UNSUPPORTED("61aw8i7lhhk5dco9iriz40sew"); //      YYERROR and the label yyerrorlab therefore never appears in user
UNSUPPORTED("2cx96j1h5f1sf0pyotl6w1g31"); //      code.  */
UNSUPPORTED("9850ib9fy0bgpnxd1mv3rhcl0"); //   if (/*CONSTCOND*/ 0)
UNSUPPORTED("a51kt3zd29fq3lcg3v1ks7u3t"); //      goto yyerrorlab;
UNSUPPORTED("2lhgt1uq3z8cnzed8w920d1og"); //   /* Do not reclaim the symbols of the rule which action triggered
UNSUPPORTED("2qdujvpg7me3yjqefsbmb4nbl"); //      this YYERROR.  */
UNSUPPORTED("8x7gb1igulyb30k4h1wip0jbw"); //   (yyvsp -= (yylen), yyssp -= (yylen));
UNSUPPORTED("8vm93a8434d8sy5ft2p0ffy2f"); //   yylen = 0;
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("zhrklmvb28eknyhrgi1sl42m"); //   yystate = *yyssp;
UNSUPPORTED("erwd0x8o17qppvw1i027q4w8g"); //   goto yyerrlab1;
UNSUPPORTED("a9uzsnursnm07o2p12lh2sbdg"); // /*-------------------------------------------------------------.
UNSUPPORTED("d5bdojxx2qhdavmglrnnu20wq"); // | yyerrlab1 -- common code for both syntax error and YYERROR.  |
UNSUPPORTED("cinw8ra05yfs6jshwnk7uer8g"); // `-------------------------------------------------------------*/
UNSUPPORTED("4a99tboc4ge220j5k0q7kkcv8"); // yyerrlab1:
UNSUPPORTED("4q9jx23t3a7q78efzc3hplezr"); //   yyerrstatus = 3;	/* Each real token shifted decrements this.  */
UNSUPPORTED("9qdgu2bhbvj6h80iki9hjhpcx"); //   for (;;)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("7h162nbw1l50eoity8vl8vlfx"); //       yyn = yypact[yystate];
UNSUPPORTED("9pbbw8v7aqlhkucx5ctr2dkak"); //       if (!((yyn) == (-18)))
UNSUPPORTED("98gvqspn5y1bfyr14rwoaqk67"); // 	{
UNSUPPORTED("2cb0b601jdhr7ao1k7uedmqp4"); // 	  yyn += 1;
UNSUPPORTED("b7uk551108q3b7c2yykr8tmfw"); // 	  if (0 <= yyn && yyn <= 59 && yycheck[yyn] == 1)
UNSUPPORTED("6dbei3uox5ql5a1vaaguh0xzp"); // 	    {
UNSUPPORTED("3h7enjuboh25u2w9uv7n20zdp"); // 	      yyn = yytable[yyn];
UNSUPPORTED("929wghuvx3qqaljlqay2r0qox"); // 	      if (0 < yyn)
UNSUPPORTED("9ekmvj13iaml5ndszqyxa8eq"); // 		break;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("1nekbbuf2scf8o8o56p3e2btr"); //       /* Pop the current state because it cannot handle the error token.  */
UNSUPPORTED("4ku603ttm915jqijkt8jfdtur"); //       if (yyssp == yyss)
UNSUPPORTED("am10j8773h9xy42gz4l87tvut"); // 	goto yyabortlab;
UNSUPPORTED("b8z1x6wup2pyz9pk8yo2f7mly"); //       yydestruct ("Error: popping",
UNSUPPORTED("3xxknhj7rdvwd70kls6v0sjlv"); // 		  yystos[yystate], yyvsp);
UNSUPPORTED("do23hvgct6rw0i2id4p6c8w3w"); //       (yyvsp -= (1), yyssp -= (1));
UNSUPPORTED("aa9r4mny7kfvlswoajt6ewiua"); //       yystate = *yyssp;
UNSUPPORTED("3ejmh10g3kyn79v59obt4uwve"); //       ;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("dqkpgoae3twion4t14photdkh"); //   *++yyvsp = yylval;
UNSUPPORTED("1bunp144fpibi7v7rbgn16l6l"); //   /* Shift the error token.  */
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("4sw9jayz05xpsc2hc4128mpt9"); //   yystate = yyn;
UNSUPPORTED("6nvi85ih8317wifajbvg2pqs2"); //   goto yynewstate;
UNSUPPORTED("179qxptpyl5068065s1ai8g3c"); // /*-------------------------------------.
UNSUPPORTED("anl6cgk1tm199ldzxzf8s1bh3"); // | yyacceptlab -- YYACCEPT comes here.  |
UNSUPPORTED("2bvn7c0u1oq31d3b0uk6m3tdy"); // `-------------------------------------*/
UNSUPPORTED("cbzrzcwa3d2vc6ordo6oj3xko"); // yyacceptlab:
UNSUPPORTED("5vzqjwd5x1qujng4k6z6tpi2o"); //   yyresult = 0;
UNSUPPORTED("9rhxz7vhxa5rm8e3p37nc24b0"); //   goto yyreturn;
UNSUPPORTED("8p4f508auqnz4koon32xrgqkm"); // /*-----------------------------------.
UNSUPPORTED("28nb5q4v0xxkeavz1lxebk5k6"); // | yyabortlab -- YYABORT comes here.  |
UNSUPPORTED("6p3zuxhtllqujwb6275y1iuol"); // `-----------------------------------*/
UNSUPPORTED("cs5upc0kvptz7pahmh8s1dhr7"); // yyabortlab:
UNSUPPORTED("dxco1j9c6ug5tilavyzolvj1v"); //   yyresult = 1;
UNSUPPORTED("9rhxz7vhxa5rm8e3p37nc24b0"); //   goto yyreturn;
UNSUPPORTED("1visspreqlkrsxbrmmtajzyi0"); // /*-------------------------------------------------.
UNSUPPORTED("29by7a2oedt1hazfly96vjurq"); // | yyexhaustedlab -- memory exhaustion comes here.  |
UNSUPPORTED("3zfwm8se9uqcr4uczanjlo4wx"); // `-------------------------------------------------*/
UNSUPPORTED("b2ygf3uu6p4g9r7tgaohy1240"); // yyexhaustedlab:
UNSUPPORTED("4ytx7di4prwazpscx8x0vbo8v"); //   yyerror ("memory exhausted");
UNSUPPORTED("e012l6rqiz3pyhp7p2yfh67zu"); //   yyresult = 2;
UNSUPPORTED("50117q88lfg743xhieoyg9dtb"); //   /* Fall through.  */
UNSUPPORTED("3ddyjbtqzdtjsfqcfj6zddwmj"); // yyreturn:
UNSUPPORTED("9nwvriowi4mgw93nqdwsg3h3y"); //   if (yychar != (-2))
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("1yvk3imqcd71tq0dg520dalwv"); //       /* Make sure we have latest lookahead translation.  See comments at
UNSUPPORTED("8f533hh53bahoyrmc8vumq0er"); //          user semantic actions for why this is necessary.  */
UNSUPPORTED("4ehc6x7nsh357m49olpc4cuhv"); //       yytoken = ((unsigned int) (yychar) <= 268 ? yytranslate[yychar] : 2);
UNSUPPORTED("bw1xk28c88hsn48guw3wtxcny"); //       yydestruct ("Cleanup: discarding lookahead",
UNSUPPORTED("8q59rkbmrhyjxo0in0tysc9d3"); //                   yytoken, &yylval);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("2lhgt1uq3z8cnzed8w920d1og"); //   /* Do not reclaim the symbols of the rule which action triggered
UNSUPPORTED("brvt6wka5tijolvbute9f9vjy"); //      this YYABORT or YYACCEPT.  */
UNSUPPORTED("8x7gb1igulyb30k4h1wip0jbw"); //   (yyvsp -= (yylen), yyssp -= (yylen));
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("4ek9gfkq4rqe58yqa7yp7n4wf"); //   while (yyssp != yyss)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("d0tynwjettp1otc13e09xap0g"); //       yydestruct ("Cleanup: popping",
UNSUPPORTED("7buci8ktyvgwlnzitin2vcnzb"); // 		  yystos[*yyssp], yyvsp);
UNSUPPORTED("do23hvgct6rw0i2id4p6c8w3w"); //       (yyvsp -= (1), yyssp -= (1));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("dt668kats752ezjns7gbcqbm"); //   if (yyss != yyssa)
UNSUPPORTED("3zst4dfy8kmamfritmsl2bgld"); //     free (yyss);
UNSUPPORTED("96m641qde7y8nrj81kip0kdli"); //   /* Make sure YYID is used.  */
UNSUPPORTED("czgny8i6sq1w5i986hse6937y"); //   return (yyresult);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 a975qyv6akt8xwhwcufnekq1l
// static item *newitem(int tag, void *p0, char *p1) 
public static Object newitem(Object... arg) {
UNSUPPORTED("b8dl64esytrvqxxp7ywb3gtcq"); // static item *newitem(int tag, void *p0, char *p1)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2h27ya0s3dauz3quw8qqs3aw2"); // 	item	*rv = agalloc(G,sizeof(item));
UNSUPPORTED("7v7zcgem5sgvx0w1iyndv2umk"); // 	rv->tag = tag; rv->u.name = (char*)p0; rv->str = p1;
UNSUPPORTED("cs1ejkx9cw658cl8cagdzqrzm"); // 	return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 em2hlpw97nd3f7ls6xc9rynhw
// static item *cons_node(Agnode_t *n, char *port) 	
public static Object cons_node(Object... arg) {
UNSUPPORTED("88sggh7i7vp5adpf6voraujdm"); // static item *cons_node(Agnode_t *n, char *port)
UNSUPPORTED("43rn4o330r3980psapkzr338a"); // 	{ return newitem(259,n,port); }

throw new UnsupportedOperationException();
}




//3 5kphi0if5q885q5d3har73wje
// static item *cons_attr(char *name, char *value) 	
public static Object cons_attr(Object... arg) {
UNSUPPORTED("aep7okz7oe4x522cwa9gxaz14"); // static item *cons_attr(char *name, char *value)
UNSUPPORTED("dtos34oztd2azw6edh1zaw3lt"); // 	{ return newitem(267,name,value); }

throw new UnsupportedOperationException();
}




//3 e9dh0fzyupvj2edilex1gct9t
// static item *cons_list(item *list) 	
public static Object cons_list(Object... arg) {
UNSUPPORTED("76k2v79akb8odg31ghy9wvqfw"); // static item *cons_list(item *list)
UNSUPPORTED("b89rx5bmmhgjvyrvgknnd310n"); // 	{ return newitem(265,list,((char*)0)); }

throw new UnsupportedOperationException();
}




//3 d9cnx4ritqwzoa3ejf7skpj3p
// static item *cons_subg(Agraph_t *subg) 	
public static Object cons_subg(Object... arg) {
UNSUPPORTED("apu6foddc7whkrx68lolzd0ij"); // static item *cons_subg(Agraph_t *subg)
UNSUPPORTED("9xsvs6x3r3nr4xlpvofo85owj"); // 	{ return newitem(262,subg,((char*)0)); }

throw new UnsupportedOperationException();
}




//3 dw40y7rzffy9kripetm233jah
// static gstack_t *push(gstack_t *s, Agraph_t *subg) 
public static Object push(Object... arg) {
UNSUPPORTED("6g2d0zo1fsa28l9978lzuac4b"); // static gstack_t *push(gstack_t *s, Agraph_t *subg) {
UNSUPPORTED("prhels2nvzpq0z0bkn59k3ys"); // 	gstack_t *rv;
UNSUPPORTED("d6bj7dnl2qz0i2kscnfi5a6az"); // 	rv = agalloc(G,sizeof(gstack_t));
UNSUPPORTED("1t3pygrz6wbtjyrqz3hp7dge1"); // 	rv->down = s;
UNSUPPORTED("7ybhn9haptenns5re5aowx6co"); // 	rv->g = subg;
UNSUPPORTED("cs1ejkx9cw658cl8cagdzqrzm"); // 	return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 jxzwff8ggkp4sb8tf5rkb8k6
// static gstack_t *pop(gstack_t *s) 
public static Object pop(Object... arg) {
UNSUPPORTED("y6djn1ocr46rnmksm418y1t5"); // static gstack_t *pop(gstack_t *s)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("prhels2nvzpq0z0bkn59k3ys"); // 	gstack_t *rv;
UNSUPPORTED("9kdpijau95h3caj4mdmzd28e"); // 	rv = S->down;
UNSUPPORTED("20w8763tgo6g8wa11teus6d2s"); // 	agfree(G,s);
UNSUPPORTED("cs1ejkx9cw658cl8cagdzqrzm"); // 	return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 a9wxp90t4zxyd9alzown5j79z
// static void delete_items(item *ilist) 
public static Object delete_items(Object... arg) {
UNSUPPORTED("c859wtmgvhdnyu4jcsnhvnoe3"); // static void delete_items(item *ilist)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("adakthiluvofo231bgcekox1y"); // 	item	*p,*pn;
UNSUPPORTED("d8vqs84reifecynxxfbrzs4xb"); // 	for (p = ilist; p; p = pn) {
UNSUPPORTED("1rsdsgy4o65igrtv29ddklf09"); // 		pn = p->next;
UNSUPPORTED("do4joj6ih8li6br0qhv9sc0ow"); // 		switch(p->tag) {
UNSUPPORTED("8mc64wnxf632jc7vgkpzrpmc6"); // 			case 265: delete_items(p->u.list); break;
UNSUPPORTED("bjm9aa3wfi56086laumuejlnk"); // 			case 267: case 266: agstrfree(G,p->str); break;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("4a0shh7695vc4d7ijtmxh1b75"); // 		agfree(G,p);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 a6k50l5l0udgy364mfec55896
// static void deletelist(list_t *list) 
public static Object deletelist(Object... arg) {
UNSUPPORTED("1mavwvvsp61ddnc5s4gzqvc6z"); // static void deletelist(list_t *list)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("apm0hkdtuh3lunq402oaf0mf5"); // 	delete_items(list->first);
UNSUPPORTED("62ls6mbj9pp2e7a66jmrf3ran"); // 	list->first = list->last = ((item*)0);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 d4b3x74h8ut28tyqp654l3yxz
// static void listapp(list_t *list, item *v) 
public static Object listapp(Object... arg) {
UNSUPPORTED("9a6638tr3ljadef82lfhpm5u6"); // static void listapp(list_t *list, item *v)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("6ypjdve6ipjlsaza1jyp3aq52"); // 	if (list->last) list->last->next = v;
UNSUPPORTED("1919zxfobsfhn3hh3kakusk6z"); // 	list->last = v;
UNSUPPORTED("369b7xeokyifvmus5jsrtdlds"); // 	if (list->first == ((item*)0)) list->first = v;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 cief5a2enufyvfkzjc5l8tdrv
// static void appendattr(char *name, char *value) 
public static Object appendattr(Object... arg) {
UNSUPPORTED("e1hjdeebaejvptg4chbjxfxlw"); // static void appendattr(char *name, char *value)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("okw2gubbmmogryjunmv5qn9p"); // 	item		*v;
UNSUPPORTED("bt8qt5d94yexozgdbv5sspmm4"); // 	;
UNSUPPORTED("bymwzwo11exkm5ct5wwcj3s5c"); // 	v = cons_attr(name,value);
UNSUPPORTED("3gsgi7ij6xugmtcek4bhqne9j"); // 	listapp(&(S->attrlist),v);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 22a8iprb23syh10mef73duysg
// static void bindattrs(int kind) 
public static Object bindattrs(Object... arg) {
UNSUPPORTED("3ifiri4pttx0f8uqgj9q9pw27"); // static void bindattrs(int kind)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("e8k6b6dqpns6cbu369ktxf47x"); // 	item		*aptr;
UNSUPPORTED("ba3awz26aqi32lyuzwi9bjop4"); // 	char		*name;
UNSUPPORTED("5utouifow6qy2mohyx1mzxxej"); // 	for (aptr = S->attrlist.first; aptr; aptr = aptr->next) {
UNSUPPORTED("bnseuabj3252vmlz3kher9cgd"); // 		;	/* signifies unbound attr */
UNSUPPORTED("cc7nepz9cww82vmycltmfx6mz"); // 		name = aptr->u.name;
UNSUPPORTED("7hgp57qf1haq6j64q9j379f33"); // 		if ((kind == AGEDGE) && ((*name == *Key) && !strcmp((name),(Key)))) continue;
UNSUPPORTED("2z0ysldpb96ztkbzneeksu9wa"); // 		if ((aptr->u.asym = agattr(S->g,kind,name,((char*)0))) == ((Agsym_t*)0))
UNSUPPORTED("11pyg30y462hwz6zmyr4em0hu"); // 			aptr->u.asym = agattr(S->g,kind,name,"");
UNSUPPORTED("6a40vm5w6ck8sm3vbkvrho04j"); // 		aptr->tag = 266;				/* signifies bound attr */
UNSUPPORTED("48c5lssz3ch20yc7ml2vwkvtj"); // 		agstrfree(G,name);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 60pki9bxocjsus7z8wtcykfeo
// static void applyattrs(void *obj) 
public static Object applyattrs(Object... arg) {
UNSUPPORTED("3hntz25fjgh9koyljbn6xulmw"); // static void applyattrs(void *obj)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("e8k6b6dqpns6cbu369ktxf47x"); // 	item		*aptr;
UNSUPPORTED("5utouifow6qy2mohyx1mzxxej"); // 	for (aptr = S->attrlist.first; aptr; aptr = aptr->next) {
UNSUPPORTED("9pyae0fw5rvcwygbcj6p2jpjk"); // 		if (aptr->tag == 266) {
UNSUPPORTED("7yvywh9cbntwuquzfeb3qaz6g"); // 			if (aptr->u.asym) {
UNSUPPORTED("9rmkbhe4u1jl9ubvajfumym47"); // 				agxset(obj,aptr->u.asym,aptr->str);
UNSUPPORTED("3to5h0rvqxdeqs38mhv47mm3o"); // 			}
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("d28blrbmwwqp80cyksuz7dwx9"); // 		else {
UNSUPPORTED("1pkb5smsyofq9owclpbhtu0p7"); // 			;
UNSUPPORTED("1pkb5smsyofq9owclpbhtu0p7"); // 			;
UNSUPPORTED("1pkb5smsyofq9owclpbhtu0p7"); // 			;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 3kajqz1exi4ckidtcqt8jlhxt
// static void nomacros(void) 
public static Object nomacros(Object... arg) {
UNSUPPORTED("2yw3ig5p34qgsxog6wiaqr4dj"); // static void nomacros(void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("aq0ntfa4k2yet3oxuyr7m9wl1"); // 	agerr(AGWARN,"attribute macros not implemented");
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 5ytzk13w8e8hhboi3dv6rf7xl
// static void attrstmt(int tkind, char *macroname) 
public static Object attrstmt(Object... arg) {
UNSUPPORTED("bytughpa0w06ktkrmhcpfedql"); // static void attrstmt(int tkind, char *macroname)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("3r0yi2uy9wcsar300yetua0c"); // 	item			*aptr;
UNSUPPORTED("1suegex1zq603kcrsvziz7wit"); // 	int				kind;
UNSUPPORTED("6fvvw9em2vuvrlyhl8gyp51ew"); // 	Agsym_t*  sym;
UNSUPPORTED("1lqmruco0z03hk5kxsr1l0rux"); // 		/* creating a macro def */
UNSUPPORTED("1mw2r9u9rz9fjb3hiobkfjvlk"); // 	if (macroname) nomacros();
UNSUPPORTED("d7brdic9r6cd6ml7ztv4t122v"); // 		/* invoking a macro def */
UNSUPPORTED("1bil5ypovm4gka7f8peqydi3k"); // 	for (aptr = S->attrlist.first; aptr; aptr = aptr->next)
UNSUPPORTED("1t776gpk1zy59afsmlo1wfok0"); // 		if (aptr->str == ((char*)0)) nomacros();
UNSUPPORTED("eqnuh5mrq2k9a3hyn15896zmc"); // 	switch(tkind) {
UNSUPPORTED("7eqhhztlyox7piaiuduah2769"); // 		case 258: kind = AGRAPH; break;
UNSUPPORTED("5jtdyifbki45rvxlj45xlcsno"); // 		case 259: kind = AGNODE; break;
UNSUPPORTED("ek10gekn8yhvy7r5n679ayuuk"); // 		case 260: kind = AGEDGE; break;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("1s53k37971sd1brthkaailb4x"); // 	bindattrs(kind);	/* set up defaults for new attributes */
UNSUPPORTED("5utouifow6qy2mohyx1mzxxej"); // 	for (aptr = S->attrlist.first; aptr; aptr = aptr->next) {
UNSUPPORTED("b6t5e2culpib8bjhfminx13db"); // 		if (!(aptr->u.asym->fixed) || (S->g != G))
UNSUPPORTED("41y7sephdm8tv6oi8651s3k4"); // 			sym = agattr(S->g,kind,aptr->u.asym->name,aptr->str);
UNSUPPORTED("7e1uy5mzei37p66t8jp01r3mk"); // 		else
UNSUPPORTED("2mylz3axox69vbqb1lfkrj8a1"); // 			sym = aptr->u.asym;
UNSUPPORTED("8jgwzlpqmfpuhomb49cuwge9w"); // 		if (S->g == G)
UNSUPPORTED("6qqdjm01wwlpeykqfq261ppp2"); // 			sym->print = (!(0));
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("4kfclkka1vu9qjxzujvijfmvk"); // 	deletelist(&(S->attrlist));
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 2pm4g43u5f2cvt5ly4zned6yh
// static void appendnode(char *name, char *port, char *sport) 
public static Object appendnode(Object... arg) {
UNSUPPORTED("ajnxiny2w8wv4ixl2nkiyum7w"); // static void appendnode(char *name, char *port, char *sport)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("fi13ksvbk0xo9rvvtuzormpz"); // 	item		*elt;
UNSUPPORTED("6o0von8levycrm10cbgd1pw2t"); // 	if (sport) {
UNSUPPORTED("41edpea9pmwibvpnglfmerch4"); // 		port = concatPort (port, sport);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("8gbpwbrm6nh33b0v51nl7vd6r"); // 	elt = cons_node(agnode(S->g,name,(!(0))),port);
UNSUPPORTED("bkqw9ol9p3jsabdaf3rs6mel2"); // 	listapp(&(S->nodelist),elt);
UNSUPPORTED("6hpfigkim341uzgw6kw2qlnha"); // 	agstrfree(G,name);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 79vf6tman8bta4s6efanxb73c
// static void endnode() 
public static Object endnode(Object... arg) {
UNSUPPORTED("dewz3puopjtpj9ebgcz98o8oh"); // static void endnode()
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("avibd2h0166tkuqp8bg1ulunq"); // 	item	*ptr;
UNSUPPORTED("b3dnknfzm40jikspo7ms4db74"); // 	bindattrs(AGNODE);
UNSUPPORTED("1a1sgbf3aosz5pm13egg3kvhr"); // 	for (ptr = S->nodelist.first; ptr; ptr = ptr->next)
UNSUPPORTED("5w5b9x03df9vgnucydqt09pe"); // 		applyattrs(ptr->u.n);
UNSUPPORTED("b8k45vn895nd1jd73v8umwmf5"); // 	deletelist(&(S->nodelist));
UNSUPPORTED("4kfclkka1vu9qjxzujvijfmvk"); // 	deletelist(&(S->attrlist));
UNSUPPORTED("4hv494qw1yr65jl3mh3kfx47o"); // 	deletelist(&(S->edgelist));
UNSUPPORTED("34tnugsr5fhtgunqnernqlnr3"); // 	S->subg = 0;  /* notice a pattern here? :-( */
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 7jeszrd41pt8bi3hfd7ou5jvd
// static void getedgeitems(int x) 
public static Object getedgeitems(Object... arg) {
UNSUPPORTED("67h9aa41589qpn225zp9vz2ed"); // static void getedgeitems(int x)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8d7p799d1a4ge5zhodmqg24el"); // 	item	*v = 0;
UNSUPPORTED("xl8aiewdmyhsh74opyd0g9ea"); // 	if (S->nodelist.first) {
UNSUPPORTED("2ubft38ftiwu6qynd76nbeq57"); // 		v = cons_list(S->nodelist.first);
UNSUPPORTED("9444iqtyunu5kmvh61prk00ah"); // 		S->nodelist.first = S->nodelist.last = ((item*)0);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dre90efj7opely1fk58dtzelk"); // 	else {if (S->subg) v = cons_subg(S->subg); S->subg = 0;}
UNSUPPORTED("c6nmi0q15ijqvkjieprxz2k0q"); // 	/* else nil append */
UNSUPPORTED("4w5cmhvt50gg5a4xugws7byyy"); // 	if (v) listapp(&(S->edgelist),v);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 anzp77i17xs50ltfzu5huwyjv
// static void endedge(void) 
public static Object endedge(Object... arg) {
UNSUPPORTED("f3r6og84x4picmcrris4vb21m"); // static void endedge(void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("eo7cvrj5fz6a90rrw21aiu9rl"); // 	char			*key;
UNSUPPORTED("9cjuubzgasbklah22ieds3q4s"); // 	item			*aptr,*tptr,*p;
UNSUPPORTED("b3zw4facxyfjdcpoxozn31x3f"); // 	Agnode_t		*t;
UNSUPPORTED("l83zfbv6jqr5s5nhi9d6ybcr"); // 	Agraph_t		*subg;
UNSUPPORTED("5lhz0se646b158w4kh0grc8op"); // 	bindattrs(AGEDGE);
UNSUPPORTED("4q63zzbnevz446qedy1c8a6hc"); // 	/* look for "key" pseudo-attribute */
UNSUPPORTED("85ug0eia1u6o9cy5kod0zt0ho"); // 	key = ((char*)0);
UNSUPPORTED("5utouifow6qy2mohyx1mzxxej"); // 	for (aptr = S->attrlist.first; aptr; aptr = aptr->next) {
UNSUPPORTED("ej7z8paut8okazahz6y4hlreo"); // 		if ((aptr->tag == 267) && ((*aptr->u.name == *Key) && !strcmp((aptr->u.name),(Key))))
UNSUPPORTED("7dphbfnxkcvrbs79duu01i1mg"); // 			key = aptr->str;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("6me3l371r3cx7nroqyagb83ye"); // 	/* can make edges with node lists or subgraphs */
UNSUPPORTED("5y73qoukadv3zroql69kq6a51"); // 	for (p = S->edgelist.first; p->next; p = p->next) {
UNSUPPORTED("h63r26tpggn2xhqklebpmws7"); // 		if (p->tag == 262) {
UNSUPPORTED("b8d8kp9bb5uu3vrabi6dt4twc"); // 			subg = p->u.subg;
UNSUPPORTED("1x342oa82npzptntsp57h99hw"); // 			for (t = agfstnode(subg); t; t = agnxtnode(subg,t))
UNSUPPORTED("djd4f57q4d2nd0mpxjbvdegsj"); // 				edgerhs(agsubnode(S->g,t,(0)),((char*)0),p->next,key);
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("d28blrbmwwqp80cyksuz7dwx9"); // 		else {
UNSUPPORTED("eiyq8yfx80vtbd93yggvthdrc"); // 			for (tptr = p->u.list; tptr; tptr = tptr->next)
UNSUPPORTED("cyx28uhmwqsopc302tkket"); // 				edgerhs(tptr->u.n,tptr->str,p->next,key);
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("b8k45vn895nd1jd73v8umwmf5"); // 	deletelist(&(S->nodelist));
UNSUPPORTED("4hv494qw1yr65jl3mh3kfx47o"); // 	deletelist(&(S->edgelist));
UNSUPPORTED("4kfclkka1vu9qjxzujvijfmvk"); // 	deletelist(&(S->attrlist));
UNSUPPORTED("dqeqz573u45i4w5530p08t112"); // 	S->subg = 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 9djkrzfzfafc6d68hbyuyvard
// static char* concat (char* s1, char* s2) 
public static Object concat(Object... arg) {
UNSUPPORTED("1yranxmu2maol02ulzd1ka1re"); // static char*
UNSUPPORTED("3wcar10y5mlmo5noson980nws"); // concat (char* s1, char* s2)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4b21y9nothvmubb9587tjs8sh"); //   char*  s;
UNSUPPORTED("9l6wsqfe86qqqr1403gr7uec7"); //   char   buf[BUFSIZ];
UNSUPPORTED("1f48j4jnissgxr7vxn2ydvcpc"); //   char*  sym;
UNSUPPORTED("bn2hu2d559vjzcspqljwuju0d"); //   int    len = strlen(s1) + strlen(s2) + 1;
UNSUPPORTED("cet6ol9qv33969gast2za432k"); //   if (len <= BUFSIZ) sym = buf;
UNSUPPORTED("67m32mb7uzppgnnd5pf7m3f4t"); //   else sym = (char*)malloc(len);
UNSUPPORTED("aymfgg3395ezmymxg0egl9wln"); //   strcpy(sym,s1);
UNSUPPORTED("cvkiaqe54lzs2xq6q470m89kq"); //   strcat(sym,s2);
UNSUPPORTED("dyxmfcfk9fwiunc9myuy0ik2w"); //   s = agstrdup (G,sym);
UNSUPPORTED("3zzvxiyb9i2jkc8vcsbzd2q18"); //   agstrfree (G,s1);
UNSUPPORTED("sslv4w9wjm8yvjeibusl2k18"); //   agstrfree (G,s2);
UNSUPPORTED("2iwa19m4ugg6arjvj5nrch2ku"); //   if (sym != buf) free (sym);
UNSUPPORTED("cw8hinum739bvjkye9axxkjp3"); //   return s;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 bkx44e7rust3ponkllhw1ahoe
// static char* concatPort (char* s1, char* s2) 
public static Object concatPort(Object... arg) {
UNSUPPORTED("1yranxmu2maol02ulzd1ka1re"); // static char*
UNSUPPORTED("adhbxv72usn95ltp2wntvrbvf"); // concatPort (char* s1, char* s2)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4b21y9nothvmubb9587tjs8sh"); //   char*  s;
UNSUPPORTED("9l6wsqfe86qqqr1403gr7uec7"); //   char   buf[BUFSIZ];
UNSUPPORTED("1f48j4jnissgxr7vxn2ydvcpc"); //   char*  sym;
UNSUPPORTED("f4lwxeaa5rnd6nz6vdzhge6et"); //   int    len = strlen(s1) + strlen(s2) + 2;  /* one more for ':' */
UNSUPPORTED("cet6ol9qv33969gast2za432k"); //   if (len <= BUFSIZ) sym = buf;
UNSUPPORTED("67m32mb7uzppgnnd5pf7m3f4t"); //   else sym = (char*)malloc(len);
UNSUPPORTED("6odnyh2beh2t4hsftcvtu4wpw"); //   sprintf (sym, "%s:%s", s1, s2);
UNSUPPORTED("dyxmfcfk9fwiunc9myuy0ik2w"); //   s = agstrdup (G,sym);
UNSUPPORTED("3zzvxiyb9i2jkc8vcsbzd2q18"); //   agstrfree (G,s1);
UNSUPPORTED("sslv4w9wjm8yvjeibusl2k18"); //   agstrfree (G,s2);
UNSUPPORTED("2iwa19m4ugg6arjvj5nrch2ku"); //   if (sym != buf) free (sym);
UNSUPPORTED("cw8hinum739bvjkye9axxkjp3"); //   return s;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 1wu2zkxrkapqxmxcpk0sz6yfb
// static void edgerhs(Agnode_t *tail, char *tport, item *hlist, char *key) 
public static Object edgerhs(Object... arg) {
UNSUPPORTED("b5cszuclmh8zcs1nm4exk4h4k"); // static void edgerhs(Agnode_t *tail, char *tport, item *hlist, char *key)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5juc6e3gmok6xh2qmseg04coo"); // 	Agnode_t		*head;
UNSUPPORTED("l83zfbv6jqr5s5nhi9d6ybcr"); // 	Agraph_t		*subg;
UNSUPPORTED("7fozzsfklec8ith6qlbd0pcac"); // 	item			*hptr;
UNSUPPORTED("2n8cerzeofmmsg8lqtfj35q8h"); // 	if (hlist->tag == 262) {
UNSUPPORTED("bcyi925rkwcxb8wm5d8c3gfr3"); // 		subg = hlist->u.subg;
UNSUPPORTED("beqq3lgovys1tdo87eej9c9wg"); // 		for (head = agfstnode(subg); head; head = agnxtnode(subg,head))
UNSUPPORTED("9236oqe7njgyne1628ibljajk"); // 			newedge(tail,tport,agsubnode(S->g,head,(0)),((char*)0),key);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("8k75h069sv2k9b6tgz77dscwd"); // 	else {
UNSUPPORTED("77skv3qf1q3nchzlmarvq49g0"); // 		for (hptr = hlist->u.list; hptr; hptr = hptr->next)
UNSUPPORTED("aotabry15o5sghsf3ede83u4f"); // 			newedge(tail,tport,agsubnode(S->g,hptr->u.n,(0)),hptr->str,key);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 a3m9s1rp1et7wscrmoort8ynw
// static void mkport(Agedge_t *e, char *name, char *val) 
public static Object mkport(Object... arg) {
UNSUPPORTED("368mljdxog3ye7fgu6dd0ruk"); // static void mkport(Agedge_t *e, char *name, char *val)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8u8vta7gzj4pptupcqrpe7chg"); // 	Agsym_t *attr;
UNSUPPORTED("32kkg8vfi204kivmg46scct2z"); // 	if (val) {
UNSUPPORTED("1ba9o42tfl2few19f4j5o7e2e"); // 		if ((attr = agattr(S->g,AGEDGE,name,((char*)0))) == ((Agsym_t*)0))
UNSUPPORTED("1ts001k918uoxowg1ifapyhgc"); // 			attr = agattr(S->g,AGEDGE,name,"");
UNSUPPORTED("8z3u8wda7bjqmhnr8qfno58ko"); // 		agxset(e,attr,val);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 3jhasz1c84d8odjwuy1vm43k4
// static void newedge(Agnode_t *t, char *tport, Agnode_t *h, char *hport, char *key) 
public static Object newedge(Object... arg) {
UNSUPPORTED("ewv9t3lhnuxkrzaiv91gcu4a3"); // static void newedge(Agnode_t *t, char *tport, Agnode_t *h, char *hport, char *key)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2dm1btnwd9xi0p9p979j8rhku"); // 	Agedge_t 	*e;
UNSUPPORTED("e0ghm0b8zsuqhgk76ecoapwo4"); // 	e = agedge(S->g,t,h,key,(!(0)));
UNSUPPORTED("1i3oiry7ci54di79pgv4ocg0e"); // 	if (e) {		/* can fail if graph is strict and t==h */
UNSUPPORTED("2tlloilvc5y6yc0d40mgj7k70"); // 		char    *tp = tport;
UNSUPPORTED("3swzx1e0as1cmh8dai9jbm1mc"); // 		char    *hp = hport;
UNSUPPORTED("5mayy4mz1bvbovxq9kj0i1xdb"); // 		if ((agtail(e) != aghead(e)) && (aghead(e) == t)) {
UNSUPPORTED("5g0p2pvtbymbvb5lpb0y0ds1y"); // 			/* could happen with an undirected edge */
UNSUPPORTED("6v7gq1686owe799wdkwcyuqtp"); // 			char    *temp;
UNSUPPORTED("dc7rssle784a7wa56fgxek6v7"); // 			temp = tp; tp = hp; hp = temp;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("78qk1y0axr2tyknef6wympqcy"); // 		mkport(e,"tailport",tp);
UNSUPPORTED("ehwsis9y6e723m7m1hgusnid2"); // 		mkport(e,"headport",hp);
UNSUPPORTED("aqch3wjhzz3bgqic0cvy7xral"); // 		applyattrs(e);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 cuw9hndwg799cg5culymno9yk
// static void startgraph(char *name, int directed, int strict) 
public static Object startgraph(Object... arg) {
UNSUPPORTED("agdswqj46guilud7xqi9ol9ti"); // static void startgraph(char *name, int directed, int strict)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("7j5god0tvtue2v94sag8bcuch"); // 	static Agdesc_t	req;	/* get rid of warnings */
UNSUPPORTED("190ox41xm4c6493dpsfjaobuw"); // 	if (G == ((Agraph_t*)0)) {
UNSUPPORTED("1zb7wxgr55vbt9grus1j3x6lw"); // 		req.directed = directed;
UNSUPPORTED("5oonop0t32gt3eel4wqz3ucsv"); // 		req.strict = strict;
UNSUPPORTED("9truon9yq3oeqvboe0dc48yah"); // 		req.maingraph = (!(0));
UNSUPPORTED("dti1d0wdjjd39kn59fp35nudd"); // 		Ag_G_global = G = agopen(name,req,Disc);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("8k75h069sv2k9b6tgz77dscwd"); // 	else {
UNSUPPORTED("38tjhst6lq4wvnpzmzj8wuxuy"); // 		Ag_G_global = G;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("bh6qzhsh06m3zoskkgao54u5r"); // 	S = push(S,G);
UNSUPPORTED("9iv7rvcylqhmo30p49vzj3vrw"); // 	agstrfree(((Agraph_t*)0),name);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 e42col7mcjqba8fenskuirugr
// static void endgraph() 
public static Object endgraph(Object... arg) {
UNSUPPORTED("8hypu5d7oarybv8tle2tceufy"); // static void endgraph()
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("6xo399l6oqr4jgsvm3u1x5919"); // 	aglexeof();
UNSUPPORTED("eieq0mv0dmgfzd35is58n0mhy"); // 	aginternalmapclearlocalnames(G);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 4vb1txgz6w6tfubnnzlrlckow
// static void opensubg(char *name) 
public static Object opensubg(Object... arg) {
UNSUPPORTED("6xnbjq6nhp1vx2gl8nwhqbaxg"); // static void opensubg(char *name)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("3nf2v51byeoqq9beson20rs71"); // 	S = push(S,agsubg(S->g,name,(!(0))));
UNSUPPORTED("6hpfigkim341uzgw6kw2qlnha"); // 	agstrfree(G,name);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 bome5g8t2s4wsjx513q5lc4u9
// static void closesubg() 
public static Object closesubg(Object... arg) {
UNSUPPORTED("865ot1za84qdkz7gd990w0sb2"); // static void closesubg()
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8g2n9ydys5iriq7d6jd62rklu"); // 	Agraph_t *subg = S->g;
UNSUPPORTED("4dzhr7th6c94bpix9lxvv4uc1"); // 	S = pop(S);
UNSUPPORTED("e6sg8bcwvjrsiucbq4bqtbkbb"); // 	S->subg = subg;
UNSUPPORTED("bt8qt5d94yexozgdbv5sspmm4"); // 	;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


//1 8g4d6dcjget27t8hqp7eybgpl
// extern FILE *yyin




//3 5wtkfeq5ox267tk12iouru1vm
// Agraph_t *agconcat(Agraph_t *g, void *chan, Agdisc_t *disc) 
public static Object agconcat(Object... arg) {
UNSUPPORTED("6r0qm94hoyqq0immumbs1ig53"); // Agraph_t *agconcat(Agraph_t *g, void *chan, Agdisc_t *disc)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8a5bzxlnuoh33m8bti9a30jma"); // 	yyin = chan;
UNSUPPORTED("1lxo1qy1v0ne39yzhb5rhnrqw"); // 	G = g;
UNSUPPORTED("5ypybw9agjfexnf556xfrowfa"); // 	Ag_G_global = ((Agraph_t*)0);
UNSUPPORTED("3k1eoyzy9cax5na4ly3m7czse"); // 	Disc = (disc? disc :  &AgDefaultDisc);
UNSUPPORTED("4wqdongggth14vrryrnyc14sm"); // 	aglexinit(Disc, chan);
UNSUPPORTED("b4r4bjbx8gll47nhuogazvah5"); // 	yyparse();
UNSUPPORTED("4cqiv8d5i2hntfqljf84l8vad"); // 	if (Ag_G_global == ((Agraph_t*)0)) aglexbad();
UNSUPPORTED("2y6jt5ao3mvjdns25xy9dlsnl"); // 	return Ag_G_global;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 7ocwvmy4lnwgipb2vh08sp13d
// Agraph_t *agread(void *fp, Agdisc_t *disc) 
public static Object agread(Object... arg) {
UNSUPPORTED("7vytxh3ldu2cxyx0i6923e5ci"); // Agraph_t *agread(void *fp, Agdisc_t *disc) {return agconcat(((Agraph_t*)0),fp,disc); }

throw new UnsupportedOperationException();
}


}
