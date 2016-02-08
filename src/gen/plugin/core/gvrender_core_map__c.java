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
package gen.plugin.core;
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

public class gvrender_core_map__c {
//1 2digov3edok6d5srhgtlmrycs
// extern lt_symlist_t lt_preloaded_symbols[]


//1 baedz5i9est5csw3epz3cv7z
// typedef Ppoly_t Ppolyline_t


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




//3 csv3l33vvs1vebcphye24jq0f
// static void map_output_shape (GVJ_t *job, map_shape_t map_shape, pointf * AF, int nump,                 char* url, char *tooltip, char *target, char *id) 
public static Object map_output_shape(Object... arg) {
UNSUPPORTED("8kf7pfh75y963yumtk9b9z3ys"); // static void map_output_shape (GVJ_t *job, map_shape_t map_shape, pointf * AF, int nump,
UNSUPPORTED("bfj85pn6xenrvqizqe3wao6l7"); //                 char* url, char *tooltip, char *target, char *id)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("b17di9c7wgtqm51bvsyxz6e2f"); //     int i;
UNSUPPORTED("4yzh52cxlcnx4kwijawrsiq93"); //     static point *A;
UNSUPPORTED("ajll5vpeb8zhkx6ef6exlg0x"); //     static int size_A;
UNSUPPORTED("1w53t40nspe671k7na03lhgrq"); //     if (!AF || !nump)
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("d68wemoq0y2k254bi7ibengwn"); //     if (size_A < nump) {
UNSUPPORTED("7edr6xzvxhtgwcv3aqikccj9i"); // 	size_A = nump + 10;
UNSUPPORTED("497iml6bv2y1ybutiuoiszh1m"); // 	A = realloc(A, size_A * sizeof(point));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("4v4y5eb8k5nr6qaau3ynqhvcq"); //     for (i = 0; i < nump; i++)
UNSUPPORTED("cx0olmahgh2xwrv8z1bx82xm2"); // 	PF2P(AF[i], A[i]);
UNSUPPORTED("5i3rds5u46g9ststudzor9xt"); //     if (job->render.id == FORMAT_IMAP && url && url[0]) {
UNSUPPORTED("2hz9rwf090vttuoibzu9fsw5q"); //         switch (map_shape) {
UNSUPPORTED("9ny69tiwv0c1k92wg0f5bc2hx"); //         case MAP_RECTANGLE:
UNSUPPORTED("3fnbb8my11ctfv54p20sjx95u"); // 	    /* Y_GOES_DOWN so need UL to LR */
UNSUPPORTED("13myxcrwgvjfs7vqhn41gptdg"); //             gvprintf(job, "rect %s %d,%d %d,%d\n", url,
UNSUPPORTED("apxbzz2r91p4jj1fzpftrnwll"); //                 A[0].x, A[1].y, A[1].x, A[0].y);
UNSUPPORTED("dtx9szdvwh3uhziubh9zvgbk5"); //             break;
UNSUPPORTED("969pm8kka9j9ajn1lpb3q0e7f"); //         case MAP_CIRCLE:
UNSUPPORTED("1f8q1mvrhrf0asqye0b30as1n"); //             gvprintf(job, "circle %s %d,%d,%d\n", url,
UNSUPPORTED("e8ycnkoqzmazghue74s8t4ods"); //                 A[0].x, A[0].y, A[1].x-A[0].x);
UNSUPPORTED("dtx9szdvwh3uhziubh9zvgbk5"); //             break;
UNSUPPORTED("clptlh6vuwx7mynynpacj0ktl"); //         case MAP_POLYGON:
UNSUPPORTED("8fgyk7ask8my1kx2al65iaaje"); //             gvprintf(job, "poly %s", url);
UNSUPPORTED("d0fj0wck6hjqyxoodtze7797f"); //             for (i = 0; i < nump; i++)
UNSUPPORTED("d0b7gixn87mqrfgw7cfdyuj9h"); //                 gvprintf(job, " %d,%d", A[i].x, A[i].y);
UNSUPPORTED("5uq09elejy2ot3s8x5d13dxs9"); //             gvputs(job, "\n");
UNSUPPORTED("dtx9szdvwh3uhziubh9zvgbk5"); //             break;
UNSUPPORTED("p0mt8wznalavjdm44ot4ykl7"); //         default:
UNSUPPORTED("1hh9o1t0fynw7ejmjny7gevig"); //             assert(0);
UNSUPPORTED("dtx9szdvwh3uhziubh9zvgbk5"); //             break;
UNSUPPORTED("4mhlpjofolwivhm0tl8cxznly"); //         }
UNSUPPORTED("d3576y606phfrc0nvil7m7j14"); //     } else if (job->render.id == FORMAT_ISMAP && url && url[0]) {
UNSUPPORTED("2hz9rwf090vttuoibzu9fsw5q"); //         switch (map_shape) {
UNSUPPORTED("9ny69tiwv0c1k92wg0f5bc2hx"); //         case MAP_RECTANGLE:
UNSUPPORTED("3fnbb8my11ctfv54p20sjx95u"); // 	    /* Y_GOES_DOWN so need UL to LR */
UNSUPPORTED("4cujqj1wxkt2prhfpa93ocz33"); //             gvprintf(job, "rectangle (%d,%d) (%d,%d) %s %s\n",
UNSUPPORTED("b0bipjx63l5bwm4ur9r16oddw"); //                 A[0].x, A[1].y, A[1].x, A[0].y, url, tooltip);
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("p0mt8wznalavjdm44ot4ykl7"); //         default:
UNSUPPORTED("1hh9o1t0fynw7ejmjny7gevig"); //             assert(0);
UNSUPPORTED("dtx9szdvwh3uhziubh9zvgbk5"); //             break;
UNSUPPORTED("4mhlpjofolwivhm0tl8cxznly"); //         }
UNSUPPORTED("f271g0t382wvokvh5b79gnj3c"); //     } else if (job->render.id == FORMAT_CMAP || job->render.id == FORMAT_CMAPX) {
UNSUPPORTED("2hz9rwf090vttuoibzu9fsw5q"); //         switch (map_shape) {
UNSUPPORTED("969pm8kka9j9ajn1lpb3q0e7f"); //         case MAP_CIRCLE:
UNSUPPORTED("apmt6zpnpwkhkathi0qvmwxok"); //             gvputs(job, "<area shape=\"circle\"");
UNSUPPORTED("dtx9szdvwh3uhziubh9zvgbk5"); //             break;
UNSUPPORTED("9ny69tiwv0c1k92wg0f5bc2hx"); //         case MAP_RECTANGLE:
UNSUPPORTED("30f72ggbasq2nt5ydpokq8id5"); //             gvputs(job, "<area shape=\"rect\"");
UNSUPPORTED("dtx9szdvwh3uhziubh9zvgbk5"); //             break;
UNSUPPORTED("clptlh6vuwx7mynynpacj0ktl"); //         case MAP_POLYGON:
UNSUPPORTED("duw3m1pbuq0p43ygvcwf5iuix"); //             gvputs(job, "<area shape=\"poly\"");
UNSUPPORTED("dtx9szdvwh3uhziubh9zvgbk5"); //             break;
UNSUPPORTED("p0mt8wznalavjdm44ot4ykl7"); //         default:
UNSUPPORTED("1hh9o1t0fynw7ejmjny7gevig"); //             assert(0);
UNSUPPORTED("dtx9szdvwh3uhziubh9zvgbk5"); //             break;
UNSUPPORTED("4mhlpjofolwivhm0tl8cxznly"); //         }
UNSUPPORTED("5rv9tqbo9cxejx41go9hrdwrl"); //         if (id && id[0]) {
UNSUPPORTED("a6oaosb1838cqwsf5ywe8guuu"); //             gvputs(job, " id=\"");
UNSUPPORTED("9cth0oqm1v5s1emzlssovm48k"); // 	    gvputs(job, xml_url_string(id));
UNSUPPORTED("95l7z94bfy2nzrl3i6ftlu2dx"); // 	    gvputs(job, "\"");
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("4ma8vut9zx3q7yov4i1ni9b3"); //         if (url && url[0]) {
UNSUPPORTED("nb9d8sf8cun8eyaxj0w8i8we"); //             gvputs(job, " href=\"");
UNSUPPORTED("em0oy8jxmfk8585ewpx8z7ggr"); // 	    gvputs(job, xml_url_string(url));
UNSUPPORTED("95l7z94bfy2nzrl3i6ftlu2dx"); // 	    gvputs(job, "\"");
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("ccc1h802tb8vbu55pzr2q88c6"); //         if (target && target[0]) {
UNSUPPORTED("87hwkj9bhvjwyeu3sy8yeb446"); //             gvputs(job, " target=\"");
UNSUPPORTED("3gjlqs0lvumek2leuhbar7742"); // 	    gvputs(job, xml_string(target));
UNSUPPORTED("95l7z94bfy2nzrl3i6ftlu2dx"); // 	    gvputs(job, "\"");
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("ccrueeib4dlvmyrlpzxl572jv"); //         if (tooltip && tooltip[0]) {
UNSUPPORTED("5z1g9653z5nll8tj1zfbtbfhs"); //             gvputs(job, " title=\"");
UNSUPPORTED("8cnn9o871ccbhwt4nvi7hj3nk"); // 	    gvputs(job, xml_string(tooltip));
UNSUPPORTED("95l7z94bfy2nzrl3i6ftlu2dx"); // 	    gvputs(job, "\"");
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("ap75hs54mf8uwlaksz3dq3q89"); //         /*
UNSUPPORTED("dlkx3227vk7i02kddhe30ckei"); // 	 * alt text is intended for the visually impaired, but such
UNSUPPORTED("blyjuls4m5n3cigyictzx21m6"); // 	 * folk are not likely to be clicking around on a graph anyway.
UNSUPPORTED("80g0irekv0ioq4hbjw5vdol8w"); // 	 * IE on the PC platform (but not on Macs) incorrectly
UNSUPPORTED("erjeyh8k70b0ioqbyappgd8u9"); // 	 * uses (non-empty) alt strings instead of title strings for tooltips.
UNSUPPORTED("c91r070nrl82e2aq0ib4z23bi"); // 	 * To make tooltips work and avoid this IE issue,
UNSUPPORTED("1ziztq91p8zvu5u89w49ok6i9"); // 	 * while still satisfying usability guidelines
UNSUPPORTED("d0jqqufyfhankljju5difsl6c"); // 	 * that require that there is always an alt string,
UNSUPPORTED("cwigxwosvw21vj7bc0wlzl3fa"); // 	 * we generate just an empty alt string.
UNSUPPORTED("62wb43w2xc6ex6hootjubbx22"); // 	 */
UNSUPPORTED("6cjb47iuidgy3uabflazyihui"); //         gvputs(job, " alt=\"\"");
UNSUPPORTED("6wlgme3q9zoghev0q35e7s8db"); //         gvputs(job, " coords=\"");
UNSUPPORTED("2hz9rwf090vttuoibzu9fsw5q"); //         switch (map_shape) {
UNSUPPORTED("969pm8kka9j9ajn1lpb3q0e7f"); //         case MAP_CIRCLE:
UNSUPPORTED("ttug313i5xbw4g00y6uuby5h"); //             gvprintf(job, "%d,%d,%d", A[0].x, A[0].y, A[1].x-A[0].x);
UNSUPPORTED("dtx9szdvwh3uhziubh9zvgbk5"); //             break;
UNSUPPORTED("9ny69tiwv0c1k92wg0f5bc2hx"); //         case MAP_RECTANGLE:
UNSUPPORTED("3fnbb8my11ctfv54p20sjx95u"); // 	    /* Y_GOES_DOWN so need UL to LR */
UNSUPPORTED("svfp196nfn5jxfrwzpscse8o"); //             gvprintf(job, "%d,%d,%d,%d", A[0].x, A[1].y, A[1].x, A[0].y);  
UNSUPPORTED("dtx9szdvwh3uhziubh9zvgbk5"); //             break;
UNSUPPORTED("clptlh6vuwx7mynynpacj0ktl"); //         case MAP_POLYGON:
UNSUPPORTED("91f5jxh3lupiyx3pclv6eqqu"); //             gvprintf(job, "%d,%d", A[0].x, A[0].y);
UNSUPPORTED("c8kuvlz6ei9dgmyc1f4xtdq1b"); //             for (i = 1; i < nump; i++)
UNSUPPORTED("1wwjp5ka1svvye9kotkdqmcye"); //                 gvprintf(job, ",%d,%d", A[i].x, A[i].y);
UNSUPPORTED("dtx9szdvwh3uhziubh9zvgbk5"); //             break;
UNSUPPORTED("p0mt8wznalavjdm44ot4ykl7"); //         default:
UNSUPPORTED("dtx9szdvwh3uhziubh9zvgbk5"); //             break;
UNSUPPORTED("4mhlpjofolwivhm0tl8cxznly"); //         }
UNSUPPORTED("ay9i8u6l0r1n1ygmd63r7goup"); //         if (job->render.id == FORMAT_CMAPX)
UNSUPPORTED("9wuepleq2yxn1w8g9l2t5bv8n"); //             gvputs(job, "\"/>\n");
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("8ljg9ari52ao59grstt68083c"); //             gvputs(job, "\">\n");
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 ecfzje2iii2p83pu7a8oknudk
// static void map_begin_page(GVJ_t * job) 
public static Object map_begin_page(Object... arg) {
UNSUPPORTED("51hmqgn59iqb0k30s7slug47h"); // static void map_begin_page(GVJ_t * job)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("84llcpxtvxaggx841n2t03850"); //     obj_state_t *obj = job->obj;
UNSUPPORTED("8yytudftst76763qgnjebkzhm"); //     char *s;
UNSUPPORTED("69opxqj69jbqthw7e5x8p71j0"); //     switch (job->render.id) {
UNSUPPORTED("7txd1s74e7fla0b5ppbpj4e9m"); //     case FORMAT_IMAP:
UNSUPPORTED("5qsnhnk2hikn4v5rngaesebru"); //         gvputs(job, "base referer\n");
UNSUPPORTED("bgwmnukjcck9eqoe70218t5sl"); //         if (obj->url && obj->url[0]) {
UNSUPPORTED("5mfw77dfjvx7mortvgofrjffx"); // 	    gvputs(job, "default ");
UNSUPPORTED("cmkzfcsqw6lcz4oeepg7r0ysr"); // 	    gvputs(job, xml_string(obj->url));
UNSUPPORTED("3wbqcj3wgh85ybkhw9jxfnqt5"); // 	    gvputs(job, "\n");
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("bzxyddcf9jharsko2rb8asyik"); //         break;
UNSUPPORTED("azd5ozzc5h2655cjyqy5l6xdm"); //     case FORMAT_ISMAP:
UNSUPPORTED("bgwmnukjcck9eqoe70218t5sl"); //         if (obj->url && obj->url[0]) {
UNSUPPORTED("5mfw77dfjvx7mortvgofrjffx"); // 	    gvputs(job, "default ");
UNSUPPORTED("cmkzfcsqw6lcz4oeepg7r0ysr"); // 	    gvputs(job, xml_string(obj->url));
UNSUPPORTED("6iupbw97yijdtdpg2bxm4syfu"); // 	    gvputs(job, " ");
UNSUPPORTED("4ujbj52xrmo4jrufevyc1puvo"); // 	    gvputs(job, xml_string(agnameof(obj->u.g)));
UNSUPPORTED("3wbqcj3wgh85ybkhw9jxfnqt5"); // 	    gvputs(job, "\n");
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("bzxyddcf9jharsko2rb8asyik"); //         break;
UNSUPPORTED("t5h5je1zpt3u8ndyh15gdg9l"); //     case FORMAT_CMAPX:
UNSUPPORTED("f34ya28ve4bvds8gp4exdfj56"); // 	s = xml_string(agnameof(obj->u.g));
UNSUPPORTED("xrk4koadrppi4k4gs57d4h9m"); // 	gvputs(job, "<map id=\"");
UNSUPPORTED("3cuw5zkbwgq5q6fre6xhaux9i"); // 	gvputs(job, s);
UNSUPPORTED("bxl37f6ness3vk5h7dtdkc68g"); // 	gvputs(job, "\" name=\"");
UNSUPPORTED("3cuw5zkbwgq5q6fre6xhaux9i"); // 	gvputs(job, s);
UNSUPPORTED("8dfworkgbm5ldpq8ipl7gnow1"); // 	gvputs(job, "\">\n");
UNSUPPORTED("bzxyddcf9jharsko2rb8asyik"); //         break;
UNSUPPORTED("8l3rwj6ctswoa4gvh2j4poq70"); //     default:
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 4mrmum1lvc20st1t0ngkucbc4
// static void map_end_page(GVJ_t * job) 
public static Object map_end_page(Object... arg) {
UNSUPPORTED("em0rrlv2wa8t6mbr0f800q1n0"); // static void map_end_page(GVJ_t * job)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("84llcpxtvxaggx841n2t03850"); //     obj_state_t *obj = job->obj;
UNSUPPORTED("69opxqj69jbqthw7e5x8p71j0"); //     switch (job->render.id) {
UNSUPPORTED("d2zsw3sbah6m5v82up3yiqu8w"); //     case FORMAT_CMAP:
UNSUPPORTED("1l81rvjolrz0avoek7zv4ikn6"); // 	map_output_shape(job, obj->url_map_shape,
UNSUPPORTED("b1a3iatyrxuif1n4gqu0f8u5u"); // 		obj->url_map_p,obj->url_map_n,
UNSUPPORTED("av1tl9edbbm94up94c6rfx2tc"); // 		obj->url, obj->tooltip, obj->target, obj->id);
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("t5h5je1zpt3u8ndyh15gdg9l"); //     case FORMAT_CMAPX:
UNSUPPORTED("1l81rvjolrz0avoek7zv4ikn6"); // 	map_output_shape(job, obj->url_map_shape,
UNSUPPORTED("b1a3iatyrxuif1n4gqu0f8u5u"); // 		obj->url_map_p,obj->url_map_n,
UNSUPPORTED("av1tl9edbbm94up94c6rfx2tc"); // 		obj->url, obj->tooltip, obj->target, obj->id);
UNSUPPORTED("bli0vsh6dvw26mi7hr07pgrto"); //         gvputs(job, "</map>\n");
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("8l3rwj6ctswoa4gvh2j4poq70"); //     default:
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6gah2kjnd3decve8krn1svbqb
// static void map_begin_anchor(GVJ_t * job, char *url, char *tooltip, char *target, char *id) 
public static Object map_begin_anchor(Object... arg) {
UNSUPPORTED("5qn8yqjbqcyx0grv0yypccdy2"); // static void map_begin_anchor(GVJ_t * job, char *url, char *tooltip, char *target, char *id)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("84llcpxtvxaggx841n2t03850"); //     obj_state_t *obj = job->obj;
UNSUPPORTED("6s3igifxj8shhox656bdbx5pf"); //     map_output_shape(job, obj->url_map_shape,
UNSUPPORTED("2clu43j15vr7y290qz69husnn"); // 		obj->url_map_p, obj->url_map_n, 
UNSUPPORTED("6vqhbjy76o3uv1cptjwt6y45l"); // 		url, tooltip, target, id);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


//1 aunc2bv7z37pgfwoea8pqzdw6
// static gvrender_engine_t map_engine = 


//1 1zilsb5vzp5hkz1bqy634l392
// static gvrender_features_t render_features_map = 


//1 bi57uhrsu8bhcnnl39xr27v97
// static gvdevice_features_t device_features_map = 


//1 3nksama0j9ayv22motim935v3
// static gvdevice_features_t device_features_map_nopoly = 


//1 zv8eak0r501gmnqu92pzr5x5
// gvplugin_installed_t gvrender_map_types[] = 


//1 97mwnp7oqdjce0xttnqhkq7t3
// gvplugin_installed_t gvdevice_map_types[] = 


}
