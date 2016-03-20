/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * Project Info:  http://plantuml.com
 * 
 * This file is part of Smetana.
 * Smetana is a partial translation of Graphviz/Dot sources from C to Java.
 *
 * (C) Copyright 2009-2017, Arnaud Roques
 *
 * This translation is distributed under the same Licence as the original C program.
 * 
 * THE ACCOMPANYING PROGRAM IS PROVIDED UNDER THE TERMS OF THIS ECLIPSE PUBLIC
 * LICENSE ("AGREEMENT"). [Eclipse Public License - v 1.0]
 * 
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THE PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THIS AGREEMENT.
 * 
 * You may obtain a copy of the License at
 * 
 * http://www.eclipse.org/legal/epl-v10.html
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

package smetana.core;

import h.Agattr_s;
import h.Agclos_s;
import h.Agdatadict_s;
import h.Agdesc_s;
import h.Agedge_s;
import h.Agedgeinfo_t;
import h.Agedgepair_s;
import h.Agiddisc_s;
import h.Agmemdisc_s;
import h.Agnode_s;
import h.Agnodeinfo_t;
import h.Agobj_s;
import h.Agraph_s;
import h.Agrec_s;
import h.Agsubnode_s;
import h.Agsym_s;
import h.Agtag_s;
import h.Dtmemory_f;
import h.GVC_s;
import h.IMapEntry_t;
import h.Pedge_t;
import h.Ppoly_t;
import h._dt_s;
import h._dtdata_s;
import h._dtdisc_s;
import h._dtlink_s;
import h._dtmethod_s;
import h.adjmatrix_t;
import h.arrowdir_t;
import h.arrowtype_t;
import h.aspect_t;
import h.bezier;
import h.boxf;
import h.deque_t;
import h.elist;
import h.fontinfo;
import h.gvlayout_engine_s;
import h.gvlayout_features_t;
import h.gvplugin_installed_t;
import h.inside_t;
import h.label_params_t;
import h.nlist_t;
import h.nodequeue;
import h.object_t;
import h.pack_info;
import h.path;
import h.pathend_t;
import h.point;
import h.pointf;
import h.pointnlink_t;
import h.polygon_t;
import h.port;
import h.refstr_t;
import h.shape_desc;
import h.shape_functions;
import h.splineInfo;
import h.spline_info_t;
import h.splines;
import h.textfont_t;
import h.textlabel_t;
import h.textspan_t;
import h.tna_t;
import h.triangle_t;
import h.xlabel_t;

public interface AllH extends Agraph_s, Agobj_s, Agrec_s, Agdesc_s, Agmemdisc_s, Agclos_s, Agiddisc_s, _dtmethod_s,
		_dtdisc_s, _dt_s, _dtdata_s, refstr_t, _dtlink_s, Agdatadict_s, Agattr_s, Agsubnode_s, Agnode_s, Agtag_s,
		Agedge_s, Agedgepair_s, Agsym_s, GVC_s, gvlayout_features_t, gvlayout_engine_s, gvplugin_installed_t, pointf,
		pack_info, aspect_t, fontinfo, shape_functions, polygon_t, shape_desc, textlabel_t, IMapEntry_t, textspan_t,
		textfont_t, point, port, elist, Dtmemory_f, nlist_t, nodequeue, Agnodeinfo_t, Agedgeinfo_t, spline_info_t,
		splineInfo, path, pathend_t, boxf, Ppoly_t, pointnlink_t, deque_t, triangle_t, tna_t, Pedge_t, splines, bezier,
		inside_t, arrowdir_t, arrowtype_t, label_params_t, object_t, xlabel_t, adjmatrix_t {

}
